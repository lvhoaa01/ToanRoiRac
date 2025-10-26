#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
    int n;
    double M, I;

    cin >> n >> M >> I;
    double monthly_rate = I / 1200.0;

    double A = M * pow(1.0 + monthly_rate, n);

    cout << fixed << setprecision(6) << A << endl;

    return 0;
}