#include <iostream>

using namespace std;

class CVector {
private:
    int n;
    float* data;

public:

    CVector(int size = 0) {

        if (size < 0)
            size = 0;

        n = size;

        data = new float[n];

        for (int i = 0; i < n; i++)
            data[i] = 0;
    }

    CVector(const CVector& v) {

        n = v.n;

        data = new float[n];

        for (int i = 0; i < n; i++)
            data[i] = v.data[i];
    }

    ~CVector() {
        delete[] data;
    }

    CVector& operator = (const CVector& v) {

        if (this != &v) {

            delete[] data;

            n = v.n;

            data = new float[n];

            for (int i = 0; i < n; i++)
                data[i] = v.data[i];
        }

        return *this;
    }

    void Nhap() {

        do {

            cout << "Nhap so chieu: ";
            cin >> n;

            if (n <= 0)
                cout << "So chieu phai > 0!\n";

        } while (n <= 0);

        delete[] data;

        data = new float[n];

        for (int i = 0; i < n; i++) {

            cout << "data[" << i << "] = ";
            cin >> data[i];
        }
    }

    void Xuat() const {

        cout << "(";

        for (int i = 0; i < n; i++) {

            cout << data[i];

            if (i != n - 1)
                cout << ", ";
        }

        cout << ")";
    }

    int GetN() const {
        return n;
    }

    float GetValue(int i) const {
        return data[i];
    }

    void SetValue(int i, float value) {
        data[i] = value;
    }

    friend ostream& operator << (ostream& out, const CVector& v) {

        v.Xuat();
        return out;
    }

    friend istream& operator >> (istream& in, CVector& v) {

        v.Nhap();
        return in;
    }
};

class CMatrix {
private:
    int rows, cols;
    float** data;

public:

    CMatrix(int r = 0, int c = 0) {

        if (r < 0)
            r = 0;

        if (c < 0)
            c = 0;

        rows = r;
        cols = c;

        data = new float*[rows];

        for (int i = 0; i < rows; i++) {

            data[i] = new float[cols];

            for (int j = 0; j < cols; j++)
                data[i][j] = 0;
        }
    }

    CMatrix(const CMatrix& m) {

        rows = m.rows;
        cols = m.cols;

        data = new float*[rows];

        for (int i = 0; i < rows; i++) {

            data[i] = new float[cols];

            for (int j = 0; j < cols; j++)
                data[i][j] = m.data[i][j];
        }
    }

    ~CMatrix() {

        for (int i = 0; i < rows; i++)
            delete[] data[i];

        delete[] data;
    }

    CMatrix& operator = (const CMatrix& m) {

        if (this != &m) {

            for (int i = 0; i < rows; i++)
                delete[] data[i];

            delete[] data;

            rows = m.rows;
            cols = m.cols;

            data = new float*[rows];

            for (int i = 0; i < rows; i++) {

                data[i] = new float[cols];

                for (int j = 0; j < cols; j++)
                    data[i][j] = m.data[i][j];
            }
        }

        return *this;
    }

    void Nhap() {

        do {

            cout << "Nhap so dong: ";
            cin >> rows;

            if (rows <= 0)
                cout << "So dong phai > 0!\n";

        } while (rows <= 0);

        do {

            cout << "Nhap so cot: ";
            cin >> cols;

            if (cols <= 0)
                cout << "So cot phai > 0!\n";

        } while (cols <= 0);

        for (int i = 0; i < rows; i++)
            delete[] data[i];

        delete[] data;

        data = new float*[rows];

        for (int i = 0; i < rows; i++) {

            data[i] = new float[cols];

            for (int j = 0; j < cols; j++) {

                cout << "data[" << i
                     << "][" << j
                     << "] = ";

                cin >> data[i][j];
            }
        }
    }

    void Xuat() const {

        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++)
                cout << data[i][j] << "\t";

            cout << endl;
        }
    }

    CMatrix operator + (const CMatrix& m) const {

        if (rows != m.rows || cols != m.cols) {

            cout << "Khong cung kich thuoc!\n";
            return CMatrix();
        }

        CMatrix kq(rows, cols);

        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++)
                kq.data[i][j] = data[i][j] + m.data[i][j];
        }

        return kq;
    }

    CMatrix operator - (const CMatrix& m) const {

        if (rows != m.rows || cols != m.cols) {

            cout << "Khong cung kich thuoc!\n";
            return CMatrix();
        }

        CMatrix kq(rows, cols);

        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++)
                kq.data[i][j] = data[i][j] - m.data[i][j];
        }

        return kq;
    }

    CVector operator * (const CVector& v) const {

        if (cols != v.GetN()) {

            cout << "Khong nhan duoc!\n";
            return CVector();
        }

        CVector kq(rows);

        for (int i = 0; i < rows; i++) {

            float tong = 0;

            for (int j = 0; j < cols; j++)
                tong += data[i][j] * v.GetValue(j);

            kq.SetValue(i, tong);
        }

        return kq;
    }

    CMatrix operator * (const CMatrix& m) const {

        if (cols != m.rows) {

            cout << "Khong nhan duoc!\n";
            return CMatrix();
        }

        CMatrix kq(rows, m.cols);

        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < m.cols; j++) {

                float tong = 0;

                for (int k = 0; k < cols; k++)
                    tong += data[i][k] * m.data[k][j];

                kq.data[i][j] = tong;
            }
        }

        return kq;
    }

    friend istream& operator >> (istream& in, CMatrix& m) {

        m.Nhap();
        return in;
    }

    friend ostream& operator << (ostream& out, const CMatrix& m) {

        m.Xuat();
        return out;
    }
};

int main() {

    CMatrix A, B;
    CVector V;

    cout << "Nhap ma tran A:\n";
    cin >> A;

    cout << "\nNhap ma tran B:\n";
    cin >> B;

    cout << "\nNhap vector V:\n";
    cin >> V;

    cout << "\nMa tran A:\n"
         << A;

    cout << "\nMa tran B:\n"
         << B;

    cout << "\nVector V: "
         << V;

    cout << "\n\nA + B:\n"
         << A + B;

    cout << "\nA - B:\n"
         << A - B;

    cout << "\nA * B:\n"
         << A * B;

    cout << "\nA * V:\n"
         << A * V;

    return 0;
}
