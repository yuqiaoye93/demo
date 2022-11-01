#include "src/foo_impl/banana_foo.h"

namespace foo {

    bool exec(std::unorderd_map<std::string id, T_ptr> input) {
        prepare(input);
        return true;
    };

    bool prepare(std::unorderd_map<std::string id, T_ptr> input) {
        return true;
    };

}