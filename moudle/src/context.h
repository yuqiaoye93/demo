#pragma once

#include <memory>

#include "libfoo/src/foo.h"
#include "src/common/data.h"
// #include <memory>

class Context {
 public:
  Context() = default;
  ~Context() = default;
  std::shared_ptr<foo::Foo<int>> foo;
};