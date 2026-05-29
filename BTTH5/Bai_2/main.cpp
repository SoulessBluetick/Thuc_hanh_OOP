#include <iostream>
#include <string>
#include <iomanip>
#define tri9 999

using namespace std;

class BatDongSan{
protected:
    int MaGD, DonGia, DienTich;
    int d, m, y;
public:
    virtual void Nhap(){
        cout << "Ma giao dich: ";
        cin >> MaGD;
        cout << "Ngay giao dich: ";
        cin >> d >> m >> y;
        cout << "Don gia: ";
        cin >> DonGia;
        cout << "Dien tich: ";
        cin >> DienTich;
    }
    virtual void Xuat(){
        cout << "Ma giao dich: " << MaGD << "\n";
        cout << "Ngay giao dich: " << d << "/ " << m << "/ "<< y << "\n";
        cout << "Don gia: " << DonGia << "\n";
        cout << "Dien tich: " << DienTich << "\n";
    }
    virtual double Herecomesdamoney() = 0;  // Đây là Thành tiền

    virtual int GetKind() = 0;  // Đây là Get loại

    virtual int GetY(){ // Đây là Get năm, dùng để thực hiện 1 trong những yêu cầu bài
        return y;
    }

    virtual int GetM(){ // Đây là Get tháng, dùng để thực hiện 1 trong những yêu cầu bài
        return m;
    }

    virtual ~ BatDongSan(){}
};

class Agito: public BatDongSan{ // Đây là lớp Giao dịch Đất
protected:
    char AgitoForm; // Đây là thông tin về Loại đất
public:
    void Nhap(){
        BatDongSan::Nhap();

        cout << "Loai dat: ";
        cin >> AgitoForm;
    }
    void Xuat(){
        BatDongSan::Xuat();

        cout << "Loai dat: " << AgitoForm << "\n";
        cout << "Thanh tien: " << Herecomesdamoney() << endl;
        }

    double Herecomesdamoney(){
        if (AgitoForm == 'A')   return DienTich * DonGia * 1.5;
        else    return DienTich * DonGia;
    }

    int GetKind(){
        return 1;
    }
};

class ZeroOne: public BatDongSan{   // Đây là lớp Giao dịch Nhà Phố
protected:
    int ProgriseKey;    // Đây là thông tin về Loại nhà
public:
    void Nhap(){
        BatDongSan::Nhap();

        cout << "Loai nha:\n"
        <<"1. Cao cap\n"
        <<"2. Thuong\n"
        << "Chon loai: ";
        cin >> ProgriseKey;
    }
    void Xuat(){
        BatDongSan::Xuat();

        cout << "Loai nha: ";
        if (ProgriseKey == 1)  cout << "Cao cap\n";
        else if(ProgriseKey == 2) cout << "Thuong\n";
        cout << "Thanh tien: " << Herecomesdamoney() << endl;
    }

    double Herecomesdamoney(){
        if (ProgriseKey == 1)   return DienTich * DonGia;
        return DienTich * DonGia * 0.9;
    }
    int GetKind(){
        return 2;
    }
};

class Ryuki: public BatDongSan{ // Đây là lớp Giao dịch Căn hộ chung cư
protected:
    string MaCan;
    int ViTriTang;
public:
    void Nhap(){
        BatDongSan::Nhap();

        cin.ignore();
        cout << "Ma can: ";
        getline(cin, MaCan);

        cout << "Vi tri tang: ";
        cin >> ViTriTang;
    }
    void Xuat(){
        BatDongSan::Xuat();

        cout << "Ma can: " << MaCan << "\n";
        cout << "Vi tri tang: " << ViTriTang << "\n";
        cout << "Thanh tien: " << Herecomesdamoney() << endl;
    }

    double Herecomesdamoney(){
        if (ViTriTang == 1)   return DienTich * DonGia * 2;
        else if(ViTriTang >= 15)    return DienTich * DonGia * 1.2;
        else    return DienTich * DonGia;
    }
    int GetKind(){
        return 3;
    }
};

class VakaLand{
protected:
    BatDongSan* ds[tri9];
    int n;
    int c1 = 0, c2 = 0, c3 = 0;
    // Đây là các biến đếm dùng để đếm loại giao dịch
    // Lần lượt là count1: Giao dịch đất, count2: Giao dịch Nhà phố, count3: Giao dịch Căn hộ chung cư
public:
    void Nhap(){
        cout << "Nhap so giao dich: ";
        cin >> n;

        for(int i = 0; i < n; i++){
            int kind;

            cout << "1. Giao dich Dat\n";
            cout << "2. Giao dich Nha pho\n";
            cout << "3. Giao dich Can ho chung cu\n";
            cout << "Chon loai: ";
            cin >> kind;

            if (kind == 1){
                ds[i] = new Agito();
                c1++;
            }
            if (kind == 2){
                ds[i] = new ZeroOne();
                c2++;
            }
            if (kind == 3){
                ds[i] = new Ryuki();
                c3++;
            }
            cout << "Nhap giao dich thu " << i+1 <<": \n";
            ds[i] -> Nhap();
        }
    }
    void Xuat(){
        cout << "\nDanh sach giao dich\n";
        for(int i = 0; i < n; i++){
            ds[i] -> Xuat();
            cout << endl;
        }
    }
    void TongSoGiaoDich(){
        cout << "So giao dich Dat: " << c1 << endl;
        cout << "So giao dich Nha pho: " << c2 << endl;
        cout << "So giao dich Can ho chung cu: " << c3 << endl;
    }
    double TBRyuki(){   // Đây là hàm tính Trung bình Thành tiền của Giao dịch Căn hộ chung cư
        double TongRyuki = 0;   // Đây là hàm tính Tổng Thành tiền của Giao dịch Căn hộ chung cư
        for (int i = 0; i < n; i++){
            if (ds[i]->GetKind() == 3){
                TongRyuki += ds[i] -> Herecomesdamoney();
            }
        }
        if (c3 == 0)    return 0;
        return TongRyuki / c3;
    }
    void ZeroTwo(){ // Đây là hàm tìm Giao dịch Nhà phố có giá trị (Thành tiền) cao nhất
        int Izu = -1;   // Đây là biến để gán giá trị max
        for (int i = 0; i < n; i++){
            if (ds[i] -> GetKind() == 2){
                if (Izu == -1 || ds[i] -> Herecomesdamoney() > ds[Izu] -> Herecomesdamoney()){
                    Izu = i;
                }
            }
        }
        if (Izu != -1){
            cout << "Giao dich Nha pho co gia tri cao nhat:\n";
            ds[Izu] -> Xuat();
            cout << endl;
        }
    }
    void Sybau(){   // Đây là hàm để tìm và xuất danh sách các Giao dịch của tháng 12 năm 2024
        cout << "\nDanh sach cac giao dich cua thang 12 nam 2024\n";
        for (int i = 0; i < n; i++){
            if (ds[i] -> GetY() == 2024 && ds[i] -> GetM() == 12){
                ds[i] -> Xuat();
            }
        }
        cout << endl;
    }
    ~VakaLand() {
        for (int i = 0; i < n; i++) {
            delete ds[i];
        }
    }
};

int main(){
    cout << fixed << setprecision(0);

    VakaLand ds;

    ds.Nhap();
    ds.Xuat();

    ds.TongSoGiaoDich();
    cout << "Trung binh thanh tien cua giao dich Can ho chung cu: " << ds.TBRyuki() << endl;
    ds.ZeroTwo();
    ds.Sybau();

return 0;
}
