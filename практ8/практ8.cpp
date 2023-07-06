#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

const double EPSILON = 1e-10;


void readMatrix(double** matrix, int n, const string& filename) {
    ifstream input(filename);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            input >> matrix[i][j];
        }
    }
    input.close();
}

void printMatrix(double** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void swapRows(double** matrix, int n, int i, int j) {
    for (int k = 0; k < n; k++) {
        double temp = matrix[i][k];
        matrix[i][k] = matrix[j][k];
        matrix[j][k] = temp;
    }
}

double calculateDet(double** matrix, int n) {
    double det = 1;

    // Приводим матрицу к треугольному виду
    for (int i = 0; i < n; i++) {
        // Если элемент на главной диагонали равен нулю, меняем местами строки
        if (fabs(matrix[i][i]) < EPSILON) {
            bool found = false;
            for (int j = i + 1; j < n; j++) {
                if (fabs(matrix[j][i]) > EPSILON) {
                    swapRows(matrix, n, i, j);
                    found = true;
                    det *= -1; // Меняем знак определителя при перестановке строк
                    break;
                }
            }
            if (!found) {
                return 0; // Матрица вырожденная, определитель равен нулю
            }
        }
        // Приводим элементы ниже главной диагонали к нулю
        for (int j = i + 1; j < n; j++) {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i; k < n; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
        det *= matrix[i][i];
    }

    return det;
}

int main() {
    const int n = 3;

    double** matrix = new double* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new double[n];
    }

    readMatrix(matrix, n, "input.txt");

    printMatrix(matrix, n);

    double det = calculateDet(matrix, n);

    cout << "Determinant: " << det << endl;

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}