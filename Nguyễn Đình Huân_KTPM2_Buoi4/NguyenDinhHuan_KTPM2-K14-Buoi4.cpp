#include<bits\stdc++.h>
using namespace std;

class PhongMay;

class MayTinh{
    private:
        char maMay[10];
        char tenMay[20];
        float tocDoCPU;
        char hangSX[15];
        char diaChiSX[30];
        friend class PhongMay;
        friend void SepXep_TenMay(PhongMay a);
        friend void HienThiMay_HangSX_DiaChi(PhongMay a, const char* hang, const char* diaChi);
        friend void HienThiMay_TocDoCPU_Max(PhongMay a);
        friend void Xuat_May(MayTinh a);
};

class PhongMay{
    private:
        char tenPhongMay[20];
        char nguoiQuanLy[30];
        MayTinh *x;
        int n;
    public:
        void Nhap();
        void Xuat();
        friend void SepXep_TenMay(PhongMay a);
        friend void HienThiMay_HangSX_DiaChi(PhongMay a, const char* hang, const char* diaChi);
        friend void HienThiMay_TocDoCPU_Max(PhongMay a);
};

void title(){
    cout << setw(15) << left << "Ma may";
    cout << setw(20) << "Ten may";
    cout << setw(15) << "Toc do CPU";
    cout << setw(20) << "Hang SX";
    cout << setw(30) << "Dia chi SX" << endl;
}

void Xuat_May(MayTinh a){
    cout << setw(15) << left << a.maMay;
    cout << setw(20) << a.tenMay;
    cout << setw(15) << a.tocDoCPU;
    cout << setw(20) << a.hangSX;
    cout << setw(30) << a.diaChiSX << endl;
}

void PhongMay::Nhap(){
    cout << "Nhap ten phong may: ";
    gets(tenPhongMay);
    cout << "Nhap nguoi quan ly: ";
    gets(nguoiQuanLy);
    cout << "Nhap so may: "; 
    cin >> n;
    cin.ignore();
    x = new MayTinh[n];
    for(int i = 0; i < n; i++){
        cout << "\nNhap thong tin may thu: " << i + 1 << endl;
        cout << "Nhap ma may: ";
        gets(x[i].maMay);
        cout << "Nhap ten may: ";
        gets(x[i].tenMay);
        cout << "Nhap toc do CPU: ";
        cin >> x[i].tocDoCPU; cin.ignore();
        cout << "Nhap hang san xuat: ";
        gets(x[i].hangSX);
        cout << "Nhap dia chi san xuat: ";
        gets(x[i].diaChiSX);
    }
}

void PhongMay::Xuat(){
    cout << "Ten phong may: " << tenPhongMay << endl;
    cout << "Nguoi quan ly: " << nguoiQuanLy << endl;
    title();
    for(int i = 0; i < n; i++){
        cout << setw(15) << left << x[i].maMay;
        cout << setw(20) << x[i].tenMay;
        cout << setw(15) << x[i].tocDoCPU;
        cout << setw(20) << x[i].hangSX;
        cout << setw(30) << x[i].diaChiSX << endl;
    }
}

void SepXep_TenMay(PhongMay a){
    for(int i = 0; i < a.n - 1; i++){
        for(int j = a.n - 1; j > i; j--){
            if(stricmp(a.x[j - 1].tenMay, a.x[j].tenMay) > 0){
                swap(a.x[j - 1], a.x[j]);
            }
        }
    }
}

void HienThiMay_HangSX_DiaChi(PhongMay a, const char* hang, const char* diaChi){
    bool check = false;
    for(int i = 0; i < a.n; i++){
        if(stricmp(a.x[i].hangSX, hang) == 0 && stricmp(a.x[i].diaChiSX, diaChi) == 0){
            check = true;
            break;
        }
    }
    if(check){
        cout << "\n-----------------may co hang: " << hang << " va dia chi SX: " << diaChi << " ---------------\n";
        title();
        for(int i = 0; i < a.n; i++){
            if(stricmp(a.x[i].hangSX, hang) == 0 && stricmp(a.x[i].diaChiSX, diaChi) == 0) {
                Xuat_May(a.x[i]);
            }
        }
    }else{
        cout << "\nKhong co may nao hang: " << hang << " va SX o: " << diaChi << endl;
    }
}

void HienThiMay_TocDoCPU_Max(PhongMay a){
    float max = 0;
    for(int i = 0; i < a.n; i++){
        if(a.x[i].tocDoCPU > max){
            max = a.x[i].tocDoCPU;
        }
    }
    cout << "\n-----------------may co toc do CPU max---------------\n";
    title();
    for(int i = 0; i < a.n; i++){
        if(a.x[i].tocDoCPU == max){
            Xuat_May(a.x[i]);
        }
    }
}

int main(){
    PhongMay a;

    a.Nhap();
    cout << "\n-----------------------phong may vua nhap--------------------------\n";
    a.Xuat();

    SepXep_TenMay(a);
    cout << "\n-----------------------phong may vua sap xep-----------------------\n";
    a.Xuat();

    HienThiMay_HangSX_DiaChi(a, "dell", "ha noi");

    HienThiMay_TocDoCPU_Max(a);

    return 0;
}