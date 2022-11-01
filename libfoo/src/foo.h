#pragma once

#include "src/foo_impl/base_foo.h"
#include "src/foo_impl/apple_foo.h"
#include "src/foo_impl/banana_foo.h"
#include "src/common/define.h"

#include <cstdio>
#include <vector>
#include <unordered_map>
#include <string>

namespace foo {

class Foo {
public:
    Foo(std::vector<std::string> class_list):_class_list(class_list) {};
    ~Foo() = default;

    bool foo(std::unorderd_map<std::string id, T_ptr> input);

    std::shared_ptr<BaseFoo> get_foo(std::string foo_name);

    std::unorderd_map<std::string, std::shared_ptr<BaseFoo>> foo_umap;

    // ["foo::AppleFoo", "foo::BananaFoo"]
    std::vector<std::string> _class_list;
};

}


