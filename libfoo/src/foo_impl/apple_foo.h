#pragma once

#include <string>
#include <unordered_map>

#include "src/common/define.h"
#include "src/foo_impl/base_foo.h"
#include "src/foo_impl/dynamic_factory.h"
namespace foo {

template <typename T, typename T_ptr = std::shared_ptr<T>>
class AppleFoo : public BaseFoo<T>,
                 public DynamicFactory<BaseFoo<T>, AppleFoo<T>> {
 public:
  AppleFoo() { BaseFoo<T>::class_name = "apple_foo"; }
  ~AppleFoo() = default;

  virtual bool exec(std::unordered_map<std::string, T_ptr> input) override {
    return true;
  }

  virtual bool prepare(std::unordered_map<std::string, T_ptr> input) {
    return true;
  }
};

}  // namespace foo
