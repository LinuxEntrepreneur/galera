//
// detail/fenced_block.hpp
// ~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2011 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef ASIO_DETAIL_FENCED_BLOCK_HPP
#define ASIO_DETAIL_FENCED_BLOCK_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "asio/detail/config.hpp"

// #763 - Galera library is multithreaded so make sure that ASIO will have
//        MT support too.
#if !defined(BOOST_HAS_THREADS)
#error "BOOST_HAS_THREADS not defined"
#endif

#if !defined(BOOST_HAS_THREADS) \
  || defined(ASIO_DISABLE_THREADS) \
  || defined(ASIO_DISABLE_FENCED_BLOCK)
# include "asio/detail/null_fenced_block.hpp"
#elif defined(__MACH__) && defined(__APPLE__)
# include "asio/detail/macos_fenced_block.hpp"
#elif defined(__sun)
# include "asio/detail/solaris_fenced_block.hpp"
#elif defined(__GNUC__) && defined(__arm__)
# include "asio/detail/gcc_arm_fenced_block.hpp"
#elif defined(__GNUC__) && (defined(__hppa) || defined(__hppa__))
# include "asio/detail/gcc_hppa_fenced_block.hpp"
#elif defined(__GNUC__) \
  && ((__GNUC__ == 4 && __GNUC_MINOR__ >= 1) || (__GNUC__ > 4)) \
  && !defined(__INTEL_COMPILER) && !defined(__ICL) \
  && !defined(__ICC) && !defined(__ECC) && !defined(__PATHSCALE__)
# include "asio/detail/gcc_sync_fenced_block.hpp"
#elif defined(__GNUC__) && (defined(__i386__) || defined(__x86_64__))
# include "asio/detail/gcc_x86_fenced_block.hpp"
#elif defined(BOOST_WINDOWS) && !defined(UNDER_CE)
# include "asio/detail/win_fenced_block.hpp"
#else
# include "asio/detail/null_fenced_block.hpp"
#endif

namespace asio {
namespace detail {

#if !defined(BOOST_HAS_THREADS) \
  || defined(ASIO_DISABLE_THREADS) \
  || defined(ASIO_DISABLE_FENCED_BLOCK)
typedef null_fenced_block fenced_block;
#elif defined(__MACH__) && defined(__APPLE__)
typedef macos_fenced_block fenced_block;
#elif defined(__sun)
typedef solaris_fenced_block fenced_block;
#elif defined(__GNUC__) && defined(__arm__)
typedef gcc_arm_fenced_block fenced_block;
#elif defined(__GNUC__) && (defined(__hppa) || defined(__hppa__))
typedef gcc_hppa_fenced_block fenced_block;
#elif defined(__GNUC__) \
  && ((__GNUC__ == 4 && __GNUC_MINOR__ >= 1) || (__GNUC__ > 4)) \
  && !defined(__INTEL_COMPILER) && !defined(__ICL) \
  && !defined(__ICC) && !defined(__ECC) && !defined(__PATHSCALE__)
typedef gcc_sync_fenced_block fenced_block;
#elif defined(__GNUC__) && (defined(__i386__) || defined(__x86_64__))
typedef gcc_x86_fenced_block fenced_block;
#elif defined(BOOST_WINDOWS) && !defined(UNDER_CE)
typedef win_fenced_block fenced_block;
#else
typedef null_fenced_block fenced_block;
#endif

} // namespace detail
} // namespace asio

#endif // ASIO_DETAIL_FENCED_BLOCK_HPP
