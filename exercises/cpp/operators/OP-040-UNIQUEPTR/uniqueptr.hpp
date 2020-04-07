#ifndef uniqueptr_hpp
#define uniqueptr_hpp

class IntUniquePtr {
    int *ptr;
public:
    IntUniquePtr();
    IntUniquePtr(int *p);
    IntUniquePtr(IntUniquePtr &p);
    ~IntUniquePtr();
    int &operator * () const;
    bool operator < (IntUniquePtr p) const;
    bool operator > (IntUniquePtr p) const;
    bool operator <= (IntUniquePtr p) const;
    bool operator >= (IntUniquePtr p) const;
    bool operator == (IntUniquePtr p) const;
    bool operator != (IntUniquePtr p) const;
    int * getraw()  const;
};

#endif
