#include "src/foo.h"

namespace foo{

bool Foo::foo(std::unorderd_map<std::string id, T_ptr> input) {
    for (auto& class_name : _class_list) {
        auto foo_ptr = get_foo(class_name);
        foo_ptr->exec(input);
    }
    return true;
};

std::shared_ptr<BaseFoo> Foo::get_foo(std::string foo_name) {
    if (foo_umap.find(foo_name) == foo_map.end()) {
        DynamicWorker<BaseFoo> woker;
        auto ptr = woker.DynamicCreate(foo_name);
        foo_umap[foo_name] = ptr;
    }
    return foo_umap[foo_name];
};

}