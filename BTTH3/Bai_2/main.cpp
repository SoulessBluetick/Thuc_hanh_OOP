#include <iostream>
#include <cmath>
using namespace std;

class cDaGiac {
private:
    int n;
    double x[100], y[100];

    double KhoangCach(double x1, double y1, double x2, double y2) {
        return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    }

public:
    void Nhap() {
        do {
            cout << "Nhap so dinh (>=3): ";
            cin >> n;
        } while (n < 3);

        for (int i = 0; i < n; i++) {
            cout << "Nhap dinh " << i + 1 << ": ";
            cin >> x[i] >> y[i];
        }
    }

    void Xuat() {
        cout << "Da giac: ";
        for (int i = 0; i < n; i++) {
            cout << "(" << x[i] << "," << y[i] << ") ";
        }
        cout << endl;
    }

    double ChuVi() {
        double cv = 0;
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            cv += KhoangCach(x[i], y[i], x[j], y[j]);
        }
        return cv;
    }

    double DienTich() {
        double s = 0;
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            s += x[i] * y[j] - x[j] * y[i];
        }
        return fabs(s) / 2;
    }

    void TinhTien(double dx, double dy) {
        for (int i = 0; i < n; i++) {
            x[i] += dx;
            y[i] += dy;
        }
    }

    void Quay(double goc) {
        double rad = goc * M_PI / 180;

        for (int i = 0; i < n; i++) {
            double x_moi = x[i] * cos(rad) - y[i] * sin(rad);
            double y_moi = x[i] * sin(rad) + y[i] * cos(rad);
            x[i] = x_moi;
            y[i] = y_moi;
        }
    }

    void PhongTo(double k) {
        for (int i = 0; i < n; i++) {
            x[i] *= k;
            y[i] *= k;
        }
    }

    void ThuNho(double k) {
        if (k != 0) {
            for (int i = 0; i < n; i++) {
                x[i] /= k;
                y[i] /= k;
            }
        }
    }
};

int main() {
    cDaGiac dg;

    dg.Nhap();
    dg.Xuat();

    cout << "Chu vi: " << dg.ChuVi() << endl;
    cout << "Dien tich: " << dg.DienTich() << endl;

    double dx, dy;
    cout << "\nNhap tinh tien: ";
    cin >> dx >> dy;
    dg.TinhTien(dx, dy);
    dg.Xuat();

    double goc;
    cout << "\nNhap goc quay: ";
    cin >> goc;
    dg.Quay(goc);
    dg.Xuat();

    double k;
    do {
        cout << "\nNhap ti le phong to (>0): ";
        cin >> k;
    } while (k <= 0);
    dg.PhongTo(k);
    dg.Xuat();

    do {
        cout << "\nNhap ti le thu nho (>0): ";
        cin >> k;
    } while (k <= 0);
    dg.ThuNho(k);
    dg.Xuat();

    return 0;
}
