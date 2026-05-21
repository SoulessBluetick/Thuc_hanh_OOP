#include <iostream>
#include <cmath>

using namespace std;

class CDaThuc {
private:
    int bac;
    float* heSo;

public:
    CDaThuc(int b = 0) {

        bac = b;

        heSo = new float[bac + 1];

        for (int i = 0; i <= bac; i++)
            heSo[i] = 0;
    }

    CDaThuc(const CDaThuc& dt) {

        bac = dt.bac;

        heSo = new float[bac + 1];

        for (int i = 0; i <= bac; i++)
            heSo[i] = dt.heSo[i];
    }

    ~CDaThuc() {
        delete[] heSo;
    }

    CDaThuc& operator = (const CDaThuc& dt) {

        if (this == &dt)
            return *this;

        delete[] heSo;

        bac = dt.bac;

        heSo = new float[bac + 1];

        for (int i = 0; i <= bac; i++)
            heSo[i] = dt.heSo[i];

        return *this;
    }

    void ChuanHoa() {

        while (bac > 0 && heSo[bac] == 0)
            bac--;
    }

    void Nhap() {

        cout << "Nhap bac da thuc: ";
        cin >> bac;

        delete[] heSo;

        heSo = new float[bac + 1];

        for (int i = bac; i >= 0; i--) {

            cout << "He so x^" << i << ": ";
            cin >> heSo[i];
        }

        ChuanHoa();
    }

    void Xuat() const {

        bool first = true;

        for (int i = bac; i >= 0; i--) {

            if (heSo[i] == 0)
                continue;

            if (!first) {

                if (heSo[i] > 0)
                    cout << " + ";
                else
                    cout << " - ";
            }
            else {

                if (heSo[i] < 0)
                    cout << "-";
            }

            float value = abs(heSo[i]);

            if (i == 0) {

                cout << value;
            }

            else if (i == 1) {

                if (value != 1)
                    cout << value;

                cout << "x";
            }

            else {

                if (value != 1)
                    cout << value;

                cout << "x^" << i;
            }

            first = false;
        }

        if (first)
            cout << "0";
    }

    float GiaTri(float x) const {

        float tong = 0;

        for (int i = 0; i <= bac; i++)
            tong += heSo[i] * pow(x, i);

        return tong;
    }

    CDaThuc operator + (const CDaThuc& dt) const {

        int maxBac = (bac > dt.bac) ? bac : dt.bac;

        CDaThuc kq(maxBac);

        for (int i = 0; i <= maxBac; i++) {

            float a = (i <= bac) ? heSo[i] : 0;

            float b = (i <= dt.bac) ? dt.heSo[i] : 0;

            kq.heSo[i] = a + b;
        }

        kq.ChuanHoa();

        return kq;
    }

    CDaThuc operator - (const CDaThuc& dt) const {

        int maxBac = (bac > dt.bac) ? bac : dt.bac;

        CDaThuc kq(maxBac);

        for (int i = 0; i <= maxBac; i++) {

            float a = (i <= bac) ? heSo[i] : 0;

            float b = (i <= dt.bac) ? dt.heSo[i] : 0;

            kq.heSo[i] = a - b;
        }

        kq.ChuanHoa();

        return kq;
    }

    CDaThuc operator * (const CDaThuc& dt) const {

        CDaThuc kq(bac + dt.bac);

        for (int i = 0; i <= bac; i++) {

            for (int j = 0; j <= dt.bac; j++) {

                kq.heSo[i + j] += heSo[i] * dt.heSo[j];
            }
        }

        kq.ChuanHoa();

        return kq;
    }

    friend istream& operator >> (istream& in, CDaThuc& dt) {

        dt.Nhap();

        return in;
    }

    friend ostream& operator << (ostream& out, const CDaThuc& dt) {

        dt.Xuat();

        return out;
    }
};

int main() {

    CDaThuc dt1, dt2;

    cout << "Nhap da thuc thu nhat:\n";
    cin >> dt1;

    cout << "\nNhap da thuc thu hai:\n";
    cin >> dt2;

    cout << "\nDa thuc 1: "
         << dt1;

    cout << "\nDa thuc 2: "
         << dt2;

    cout << "\n\nTong: "
         << dt1 + dt2;

    cout << "\nHieu: "
         << dt1 - dt2;

    cout << "\nTich: "
         << dt1 * dt2;

    float x;

    cout << "\n\nNhap x: ";
    cin >> x;

    cout << "P1(" << x << ") = "
         << dt1.GiaTri(x);

    return 0;
}
