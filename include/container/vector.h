#pragma once

#include <concepts>

#include <container/container.h>

namespace hlc {
    template <typename T>
    concept vector = container<T> && requires(T& t, const T& ct, const std::size_t i) {
        typename T::size_type;

        { t.front() } -> std::same_as<typename T::value_type&>;
        { t.back() } -> std::same_as<typename T::value_type&>;

        { t[i] } -> std::same_as<typename T::value_type&>;
        { ct[i] } -> std::same_as<const typename T::value_type&>;


        { t.clear() } -> std::same_as<void>;

        { t.push_back(std::declval<const typename T::value_type&>()) } -> std::same_as<void>;
        { t.push_back(std::declval<typename T::value_type&&>()) } -> std::same_as<void>;

        {
            t.insert(std::declval<typename T::const_iterator>(), std::declval<const typename T::value_type&>())
        } -> std::same_as<typename T::iterator>;

        {
            t.insert(std::declval<typename T::const_iterator>(), std::declval<typename T::value_type&&>())
        } -> std::same_as<typename T::iterator>;
   };

}  // namespace hlc