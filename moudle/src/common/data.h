#pragma once

#include <string>
#include <shared_ptr>

#ifdef DOG_SERVICE
#include "src/common/dog.h"
#define DATA DogData

#elif CAT_SERVICE
#include "src/common/cat.h"
#define DATA CatData
#endif

#ifndef DATA
#define DATA bool
#endif

namespace moudle {

    struct Data {
        DATA data;
        std::string id;
        std::string name;
    };

    typedef std::shared_ptr<Data> DataPtr;

}