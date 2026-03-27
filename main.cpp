#include <iostream>
#include <map>
#include <vector>

#include <hlc.h>

class Test {
public:
    Test& operator<<(int x) {
        return *this;
    }
    Test& operator<<(std::string x) {
        return *this;
    }

    Test& operator>>(int x) {
        return *this;
    }
    Test& operator>>(std::string x) {
        return *this;
    }

    bool eof() {
        return false;
    }
};

int main() {
    static_assert(hlc::stream<std::ios>);

    static_assert(hlc::output_stream<Test, int>);
    static_assert(hlc::output_stream<Test, std::string>);
    static_assert(hlc::output_stream<std::ostream, int>);

    static_assert(hlc::input_stream<std::istream, int>);
    static_assert(hlc::input_stream<std::istream, std::string>);
    static_assert(hlc::input_stream<std::istream, int>);

    static_assert(hlc::vector<std::vector<int>>);

    static_assert(hlc::container<std::vector<int>>);
    static_assert(hlc::container<std::map<int, int>>);

    return 0;
}
