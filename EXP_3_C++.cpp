#include <cassert>
#include <iostream>

class Matrix {
    int data[2][2]{};

public:
    Matrix(int a = 0, int b = 0, int c = 0, int d = 0)
        : data{{a, b}, {c, d}} {}

    Matrix operator+(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                for (int k = 0; k < 2; ++k)
                    result.data[i][j] += data[i][k] * other.data[k][j];
        return result;
    }

    int* operator[](int row) { return data[row]; }
    const int* operator[](int row) const { return data[row]; }

    friend std::ostream& operator<<(std::ostream& out, const Matrix& m) {
        for (int i = 0; i < 2; ++i)
            out << m.data[i][0] << ' ' << m.data[i][1] << '\n';
        return out;
    }
};

int main() {
    const Matrix a(2, 3, 1, 4);
    const Matrix b(5, 1, 2, 3);

    const Matrix sum = a + b;
    const Matrix product = a * b;

    assert(sum[0][0] == 7 && sum[0][1] == 4 &&
           sum[1][0] == 3 && sum[1][1] == 7);

    assert(product[0][0] == 16 && product[0][1] == 11 &&
           product[1][0] == 13 && product[1][1] == 13);

    std::cout << "Matrix A:\n" << a
              << "Matrix B:\n" << b
              << "A + B:\n" << sum
              << "A * B:\n" << product
              << "All checks passed.\n";

    return 0;
}