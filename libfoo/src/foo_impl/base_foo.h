#pragma once

#include <string>
#include <unordered_map>

#include "src/common/define.h"

namespace foo {

template <typename T, typename T_ptr = std::shared_ptr<T>>
class BaseFoo {
 public:
  BaseFoo() = default;
  ~BaseFoo() = default;

  virtual bool exec(std::unordered_map<std::string, T_ptr> input) {
    return true;
  }
  virtual bool prepare(std::unordered_map<std::string, T_ptr> input) {
    return true;
  }

  std::string class_name{};
};

}  // namespace foo
