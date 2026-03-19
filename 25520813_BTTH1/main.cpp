#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/* ================= BÀI 1 ================= */
struct PhanSo {
    int tu, mau;
};

int UCLN(int a, int b) {
    if (b == 0) return a;
    return UCLN(b, a % b);
}

void rutGon(PhanSo &p) {
    int u = UCLN(abs(p.tu), abs(p.mau));
    p.tu /= u;
    p.mau /= u;
    if (p.mau < 0) {
        p.tu = -p.tu;
        p.mau = -p.mau;
    }
}

void bai1() {
    PhanSo p;
    cin >> p.tu >> p.mau;

    if (p.mau == 0) {
        cout << "Khong hop le\n";
        return;
    }

    rutGon(p);

    if (p.mau == 1) cout << p.tu << endl;
    else cout << p.tu << "/" << p.mau << endl;
}

/* ================= BÀI 2 ================= */
PhanSo lonHon(PhanSo a, PhanSo b) {
    if ((long long)a.tu * b.mau > (long long)b.tu * a.mau)
        return a;
    return b;
}

void bai2() {
    PhanSo a, b;
    cin >> a.tu >> a.mau;
    cin >> b.tu >> b.mau;

    if (a.mau == 0 || b.mau == 0) {
        cout << "Khong hop le\n";
        return;
    }

    rutGon(a);
    rutGon(b);

    PhanSo kq = lonHon(a, b);

    if (kq.mau == 1) cout << kq.tu << endl;
    else cout << kq.tu << "/" << kq.mau << endl;
}

/* ================= BÀI 3 ================= */
PhanSo cong(PhanSo a, PhanSo b) {
    PhanSo kq;
    kq.tu = a.tu * b.mau + b.tu * a.mau;
    kq.mau = a.mau * b.mau;
    rutGon(kq);
    return kq;
}

PhanSo tru(PhanSo a, PhanSo b) {
    PhanSo kq;
    kq.tu = a.tu * b.mau - b.tu * a.mau;
    kq.mau = a.mau * b.mau;
    rutGon(kq);
    return kq;
}

PhanSo nhan(PhanSo a, PhanSo b) {
    PhanSo kq;
    kq.tu = a.tu * b.tu;
    kq.mau = a.mau * b.mau;
    rutGon(kq);
    return kq;
}

PhanSo chia(PhanSo a, PhanSo b) {
    PhanSo kq;
    kq.tu = a.tu * b.mau;
    kq.mau = a.mau * b.tu;
    rutGon(kq);
    return kq;
}

void inPS(PhanSo p) {
    if (p.mau == 1) cout << p.tu;
    else cout << p.tu << "/" << p.mau;
}

void bai3() {
    PhanSo a, b;
    cin >> a.tu >> a.mau;
    cin >> b.tu >> b.mau;

    if (a.mau == 0 || b.mau == 0) {
        cout << "Khong hop le\n";
        return;
    }

    cout << "Tong: "; inPS(cong(a,b)); cout << endl;
    cout << "Hieu: "; inPS(tru(a,b)); cout << endl;
    cout << "Tich: "; inPS(nhan(a,b)); cout << endl;

    if (b.tu == 0) cout << "Thuong: Khong hop le\n";
    else {
        cout << "Thuong: ";
        inPS(chia(a,b));
        cout << endl;
    }
}

/* ================= BÀI 4 ================= */
struct Date {
    int d, m, y;
};

bool namNhuan(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int soNgay(int m, int y) {
    if (m == 1 || m == 3 || m == 5 || m == 7 ||
        m == 8 || m == 10 || m == 12) return 31;
    if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
    if (m == 2) return namNhuan(y) ? 29 : 28;
    return 0;
}

void bai4() {
    Date t;
    cin >> t.d >> t.m >> t.y;

    if (t.m < 1 || t.m > 12 || t.d < 1 || t.d > soNgay(t.m, t.y)) {
        cout << "Khong hop le\n";
        return;
    }

    t.d++;
    if (t.d > soNgay(t.m, t.y)) {
        t.d = 1;
        t.m++;
        if (t.m > 12) {
            t.m = 1;
            t.y++;
        }
    }

    cout << t.d << "/" << t.m << "/" << t.y << endl;
}

/* ================= BÀI 5 ================= */
struct HocSinh {
    string hoten;
    float toan, van;
};

void bai5() {
    HocSinh hs;
    getline(cin, hs.hoten);
    cin >> hs.toan >> hs.van;

    float dtb = (hs.toan + hs.van) / 2;

    cout << "Ho ten: " << hs.hoten << endl;
    cout << "Diem trung binh: " << fixed << setprecision(2) << dtb << endl;
}

/* ================= MAIN ================= */
int main() {

    bai1();
    bai2();
    bai3();
    bai4();
    bai5();

    return 0;
}
