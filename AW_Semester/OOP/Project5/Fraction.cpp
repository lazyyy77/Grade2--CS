#include <iostream>
#include <string>
#include <cmath>
#include "Fraction.h"

using namespace std;

//default ctor
Fraction::Fraction(){
    cout << "call ctor" << endl;
    numerator=0;
    denominator=1;
}

//ctor takes 2 integer
Fraction::Fraction(int x, int y){
    cout << "call ctor takes 2 integers" << endl;
    numerator=x;
    denominator=y;
    return;
}

//copy ctor
Fraction::Fraction(const Fraction &obj){
    cout << "call copy ctor" << endl;    
    if(this==&obj){
        cout << "can't copy to itself" << endl;
        return;
    }
    numerator=obj.numerator;
    denominator=obj.denominator;
    return;
}

//dtor
Fraction::~Fraction(){
    return;
}

//return the gcd of the numerator and denominator
int  Fraction::GCD(){
    int x=numerator, y=denominator, z;
    z=x%y;
    while(z){
        x=y;
        y=z;
        z=x%y;
    }
    return y;
}

//print the fraction in the form: numerator/denominator
void Fraction::PrintFraction1(){
    cout << numerator << "/" << denominator;
}

//print the fraction in the form above and print the address in a line
void Fraction::PrintFraction2(){
    cout << numerator << "/" << denominator << " address " << this << endl;
}

//reduct the fraction, and standarlize the position of the plus-minus 
void Fraction::SimplifyFraction(){
    int gcd=this->GCD();
    // cout << gcd << endl;
    numerator/=gcd;
    denominator/=gcd;
    if(denominator<0){
        numerator*=(-1);
        denominator*=(-1);
    }
    return;
}

//convert the input string a to a fraction
void Fraction::ConversionString(string a){
    int length=a.size(), i=0, flag=1;
    numerator=0;
    denominator=1;
    if(a.at(0)=='-'){
        flag=(-1);
        i++;
    }
    while(a.at(i)!='.'&&i<length){
        numerator=numerator*10+a.at(i)-'0';
        i++;
    }
    while(++i<length){
        numerator=numerator*10+a.at(i)-'0';
        denominator*=10;
    }
    cout << numerator << " " << denominator << endl;
    numerator*=flag;
    this->SimplifyFraction();
    return;
}

//typecast a fraction to a double
double Fraction::TypecastDouble(){
    double a=1;
    return (a*numerator)/(a*denominator);
}

//typecast a fraction to a string
string Fraction::TypecastString(){
    double a=1;
    return to_string((a*numerator)/(a*denominator));
}

//overload << extracter to invert fraction to stream
std::ostream& operator<<(std::ostream& oss, const Fraction& obj){
    oss << obj.numerator << "/" << obj.denominator;
    return oss;
}

//overload >> inverter to extract fraction from stream
std::istream& operator>>(std::istream& iss, Fraction& obj){
    char slash;
    iss >> obj.numerator >> slash >> obj.denominator;
    return iss;
}