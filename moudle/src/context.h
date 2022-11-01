#pragma once

#include "src/common/data.h"

#include "libfoo/src/foo.h"

#include <shared_ptr>



class Context {
public:
    Context() = default;
    ~Context() = default;
    std::shared_ptr<foo::Foo> foo;
}