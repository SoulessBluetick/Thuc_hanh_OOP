#include <iostream>
#include <string>
#include <iomanip>
#define tri9 999

using namespace std;

class NhanVien{
protected:
    int MaNV, tuoi;
    double LuongBase;   // Đây là Lương cơ bản
    string Hoten, email, sdt;
public:
    virtual void Nhap(){

    cin.ignore();

    cout << "Ma nhan vien: ";
    cin >> MaNV;

    cin.ignore();

    cout << "Ho ten: ";
    getline(cin, Hoten);

    cout << "Tuoi: ";
    cin >> tuoi;

    cin.ignore();

    cout << "So dien thoai: ";
    getline(cin, sdt);

    cout << "Email: ";
    getline(cin, email);

    cout << "Luong co ban: ";
    cin >> LuongBase;
}
    virtual void Xuat(){
        cout << "Ma nhan vien: " << MaNV
        << " | Ho ten: " << Hoten
        << " | Tuoi: " << tuoi
        << " | So dien thoai: " << sdt
        << " | Email: " << email
        << " | Luong co ban: " << LuongBase;
    }
    virtual int Getloai() =0;

    virtual double GetLuongBase(){return LuongBase;}

    virtual double comaogaotien() = 0;  // Đây là Lương

    virtual ~NhanVien(){}
};

class Larper: public NhanVien{  // Đây là lớp Lập trình viên
protected:
    double OTHours;
public:
    void Nhap(){
        NhanVien::Nhap();

        cout << "So gio overtime: ";
        cin >> OTHours;
    }
    void Xuat(){
        NhanVien::Xuat();

        cout << " | So gio overtime: " << OTHours <<endl;
    }

    int Getloai(){
        return 1;
    }

    double comaogaotien(){
        return LuongBase + OTHours * 200000;
    }
};

class Checker: public NhanVien{ // Đây là lớp Kiểm chứng viên
protected:
    double ErrorHasse;  // Đây là số lỗi phát hiện được
public:
    void Nhap(){
        NhanVien::Nhap();

        cout << "So loi phat hien duoc: ";
        cin >> ErrorHasse;
    }
    void Xuat(){
        NhanVien::Xuat();

        cout << " | So loi phat hien duoc: " << ErrorHasse << endl;
    }

    int Getloai(){
        return 2;
    }

    double comaogaotien(){
        return LuongBase + ErrorHasse * 50000;
    }
};

class TuBan{
protected:
    NhanVien* ds[tri9];
    int n;
public:
    void Nhap(){
        cout << "So luong nhan vien: ";
        cin >> n;

        int loai;
        for (int i = 0; i < n; i++){
            cout << "1. Lap trinh vien\n";
            cout << "2. Kiem chung vien\n";
            cout << "Chon loai nhan vien: ";
            cin >> loai;

            if (loai == 1) ds[i] = new Larper();
            else    ds[i] = new Checker();
            cout << "Nhan vien thu " << i+1 << ": \n";
            ds[i] -> Nhap();
        }
    }
    void Xuat(){
        cout << "\nDanh sach nhan vien\n";
        for (int i = 0; i < n; i++){
            ds[i] -> Xuat();
            cout << endl;
        }
    }
    void maycongaLuongTBthap(){ // Đây là hàm tạo Danh sách các Nhân viên có Lương thấp hơn mức trung bình
        double LuongTong = 0;
        for (int i = 0; i < n; i++){
            LuongTong += ds[i] -> comaogaotien();
        }
        double  LuongTB = LuongTong / n;
        cout << "\nDanh sach cac nhan vien co luong thap hon muc trung binh\n";
        for (int i = 0; i< n; i++){
            if (ds[i] -> comaogaotien() < LuongTB)
                ds[i] -> Xuat();
            cout << endl;
        }
    }
    void nguoitay(){    // Đây là hàm tìm Nhân viên lương cao nhất
        int cownhan = -1;   // Đây là biến gán giá trị max
        for (int i = 0; i< n; i++){
            if (cownhan == -1 || ds[i] -> comaogaotien() > ds[cownhan] -> comaogaotien()){
                cownhan = i;
            }
        }
        if (cownhan != -1){
            cout << "\nNhan vien co luong cao nhat\n";
            ds[cownhan] -> Xuat();
            cout << endl;
        }
    }
    void conga(){   // Đây là hàm tìm Nhân viên lương thấp nhất
    int noob = -1;  // Đây là biến gán giá trị min
        for (int i = 0; i< n; i++){
            if (noob == -1 || ds[i] -> comaogaotien() < ds[noob] -> comaogaotien()){
                noob = i;
            }
        }
        if (noob != -1){
            cout << "\nNhan vien co luong thap nhat\n";
            ds[noob] -> Xuat();
            cout << endl;
        }
    }

    void nguoitayLarper(){  // Đây là hàm tìm Lập trình viên lương cao nhất
        int cownhanLarper = -1; // Đây là biến gán giá trị max
        for (int i = 0; i< n; i++){
            if (ds[i] -> Getloai() == 1){
                if (cownhanLarper == -1 || ds[i] -> comaogaotien() > ds[cownhanLarper] -> comaogaotien()){
                cownhanLarper = i;
                }
            }
        }
        if (cownhanLarper != -1){
            cout << "\nLap trinh vien co luong cao nhat\n";
            ds[cownhanLarper] -> Xuat();
            cout << endl;
        }
    }
    void congaChecker(){    // Đây là hàm tìm Kiểm chứng viên lương thấp nhất
        int noobChecker = -1;   // Đây là biến gán giá trị min
        for (int i = 0; i< n; i++){
            if (ds[i] -> Getloai() == 2){
                if (noobChecker == -1 || ds[i] -> comaogaotien() < ds[noobChecker] -> comaogaotien()){
                noobChecker = i;
                }
            }
        }
        if (noobChecker != -1){
            cout << "\nKiem chung vien co luong thap nhat\n";
            ds[noobChecker] -> Xuat();
            cout << endl;
        }
    }

    ~TuBan(){
        for (int i = 0; i < n; i++) {
            delete ds[i];
        }
    }
};

int main(){
    cout << fixed << setprecision(0);

    TuBan ds;

    ds.Nhap();
    ds.Xuat();

    ds.maycongaLuongTBthap();
    ds.nguoitay();
    ds.conga();
    ds.nguoitayLarper();
    ds.congaChecker();

return 0;
}
