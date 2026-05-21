#include <iostream>
#include <iomanip>

using namespace std;

class CTime {
private:
    int iGio, iPhut, iGiay;

public:
    CTime(int gio = 0, int phut = 0, int giay = 0) {

        iGio = gio;
        iPhut = phut;
        iGiay = giay;

        ChuanHoa();
    }

    void ChuanHoa() {

        int tongGiay = iGio * 3600 + iPhut * 60 + iGiay;

        tongGiay = ((tongGiay % 86400) + 86400) % 86400;

        iGio = tongGiay / 3600;
        tongGiay %= 3600;

        iPhut = tongGiay / 60;
        iGiay = tongGiay % 60;
    }

    CTime operator + (int giay) {

        CTime kq(iGio, iPhut, iGiay + giay);

        kq.ChuanHoa();

        return kq;
    }

    CTime operator - (int giay) {

        CTime kq(iGio, iPhut, iGiay - giay);

        kq.ChuanHoa();

        return kq;
    }

    CTime operator ++ () {

        iGiay++;
        ChuanHoa();

        return *this;
    }

    CTime operator -- () {

        iGiay--;
        ChuanHoa();

        return *this;
    }

    friend istream& operator >> (istream& in, CTime& t) {

        cout << "Nhap gio: ";
        in >> t.iGio;

        cout << "Nhap phut: ";
        in >> t.iPhut;

        cout << "Nhap giay: ";
        in >> t.iGiay;

        t.ChuanHoa();

        return in;
    }

    friend ostream& operator << (ostream& out, CTime t) {

        out << setfill('0')
            << setw(2) << t.iGio << ":"
            << setw(2) << t.iPhut << ":"
            << setw(2) << t.iGiay;

        return out;
    }
};

int main() {

    CTime t;

    cin >> t;

    cout << "\nThoi gian vua nhap: " << t;

    cout << "\n\nCong 5000 giay: " << t + 5000;

    cout << "\nTru 3000 giay: " << t - 3000;

    ++t;
    cout << "\n\nSau ++t: " << t;

    --t;
    cout << "\nSau --t: " << t;

    return 0;
}
