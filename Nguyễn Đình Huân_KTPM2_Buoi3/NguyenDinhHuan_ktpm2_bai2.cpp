#include<bits\stdc++.h>
using namespace std;

int n;

class XeHoi;

class NhaSanXuat{
    private:
        string maNhaSx, tenNhaSx;
        char diaChiNhaSx[20];
        friend class XeHoi;
        friend void LocXeHoi_mauSon_DiaChi(XeHoi *a, int n);
};

class XeHoi{
    private:
        char nhanHieu[20];
        NhaSanXuat nhaSx;
        char mauSon[15], xuatXu[20];
        long giaBan;
    public:
        void Nhap();
        void Xuat();
        friend void LocXeHoi_hangXe(XeHoi *a, int n);
        friend void LocXeHoi_mauSon_DiaChi(XeHoi *a, int n);
};

void XeHoi::Nhap(){
    cout << "\nNhap nhan hieu: "; gets(nhanHieu);
    cout << "Nhap ma nha san xuat: "; getline(cin, nhaSx.maNhaSx);
    cout << "Nhap ten nha san xuat: "; getline(cin, nhaSx.tenNhaSx);
    cout << "Nhap dia chi nha san xuat: "; gets(nhaSx.diaChiNhaSx);
    cout << "Nhap mau son: "; gets(mauSon);
    cout << "Nhap xuat xu: "; gets(xuatXu);
    cout << "Nhap gia ban: "; cin >> giaBan; 
    cin.ignore();
}   

void XeHoi::Xuat(){
    cout << setw(20) << left << nhanHieu << setw(15) << nhaSx.maNhaSx << setw(15) << nhaSx.tenNhaSx << setw(20) << nhaSx.diaChiNhaSx << setw(15) << mauSon << setw(15) << xuatXu << setw(15) << giaBan << endl;
}

void tieuDe(){
    cout << setw(20) << left << "Nhan hieu" << setw(15) << "Ma hn Sx" << setw(15) << "Ten nha Sx" << setw(20) << "Dia chi nha Sx" << setw(15) << "Mau son" << setw(15) << "Xuat xu" << setw(15) << "Gia ban" << endl;
}

void LocXeHoi_hangXe(XeHoi *a, int n){
    int count = 0;
    for(int i = 0; i < n; i++){
        if(stricmp(a[i].nhanHieu, "Toyota") == 0){
            count++;
        }
    }
    if(count == 0){
        cout << "Khong co xe hang Toyota." << endl;
    }else{
        tieuDe();
        for(int i = 0; i < n; i++){
            if(stricmp(a[i].nhanHieu, "Toyota") == 0){
                a[i].Xuat();
            }
        }
    }
    
}

void LocXeHoi_mauSon_DiaChi(XeHoi *a, int n){
    int count = 0;
    for(int i = 0; i < n; i++){
        if(stricmp(a[i].mauSon, "Green") == 0 && stricmp(a[i].nhaSx.diaChiNhaSx, "Nhat Ban") == 0)
            count++;
    }
    if(count == 0)
        cout << "Khong co xe nao phu hop." << endl;
    else{
        tieuDe();
        for(int i = 0; i < n; i++){
            if(stricmp(a[i].mauSon, "Green") == 0 && stricmp(a[i].nhaSx.diaChiNhaSx, "Nhat Ban") == 0)
                a[i].Xuat();
            }
    }
}

int main(){
    cout << "Nhap so xe hoi: ";
    cin >> n; cin.ignore();
    XeHoi *a = new XeHoi[n];

    for(int i = 0; i < n; i++)
        a[i].Nhap();

    cout << "\n=========Danh sach vua nhap=============\n";
    tieuDe();
    for(int i = 0; i < n; i++)
        a[i].Xuat();

    cout << "\n=========Danh sach xe cua hang Toyota=============\n";
    LocXeHoi_hangXe(a, n);


    cout << "\n=========Danh sach xe mau Green && SX o Nhat Ban=============\n";
    LocXeHoi_mauSon_DiaChi(a, n);
    
    return 0;
}