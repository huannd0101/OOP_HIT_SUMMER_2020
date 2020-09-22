#include<bits\stdc++.h>
using namespace std;

class NSX{
private:
    char tenNSX[30];
    char diaChi[30];
public:
    void Nhap(){
        cout << "Nhap ten NSX: ";
        gets(tenNSX);
        cout << "Nhap dia chi SX: ";
        gets(diaChi);
    }

    void Xuat(){
        cout << setw(20) << tenNSX;
        cout << setw(20) << diaChi;
    }
};

class Date{
private:
    int D, M, Y;
public:
    void Nhap(){
        cout << "Nhap ngay: ";
        cin >> D;
        cout << "Nhap thang: ";
        cin >> M;
        cout << "Nhap nam: ";
        cin >> Y;
    }

    void Xuat(){
        cout << setw(2) << D << "/" << setw(2) << M << "/" << setw(9) << Y;
    }
};


class Hang{
protected:
    char tenHang[30];
    NSX x;
    float donGia;
public:
    void Nhap(){
        cout << "Nhap ten hang: ";
        gets(tenHang);
        x.Nhap();
        cout << "Nhap don gia: ";
        cin >> donGia;
        cin.ignore();
    }

    void Xuat(){
        cout << setw(20) << left << tenHang;
        x.Xuat();
        cout << setw(15) << donGia;
    }
};

class Tivi: public Hang{
private:
    float kichThuoc;
    Date ngayNhap;
public:
    void Nhap(){
        Hang::Nhap();
        cout << "Nhap kich thuoc: ";
        cin >> kichThuoc;
        ngayNhap.Nhap();
    }

    void Xuat(){
        Hang::Xuat();
        cout << setw(15) << kichThuoc;
        ngayNhap.Xuat();
    }
};

void Title(){
    cout << setw(20) << left << "Ten hang";
    cout << setw(20) << "Ten NSX";
    cout << setw(20) << "Dia chi SX";
    cout << setw(15) << "Don gia";
    cout << setw(15) << "Kich thuoc";
    cout << setw(15) << "Ngay SX" << endl;
}

int main(){
    Tivi a;
    a.Nhap();
    Title();
    a.Xuat();
    return 0;
}