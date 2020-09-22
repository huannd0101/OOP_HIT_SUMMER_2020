#include<bits\stdc++.h>
using namespace std;

class PTB2{
    private: 
        float a, b, c;
    public:
        PTB2(){
            a = b = c = 0;
        }

        PTB2(float a, float b, float c){
            this->a = a;
            this->b = b;
            this->c = c;
        }

        ~PTB2(){
            a = b = c = 0;
        }

        void NHAP(){
            cout << "\nNhap he so a, b, c: ";
            cin >> a >> b >> c;
        }

        void XUAT(){
            cout << a << "x2 + " << b << "x + " << c << " = 0";
        }

        void GIAI(){
            float del = b * b - 4 * a * c;
            if(del < 0)
                cout << "\nPhuong trinh vo nghiem.";
            else if(del == 0)
                cout << "\nPhuong trinh co nghiem duy nhat: x = " << - b / (2 * a);
            else
                cout << "\nPhuong trinh co 2 nghiem phan biet: \nx1 = " << (-b + sqrt(del)) / (2 * a) << "\nx2 = " << (-b - sqrt(del)) / (2 * a);  
        }
};

int main(){
    PTB2 P(1, 2, 1), Q;
    P.XUAT();
    P.GIAI();
    Q.NHAP();
    Q.XUAT();
    Q.GIAI();
    return 0;
}