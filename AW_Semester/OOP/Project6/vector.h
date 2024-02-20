#ifndef __Vector_H__
#define __Vector_H__

template <class T>
class Vector{
private:
    T *m_pElements;
    int m_nSize;
    int m_nCapacity;
    void inflate();

public:
    Vector();
    Vector(int size);
    Vector(const Vector& r);
    T& operator[](int index){                       // accesses the specified element without bounds checking
        T& x = *(m_pElements+index);
        return x;
    }
    T& at(int index);                               // accesses the specified element, throws an exception of
                                                    // type 'std::out_of_range' when index <0 or >=m_nSize
    int size() const{   return m_nSize; }           // return the size of the container
    int capacity() const{   return m_nCapacity; }   // return the capacity of the container
    void clear(){   m_nSize=0;  };                  // clears the contents
    bool empty() const{   return m_nSize==0;    };  // checks whether the container is empty
    ~Vector();

    void push_back(const T& x);

};

#endif