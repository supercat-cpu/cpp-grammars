//
//  uniqueptr.hpp
//  
//
//  Created by Екатерина Евдокимова on 05.03.20.
//

#ifndef uniqueptr_hpp
#define uniqueptr_hpp

#include <stdio.h>

class IntUniquePtr {
    int *ptr;
public:
    IntUniquePtr(): ptr(nullptr) {}
    IntUniquePtr(int *p);
    IntUniquePtr(IntUniquePtr &p);
    ~IntUniquePtr();
    int operator * ();
    bool operator < (IntUniquePtr p);
    bool operator > (IntUniquePtr p);
    bool operator <= (IntUniquePtr p);
    bool operator >= (IntUniquePtr p);
    bool operator == (IntUniquePtr p);
    bool operator != (IntUniquePtr p);
    int * getraw () {
        return ptr;
    }
};

#endif /* uniqueptr_hpp */
