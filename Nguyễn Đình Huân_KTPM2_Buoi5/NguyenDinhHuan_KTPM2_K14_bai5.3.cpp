#include<bits\stdc++.h>
using namespace std;

class VEHICLE {
protected:
    string nhanHieu;
    int namSx;
    string hang;
public:
    void Nhap(){
        cout << "Nhap nhan hieu: "; 
        getline(cin, nhanHieu);
        cout << "Nhap nam sx: ";
        cin >> namSx;
        cin.ignore();
        cout << "Nhap hang: "; 
        getline(cin, hang);
    }

    void Xuat(){
        cout << "\nNhan hieu: " << nhanHieu << "\nNam sx: " << namSx << "\nHang: " << hang << endl;
    }
};

class OTO: public VEHICLE {
private: 
    int soChoNgoi, dungTich;
public:
    void Nhap(){
        cout << "\nNhap so cho ngoi: "; 
        cin >> this->soChoNgoi;
        cout << "Nhap dung tich: "; 
        cin >> this->dungTich;
        cin.ignore();
        VEHICLE::Nhap();
    }

    void Xuat(){
        cout << "\nXe o to: \nSo cho: " << soChoNgoi << "\nDung tich: " << dungTich;
        VEHICLE::Xuat();
    }
};

class MOTO: public VEHICLE {
private:    
    int phanKhoi;
public:
    void Nhap(){
        cout << "\nNhap phan khoi: ";
        cin >> phanKhoi; cin.ignore();
        VEHICLE::Nhap();
    }

    void Xuat(){
        cout << "\nXe Mo to: \nPhan khoi: " << phanKhoi;
        VEHICLE::Xuat();
    }
};

int main(){
    OTO a;
    cout << "Nhap thong tin xe o to: ";
    a.Nhap();
    
    MOTO b;
    cout << "\nNhap thong tin xe mo to: ";
    b.Nhap();

    a.Xuat();
    b.Xuat();

    return 0;
}