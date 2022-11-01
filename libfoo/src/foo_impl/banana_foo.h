#pragma once

#include <string>
#include <unordered_map>

#include "src/common/define.h"
#include "src/foo_impl/base_foo.h"
#include "src/foo_impl/dynamic_factory.h"
namespace foo {

template <typename T, typename T_ptr = std::shared_ptr<T>>
class BananaFoo : public BaseFoo<T>,
                  public DynamicFactory<BaseFoo<T>, BananaFoo<T>> {
 public:
  bool exec(std::unordered_map<std::string, T_ptr> input) {
    prepare(input);
    return true;
  };

  bool prepare(std::unordered_map<std::string, T_ptr> input) { return true; }

  BananaFoo() { BaseFoo<T>::class_name = "banana_foo"; }
  //   ~BaseFoo() = default;
};

}  // namespace foo