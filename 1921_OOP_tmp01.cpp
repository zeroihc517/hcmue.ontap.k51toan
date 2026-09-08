#include <iostream>
#include <iomanip>
using namespace std;
class PhanSo {
private:
    int tu, mau;
public:
    PhanSo() {
        tu=0;
        mau=1;
    }
    PhanSo(int t, int m) {
        tu=t;
        mau=m;
        if (mau<0) {
            tu=-tu;
            mau=-mau;
        }
    }
    PhanSo (PhanSo&p) {
        tu=p.tu;
        mau=p.mau;
    }
    int getTu() { return tu; }
    int getMau() { return mau; }
    void setTu(int t) { tu=t; }
    void setMau(int m) { 
        mau=m; 
        if (mau<0) {
            tu=-tu;
            mau=-mau;
        }
    }
    int UCLN(int a, int b) {
        if (a<0) { a=-a; }
        if (b<0) { b=-b; }
        while (b != 0) {
            int r=a%b;
            a=b;
            b=r;
        }
        return a;
    }
    double getGiaTri() { return (double) tu/mau; }
    PhanSo psRutGon() {
        int gcd=UCLN(tu, mau);
        return PhanSo(tu/gcd, mau/gcd);
    }
    PhanSo psNghichDao() { return PhanSo(mau, tu).psRutGon(); }
    void output() { cout<<tu<<"/"<<mau; }
};
int main() {
    int tuA, mauA;
    int tuB, mauB;
    cin>>tuA>>mauA;
    cin>>tuB>>mauB;
    PhanSo A(tuA, mauA);
    PhanSo B(tuB, mauB);
    A.output();
    cout<<endl;
    B.output();
    cout<<endl;
    cout<<A.getTu()+B.getMau()<<endl;
    cout<<fixed<<setprecision(3);
    cout<<A.getGiaTri()<<" "<<B.getGiaTri()<<endl;
    PhanSo ARG=A.psRutGon();
    ARG.output();
    cout<<endl;
    PhanSo BND=B.psNghichDao();
    BND.output();
    return 0;
}
