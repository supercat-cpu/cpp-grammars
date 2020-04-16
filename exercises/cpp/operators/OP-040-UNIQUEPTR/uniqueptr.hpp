#ifndef uniqueptr_hpp
#define uniqueptr_hpp

class IntUniquePtr {
    int *ptr;
public:
    IntUniquePtr();
    IntUniquePtr(int *p);
    IntUniquePtr(IntUniquePtr &p);
    ~IntUniquePtr();
    int& operator * () const;
    int* getraw()  const;
    int* operator -> ();
};

#endif
