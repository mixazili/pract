#include <iostream>
#include <fstream>

using namespace std;

bool isFibonacci(int n) {
    int a = 0, b = 1;
    while (b < n) {
        int c = a + b;
        a = b;
        b = c;
    }
    return (b == n);
}

void findFibonacciNumbers(int arr[], int size) {
    int fibonacciNumber;
    for (int i = 0; i < size; i++) {
        if (isFibonacci(arr[i])) {
            fibonacciNumber = 1;
            int a = 0, b = 1, c = 1;
            while (c < arr[i]) {
                c = a + b;
                a = b;
                b = c;
                fibonacciNumber++;
            }
            cout << "Число " << arr[i] << " является числом Фибоначчи" << " величины " << fibonacciNumber << endl;
        }
    }
}

int main() {

    setlocale(LC_ALL, "Ru");

    ifstream input("input.txt");
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int n, count = 0;
    while (input >> n && count < MAX_SIZE) {
        arr[count++] = n;
    }
    input.close();

    findFibonacciNumbers(arr, count);

    return 0;
}