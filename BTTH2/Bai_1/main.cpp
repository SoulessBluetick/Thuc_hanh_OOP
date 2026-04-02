#include <iostream>
using namespace std;

class NgayThangNam {
private:
    int iNgay, iThang, iNam;

    // Kiểm tra năm nhuận
    bool KiemTraNamNhuan() {
        return (iNam % 400 == 0 || (iNam % 4 == 0 && iNam % 100 != 0));
    }

    // Trả về số ngày trong tháng
    int SoNgayTrongThang() {
        switch (iThang) {
            case 1: case 3: case 5: case 7:
            case 8: case 10: case 12:
                if (iNgay > 31){
                    cout << "Ngay/ thang/ nam nay khong ton tai! \n";
                    return 0;
                }
                return 31;
            case 4: case 6: case 9: case 11:
                if (iNgay > 30){
                    cout << "Ngay/ thang/ nam nay khong ton tai! \n";
                    return 0;
                }
                return 30;
            case 2:
                if (KiemTraNamNhuan() != 29 || KiemTraNamNhuan() != 28){
                    cout << "Ngay/ thang/ nam nay khong ton tai! \n";
                    return 0;
                }
                else
                    return KiemTraNamNhuan() ? 29 : 28;
            default:
                cout << "Ngay/ thang/ nam nay khong ton tai! \n";
                return 0;
        }
    }

public:
    // Kiểm tra tính hợp lệ của ngày tháng năm
    bool NgayThangNamHopLe() {
        if (SoNgayTrongThang() == 0) return 0;
        return 1;
    }
    // Nhập ngày tháng năm
    void Nhap() {
        cout << "Nhap ngay: ";
        cin >> iNgay;
        cout << "Nhap thang: ";
        cin >> iThang;
        cout << "Nhap nam: ";
        cin >> iNam;
    }

    // Xuất ngày tháng năm
    void Xuat() {
        cout << iNgay << "/" << iThang << "/" << iNam << endl;
    }

    // Tính ngày tiếp theo
    void NgayThangNamTiepTheo() {
        iNgay++;

        if (iNgay > SoNgayTrongThang()) {
            iNgay = 1;
            iThang++;

            if (iThang > 12) {
                iThang = 1;
                iNam++;
            }
        }
    }
};

int main() {
    NgayThangNam d;

    cout << "Nhap ngay thang nam:\n";
    d.Nhap();

    cout << "Ngay vua nhap: ";
    d.Xuat();

    if (d.NgayThangNamHopLe() == 0) return 0;

    d.NgayThangNamTiepTheo();

    cout << "Ngay tiep theo: ";
    d.Xuat();

    return 0;
}
