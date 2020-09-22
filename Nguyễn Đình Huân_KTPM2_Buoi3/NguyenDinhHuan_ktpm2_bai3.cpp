#include<bits\stdc++.h>
using namespace std;
int n;
class DoanhNghiep;

class Date{
    private:
        int day, month, year;
    public:
        void Nhap();
        void Xuat(); 
        friend long TongDoanhThu_2015(DoanhNghiep *a, int n);
};

class DiaChi{
    private:
        char dienThoai[12];
        char phuong[30];
        char quan[30];
        char thanhPho[30];
        friend class DoanhNghiep;
        friend void LocDoanhNghiep(DoanhNghiep *a, int n);
};

class DoanhNghiep{
    private:
        int maDn;
        char tenDn[60];
        Date ngayTl;
        DiaChi diaChi;
        char giamDoc[30];
        long doanhThu;
    public:
        void Nhap();
        void Xuat();
        friend void LocDoanhNghiep(DoanhNghiep *a, int n);
        friend long TongDoanhThu_2015(DoanhNghiep *a, int n);
};

void Date::Nhap(){
    cout << "Nhap ngay: "; cin >> day;
    cout << "Nhap thang: "; cin >> month;
    cout << "Nhap nam: "; cin >> year;
    cin.ignore();
}

void Date::Xuat(){
    cout << setw(2) << day << "/" << setw(2) << month << "/" << setw(9) << year;
}

void DoanhNghiep::Nhap(){
    cout << "\nNhap ma DN: "; cin >> maDn; cin.ignore();
    cout << "Nhap ten DN: "; gets(tenDn);
    cout << "Nhap ngay thanh lap: " << endl;
    ngayTl.Nhap();
    cout << "Nhap dia chi: " << endl;
    cout << "1.Dien thoai: "; gets(diaChi.dienThoai);
    cout << "2.Phuong: "; gets(diaChi.phuong);
    cout << "3.Quan: "; gets(diaChi.quan);
    cout << "4.Thanh pho: "; gets(diaChi.thanhPho);
    cout << "Nhap ten giam doc: "; gets(giamDoc);
    cout << "Nhap doanh thu: "; cin >> doanhThu; cin.ignore();
}

void DoanhNghiep::Xuat(){
    cout << setw(20) << left << maDn << setw(20) << tenDn;
    ngayTl.Xuat();
    cout << setw(15) << diaChi.dienThoai << setw(20) << diaChi.phuong << setw(20) << diaChi.quan << setw(20) << diaChi.thanhPho << setw(20) << giamDoc << setw(10) << doanhThu << endl;
}

void tieuDe(){
    cout << setw(20) << left << "Ma DN" << setw(20) << "Ten DN" << setw(15) << "Ngay TL" << setw(15) << "Dien thoai" << setw(20) << "Phuong" << setw(20) << "Quan" << setw(20) << "Thanh pho" << setw(20) << "Giam Doc" << setw(10) << "Doanh thu" << endl;
}

void LocDoanhNghiep(DoanhNghiep *a, int n){
    int count = 0;
    for(int i = 0; i < n; i++)
        if(stricmp(a[i].diaChi.thanhPho, "Ha Noi") == 0)
            count++;
    if(count == 0)
        cout << "\n\t\t\t\tKhong co doanh nghiep o Ha Noi." << endl;
    else{
        tieuDe();
        for(int i = 0; i < n; i++)
            if(stricmp(a[i].diaChi.thanhPho, "Ha Noi") == 0)
                a[i].Xuat();
    }
}

long TongDoanhThu_2015(DoanhNghiep *a, int n){
    long Sum = 0;
    for(int i = 0; i < n; i++){
        if(a[i].ngayTl.year == 2015)
            Sum += a[i].doanhThu;
    }
    return Sum;
}

int main(){
    cout << "Nhap so doanh nghiep: "; cin >> n;
    DoanhNghiep *a = new DoanhNghiep[n];
    for(int i = 0; i < n; i++)
        a[i].Nhap();
    cout << "\n====================================Danh sach vua nhap==============================================\n";
    tieuDe();
    for(int i = 0; i < n; i++)
        a[i].Xuat();

    cout << "\n===============================Danh sach doanh nghiep o Ha Noi=======================================\n";
    LocDoanhNghiep(a, n);

    cout << "\nTong doanh thu cua doanh nghiep thanh lap nam 2015 la: " << TongDoanhThu_2015(a, n);
    return 0;
}