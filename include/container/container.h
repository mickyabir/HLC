#pragma once

#include <concepts>

namespace hlc {
    template <typename T>
    concept container = requires(T& t, const T& ct, T& other) {
        typename T::value_type;
        typename T::reference;
        typename T::const_reference;
        typename T::iterator;
        typename T::const_iterator;

        { t.begin() } -> std::same_as<typename T::iterator>;
        { t.end() } -> std::same_as<typename T::iterator>;

        { ct.begin() } -> std::same_as<typename T::const_iterator>;
        { ct.end() } -> std::same_as<typename T::const_iterator>;

        { t.empty() } -> std::same_as<bool>;

        { t.size() } -> std::same_as<typename T::size_type>;
        { t.max_size() } -> std::same_as<typename T::size_type>;

        { t.swap(other) } -> std::same_as<void>;
    };

    template <typename T>
    concept sequence_container = container<T> && requires(T& t, const T& ct) {
        { t.front() } -> std::same_as<typename T::reference>;
        { ct.front() } -> std::same_as<typename T::const_reference>;
    };
}  // namespace hlc