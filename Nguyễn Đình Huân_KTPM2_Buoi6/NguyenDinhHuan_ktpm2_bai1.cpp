#include<bits\stdc++.h>
using namespace std;

class TamThucBac2{
private:
    double a, b, c;
public:
    TamThucBac2();
    TamThucBac2(double a, double b, double c);
    friend istream &operator>>(istream &is, TamThucBac2 &x);
    friend ostream &operator<<(ostream &os, TamThucBac2 x);
    TamThucBac2 operator+(TamThucBac2 x){
        TamThucBac2 tmp;
        tmp.a = this->a + x.a;
        tmp.b = this->b + x.b;
        tmp.c = this->c + x.c;
        return tmp;
    }
    TamThucBac2 operator-(TamThucBac2 x){
        TamThucBac2 tmp;
        tmp.a = this->a - x.a;
        tmp.b = this->b - x.b;
        tmp.c = this->c - x.c;
        return tmp;
    }
    TamThucBac2 operator-(){
        TamThucBac2 tmp;
        tmp.a = -this->a;
        tmp.b = -this->b;
        tmp.c = -this->c;
        return tmp;
    }
};
TamThucBac2::TamThucBac2(){
    a = b = c = 0;
}
TamThucBac2::TamThucBac2(double a, double b, double c) {
    this->a = a;
    this->b = b;
    this->c = c;
}
istream &operator>>(istream &is, TamThucBac2 &x){
    cout << "\tNhap he so a, b, c: ";
    is >> x.a >> x.b >> x.c;
    return is;
}
ostream &operator<<(ostream &os, TamThucBac2 x){
    os << x.a << "x^2 + " << x.b << "x + " << x.c << endl;
    return os; 
}

int main(){
    TamThucBac2 a, b, c;
    cout << "Nhap tam thuc bac 2 a:" << endl;
    cin >> a;
    
    cout << "Nhap tam thuc bac 2 b:" << endl;
    cin >> b;

    cout << "\nDoi dau tam thuc a: ";
    a = -a;
    cout << a;

    cout << "\nDoi dau tam thuc b: ";
    b = -b;
    cout << b;

    cout << "\nTong cua 2 tam thuc a va b la: ";
    c = a + b;
    cout << c;

    cout << "\nHieu cua 2 tam thuc a va b la: ";
    c = a - b;
    cout << c;
    
    return 0;
}