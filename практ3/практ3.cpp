#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.1415;

struct Point {
    double x, y;
};

bool isValidTriangle(Point A, Point B, Point C) {
    double area = abs((B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x)) / 2.0;
    if (area != 0) {
        return true;
    }
    else {
        return false;
    }
}

void rotate(Point& P, double alpha) {

    // Аффинное преобразование(поворот) 
    double x_new = P.x * cos(alpha) - P.y * sin(alpha);
    double y_new = P.x * sin(alpha) + P.y * cos(alpha);

    P.x = x_new;
    P.y = y_new;

    P.x = round(P.x * 100.0) / 100.0;
    P.y = round(P.y * 100.0) / 100.0;
}

int main() {

    setlocale(LC_ALL, "Ru");

    Point A, B, C;
    double alpha;
    cout << "Введите координаты первой вершины треугольника (x1 y1): ";
    cin >> A.x >> A.y;
    cout << "Введите координаты второй вершины треугольника (x2 y2): ";
    cin >> B.x >> B.y;
    cout << "Введите координаты третьей вершины треугольника (x3 y3): ";
    cin >> C.x >> C.y;
    cout << "Введите угол поворота в градусах: ";
    cin >> alpha;

    if (!isValidTriangle(A, B, C)) {
        cout << "Введен несуществующий треугольник";
        return 0;
    }

    alpha = alpha * PI / 180;

    rotate(A, alpha);
    rotate(B, alpha);
    rotate(C, alpha);

    cout << "Новые координаты первой вершины треугольника: " << A.x << " " << A.y << endl;
    cout << "Новые координаты второй вершины треугольника: " << B.x << " " << B.y << endl;
    cout << "Новые координаты третьей вершины треугольника: " << C.x << " " << C.y << endl;

    return 0;
}