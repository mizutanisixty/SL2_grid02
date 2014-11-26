#ifndef __includer_std__
#define __includer_std__

#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

#define errorMessage(file, func) cui << "fatal exception occured at \"" << (func) << " in " << (file) << "\"\n"

#define void_to_ref(type, source, dest) type &dest = *(type*)source;
//if(!_target) -> return FAIL
#define vtor(type, target) if(!##_##target)return RETURN_FAILED;type &target = *(type*)##_##target

#define ma(type, size) (type*)malloc(sizeof(type)*(size))

#endif
