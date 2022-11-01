# pragma once

#include "src/common/define.h"

#include <unordered_map>
#include <string>

namespace foo{

template <typename T, typename T_ptr = std::shared_ptr<T>>
class BaseFoo {
public:
    BaseFoo() = default;
    ~BaseFoo() = default;

    virtual bool exec(std::unorderd_map<std::string id, T_ptr> input) { return true};

    virtual bool prepare(std::unorderd_map<std::string id, T_ptr> input) { return true};

    std::string class_name = "BaseFoo";

};

}
