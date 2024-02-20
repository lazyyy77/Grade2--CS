#ifndef __FRACTION_H__
#define __FRACTION_H__

using namespace std;

/*the Fraction class
*/
class Fraction{
private:
    int numerator, denominator;

public:
    Fraction();                     //default ctor
    Fraction(int x, int y);         //ctor takes 2 integers
    Fraction(const Fraction &obj);  //copy ctor
    ~Fraction();                    //dtor

    //overload the operator '+'
    Fraction operator+(const Fraction &add) const{
        int x=numerator*add.denominator+denominator*add.numerator;
        int y=denominator*add.denominator;
        Fraction ans(x, y);
        ans.SimplifyFraction();
        return ans;
    }

    //overload the operator '-'
    Fraction operator-(const Fraction &minus) const{
        int x=numerator*minus.denominator-denominator*minus.numerator;
        int y=denominator*minus.denominator;
        Fraction ans(x, y);
        ans.SimplifyFraction();
        return ans;
    }

    //overload the operator '*'
    Fraction operator*(const Fraction &multiply) const{
        Fraction ans(numerator*multiply.numerator, denominator*multiply.denominator);
        ans.SimplifyFraction();
        return ans;
    }

    //overload the operator '/'
    Fraction operator/(const Fraction &divide) const{
        Fraction ans(numerator*divide.denominator, denominator*divide.numerator);
        ans.SimplifyFraction();
        return ans;
    }

    //overload the operator '<'
    bool operator<(const Fraction &cmp_l) const{
        int temp1=numerator, temp2=cmp_l.numerator;
        if(denominator<0)   temp1*=(-1);
        if(cmp_l.denominator<0) temp2*=(-1);
        if(temp1<=0&&temp2>=0)  return true;
        return (temp1*abs(cmp_l.denominator) < temp2*abs(denominator));
    }

    //overload the operator '>'
    bool operator>(const Fraction &cmp_g) const{
        int temp1=numerator, temp2=cmp_g.numerator;
        if(denominator<0)   temp1*=(-1);
        if(cmp_g.denominator<0) temp2*=(-1);
        if(temp1>=0&&temp2<=0)  return true;
        return (temp1*abs(cmp_g.denominator) > temp2*abs(denominator));
    }

    //overload the operator '=='
    bool operator==(const Fraction &cmp_e) const{
        return (numerator*cmp_e.denominator == denominator*cmp_e.numerator);
    }

    //overload the operator '!=' by inverse the '=='
    bool operator!=(const Fraction &cmp_ne) const{
        return !(*this == cmp_ne);
    }

    //overload the operator '<=' by inverse the '>'
    bool operator<=(const Fraction &cmp_le) const{
        return !(*this > cmp_le);
    }

    //overload the operator '>=' by inverse the '<'
    bool operator>=(const Fraction &cmp_ge) const{
        return !(*this < cmp_ge);
    }
    
    int  GCD();             //find the gcd of numerator and denominator
    void PrintFraction1();  //only print the fraction in a/b
    void PrintFraction2();  //print a/b and the address in a line
    void SimplifyFraction();//simplify the fraction and standarlize the plus-minus
    void ConversionString(string a);    //convert a finite string to a fraction
    double TypecastDouble();            //typecast a fraction to double
    string TypecastString();            //typecast a fraction to string
    friend std::ostream& operator<<(std::ostream& oss, const Fraction& obj);
    friend std::istream& operator>>(std::istream& iss, Fraction& obj);

};


#endif