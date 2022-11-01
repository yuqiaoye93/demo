#pragma once

#include <cstdio>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "src/common/define.h"
#include "src/foo_impl/apple_foo.h"
#include "src/foo_impl/banana_foo.h"
#include "src/foo_impl/base_foo.h"

namespace foo {

template <typename T, typename T_ptr = std::shared_ptr<T>>
class Foo {
  using Ptr = T_ptr;

 public:
  Foo(std::vector<std::string> class_list) : _class_list(class_list){};
  ~Foo() = default;

  bool foo(std::unordered_map<std::string, T_ptr> input) {
    for (auto& class_name : _class_list) {
      auto foo_ptr = get_foo(class_name);
      foo_ptr->exec(input);
    }
    return true;
  };

  std::shared_ptr<BaseFoo<T>> get_foo(std::string foo_name) {
    if (foo_umap.find(foo_name) == foo_umap.end()) {
      DynamicFactory<BaseFoo<T>, Foo<T>> woker;
      auto ptr = woker.DynamicCreate(foo_name);
      foo_umap[foo_name] = ptr;
    }
    return foo_umap[foo_name];
  };

  std::unordered_map<std::string, std::shared_ptr<BaseFoo<T>>> foo_umap;

  // ["foo::AppleFoo", "foo::BananaFoo"]
  std::vector<std::string> _class_list;
};

}  // namespace foo
