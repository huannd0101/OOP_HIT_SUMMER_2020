#include<bits\stdc++.h>
using namespace std;

class Matrix{
private:
    double **a;
    int m, n;
public:
    Matrix(){
        m = n = 0;
        a = new double*[m];
        for(int i = 0; i < m; i++){
            a[i] = new double[n];
        }
    }
    friend istream &operator>>(istream &is, Matrix &x){
        cout << "Nhap m = ";
        is >> x.m;
        cout << "Nhap n = ";
        is >> x.n;
        x.a = new double*[x.m];
        for(int i = 0; i < x.m; i++){
           x.a[i] = new double[x.n];
        }
        for(int i = 0; i < x.m; i++){
            for(int j = 0; j < x.n; j++){
                cout << "Nhap a[" << i << "][" << j << "] = ";
                is >> x.a[i][j];
            }
        }
        return is;
    }
    friend ostream &operator<<(ostream &os, Matrix x){
        for(int i = 0; i < x.m; i++){
            for(int j = 0; j < x.n; j++){
                os << x.a[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }
    Matrix operator+(Matrix x){
        if(m != x.m || n != x.n){
            cout << "Khong thuc hien duoc";
            return x;
        }
        Matrix tmp;
        tmp.m = x.m;
        tmp.n = x.n;
        tmp.a = new double*[m];
        for(int i = 0; i < x.m; i++)
            tmp.a[i] = new double[n];
        for(int i = 0; i < tmp.m; i++){
            for(int j = 0; j < tmp.n; j++){
                tmp.a[i][j] = a[i][j] + x.a[i][j];
            }
        }
        return tmp;
    }
    Matrix operator-(Matrix x){
        if(m != x.m || n != x.n){
            cout << "Khong thuc hien duoc";
            return x;
        }
        Matrix tmp;
        tmp.m = x.m;
        tmp.n = x.n;
        tmp.a= new double*[m];
        for(int i = 0; i < x.m; i++)
            tmp.a[i] = new double[n];
        for(int i = 0; i < x.m; i++){
            for(int j = 0; j < x.n; j++){
                tmp.a[i][j] = a[i][j] - x.a[i][j];
            }
        }
        return tmp;
    }
    Matrix operator-(){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                a[i][j] = -a[i][j];
            }
        }
        return *this;
    }
};

int main(){
    Matrix P, Q, KQ;
    cout << "Nhap ma tran P\n";
    cin >> P;
    cout << "Nhap ma tran Q\n";
    cin >> Q;
    cout << "Ma tran dao cua P la: \n";
    cout << -P << endl;
    cout << "Ma tran dao cua Q la: \n";
    cout << -Q << endl;

    cout << "Tong 2 ma tran dao la: \n";
    KQ = P + Q;
    cout << KQ;
    cout << "\nHieu 2 ma tran dao la: \n";
    KQ = P - Q;
    cout << KQ;
    return 0;
}