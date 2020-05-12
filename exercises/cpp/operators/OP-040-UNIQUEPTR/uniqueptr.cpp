#include "uniqueptr.hpp"
#include <iostream>

IntUniquePtr :: IntUniquePtr(): ptr(nullptr) {}

IntUniquePtr :: IntUniquePtr(int *p): ptr(p) {}

IntUniquePtr :: IntUniquePtr(IntUniquePtr &p) {
    ptr = p.ptr;
    p.ptr = nullptr;
}

IntUniquePtr :: ~IntUniquePtr() {
    if (ptr != nullptr) {
        delete ptr;
    }
}

int &IntUniquePtr :: operator * () const {
    return *ptr;
}
int *IntUniquePtr :: getraw ()  const {
    return ptr;
}