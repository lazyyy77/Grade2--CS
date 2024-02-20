#include <iostream>
#include <string>
#include "Fraction.h"
using namespace std;

void Test_Ctor();
void Test_Ctor_INT();
void Test_Copy_Ctor();
void Test_OP_Plus();
void Test_OP_Minus();
void Test_OP_Multiply();
void Test_OP_Divide();
void Test_OP_Cmp_l();
void Test_OP_Cmp_g();
void Test_OP_Cmp_e();
void Test_OP_Cmp_ne();
void Test_OP_Cmp_le();
void Test_OP_Cmp_ge();
void Test_Tc_Double();
void Test_Tc_String();
void Test_Inserter_Extractor();
void Test_Conversion_String();

int main(){

    // Test_Ctor();
    // Test_Ctor_INT();
    // Test_Copy_Ctor();

    // Test_OP_Plus();
    // Test_OP_Minus();
    // Test_OP_Multiply();
    // Test_OP_Divide();

    // Test_OP_Cmp_l();
    // Test_OP_Cmp_le();
    // Test_OP_Cmp_g();
    // Test_OP_Cmp_ge();
    // Test_OP_Cmp_e();
    // Test_OP_Cmp_ne();

    // Test_Tc_Double();
    // Test_Tc_String();

    // Test_Inserter_Extractor();

    // Test_Conversion_String();

    int choice, flag=1;
    cout << "Here is to test the fraction class's function." << endl;
    cout << "You can input the number to test the corresponding function:" << endl;
    cout << "1. Default Ctor" << endl << "2. Ctor_2_INT" << endl << "3. Copy Ctor" << endl;
    cout << "4. Overload +" << endl << "5. Overload -" << endl << "6. Overload *" << endl << "7. Overload /" << endl;
    cout << "8. Overload <" << endl << "9. Overload >" << endl << "10. Overload ==" << endl;
    cout << "11. Overload !=" << endl << "12. Overload <=" << endl << "13. Overload >=" << endl;
    cout << "14. Typecast double" << endl << "15. Typecast string" << endl;
    cout << "16. Overload << & >>" << endl << "17. Convert from string" << endl;
    cout << "-1. EXIT" << endl;
    while(flag){
        cout << "Please input your choice:" << endl;
        cin >> choice;
        switch(choice){
            case 1: Test_Ctor();break;
            case 2: Test_Ctor_INT();break;
            case 3: Test_Copy_Ctor();break;
            case 4: Test_OP_Plus();break;
            case 5: Test_OP_Minus();break;
            case 6: Test_OP_Multiply();break;
            case 7: Test_OP_Divide();break;
            case 8: Test_OP_Cmp_l();break;
            case 9: Test_OP_Cmp_g();break;
            case 10: Test_OP_Cmp_e();break;
            case 11: Test_OP_Cmp_ne();break;
            case 12: Test_OP_Cmp_le();break;
            case 13: Test_OP_Cmp_ge();break;
            case 14: Test_Tc_Double();break;
            case 15: Test_Tc_String();break;
            case 16: Test_Inserter_Extractor();break;
            case 17: Test_Conversion_String();break;
            case -1: flag=0;break;
            default: cout << "illegal input!" << endl;break;
        }
    }
    

    return 0;
}

void Test_Ctor(){
    cout << "-------------------------------" << endl;
    cout << "----HERE IS TO TEST:  Ctor ----" << endl;
    Fraction a;
    a.PrintFraction2();
    return;
}

void Test_Ctor_INT(){
    cout << "-------------------------------" << endl;
    cout << "----HERE IS TO TEST:  Ctor takes 2 integers----" << endl;
    int x, y;
    cout << "please input the numerator and the denominator:" << endl;
    cin >> x >> y;
    Fraction a(x, y);
    a.PrintFraction2();
}

void Test_Copy_Ctor(){

    cout << "-------------------------------" << endl;
    cout << "----HERE IS TO TEST:  Copy Ctor----" << endl;
    int x, y;
    cout << "please input the numerator and the denominator of the base fraction:" << endl;
    cin >> x >> y;
    Fraction a(x, y);
    Fraction b(a);
    b.PrintFraction2();
    Fraction c=a;
    c.PrintFraction2();
    Fraction d(d);
}

void Test_OP_Plus(){

    cout << "-------------------------------" << endl;
    cout << "----HERE IS TO TEST:  OP '+' ----" << endl;
    int x1, y1, x2, y2;
    cout << "please input the numerator and the denominator of fraction 1:" << endl;
    cin >> x1 >> y1;
    cout << "please input the numerator and the denominator of fraction 2:" << endl;
    cin >> x2 >> y2;
    Fraction a(x1, y1);
    Fraction b(x2, y2);
    Fraction c = a + b;
    c.PrintFraction2();
    return;
}

void Test_OP_Minus(){

    cout << "-------------------------------" << endl;
    cout << "----HERE IS TO TEST:  OP '-' ----" << endl;
    int x1, y1, x2, y2;
    cout << "please input the numerator and the denominator of fraction 1:" << endl;
    cin >> x1 >> y1;
    cout << "please input the numerator and the denominator of fraction 2:" << endl;
    cin >> x2 >> y2;
    Fraction a(x1, y1);
    Fraction b(x2, y2);
    Fraction c = a - b;
    c.PrintFraction2();
    return;
}

void Test_OP_Multiply(){
    
    cout << "-------------------------------" << endl;
    cout << "----HERE IS TO TEST:  OP '*' ----" << endl;
    int x1, y1, x2, y2;
    cout << "please input the numerator and the denominator of fraction 1:" << endl;
    cin >> x1 >> y1;
    cout << "please input the numerator and the denominator of fraction 2:" << endl;
    cin >> x2 >> y2;
    Fraction a(x1, y1);
    Fraction b(x2, y2);
    Fraction c = a * b;
    c.PrintFraction2();
    return;
}

void Test_OP_Divide(){
    
    cout << "-------------------------------" << endl;
    cout << "----HERE IS TO TEST:  OP '/' ----" << endl;
    int x1, y1, x2, y2;
    cout << "please input the numerator and the denominator of fraction 1:" << endl;
    cin >> x1 >> y1;
    cout << "please input the numerator and the denominator of fraction 2:" << endl;
    cin >> x2 >> y2;
    Fraction a(x1, y1);
    Fraction b(x2, y2);
    Fraction c = a / b;
    c.PrintFraction2();
    return;
}

void Test_OP_Cmp_l(){
    
    cout << "-------------------------------" << endl;
    cout << "----HERE IS TO TEST:  OP '<' ----" << endl;
    int x1, y1, x2, y2;
    cout << "please input the numerator and the denominator of fraction 1:" << endl;
    cin >> x1 >> y1;
    cout << "please input the numerator and the denominator of fraction 2:" << endl;
    cin >> x2 >> y2;
    Fraction a(x1, y1);
    Fraction b(x2, y2);
    a.PrintFraction1();
    cout << " < ";
    b.PrintFraction1();
    cout << " is " << (a<b) << endl;

}

void Test_OP_Cmp_g(){

    cout << "-------------------------------" << endl;
    cout << "----HERE IS TO TEST:  OP '>' ----" << endl;
    int x1, y1, x2, y2;
    cout << "please input the numerator and the denominator of fraction 1:" << endl;
    cin >> x1 >> y1;
    cout << "please input the numerator and the denominator of fraction 2:" << endl;
    cin >> x2 >> y2;
    Fraction a(x1, y1);
    Fraction b(x2, y2);
    a.PrintFraction1();
    cout << " > ";
    b.PrintFraction1();
    cout << " is " << (a>b) << endl;
}

void Test_OP_Cmp_e(){
    cout << "-------------------------------" << endl;
    cout << "----HERE IS TO TEST:  OP '==' ----" << endl;
    int x1, y1, x2, y2;
    cout << "please input the numerator and the denominator of fraction 1:" << endl;
    cin >> x1 >> y1;
    cout << "please input the numerator and the denominator of fraction 2:" << endl;
    cin >> x2 >> y2;
    Fraction a(x1, y1);
    Fraction b(x2, y2);
    a.PrintFraction1();
    cout << " == ";
    b.PrintFraction1();
    cout << " is " << (a==b) << endl;    
}

void Test_OP_Cmp_ne(){
    cout << "-------------------------------" << endl;
    cout << "----HERE IS TO TEST:  OP '!=' ----" << endl;
    int x1, y1, x2, y2;
    cout << "please input the numerator and the denominator of fraction 1:" << endl;
    cin >> x1 >> y1;
    cout << "please input the numerator and the denominator of fraction 2:" << endl;
    cin >> x2 >> y2;
    Fraction a(x1, y1);
    Fraction b(x2, y2);
    a.PrintFraction1();
    cout << " != ";
    b.PrintFraction1();
    cout << " is " << (a!=b) << endl;
}

void Test_OP_Cmp_le(){
    cout << "-------------------------------" << endl;
    cout << "----HERE IS TO TEST:  OP '<=' ----" << endl;
    int x1, y1, x2, y2;
    cout << "please input the numerator and the denominator of fraction 1:" << endl;
    cin >> x1 >> y1;
    cout << "please input the numerator and the denominator of fraction 2:" << endl;
    cin >> x2 >> y2;
    Fraction a(x1, y1);
    Fraction b(x2, y2);
    a.PrintFraction1();
    cout << " <= ";
    b.PrintFraction1();
    cout << " is " << (a<=b) << endl;
}

void Test_OP_Cmp_ge(){
    cout << "-------------------------------" << endl;
    cout << "----HERE IS TO TEST:  OP '>=' ----" << endl;
    int x1, y1, x2, y2;
    cout << "please input the numerator and the denominator of fraction 1:" << endl;
    cin >> x1 >> y1;
    cout << "please input the numerator and the denominator of fraction 2:" << endl;
    cin >> x2 >> y2;
    Fraction a(x1, y1);
    Fraction b(x2, y2);
    a.PrintFraction1();
    cout << " >= ";
    b.PrintFraction1();
    cout << " is " << (a>=b) << endl;
}

void Test_Tc_Double(){
    cout << "-------------------------------" << endl;
    cout << "----HERE IS TO TEST:  Typecast 'double' ----" << endl;
    int x1, y1;
    cout << "please input the numerator and the denominator of fraction:" << endl;
    cin >> x1 >> y1;
    Fraction a(x1, y1);
    double ans=a.TypecastDouble();
    cout << ans << " " << sizeof(ans) << endl;
}

void Test_Tc_String(){
    cout << "-------------------------------" << endl;
    cout << "----HERE IS TO TEST:  Typecast 'string' ----" << endl;
    int x1, y1;
    cout << "please input the numerator and the denominator of fraction:" << endl;
    cin >> x1 >> y1;
    Fraction a(x1, y1);
    string ans=a.TypecastString();
    cout << ans << " " << sizeof(ans) << endl;
}

void Test_Inserter_Extractor(){
    cout << "-------------------------------" << endl;
    cout << "----HERE IS TO TEST: 'INSERTER&EXTRACTOR' ----" << endl;
    cout << "please input the fraction in the way numerator/denominator:" << endl;
    Fraction a;
    cin >> a;
    cout << a << endl;
}

void Test_Conversion_String(){
    cout << "-------------------------------" << endl;
    cout << "----HERE IS TO TEST: 'Conversion_String' ----" << endl;
    cout << "please input the string you want to convert:" << endl;
    Fraction a;
    string b;
    cin >> b;
    a.ConversionString(b);
    a.PrintFraction2();
}
