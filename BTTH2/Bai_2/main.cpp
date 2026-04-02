#include <iostream>
using namespace std;

class PhanSo {
private:
    int iTu;
    int iMau;

public:
    void Nhap();
    void Xuat();
    void RutGon();

    PhanSo Tong(PhanSo ps);
    PhanSo Hieu(PhanSo ps);
    PhanSo Tich(PhanSo ps);
    PhanSo Thuong(PhanSo ps);

    int SoSanh(PhanSo ps); // 1: >, 0: =, -1: <
};
// Hàm tìm UCLN
int UCLN(int a, int b) {
    if (b == 0) return a;
    return UCLN(b, a % b);
}
// Nhập phân số điều kiện mẫu khác 0
void PhanSo::Nhap() {
    cout << "Nhap tu: ";
    cin >> iTu;
    do {
        cout << "Nhap mau (khac 0): ";
        cin >> iMau;
    } while (iMau == 0);
}
// Xuất phân số
void PhanSo::Xuat() {
    cout << iTu << "/" << iMau;
}
// Rút gọn phân số
void PhanSo::RutGon() {
    int ucln = UCLN(abs(iTu), abs(iMau));
    iTu /= ucln;
    iMau /= ucln;

    // Đưa dấu về tử
    if (iMau < 0) {
        iTu = -iTu;
        iMau = -iMau;
    }
}
// Tổng
PhanSo PhanSo::Tong(PhanSo ps) {
    PhanSo kq;
    kq.iTu = iTu * ps.iMau + ps.iTu * iMau;
    kq.iMau = iMau * ps.iMau;
    kq.RutGon();
    return kq;
}
// Hiệu
PhanSo PhanSo::Hieu(PhanSo ps) {
    PhanSo kq;
    kq.iTu = iTu * ps.iMau - ps.iTu * iMau;
    kq.iMau = iMau * ps.iMau;
    kq.RutGon();
    return kq;
}
// Tích
PhanSo PhanSo::Tich(PhanSo ps) {
    PhanSo kq;
    kq.iTu = iTu * ps.iTu;
    kq.iMau = iMau * ps.iMau;
    kq.RutGon();
    return kq;
}
// Thương
PhanSo PhanSo::Thuong(PhanSo ps) {
    PhanSo kq;
    kq.iTu = iTu * ps.iMau;
    kq.iMau = iMau * ps.iTu;
    kq.RutGon();
    return kq;
}
// So sánh
int PhanSo::SoSanh(PhanSo ps) {
    int left = iTu * ps.iMau;
    int right = ps.iTu * iMau;

    if (left > right) return 1;
    if (left == right) return 0;
    return -1;
}

int main() {
    PhanSo a, b;

    cout << "Nhap phan so A:\n";
    a.Nhap();

    cout << "Nhap phan so B:\n";
    b.Nhap();

    cout << "\nPhan so A: ";
    a.RutGon();
    a.Xuat();

    cout << "\nPhan so B: ";
    b.RutGon();
    b.Xuat();

    // Tính toán
    PhanSo tong = a.Tong(b);
    PhanSo hieu = a.Hieu(b);
    PhanSo tich = a.Tich(b);
    PhanSo thuong = a.Thuong(b);

    cout << "\n\nTong: ";
    tong.Xuat();

    cout << "\nHieu: ";
    hieu.Xuat();

    cout << "\nTich: ";
    tich.Xuat();

    cout << "\nThuong: ";
    thuong.Xuat();

    // So sánh
    int cmp = a.SoSanh(b);
    if (cmp == 1)
        cout << "\nA > B";
    else if (cmp == 0)
        cout << "\nA = B";
    else
        cout << "\nA < B";

    return 0;
}
