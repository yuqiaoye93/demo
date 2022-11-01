#pragma once 

#include "src/foo_impl/base_foo.h"
#include "src/common/define.h"

#include <unordered_map>
#include <string>

namespace foo {

class AppleFoo : public BaseFoo, Public DynamicFactory<BaseFoo, AppleFoo> {
public:
    BaseFoo() {
        class_name = "apple_foo"
    };
    ~BaseFoo() = default;

    virtual bool exec(std::unorderd_map<std::string id, T_ptr> input) override;

    virtual bool prepare(std::unorderd_map<std::string id, T_ptr> input) override;

};

}
