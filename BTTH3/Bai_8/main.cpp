#include <iostream>
#include <string>
using namespace std;

class cNhanVienSX {
private:
    string ma, hoten;
    int ngay, thang, nam;
    int soSP;
    double donGia;

public:
    // Constructor
    cNhanVienSX() {
        ma = "";
        hoten = "";
        ngay = thang = nam = 0;
        soSP = 0;
        donGia = 0;
    }

    // Nhập
    void Nhap() {
        cin.ignore();
        cout << "Ma NV: ";
        getline(cin, ma);
        cout << "Ho ten: ";
        getline(cin, hoten);
        cout << "Ngay sinh (dd mm yyyy): ";
        cin >> ngay >> thang >> nam;
        cout << "So san pham: ";
        cin >> soSP;
        cout << "Don gia: ";
        cin >> donGia;
    }

    // Xuất
    void Xuat() {
        cout << ma << " | " << hoten << " | "
             << ngay << "/" << thang << "/" << nam
             << " | SP: " << soSP
             << " | Don gia: " << donGia
             << " | Luong: " << TinhLuong() << endl;
    }

    // Tính lương
    double TinhLuong() {
        return soSP * donGia;
    }

    // Lấy năm sinh
    int GetNam() {
        return nam;
    }
};

int main() {
    int n;
    cout << "Nhap so nhan vien: ";
    cin >> n;

    cNhanVienSX ds[100];

    // Nhập danh sách
    for (int i = 0; i < n; i++) {
        cout << "\nNhap NV thu " << i + 1 << ":\n";
        ds[i].Nhap();
    }

    // Xuất danh sách
    cout << "\nDanh sach nhan vien:\n";
    for (int i = 0; i < n; i++) {
        ds[i].Xuat();
    }

    // NV lương thấp nhất
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (ds[i].TinhLuong() < ds[minIndex].TinhLuong()) {
            minIndex = i;
        }
    }
    cout << "\nNhan vien luong thap nhat:\n";
    ds[minIndex].Xuat();

    // Tổng lương
    double tong = 0;
    for (int i = 0; i < n; i++) {
        tong += ds[i].TinhLuong();
    }
    cout << "\nTong luong cong ty phai tra: " << tong << endl;

    // NV lớn tuổi nhất (năm sinh nhỏ nhất)
    int maxAgeIndex = 0;
    for (int i = 1; i < n; i++) {
        if (ds[i].GetNam() < ds[maxAgeIndex].GetNam()) {
            maxAgeIndex = i;
        }
    }
    cout << "\nNhan vien lon tuoi nhat:\n";
    ds[maxAgeIndex].Xuat();

    // Sắp xếp tăng dần theo lương
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].TinhLuong() > ds[j].TinhLuong()) {
                swap(ds[i], ds[j]);
            }
        }
    }

    cout << "\nDanh sach sau khi sap xep tang dan theo luong:\n";
    for (int i = 0; i < n; i++) {
        ds[i].Xuat();
    }

    return 0;
}
