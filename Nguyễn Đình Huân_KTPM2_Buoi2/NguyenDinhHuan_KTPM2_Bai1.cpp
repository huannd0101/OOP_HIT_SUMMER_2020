#include<bits\stdc++.h>
using namespace std;

class HCN{
    private:
        float D, R;
    public:
        HCN(){
            D = R = 0;
        }

        ~HCN(){
            D = R = 0;
        }

        void Input(){
            cout << "Nhap chieu dai va chieu rong la: ";
            cin >> D >> R;
        }

        void VE(){
            for(int i = 0; i < R; i++){
                for(int j = 0; j < D; j++){
                    cout << " * ";
                }
                cout << endl;
            }
        }

        float ChuVi(){
            return 2 * (D + R);
        }

        float DienTich(){
            return D * R;
        }
};

int main(){
    HCN a;
    a.Input();
    a.VE();
    cout << "\nChu vi: " << a.ChuVi() << endl;
    cout << "Dien tich: " << a.DienTich();
    return 0;
}