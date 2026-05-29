#include <iostream>
#include <string>
#include <iomanip>
#define tri9 999

using namespace std;

class NhanVien{
    protected:
        string Hoten;
        int d, m, y;
    public:
        virtual void Nhap(){
            cin.ignore();
            cout << "Ho ten: ";
            getline(cin, Hoten);
            cout << "Ngay sinh (dd/ mm/ yy): ";
            cin >> d >> m >> y;
        }

        virtual void Xuat(){
            cout << Hoten << " | " << d << "/ " << m << "/ " << y;
        }

        virtual double Lidobandilam() = 0;  //Đây là lương

        virtual int GetLoai() = 0;

        virtual int GetNam() {  //Dùng để xác định nhân viên lớn tuổi nhất
            return y;
        }
        virtual ~NhanVien(){}
};

class NhanVienSX: public NhanVien{
    protected:
        int LuongBase;  // Lương cơ bản
        int SoSP;
    public:
        void Nhap(){
            NhanVien::Nhap();

            cout << "Luong can ban: ";
            cin >> LuongBase;
            cout << "So san pham: ";
            cin >> SoSP;
        }
        void Xuat(){
            NhanVien::Xuat();

            cout << " | So san pham: " << SoSP
            << " | Luong can ban: " << LuongBase
            << " | Luong: " << Lidobandilam();
        }
        double Lidobandilam(){
            return LuongBase + SoSP*5000;
        }
        int GetLoai(){
            return 1;
        }
};

class NhanVienVP: public NhanVien{
    protected:
        int SoNgayConTho;   // Số ngày làm việc
    public:
        void Nhap(){
            NhanVien::Nhap();

            cout << "So ngay lam viec: ";
            cin >> SoNgayConTho;
        }
        void Xuat(){
            NhanVien::Xuat();

            cout << " | So ngay lam viec: " << SoNgayConTho
            << " | Luong: " << Lidobandilam();
        }
        double Lidobandilam(){
            return SoNgayConTho *100000;
        }

        int GetLoai(){
            return 2;
        }
};

class DSNV{
    protected:
        NhanVien* ds[tri9];
        int n;
    public:
        void Nhap(){
            cout << "Nhap so nhan vien: ";
            cin >> n;

            for (int i = 0; i < n; i++){
            int toche; // Loại nhân viên

            cout << "1. Nhan vien san xuat\n";
            cout << "2. Nhan vien van phong\n";
            cout << "Chon loai: ";
            cin >> toche;

            if (toche == 1) {
                ds[i] = new NhanVienSX();
            }
            else {
                ds[i] = new NhanVienVP();
            }

            cout << "Nhap nhan vien thu " << i+1 <<": \n";
            ds[i]->Nhap();
            }
        }

        void Xuat(){
            cout << "\nDanh sach nhan vien:\n";
            for (int i = 0; i < n; i++) {
                ds[i]->Xuat();
                cout << endl;
            }
        }
        double HyperMuteki(){   // Tính tổng lương
            double Tong = 0;

            for(int i = 0; i < n; i++){
                Tong+= ds[i] -> Lidobandilam();
            }

            return Tong;
        }
        void NVSXLuongThapNhat() {

            int vitri = -1;

            for (int i = 0; i < n; i++) {

                if (ds[i]->GetLoai() == 1) {

                    if (vitri == -1 || ds[i]->Lidobandilam() < ds[vitri]->Lidobandilam()) {
                        vitri = i;
                    }
                }
            }

            if (vitri != -1) {

                cout << "\nNhan vien san xuat luong thap nhat:\n";

                ds[vitri]->Xuat();
                cout << endl;
            }
        }
        void NVVPLonTuoiNhat() {

            int vitri = -1;

            for (int i = 0; i < n; i++) {

                if (ds[i]->GetLoai() == 2) {

                    if (vitri == -1 || ds[i]->GetNam() < ds[vitri]->GetNam()) {
                        vitri = i;
                    }
                }
            }

            if (vitri != -1) {

                cout << "\nNhan vien van phong lon tuoi nhat:\n";

                ds[vitri]->Xuat();
                cout << endl;
            }
        }
        ~DSNV() {
            for (int i = 0; i < n; i++) {
                delete ds[i];
            }
        }
};

int main(){
    cout << fixed << setprecision(0);

    DSNV ds;

    ds.Nhap();
    ds.Xuat();

    cout << "Tong luong cong ty phai tra cho nhan vien: " << ds.HyperMuteki();

    ds.NVSXLuongThapNhat();
    ds.NVVPLonTuoiNhat();

    return 0;
}
