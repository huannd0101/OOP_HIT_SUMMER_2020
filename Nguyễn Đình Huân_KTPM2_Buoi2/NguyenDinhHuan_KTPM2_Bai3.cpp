#include<bits\stdc++.h>
using namespace std;

class HANG{
    private:
        string Mahang, Tenhang;
        float Dongia;
        int Soluong;
    public:
        HANG(){
            Mahang = "";
            Tenhang = "";
            Dongia = 0;
            Soluong = 0;
        }

        ~HANG(){
            Mahang = "";
            Tenhang = "";
            Dongia = 0;
            Soluong = 0;
        }

        void NHAP(){
            cout << "Nhap ma hang: "; getline(cin, Mahang);
            cout << "Nhap ten hang: "; getline(cin, Tenhang);
            cout << "Nhap don gia: "; cin >> Dongia;
            cout << "Nhap so luong: "; cin >> Soluong; cin.ignore();
        }

        void XUAT(){
            cout << setw(20) << Mahang << setw(30) << Tenhang << setw(10) << Dongia << setw(5) << Soluong << setw(10) << Dongia * Soluong << endl;
        }
};

int main(){
    HANG *a;
    int n;
    cout << "Nhap so luong hang: "; 
    cin >> n; cin.ignore();
    a = new HANG[n];
    for(int i = 0; i < n; i++)
        (a + i)->NHAP();
    
    for(int i = 0; i < n; i++)
        (a + i)->XUAT();
    
    return 0;
}