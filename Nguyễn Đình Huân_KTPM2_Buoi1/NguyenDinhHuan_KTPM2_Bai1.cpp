#include<bits\stdc++.h>
using namespace std;
#define PI 3.14

class Hinhtron{
    private: 
        float r;
    public:
        Hinhtron(){
            this->r = 0;
        }

        ~Hinhtron(){
            this->r = 0;
        }

        Hinhtron(float r1){
            this->r = r1;
        }

        float ChuVi();
        float DienTich();
};

float Hinhtron::ChuVi(){
    return 2 * PI * r;
}

float Hinhtron::DienTich(){
    return r * r * PI;
}

int main(){
    Hinhtron a(3);
    cout << "Chu vi hinh tron la: " << a.ChuVi() << endl;
    cout << "Dien tich hinh tron la: " << a.DienTich();
    return 0;
}