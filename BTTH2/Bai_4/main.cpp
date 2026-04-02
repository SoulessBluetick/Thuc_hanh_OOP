#include <iostream>
#include <iomanip>
using namespace std;

class GioPhutGiay {
private:
    int iGio, iPhut, iGiay;

    // Kiểm tra hợp lệ
    bool KiemTraHopLe() {
        return (iGio >= 0 && iGio < 24 &&
                iPhut >= 0 && iPhut < 60 &&
                iGiay >= 0 && iGiay < 60);
    }

public:
    // Nhập
    void Nhap() {
        do {
            cout << "Nhap gio: ";
            cin >> iGio;
            cout << "Nhap phut: ";
            cin >> iPhut;
            cout << "Nhap giay: ";
            cin >> iGiay;

            if (!KiemTraHopLe())
                cout << "Thoi gian khong hop le! Nhap lai.\n";
        } while (!KiemTraHopLe());
    }

    // Xuất (định dạng đẹp)
    void Xuat() {
        cout << setfill('0') << setw(2) << iGio << ":"
             << setw(2) << iPhut << ":"
             << setw(2) << iGiay;
    }

    // Cộng thêm 1 giây
    void TinhCongThemMotGiay() {
        iGiay++;

        if (iGiay == 60) {
            iGiay = 0;
            iPhut++;

            if (iPhut == 60) {
                iPhut = 0;
                iGio++;

                if (iGio == 24) {
                    iGio = 0;
                }
            }
        }
    }
};

int main() {
    GioPhutGiay t;

    cout << "Nhap thoi gian:\n";
    t.Nhap();

    cout << "Thoi gian ban dau: ";
    t.Xuat();

    t.TinhCongThemMotGiay();

    cout << "\nSau khi cong 1 giay: ";
    t.Xuat();

    return 0;
}
