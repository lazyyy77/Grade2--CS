#include <iostream>
#include <vector>
#include "Vector.h"


template<class T>
Vector<T>::Vector(){
    m_nSize=0;
    m_nCapacity=0;
    m_pElements = new T;
}

template<class T>
Vector<T>::Vector(int size){
    m_pElements = new T[size];
    m_nSize=size;
    m_nCapacity=size;
}

template<class T>
Vector<T>::Vector(const Vector& r){
    if(m_nCapacity)  this->~Vector();
    m_nSize=r.m_nSize;
    m_nCapacity=r.m_nCapacity;
    if(m_nCapacity==0)
        return;
    m_pElements = new T[m_nCapacity];
    for(int i=0;i<m_nCapacity;i++)
        m_pElements[i]=r.m_pElements[i];
}

template<class T>
Vector<T>::~Vector(){
    std::cout << "myVector::before dtor -";
    delete [] m_pElements;
    std::cout << "- myVector::after dtor\n";
    return;
}

template<class T>
void Vector<T>::inflate(){
    if(m_nCapacity==0)  m_nCapacity=1;
    else    m_nCapacity*=2;
    T* new_m_pElements;
    new_m_pElements = new T[m_nCapacity];
    for(int i=0;i<m_nCapacity;i++)
        new_m_pElements[i]=m_pElements[i];
    delete[] m_pElements;
    m_pElements=new_m_pElements;
}

template<class T>
void Vector<T>::push_back(const T& x){
    //std::cout << "in pb: " << m_nSize << " " << m_nCapacity << std::endl;
    if(m_nSize==m_nCapacity){
        inflate();
    }
    m_pElements[m_nSize]=x;
    m_nSize++;
}

template<class T>
T& Vector<T>::at(int index){
    if(m_nCapacity<=index){
        std::cout << "terminate called after throwing an instance of 'myVector::out_of_range'\n";
        std::cout << "what():  Vector::_M_range_check: __n (which is " << index << ") >= this->capacity() (which is " << m_nCapacity << ")";
        exit(0);
    }
    T& x = m_pElements[index];
    return x;
}

void Test_Ctor();
void Test_Ctor_N();
void Test_Copy_Ctor();
void Test_Dtor();
void Test_Op();
void Test_At();
void Test_Size();
void Test_Pushback();
void Test_Clear();
void Test_Empty();

int main(){
    // int x = 0;
    // Vector<int> a;
    // while(x!=-1){
    //     std::cin >> x;
    //     a.push_back(x);
    //     std::cout << "myVector-- size = " << a.size() << "; capacity = " << a.capacity() << "; address = " << &a <<  std::endl;
    // }


     int flag = 1, choice;
    std::cout << "Here is to test the functions of Vector with std::vector.\n";
    std::cout << "You can input different number to test different function:\n";
    std::cout << "1: ctor.\n2: ctor takes n integers.\n3: copy ctor.\n4: dtor.\n";
    std::cout << "5: op[].\n6: at().\n7: size().\n8: push_back(x).\n";
    std::cout << "9: clear().\n10: empty().\n-1: exit the programm.\n";

    while(flag){
        std::cout << "Please choose the function you want to test\n";
        std::cin >> choice;
        switch(choice){
            case 1: Test_Ctor(); break;
            case 2: Test_Ctor_N(); break;
            case 3: Test_Copy_Ctor(); break;
            case 4: Test_Dtor(); break;
            case 5: Test_Op(); break;
            case 6: Test_At(); break;
            case 7: Test_Size(); break;
            case 8: Test_Pushback(); break;
            case 9: Test_Clear(); break;
            case 10: Test_Empty(); break;
            case -1: flag = 0; break;
            default: std::cout <<"please input the legal number.\n"; break;
        }
        std::cout << "-------------------------------" << std::endl;
    }

    return 0;
}

void Test_Ctor(){

    std::cout << "-----------------------------------\n";
    std::cout << "Here is to test Ctor.\n" << "By output the size.\n";
    Vector<int> a;
    std::vector<int> b;
    std::cout << "myVector-- size = " << a.size() << "; capacity = " << a.capacity() << std::endl;
    std::cout << "std::vector-- size = " << b.size() << "; capacity = " << b.capacity() << std::endl;  

}

void Test_Ctor_N(){

    std::cout << "-----------------------------------\n";
    std::cout << "Here is to test Ctor with N integers.\n" << "By output the size and capacity.\n";
    std::cout << "Please in put N:\n";
    int n;
    std::cin >> n;
    Vector<int> a(n);
    std::vector<int> b(n);
    std::cout << "N = " << n << std::endl;
    std::cout << "myVector-- size = " << a.size() << "; capacity = " << a.capacity() << std::endl;
    std::cout << "std::vector-- size = " << b.size() << "; capacity = " << b.capacity() << std::endl; 

}

void Test_Copy_Ctor(){

    std::cout << "-----------------------------------\n";
    std::cout << "Here is to test Copy Ctor.\n" << "By output the size, capacity and address.\n";
    std::cout << "Please note that std::vector use light copy while myVector use deep copy.\n";
    Vector<double> a(5);
    Vector<double> c(a);
    std::vector<double> b(5);
    std::vector<double> d(b);
    std::cout << "myVector-- a.size = " << a.size() << "; a.capacity = " << a.capacity() << "; address = " << &a <<  std::endl;
    std::cout << "myVector-- c.size = " << c.size() << "; c.capacity = " << c.capacity() << "; address = " << &c <<  std::endl;    
    std::cout << "std::vector-- b.size = " << b.size() << "; b.capacity = " << b.capacity() << "; address = " << &b <<  std::endl;
    std::cout << "std::vector-- d.size = " << d.size() << "; d.capacity = " << d.capacity() << "; address = " << &d <<  std::endl;

}

void Test_Dtor(){
    
    std::cout << "-----------------------------------\n";
    std::cout << "Here is to test Dtor.\n" << "By calling the dtor.\n";
    
    {Vector<char> a(5);}
    {std::vector<char> b(5);}

}

void Test_Op(){

    std::cout << "-----------------------------------\n";
    std::cout << "Here is to test OP[].\n" << "By output the assignment.\n";
    std::cout << "Please input the initial size N, a index X, and a assigning number Y.\n";
    std::cout << "(When testing, it's recommended to first input N > X, and then N <= X.\n";
    std::cout << "(When testing N <= X, the program will crush. it's right.)\n";
    int N, X, Y, Z1, Z2;
    std::cin >> N >> X >> Y;
    Vector<int> a(N);
    std::vector<int> b(N);
    a[X]=Y; Z1=a[X];
    b[X]=Y; Z2=b[X];
    std::cout << "Here make the assignment: vector[X]=Y; Z=vector[X]. Then output Z.\n";
    std::cout << "myVector-- Z = " << Z1 <<  std::endl;
    std::cout << "std::vector-- Z = " << Z2 <<  std::endl;

}

void Test_At(){
    
    std::cout << "-----------------------------------\n";
    std::cout << "Here is to test at.\n" << "By output the assignment.\n";
    std::cout << "Please input the initial size N, a index X, and a assigning number Y.\n";
    std::cout << "Here make the assignment: vector[X]=Y; Z=vector[X]. Then output Z.\n";
    std::cout << "(When testing, it's recommended to first input N > X, and then N <= X.)\n";
    std::cout << "(When testing N<=X, both myVector and std::vector will check the bound\n";
    std::cout << " and shut the program due to the illgal input. So only one alert will be called.\n";
    std::cout << " if Y is even, we called myVector. if Y is odd, we called std::vector.)\n";
    int N, X, Y, Z1, Z2;
    std::cin >> N >> X >> Y;
    Vector<int> a(N);
    std::vector<int> b(N);
    if(Y%2){
        a.at(X)=Y; Z1=a.at(X);
        b.at(X)=Y; Z2=b.at(X);
    }else{
        b.at(X)=Y; Z2=b.at(X);
        a.at(X)=Y; Z1=a.at(X);
    }
    a.push_back(Y);
    a.at(N);
    std::cout << "myVector-- Z = " << Z1 <<  std::endl;
    std::cout << "std::vector-- Z = " << Z2 <<  std::endl;
}

void Test_Size(){
    
    std::cout << "-----------------------------------\n";
    std::cout << "Here is to test size.\n" << "By output the size.\n";
    std::cout << "Please input the initial size N.\n";
    std::cout << "Actually this has already been tested in ctor and ctor with N integers.\n";
    std::cout << "What's more, you can find more about the increase and address of the size in test_push_back.\n";
    int N;
    std::cin >> N;
    Vector<int> a(N);
    std::vector<int> b(N);

    std::cout << "myVector-- size = " << a.size() << "; capacity = " << a.capacity() << std::endl;
    std::cout << "std::vector-- size = " << b.size() << "; capacity = " << b.capacity() << std::endl; 

}

void Test_Pushback(){

    std::cout << "-----------------------------------\n";
    std::cout << "Here is to test push_back.\n" << "By output the size and capacity.\n";
    std::cout << "Please input the initial size N and the X you want to push_back.\n";
    std::cout << "The programm will continueously do 'push_back(X) and print the size and address.'\n";
    std::cout << "when input X == -1, the push_back program quit and will print from vector[initial_size] to vector[temp_size].\n";
    int N, X=0;
    std::cin >> N;
    Vector<int> a(N);
    std::vector<int> b(N);
    std::cout << "myVector-- size = " << a.size() << "; capacity = " << a.capacity() << "; address = " << &a <<  std::endl;
    std::cout << "std::vector-- size = " << b.size() << "; capacity = " << b.capacity() << "; address = " << &b <<  std::endl;
    while(X!=-1){
        std::cout << "please input the push_back X (input -1 to quit): " << std::endl;
        std::cin >> X;
        if(X==-1)break;
        a.push_back(X);
        b.push_back(X);
        std::cout << "myVector-- size = " << a.size() << "; capacity = " << a.capacity() << "; address = " << &a <<  std::endl;
        std::cout << "std::vector-- size = " << b.size() << "; capacity = " << b.capacity() << "; address = " << &b <<  std::endl;
    }
    std::cout << "myVector-- ";
    for(int i=N;i<a.size();i++)
        std::cout << a.at(i) << " ";
    std::cout << std::endl;
    std::cout << "std::vector-- ";
    for(int i=N;i<b.size();i++)
        std::cout << b.at(i) << " ";        
    std::cout << std::endl;

}

void Test_Clear(){
    
    std::cout << "-----------------------------------\n";
    std::cout << "Here is to test clear.\n" << "By output the size and capacity after clear.\n";
    std::cout << "The function will create a vector with simple ctor. Please input the X you want to push_back.\n";
    std::cout << "The function will continueously do 'push_back(X) and print the size and address.'\n";
    std::cout << "when input X == -1, the function will do clear and print the size and capacity.\n";
    int N, X=0;
    Vector<int> a;
    std::vector<int> b;
    while(X!=-1){
        std::cout << "please input the push_back X (input -1 to quit): " << std::endl;
        std::cin >> X;
        if(X==-1)break;
        a.push_back(X);
        b.push_back(X);
        std::cout << "myVector-- size = " << a.size() << "; capacity = " << a.capacity() << std::endl;
        std::cout << "std::vector-- size = " << b.size() << "; capacity = " << b.capacity() << std::endl; 
    }
    a.clear();
    b.clear();
    std::cout << "myVector-- after clear-- size = " << a.size() << "; capacity = " << a.capacity() << std::endl;
    std::cout << "std::vector-- after clear-- size = " << b.size() << "; capacity = " << b.capacity() << std::endl;

}

void Test_Empty(){

    std::cout << "-----------------------------------\n";
    std::cout << "Here is to test empty.\n" << "1 == isEmpty, 0 == isNotEmpty.\n";
    std::cout << "PART 1: start from simple ctor.\n";
    std::cout << "Please input the X you want to push_back.\n";
    std::cout << "The function will continueously do 'push_back(X) and print the size and address.'\n";
    std::cout << "when input X == -1, the function will call empty().\n";
    std::cout << "You can directly input X = -1 at the start to test the initial situation.\n";
    int N, X=0;
    Vector<int> a;
    std::vector<int> b;
    while(X!=-1){
        std::cout << "please input the push_back X (input -1 to quit): " << std::endl;
        std::cin >> X;
        if(X==-1)break;
        a.push_back(X);
        b.push_back(X);
    }
    std::cout << "myVector-- isEmpty = " << a.empty() << std::endl;
    std::cout << "std::vector-- isEmpty = " << b.empty() << std::endl;

    std::cout << "PART 2: start from ctor takes N integer.\n";
    std::cout << "Please input the initial size N and the X you want to push_back.\n";
    std::cout << "The function will continueously do 'push_back(X).'\n";
    std::cout << "when input X == -1, the function will call empty().\n";
    std::cout << "You can directly input X = -1 at the start to test the initial situation.\n";
    std::cout << "Please input N: \n";
    std::cin >> N;
    Vector<int> c(N);
    std::vector<int> d(N);
    X=0;
    while(X!=-1){
        std::cout << "please input the push_back X (input -1 to quit): " << std::endl;
        std::cin >> X;
        c.push_back(X);
        d.push_back(X);
    }
    std::cout << "myVector-- isEmpty = " << c.empty() << std::endl;
    std::cout << "std::vector-- isEmpty = " << d.empty() << std::endl;
}