#include "uniqueptr.hpp"


IntUniquePtr :: IntUniquePtr(int *p) {
    ptr = p;
}

IntUniquePtr :: IntUniquePtr(IntUniquePtr &p) {
    ptr = p.ptr;
    p.ptr = nullptr;
}

IntUniquePtr :: ~IntUniquePtr() {
    if (ptr != nullptr) {
        delete ptr;
    }
}

int &IntUniquePtr :: operator * () {
    return *ptr;
}
bool IntUniquePtr :: operator < (IntUniquePtr p) {
    return ptr < p.ptr;
}
bool IntUniquePtr :: operator > (IntUniquePtr p) {
    return ptr > p.ptr;
}
bool IntUniquePtr :: operator <= (IntUniquePtr p) {
    return !(*this > p);
}
bool IntUniquePtr :: operator >= (IntUniquePtr p) {
    return !(*this < p);
}
bool IntUniquePtr :: operator == (IntUniquePtr p) {
    return p.ptr == ptr;
}
bool IntUniquePtr :: operator != (IntUniquePtr p) {
    return !(p == *this);
}
