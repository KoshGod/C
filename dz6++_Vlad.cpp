#include <iostream>
#include <vector>

class Matrix {
public:
    std::vector<std::vector<int>> matrix;
    int rows, cols;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        matrix.resize(rows, std::vector<int>(cols, 0));
    }

    ~Matrix() {}

    void insertRow(int row) {
        matrix.insert(matrix.begin() + row, std::vector<int>(cols, 0));
        rows++;
    }

    void insertCol(int col) {
        for (int i = 0; i < rows; i++) {
            matrix[i].insert(matrix[i].begin() + col, 0);
        }
        cols++;
    }

    void deleteRow(int row) {
        matrix.erase(matrix.begin() + row);
        rows--;
    }

    void deleteCol(int col) {
        for (int i = 0; i < rows; i++) {
            matrix[i].erase(matrix[i].begin() + col);
        }
        cols--;
    }

    Matrix operator+(const Matrix& other) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }
        return result;
    }

    Matrix operator*(int num) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.matrix[i][j] = matrix[i][j] * num;
            }
        }
        return result;
    }
    static void printMatrix(const Matrix& m) {
        for (int i = 0; i < m.rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                std::cout << m.matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    friend Matrix multiplyMatrices(const Matrix& m1, const Matrix& m2) {
        Matrix result(m1.rows, m2.cols);
        for (int i = 0; i < m1.rows; i++) {
            for (int j = 0; j < m2.cols; j++) {
                for (int k = 0; k < m1.cols; k++) {
                    result.matrix[i][j] += m1.matrix[i][k] * m2.matrix[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    Matrix m1(1, 1);
    m1.insertRow(1);
    m1.insertCol(1);

    // Добавление чисел в матрицу m1
    m1.matrix[0][0] = 1;
    m1.matrix[0][1] = 2;
    m1.matrix[1][0] = 3;
    m1.matrix[1][1] = 4;
    std::cout << "matrix 1\n";
    m1.printMatrix(m1);

    Matrix m2(1, 1);
    m2.insertRow(1);
    m2.insertCol(1);

    // Добавление чисел в матрицу m2
    m2.matrix[0][0] = 5;
    m2.matrix[0][1] = 6;
    m2.matrix[1][0] = 7;
    m2.matrix[1][1] = 8;
    std::cout << "matrix 2\n";
    m2.printMatrix(m2);

    Matrix m3 = m1 + m2;
    std::cout << "Matrix sum m3:" << std::endl;
    m3.printMatrix(m3);

    Matrix m4 = m1 * 2;
    std::cout << "Matrix multi m1 on scalar m4:" << std::endl;
    m4.printMatrix(m4);

    Matrix m5 = multiplyMatrices(m1, m2);
    std::cout << "Matrix multi m2 and m1:" << std::endl;
    m5.printMatrix(m5);

    return 0;
}
