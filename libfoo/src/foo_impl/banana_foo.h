#pragma once 

#include "src/foo_impl/base_foo.h"
#include "src/common/define.h"

#include <unordered_map>
#include <string>

namespace foo {

class BananaFoo : public BaseFoo, Public DynamicFactory<BaseFoo, BananaFoo> {
public:
    BaseFoo() {
        class_name = "banana_foo"
    };
    ~BaseFoo() = default;

    virtual bool exec(std::unorderd_map<std::string id, T_ptr> input) override;

    virtual bool prepare(std::unorderd_map<std::string id, T_ptr> input) override;

};

}