#pragma once

#include <concepts>

namespace hlc {
    /*
     * Reference requirements from:
     * https://en.cppreference.com/w/cpp/named_req/Container.html
     */
    template <typename T>
    concept container = requires(T& t, const T& ct, T& other) {
        typename T::value_type;
        typename T::reference;
        typename T::const_reference;
        typename T::iterator;
        typename T::const_iterator;
        typename T::difference_type;
        typename T::size_type;

        { T() } -> std::same_as<T>;
        { t.~T() } -> std::same_as<void>;

        { t.begin() } -> std::same_as<typename T::iterator>;
        { ct.begin() } -> std::same_as<typename T::const_iterator>;

        { t.end() } -> std::same_as<typename T::iterator>;
        { ct.end() } -> std::same_as<typename T::const_iterator>;

        { t.cbegin() } -> std::same_as<typename T::const_iterator>;
        { t.cend() } -> std::same_as<typename T::const_iterator>;

        { t == other } -> std::same_as<bool>;
        { t != other } -> std::same_as<bool>;

        { t.size() } -> std::same_as<typename T::size_type>;
        { t.max_size() } -> std::same_as<typename T::size_type>;
        { t.empty() } -> std::same_as<bool>;

        { swap(t, other) } -> std::same_as<void>;
        { t.swap(other) } -> std::same_as<void>;
    };

    template <typename T>
    concept sequence_container = container<T> && requires(T& t, const T& ct) {
        { t.front() } -> std::same_as<typename T::reference>;
        { ct.front() } -> std::same_as<typename T::const_reference>;
    };

    template <typename T>
    concept associative_container = container<T> && requires(T& t, const T& ct) {
        { t.rbegin() } -> std::same_as<typename T::iterator>;
        { ct.rbegin() } -> std::same_as<const typename T::iterator>;
    };
}  // namespace hlc