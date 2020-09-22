#include<bits\stdc++.h>

using namespace std;

class STUDENT;

class DIACHI{
    private:
        int soNha, soDuong;
        char tenThanhPho[30];
        friend class STUDENT;
        friend void LocStudent(STUDENT *a, int n);
};

class STUDENT{
    private:
        string MSV;
        char hoTen[50];
        DIACHI diaChi;
    public:
        void Nhap();
        void Xuat();
        // friend void SapXep(STUDENT *a, int n);
        friend void SapXep1(STUDENT *x, int n);
        friend void LocStudent(STUDENT *a, int n);  
};

void STUDENT::Nhap(){
    cout << "Nhap ma sinh vien: ";
    getline(cin, MSV);
    cout << "Nhap ho ten sinh vien: ";
    gets(hoTen);
    cout << "Nhap so nha: ";
    cin >> diaChi.soNha;
    cout << "Nhap so duong: ";
    cin >> diaChi.soDuong;
    cin.ignore();
    cout << "Nhap ten thanh pho: ";
    gets(diaChi.tenThanhPho);
}

void STUDENT::Xuat(){
    cout << setw(15) << MSV << setw(25) << hoTen << "So nha " << diaChi.soNha << ", Duong "<< diaChi.soDuong << ", TP "<< diaChi.tenThanhPho << endl;
}

// void SapXep(STUDENT *a, int n){
//     for(int i = 0; i < n - 1; i++){
//         for(int j = i + 1; j < n; j++){
//             char char1, char2;
//             int k, tmp1, tmp2;
//             for(k = a[i].hoTen.length() - 1; k >= 0 ; k--){
//                 if(a[i].hoTen[k] == 32){
//                     char1 = a[i].hoTen[k + 1];
//                     tmp1 = k + 1;
//                     break;
//                 }
//             }
//             for(k = a[j].hoTen.length() - 1; k >= 0 ; k--){
//                 if(a[j].hoTen[k] == 32){
//                     char2 = a[j].hoTen[k + 1];
//                     tmp2 = k + 1;
//                     break;
//                 }
//             }
//             while(tmp1 < a[i].hoTen.length() && tmp2 < a[j].hoTen.length()){
//                 if(char1 == char2){
//                     char1 = a[i].hoTen[++tmp1];
//                     char2 = a[j].hoTen[++tmp2];
//                 }else 
//                     break;
//             }
//             if(char1 > char2){
//                 STUDENT tmp = a[i];
//                 a[i] = a[j];
//                 a[j] = tmp;
//             }
//         }
//     }
// }

void LocStudent(STUDENT *a, int n){
    int count = 0;
    for(int i = 0; i < n; i++){
        if(a[i].diaChi.soNha < 100 || a[i].diaChi.soDuong > 40 || stricmp(a[i].diaChi.tenThanhPho, "Da Nang") == 0){
            count++;
        }
    }
    if(count == 0){
        cout << "\nKhong co sinh vien theo yeu cau." << endl;
    }else{
        cout << setw(15) << left << "MSV" << setw(25) << "Ho ten sinh vien" << "Dia chi" << endl;
        for(int i = 0; i < n; i++){
            if(a[i].diaChi.soNha < 100 || a[i].diaChi.soDuong > 40 || stricmp(a[i].diaChi.tenThanhPho, "Da Nang") == 0){
                a[i].Xuat();
            }
        }
    }
}

void SapXep1(STUDENT *x, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = n - 1; j > i; j--){
            if(strcmpi(x[j - 1].hoTen, x[j].hoTen) > 0){
                swap(x[j - 1], x[j]);
            }
        }
    }
}

int main(){
    STUDENT *student = new STUDENT[5];
    for(int i = 0; i < 5; i++){
        cout << "\nNhap thong tin sinh vien thu: " << i + 1 << endl;
        student[i].Nhap();
    }

    cout << "\n======Thong tin sinh vien vua nhap=========\n";
    cout << setw(15) << left << "MSV" << setw(25) << "Ho ten sinh vien" << "Dia chi" << endl;
    for(int i = 0; i < 5; i++){
        student[i].Xuat();
    }

    cout << "\n======Thong tin sinh vien sap xep theo ho ten(abc)=========\n";
    SapXep1(student, 5);
    cout << setw(15) << left << "MSV" << setw(25) << "Ho ten sinh vien" << "Dia chi" << endl;
    for(int i = 0; i < 5; i++){
        student[i].Xuat();
    }

    //SoNha < 100 hoặc SoDuong > 40 hoặc ở thành phố “Da Nang”

    // cout << "\n======students: soNha < 100 || soDuong > 40 || tenThanhPho == Da Nang=========\n ";
    // LocStudent(student, 5);

    return 0;
}