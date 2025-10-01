#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
    {
    float R, S, C;
    float x, y;
    cin >> x;
    cin >> y;
    R = sqrt(x * y) / abs(x);
    S = cos(y) * log2(x);
    cout << R << endl;
    cout << S << endl;

    C = max(R, S);
    cout << C << endl;
    system("pause");

}