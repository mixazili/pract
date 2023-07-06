#include <iostream>

using namespace std;

double geometricProgr(int n, double b, double q) {
    if (n == 1) {
        return b;
    }
    else {
        return q * geometricProgr(n - 1, b, q);
    }
}

int main() {
    setlocale(LC_ALL, "Ru");
    double b, q;
    int n;

    cout << "Первый член b: ";
    cin >> b;
    cout << "Знаменатель q: ";
    cin >> q;
    cout << "Номер искомого члена n: ";
    cin >> n;

    double result = geometricProgr(n, b, q);

    cout << "n-ый член: " << result << endl; 

    return 0;
}