#include <iostream>
#include <fstream>

using namespace std;

int ackermann(int n, int m) {
    if (m == 0) {
        return n + 1;
    }
    else if (n == 0) {
        return ackermann(m - 1, 1);
    }
    else {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}

int main() {
    int n, m;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter m: ";
    cin >> m;

    int result = ackermann(n, m);

    ofstream outFile("result.txt");
        outFile << result;
        outFile.close();
        cout << "Result saved in 'result.txt'" << endl;

    return 0;
}
