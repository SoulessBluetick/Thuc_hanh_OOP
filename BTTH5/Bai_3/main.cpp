#include <iostream>
#include <string>
#include <iomanip>
#define tri9 999

using namespace std;

class SV{
protected:
    int MS, TongTC;
    double DTB;
    string namae, diachi;
public:
    virtual void Nhap(){
        cout << "Ma so sinh vien: ";
        cin >> MS;
        cin.ignore();
        cout << "Ho ten: ";
        getline(cin, namae);
        cout << "Dia chi: ";
        getline(cin, diachi);
        cout << "Tong so tin chi: ";
        cin >> TongTC;
        cout << "Diem trung binh: ";
        cin >> DTB;
    }
    virtual void Xuat(){
        cout << "MSSV: " << MS
        << " | Ho ten: " << namae
        << " | Dia chi: " << diachi
        << " | Tong so tin chi: " << TongTC
        << " | Diem trung binh: " << DTB;
    }

    virtual double GetDTB(){
        return DTB;
    }

    virtual int Getloai() = 0;

    virtual bool Decade() = 0;
    // Đây là hàm Xét tốt nghiệp
    // Trả về 1: Đủ điều kiện tốt nghiệp
    // Trả về 0: Không đủ điều kiện tốt nghiệp

    virtual ~SV(){}
};

class SVCD: public SV{  // Đây là lớp Sinh viên Cao đẳng
protected:
    double DTN; // Đây là Điểm thi tốt nghiệp
public:
    void Nhap(){
        SV::Nhap();

        cout << "Diem thi tot nghiep: ";
        cin >> DTN;
    }
    void Xuat(){
        SV::Xuat();

        cout << " | Diem thi tot nghiep: " << DTN << endl;
    }
    bool Decade(){
        if(TongTC >= 120 && DTB >= 5 && DTN >= 5)
            return 1;
        return 0;
    }

    int Getloai(){
        return 1;
    }
};

class SVDH: public SV{  // Đây là lớp Sinh viên Đại học
protected:
    double DLV; // Đây là Điểm Luận văn
    string TenLV;   // Đây là Tên Luận văn
public:
    void Nhap(){
        SV::Nhap();

        cin.ignore();
        cout << "Ten luan van: ";
        getline(cin, TenLV);
        cout << "Diem luan van: ";
        cin >> DLV;
    }
    void Xuat(){
        SV::Xuat();

        cout << " | Ten luan van: " << TenLV;
        cout << " | Diem luan van: " << DLV << endl;
    }
     bool Decade(){
        if(TongTC >= 170 && DTB >= 5 && DLV >= 5)
            return 1;
        return 0;
    }

    int Getloai(){
        return 2;
    }
};

class NgoiNhaThu2{
protected:
    SV* ds[tri9];
    int n;
public:
    void Nhap(){
        cout << "Nhap so sinh vien: ";
        cin >> n;

        for (int i = 0; i< n; i++){
            int loai;

            cout << "1. Sinh vien Cao dang\n";
            cout << "2. Sinh vien Dai hoc\n";
            cout << "Chon loai: ";
            cin >> loai;

            if (loai == 1)  ds[i] = new SVCD();
            else    ds[i] = new SVDH();
            cout << "Nhap sinh vien thu " << i+1 << ": " << endl;
            ds[i] -> Nhap();
        }
    }
    void Xuat (){
        cout << "\nDanh sach sinh vien\n";
        for (int i = 0; i < n; i++){
            ds[i] -> Xuat();
            cout << endl;
        }
    }
    void Ngu(){ // Đây là hàm Danh sách sinh viên không đủ điều kiện tốt nghiệp
        cout << "\nDanh sach sinh vien khong du dieu kien tot nghiep\n";
        for (int i = 0; i < n; i++){
            if (ds[i] -> Decade() == 0){
                ds[i] -> Xuat();
            }
        }
        cout << endl;
    }
    void Khon(){    // Đây là hàm Danh sách sinh viên đủ điều kiện tốt nghiệp
        cout << "\nDanh sach sinh vien du dieu kien tot nghiep\n";
        for (int i = 0; i < n; i++){
            if (ds[i] -> Decade() == 1){
                ds[i] -> Xuat();
            }
        }
        cout << endl;
    }

    void TayDH(){   // Đây là hàm Tìm và Xuất ra Sinh viên Đại học điểm cao nhất
        int diemCN = -1;
        for (int i = 0; i < n; i++){
            if (ds[i] -> Getloai() == 2){
                if (diemCN == -1 || ds[i] -> GetDTB() > ds[diemCN] -> GetDTB()){
                    diemCN = i;
                }
            }
        }
        if (diemCN != -1){
            cout << "\nSinh vien Dai hoc co diem cao nhat\n";
            ds[diemCN] -> Xuat();
            cout << endl;
        }
    }
    void TayCD(){   // Đây là hàm Tìm và Xuất ra Sinh viên Cao đẳng điểm cao nhất
        int diemCN = -1;
        for (int i = 0; i < n; i++){
            if (ds[i] -> Getloai() == 1){
                if (diemCN == -1 || ds[i] -> GetDTB() > ds[diemCN] -> GetDTB()){
                    diemCN = i;
                }
            }
        }
        if (diemCN != -1){
            cout << "\nSinh vien Cao dang co diem cao nhat\n";
            ds[diemCN] -> Xuat();
            cout << endl;
        }
    }
    void mayconga(){    // Đây là hàm Tìm và Xuất ra Danh sách các sinh viên CĐ/ ĐH rớt tốt nghiệp

        int c1 = 0;
        int c2 = 0;

        cout << "\nSo sinh vien Cao dang khong du dieu kien tot nghiep: ";
        for (int i = 0; i < n; i++){
            if(ds[i] -> Getloai() == 1){
                if (ds[i] -> Decade() == 0)
                    c1++;
            }
        }
        cout << c1 << endl;

        cout << "\nSo sinh vien Dai hoc khong du dieu kien tot nghiep: ";
        for (int i = 0; i < n; i++){
            if(ds[i] -> Getloai() == 2){
                if (ds[i] -> Decade() == 0)
                    c2++;
            }
        }
        cout << c2 << endl;
    }
};

int main(){
    cout << fixed << setprecision(0);

    NgoiNhaThu2 ds;

    ds.Nhap();
    ds.Xuat();

    ds.Ngu();
    ds.Khon();

    ds.TayDH();
    ds.TayCD();

    ds.mayconga();

return 0;
}
