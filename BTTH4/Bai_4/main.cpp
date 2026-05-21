#include <iostream>
#include <iomanip>

using namespace std;

class CDate {
private:
    int iNgay, iThang, iNam;

public:

    CDate(int ngay = 1, int thang = 1, int nam = 2000) {
        iNgay = ngay;
        iThang = thang;
        iNam = nam;
    }

    bool KiemTraNamNhuan() const {

        return (iNam % 400 == 0) || (iNam % 4 == 0 && iNam % 100 != 0);
    }

    int SoNgayTrongThang() const {

        int ngayThang[] = {31,28,31,30,31,30,31,31,30,31,30,31};

        if (iThang == 2 && KiemTraNamNhuan())
            return 29;

        return ngayThang[iThang - 1];
    }

    bool HopLe() const {

        if (iNam < 1)
            return false;

        if (iThang < 1 || iThang > 12)
            return false;

        if (iNgay < 1 || iNgay > SoNgayTrongThang())
            return false;

        return true;
    }

    CDate& operator ++ () {

        iNgay++;

        if (iNgay > SoNgayTrongThang()) {

            iNgay = 1;
            iThang++;

            if (iThang > 12) {
                iThang = 1;
                iNam++;
            }
        }

        return *this;
    }

    CDate& operator -- () {

        iNgay--;

        if (iNgay < 1) {

            iThang--;

            if (iThang < 1) {
                iThang = 12;
                iNam--;
            }

            int ngayThang[] = {31,28,31,30,31,30,31,31,30,31,30,31};

            iNgay = ngayThang[iThang - 1];

            if (iThang == 2 && KiemTraNamNhuan())
                iNgay = 29;
        }

        return *this;
    }

    CDate operator + (int n) const {

        CDate kq = *this;

        for (int i = 0; i < n; i++)
            ++kq;

        return kq;
    }

    CDate operator - (int n) const {

        CDate kq = *this;

        for (int i = 0; i < n; i++)
            --kq;

        return kq;
    }

    int ToDays() const {

        int tong = 0;

        for (int nam = 1; nam < iNam; nam++) {

            if ((nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0))
                tong += 366;
            else
                tong += 365;
        }

        int ngayThang[] = {31,28,31,30,31,30,31,31,30,31,30,31};

        for (int thang = 1; thang < iThang; thang++) {

            if (thang == 2 && KiemTraNamNhuan())
                tong += 29;
            else
                tong += ngayThang[thang - 1];
        }

        tong += iNgay;

        return tong;
    }

    int operator - (const CDate& other) const {

        int d1 = ToDays();
        int d2 = other.ToDays();

        return abs(d1 - d2);
    }

    friend istream& operator >> (istream& in, CDate& d) {

        do {

            cout << "Nhap ngay: ";
            in >> d.iNgay;

            cout << "Nhap thang: ";
            in >> d.iThang;

            cout << "Nhap nam: ";
            in >> d.iNam;

            if (!d.HopLe())
                cout << "Ngay khong hop le! Nhap lai.\n";

        } while (!d.HopLe());

        return in;
    }

    friend ostream& operator << (ostream& out, const CDate& d) {

        out << setfill('0');

        out << setw(2) << d.iNgay << "/";
        out << setw(2) << d.iThang << "/";
        out << setw(4) << d.iNam;

        return out;
    }
};

int main() {

    CDate d1, d2;

    cout << "Nhap ngay thu nhat:\n";
    cin >> d1;

    cout << "\nNhap ngay thu hai:\n";
    cin >> d2;

    cout << "\nNgay 1: " << d1;
    cout << "\nNgay 2: " << d2;

    cout << "\n\nNgay 1 + 30 ngay: "
         << d1 + 30;

    cout << "\nNgay 1 - 15 ngay: "
         << d1 - 15;

    ++d1;
    cout << "\n\nSau ++d1: "
         << d1;

    --d1;
    cout << "\nSau --d1: "
         << d1;

    cout << "\n\nKhoang cach 2 ngay: "
         << d1 - d2
         << " ngay";

    return 0;
}
