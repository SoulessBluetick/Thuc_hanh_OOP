#include <iostream>
using namespace std;

class cPhanSo {
private:
    int iTu, iMau;

public:
    cPhanSo(int tu = 0, int mau = 1) {
        iTu = tu;
        iMau = mau;
        RutGon();
    }

    int UCLN(int a, int b) {

        a = abs(a);
        b = abs(b);

        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }

        return a;
    }

    void RutGon() {

        int ucln = UCLN(iTu, iMau);

        iTu /= ucln;
        iMau /= ucln;

        if (iMau < 0) {
            iTu = -iTu;
            iMau = -iMau;
        }
    }

    cPhanSo operator + (const cPhanSo& ps) {

        cPhanSo kq;

        kq.iTu = iTu * ps.iMau + ps.iTu * iMau;

        kq.iMau = iMau * ps.iMau;

        kq.RutGon();

        return kq;
    }

    cPhanSo operator - (const cPhanSo& ps) {

        cPhanSo kq;

        kq.iTu = iTu * ps.iMau - ps.iTu * iMau;

        kq.iMau = iMau * ps.iMau;

        kq.RutGon();

        return kq;
    }

    cPhanSo operator * (const cPhanSo& ps) {

        cPhanSo kq;

        kq.iTu = iTu * ps.iTu;
        kq.iMau = iMau * ps.iMau;

        kq.RutGon();

        return kq;
    }

    cPhanSo operator / (const cPhanSo& ps) {

        cPhanSo kq;

        kq.iTu = iTu * ps.iMau;
        kq.iMau = iMau * ps.iTu;

        kq.RutGon();

        return kq;
    }

    bool operator == (const cPhanSo& ps) {

        return (iTu == ps.iTu && iMau == ps.iMau);
    }

    bool operator > (const cPhanSo& ps) {

        return (iTu * ps.iMau > ps.iTu * iMau);
    }

    bool operator < (const cPhanSo& ps) {

        return (iTu * ps.iMau < ps.iTu * iMau);
    }

    friend istream& operator >> (istream& in, cPhanSo& ps) {

        cout << "Nhap tu so: ";
        in >> ps.iTu;

        do {
            cout << "Nhap mau so: ";
            in >> ps.iMau;

            if (ps.iMau == 0)
                cout << "Mau so phai khac 0!\n";

        } while (ps.iMau == 0);

        ps.RutGon();

        return in;
    }

    friend ostream& operator << (ostream& out, cPhanSo ps) {

        if (ps.iMau == 1)
            out << ps.iTu;
        else
            out << ps.iTu
                << "/"
                << ps.iMau;

        return out;
    }
};

int main() {

    cPhanSo ps1, ps2;

    cout << "Nhap phan so thu nhat:\n";
    cin >> ps1;

    cout << "\nNhap phan so thu hai:\n";
    cin >> ps2;

    cout << "\nPhan so 1: " << ps1;
    cout << "\nPhan so 2: " << ps2;

    cout << "\n\nTong: " << ps1 + ps2;
    cout << "\nHieu: " << ps1 - ps2;
    cout << "\nTich: " << ps1 * ps2;
    cout << "\nThuong: " << ps1 / ps2;

    if (ps1 == ps2)
        cout << "\n\nHai phan so bang nhau";
    else if (ps1 > ps2)
        cout << "\n\nPhan so 1 lon hon";
    else
        cout << "\n\nPhan so 2 lon hon";

    return 0;
}
