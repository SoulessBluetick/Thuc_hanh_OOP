#include <iostream>
#include <cmath>

using namespace std;

class CVector {
private:
    int soChieu;
    float* data;

public:

    CVector(int n = 0) {

        if (n < 0)
            n = 0;

        soChieu = n;

        data = new float[soChieu];

        for (int i = 0; i < soChieu; i++)
            data[i] = 0;
    }

    CVector(const CVector& v) {

        soChieu = v.soChieu;

        data = new float[soChieu];

        for (int i = 0; i < soChieu; i++)
            data[i] = v.data[i];
    }

    ~CVector() {
        delete[] data;
    }

    CVector& operator = (const CVector& v) {

        if (this != &v) {

            delete[] data;

            soChieu = v.soChieu;

            data = new float[soChieu];

            for (int i = 0; i < soChieu; i++)
                data[i] = v.data[i];
        }

        return *this;
    }

    void Nhap() {

        do {

            cout << "Nhap so chieu: ";
            cin >> soChieu;

            if (soChieu <= 0)
                cout << "So chieu phai > 0!\n";

        } while (soChieu <= 0);

        delete[] data;

        data = new float[soChieu];

        for (int i = 0; i < soChieu; i++) {

            cout << "Phan tu [" << i << "] = ";
            cin >> data[i];
        }
    }

    void Xuat() const {

        cout << "(";

        for (int i = 0; i < soChieu; i++) {

            cout << data[i];

            if (i != soChieu - 1)
                cout << ", ";
        }

        cout << ")";
    }

    float DoDai() const {

        float tong = 0;

        for (int i = 0; i < soChieu; i++)
            tong += data[i] * data[i];

        return sqrt(tong);
    }

    CVector operator + (const CVector& v) const {

        if (soChieu != v.soChieu) {

            cout << "Khong cung so chieu!\n";
            return CVector();
        }

        CVector kq(soChieu);

        for (int i = 0; i < soChieu; i++)
            kq.data[i] = data[i] + v.data[i];

        return kq;
    }

    CVector operator - (const CVector& v) const {

        if (soChieu != v.soChieu) {

            cout << "Khong cung so chieu!\n";
            return CVector();
        }

        CVector kq(soChieu);

        for (int i = 0; i < soChieu; i++)
            kq.data[i] = data[i] - v.data[i];

        return kq;
    }

    float operator * (const CVector& v) const {

        if (soChieu != v.soChieu) {

            cout << "Khong cung so chieu!\n";
            return 0;
        }

        float tong = 0;

        for (int i = 0; i < soChieu; i++)
            tong += data[i] * v.data[i];

        return tong;
    }

    friend istream& operator >> (istream& in, CVector& v) {

        v.Nhap();

        return in;
    }

    friend ostream& operator << (ostream& out, const CVector& v) {

        v.Xuat();

        return out;
    }
};

int main() {

    CVector v1, v2;

    cout << "Nhap vector thu nhat:\n";
    cin >> v1;

    cout << "\nNhap vector thu hai:\n";
    cin >> v2;

    cout << "\nVector 1: " << v1;
    cout << "\nVector 2: " << v2;

    cout << "\n\nTong: "
         << v1 + v2;

    cout << "\nHieu: "
         << v1 - v2;

    cout << "\nTich vo huong: "
         << v1 * v2;

    cout << "\n\nDo dai vector 1: "
         << v1.DoDai();

    cout << "\nDo dai vector 2: "
         << v2.DoDai();

    return 0;
}
