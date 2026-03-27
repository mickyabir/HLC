#pragma once

#include <concepts>

#include <container/container.h>

namespace hlc {
    template <typename T>
    concept map = container<T> && requires(T& t, const T& ct) {
        typename T::key_type;
        typename T::mapped_type;
        typename T::size_type;

        { t.at(std::declval<const typename T::key_type&>()) } -> std::same_as<typename T::mapped_type&>;
        { ct.at(std::declval<const typename T::key_type&>()) } -> std::same_as<const typename T::mapped_type&>;

        { t[std::declval<const typename T::key_type&>()] } -> std::same_as<typename T::mapped_type&>;
        { t[std::declval<typename T::key_type&&>()] } -> std::same_as<typename T::mapped_type&>;
    };
}  // namespace hlc
