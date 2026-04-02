#include <iostream>
using namespace std;

class SoPhuc {
private:
    double iThuc, iAo;

public:
    // Nhập
    void Nhap() {
        cout << "Nhap phan thuc: ";
        cin >> iThuc;
        cout << "Nhap phan ao: ";
        cin >> iAo;
    }

    // Xuất
    void Xuat() {
        if (iAo >= 0)
            cout << iThuc << " + " << iAo << "i";
        else
            cout << iThuc << " - " << -iAo << "i";
    }

    // Tổng
    SoPhuc Tong(SoPhuc p) {
        SoPhuc kq;
        kq.iThuc = iThuc + p.iThuc;
        kq.iAo = iAo + p.iAo;
        return kq;
    }

    // Hiệu
    SoPhuc Hieu(SoPhuc p) {
        SoPhuc kq;
        kq.iThuc = iThuc - p.iThuc;
        kq.iAo = iAo - p.iAo;
        return kq;
    }

    // Tích
    SoPhuc Tich(SoPhuc p) {
        SoPhuc kq;
        kq.iThuc = iThuc * p.iThuc - iAo * p.iAo;
        kq.iAo = iThuc * p.iAo + iAo * p.iThuc;
        return kq;
    }

    // Thương
    SoPhuc Thuong(SoPhuc p) {
        SoPhuc kq;
        double mau = p.iThuc * p.iThuc + p.iAo * p.iAo;

        kq.iThuc = (iThuc * p.iThuc + iAo * p.iAo) / mau;
        kq.iAo = (iAo * p.iThuc - iThuc * p.iAo) / mau;

        return kq;
    }
};

int main() {
    SoPhuc a, b;

    cout << "Nhap so phuc thu 1:\n";
    a.Nhap();

    cout << "Nhap so phuc thu 2:\n";
    b.Nhap();

    cout << "\nSo phuc 1: ";
    a.Xuat();

    cout << "\nSo phuc 2: ";
    b.Xuat();

    SoPhuc tong = a.Tong(b);
    SoPhuc hieu = a.Hieu(b);
    SoPhuc tich = a.Tich(b);
    SoPhuc thuong = a.Thuong(b);

    cout << "\n\nTong: ";
    tong.Xuat();

    cout << "\nHieu: ";
    hieu.Xuat();

    cout << "\nTich: ";
    tich.Xuat();

    cout << "\nThuong: ";
    thuong.Xuat();

    return 0;
}
