#include <iostream>
#include <cmath>
using namespace std;

class cTamGiac {
private:
    double Ax, Ay, Bx, By, Cx, Cy;

    double KhoangCach(double x1, double y1, double x2, double y2) {
        return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    }

public:
    void Nhap() {
        cout << "Nhap diem A: ";
        cin >> Ax >> Ay;
        cout << "Nhap diem B: ";
        cin >> Bx >> By;
        cout << "Nhap diem C: ";
        cin >> Cx >> Cy;
    }

    void Xuat() {
        cout << "Tam giac: ";
        cout << "(" << Ax << "," << Ay << ") ";
        cout << "(" << Bx << "," << By << ") ";
        cout << "(" << Cx << "," << Cy << ")\n";
    }

    bool HopLe() {
        double AB = KhoangCach(Ax, Ay, Bx, By);
        double BC = KhoangCach(Bx, By, Cx, Cy);
        double CA = KhoangCach(Cx, Cy, Ax, Ay);
        return (AB + BC > CA && AB + CA > BC && BC + CA > AB);
    }

    double ChuVi() {
        double AB = KhoangCach(Ax, Ay, Bx, By);
        double BC = KhoangCach(Bx, By, Cx, Cy);
        double CA = KhoangCach(Cx, Cy, Ax, Ay);
        return AB + BC + CA;
    }

    double DienTich() {
        double AB = KhoangCach(Ax, Ay, Bx, By);
        double BC = KhoangCach(Bx, By, Cx, Cy);
        double CA = KhoangCach(Cx, Cy, Ax, Ay);
        double p = (AB + BC + CA) / 2;

        double s = p * (p - AB) * (p - BC) * (p - CA);

        if (s < 0) return 0;
            return sqrt(s);
    }

    void KiemTraLoai() {
        double a = KhoangCach(Bx, By, Cx, Cy);
        double b = KhoangCach(Ax, Ay, Cx, Cy);
        double c = KhoangCach(Ax, Ay, Bx, By);

        if (fabs(a - b) < 1e-6 && fabs(b - c) < 1e-6) {
            cout << "Tam giac deu\n";
        }
        else if (fabs(a - b) < 1e-6 || fabs(b - c) < 1e-6 || fabs(a - c) < 1e-6) {
            if (fabs(a*a + b*b - c*c) < 1e-6 ||
                fabs(a*a + c*c - b*b) < 1e-6 ||
                fabs(b*b + c*c - a*a) < 1e-6)
                cout << "Tam giac vuong can\n";
            else
                cout << "Tam giac can\n";
        }
        else if (fabs(a*a + b*b - c*c) < 1e-6 ||
                 fabs(a*a + c*c - b*b) < 1e-6 ||
                 fabs(b*b + c*c - a*a) < 1e-6) {
            cout << "Tam giac vuong\n";
        }
        else {
            cout << "Tam giac thuong\n";
        }
    }

    void TinhTien(double dx, double dy) {
        Ax += dx; Ay += dy;
        Bx += dx; By += dy;
        Cx += dx; Cy += dy;
    }

    void Quay(double goc) {
        double rad = goc * M_PI / 180;

        auto quay = [&](double &x, double &y) {
            double x_moi = x * cos(rad) - y * sin(rad);
            double y_moi = x * sin(rad) + y * cos(rad);
            x = x_moi;
            y = y_moi;
        };

        quay(Ax, Ay);
        quay(Bx, By);
        quay(Cx, Cy);
    }

    void PhongTo(double k) {
        Ax *= k; Ay *= k;
        Bx *= k; By *= k;
        Cx *= k; Cy *= k;
    }

    void ThuNho(double k) {
        if (k != 0) {
            Ax /= k; Ay /= k;
            Bx /= k; By /= k;
            Cx /= k; Cy /= k;
        }
    }
};

int main() {
    cTamGiac tg;

    tg.Nhap();

    if (!tg.HopLe()) {
        cout << "Khong phai tam giac hop le!\n";
        return 0;
    }

    tg.Xuat();

    cout << "Chu vi: " << tg.ChuVi() << endl;
    cout << "Dien tich: " << tg.DienTich() << endl;

    tg.KiemTraLoai();

    double a, b;
    cout << "\nNhap toa do tinh tien: "; cin >> a >> b;
    cout << "\nTinh tien (" << a << "," << b << "):\n";
    tg.TinhTien(a, b);
    tg.Xuat();

    double deg;
    cout << "\nNhap goc do quay: "; cin >> deg;
    cout << "\nQuay " << deg << " do:\n";
    tg.Quay(deg);
    tg.Xuat();

    double r1, r2;

    do {
        cout << "\nNhap ti le phong to R1 (>0): ";
        cin >> r1;
    }
    while (r1 <= 0);
    cout << "\nPhong to:\n";
    tg.PhongTo(r1);
    tg.Xuat();

    do {
        cout << "\nNhap ti le thu nho R2 (>0): ";
        cin >> r2;
    }
    while (r2 <= 0);
    cout << "\nThu nho:\n";
    tg.ThuNho(r2);
    tg.Xuat();

    return 0;
}
