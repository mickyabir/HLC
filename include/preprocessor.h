#pragma once

#if !defined(__cplusplus) || (__cplusplus < 202002L) || !defined(__cpp_concepts)
#error "The High-Level Concepts (HLC) library requires C++20 or later (concepts support)."
#endif

#if defined(_MSC_VER)
#define HLC_COMPILER_MSVC _MSC_VER
#elif defined(__clang__)
#define HLC_COMPILER_CLANG __clang_major__
#elif defined(__GNUC__)
#define HLC_COMPILER_GCC __GNUC__
#else
#define HLC_COMPILER_UNKNOWN 1
#endif

#ifndef __has_cpp_attribute
#define __has_cpp_attribute(x) 0
#endif

#if defined(_MSC_VER)
#define HLC_FORCEINLINE __forceinline
#elif defined(__GNUC__) || defined(__clang__)
#define HLC_FORCEINLINE inline __attribute__((always_inline))
#else
#define HLC_FORCEINLINE inline
#endif

#define HLC_CONSTEXPR constexpr

#define HLC_INLINE inline

#if __has_cpp_attribute(nodiscard)
#define HLC_NODISCARD [[nodiscard]]
#else
#define HLC_NODISCARD
#endif

#if __has_cpp_attribute(maybe_unused)
#define HLC_MAYBE_UNUSED [[maybe_unused]]
#else
#define HLC_MAYBE_UNUSED
#endif

#if __has_cpp_attribute(deprecated)
#define HLC_DEPRECATED(msg) [[deprecated(msg)]]
#else
#define HLC_DEPRECATED(msg)
#endif

#if defined(NDEBUG)
#define HLC_DEBUG 0
#else
#define HLC_DEBUG 1
#endif