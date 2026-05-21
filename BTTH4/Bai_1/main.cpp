#include <iostream>
using namespace std;

class cSoPhuc {
private:
    float iThuc, iAo;

public:

    cSoPhuc(float thuc = 0, float ao = 0) {
        iThuc = thuc;
        iAo = ao;
    }

    cSoPhuc operator + (const cSoPhuc& sp) {
        return cSoPhuc(
            iThuc + sp.iThuc, iAo + sp.iAo
        );
    }

    cSoPhuc operator - (const cSoPhuc& sp) {
        return cSoPhuc(
            iThuc - sp.iThuc, iAo - sp.iAo
        );
    }

    cSoPhuc operator * (const cSoPhuc& sp) {
        return cSoPhuc(
            iThuc * sp.iThuc - iAo * sp.iAo, iThuc * sp.iAo + iAo * sp.iThuc
        );
    }

    cSoPhuc operator / (const cSoPhuc& sp) {

    float mau = sp.iThuc * sp.iThuc + sp.iAo * sp.iAo;

    if (mau == 0) {
        cout << "\nLoi: Khong the chia cho so phuc 0!";
        return cSoPhuc();
    }

    return cSoPhuc(
        (iThuc * sp.iThuc + iAo * sp.iAo) / mau, (iAo * sp.iThuc - iThuc * sp.iAo) / mau);
    }

    bool operator == (const cSoPhuc& sp) {
        return (iThuc == sp.iThuc && iAo == sp.iAo);
    }

    bool operator != (const cSoPhuc& sp) {
        return !(*this == sp);
    }

    friend istream& operator >> (istream& in, cSoPhuc& sp) {

        cout << "Nhap phan thuc: ";
        in >> sp.iThuc;

        cout << "Nhap phan ao: ";
        in >> sp.iAo;

        return in;
    }

    friend ostream& operator << (ostream& out, cSoPhuc sp) {

        if (sp.iAo >= 0)
            out << sp.iThuc
                << " + "
                << sp.iAo << "i";
        else
            out << sp.iThuc
                << " - "
                << -sp.iAo << "i";

        return out;
    }
};

int main() {

    cSoPhuc sp1, sp2;

    cout << "Nhap so phuc thu nhat:\n";
    cin >> sp1;

    cout << "\nNhap so phuc thu hai:\n";
    cin >> sp2;

    cout << "\nSo phuc 1: " << sp1;
    cout << "\nSo phuc 2: " << sp2;

    cout << "\n\nTong: " << sp1 + sp2;
    cout << "\nHieu: " << sp1 - sp2;
    cout << "\nTich: " << sp1 * sp2;
    cout << "\nThuong: " << sp1 / sp2;

    if (sp1 == sp2)
        cout << "\n\nHai so phuc bang nhau";
    else
        cout << "\n\nHai so phuc khac nhau";

    return 0;
}
