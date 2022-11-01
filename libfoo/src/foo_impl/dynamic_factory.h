#pragma once
#include <memory>
#include <string>
namespace foo {

template <typename T, typename BASE>
class DynamicFactory {
 public:
  using base = BASE;
  using type = T;
  std::shared_ptr<BASE> DynamicCreate(std::string name) {
    return std::make_shared<type>();
  }
};
}  // namespace foo