#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

class cArray {
private:
    int n;
    int a[100];

    // Hàm kiểm tra số nguyên tố
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i <= sqrt(x); i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

public:
    void TaoNgauNhien() {
        cout << "Nhap so phan tu n: ";
        cin >> n;

        srand(time(0));
        for (int i = 0; i < n; i++) {
            a[i] = rand() % 100; // 0 -> 99
        }
    }

    void Xuat() {
        cout << "Mang: ";
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    int DemX(int x) {
        int dem = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == x) dem++;
        }
        return dem;
    }

    bool TangDan() {
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) return false;
        }
        return true;
    }

    int LeNhoNhat() {
        int minLe = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 != 0) {
                if (minLe == -1 || a[i] < minLe)
                    minLe = a[i];
            }
        }
        return minLe;
    }

    int SNTLonNhat() {
        int maxPrime = -1;
        for (int i = 0; i < n; i++) {
            if (isPrime(a[i])) {
                if (a[i] > maxPrime)
                    maxPrime = a[i];
            }
        }
        return maxPrime;
    }

    void SapXepTang() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] > a[j]) {
                    swap(a[i], a[j]);
                }
            }
        }
    }

    void SapXepGiam() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] < a[j]) {
                    swap(a[i], a[j]);
                }
            }
        }
    }
};

int main() {
    cArray arr;

    arr.TaoNgauNhien();
    arr.Xuat();

    int x;
    cout << "Nhap gia tri x: ";
    cin >> x;
    cout << "So lan xuat hien: " << arr.DemX(x) << endl;

    if (arr.TangDan())
        cout << "Mang tang dan\n";
    else
        cout << "Mang khong tang dan\n";

    int minLe = arr.LeNhoNhat();
    if (minLe == -1)
        cout << "Khong co so le\n";
    else
        cout << "So le nho nhat: " << minLe << endl;

    int maxPrime = arr.SNTLonNhat();
    if (maxPrime == -1)
        cout << "Khong co so nguyen to\n";
    else
        cout << "So nguyen to lon nhat: " << maxPrime << endl;

    cout << "\nSap xep tang:\n";
    arr.SapXepTang();
    arr.Xuat();

    cout << "\nSap xep giam:\n";
    arr.SapXepGiam();
    arr.Xuat();

    return 0;
}
