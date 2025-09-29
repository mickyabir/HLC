#pragma once

#include <concepts>

namespace hlc {
    template <typename Stream>
    concept stream = requires(Stream& s) {
        { s.eof() } -> std::same_as<bool>;
    };

    template <typename Stream, typename Value>
    concept output_stream = stream<Stream> && requires(Stream& s, Value v) {
        { s << v } -> std::same_as<Stream&>;
    };

    template <typename Stream, typename Value>
    concept input_stream = stream<Stream> && requires(Stream& s, Value v) {
        { s >> v } -> std::same_as<Stream&>;
    };
}  // namespace hlc
