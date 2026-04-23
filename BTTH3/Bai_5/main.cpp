#include <iostream>
#include <cmath>
using namespace std;

class cDaThuc {
private:
    int n;          // bậc
    double a[100];  // hệ số

public:
    // Khởi tạo mặc định
    cDaThuc() {
        n = 0;
        a[0] = 0;
    }

    // Nhập đa thức
    void Nhap() {
        cout << "Nhap bac n: ";
        cin >> n;

        for (int i = n; i >= 0; i--) {
            cout << "Nhap he so bac " << i << ": ";
            cin >> a[i];
        }
    }

    // Xuất đa thức
    void Xuat() {
        for (int i = n; i >= 0; i--) {
                cout << a[i] << "x^" << i;
                if (i > 0) cout << " + ";
        }
        cout << endl;
    }

    // Tính giá trị P(x)
    double TinhGiaTri(double x) {
        double res = 0;
        for (int i = 0; i <= n; i++) {
            res += a[i] * pow(x, i);
        }
        return res;
    }

    // Cộng hai đa thức
    cDaThuc Cong(cDaThuc b) {
        cDaThuc kq;
        kq.n = max(n, b.n);

        for (int i = 0; i <= kq.n; i++) {
            double ai = (i <= n) ? a[i] : 0;
            double bi = (i <= b.n) ? b.a[i] : 0;
            kq.a[i] = ai + bi;
        }
        return kq;
    }

    // Trừ hai đa thức
    cDaThuc Tru(cDaThuc b) {
        cDaThuc kq;
        kq.n = max(n, b.n);

        for (int i = 0; i <= kq.n; i++) {
            double ai = (i <= n) ? a[i] : 0;
            double bi = (i <= b.n) ? b.a[i] : 0;
            kq.a[i] = ai - bi;
        }
        return kq;
    }
};

int main() {
    cDaThuc A, B, C, D;

    cout << "Nhap da thuc A:\n";
    A.Nhap();

    cout << "\nNhap da thuc B:\n";
    B.Nhap();

    cout << "\nDa thuc A: ";
    A.Xuat();

    cout << "Da thuc B: ";
    B.Xuat();

    double x;
    cout << "\nNhap x: ";
    cin >> x;

    cout << "A(x) = " << A.TinhGiaTri(x) << endl;
    cout << "B(x) = " << B.TinhGiaTri(x) << endl;

    C = A.Cong(B);
    cout << "\nA + B = ";
    C.Xuat();

    D = A.Tru(B);
    cout << "A - B = ";
    D.Xuat();

    return 0;
}
