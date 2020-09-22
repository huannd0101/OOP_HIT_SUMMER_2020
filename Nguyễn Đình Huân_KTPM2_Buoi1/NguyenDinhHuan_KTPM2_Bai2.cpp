#include<bits\stdc++.h>
using namespace std;

class SINHVIEN {
    private:    
        string MSV;
        string HT;
        int Tuoi;
        float diem;
    public:
        void nhap();
        void xuat();
        void setMSV(string msv){
            MSV = msv;
        }
        string getMSV(){
            return MSV;
        }
};

void SINHVIEN::nhap(){

}

void SINHVIEN::xuat(){
    cout<< "================INFO====================" << endl 
        << "Ma sinh vien: " << getMSV() << endl 
        << "Ho ten: " << HT << endl
        << "Tuoi: " << Tuoi << endl 
        << "Diem: " << diem << endl;
}

int main(){
    SINHVIEN a, b;
    a.setMSV("MSV2019602287");
    a.xuat();
    return 0;
}