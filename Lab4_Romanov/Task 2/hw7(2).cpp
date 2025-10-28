#include <iostream>
#include <set>

using namespace std;

int main() {
    setlocale(LC_ALL, "russian");
    cout << "Элементы множества A через пробел:" << endl;

    set<int> A;
    int num;

    while (cin >> num) {
        A.insert(num);
        if (cin.peek() == '\n') break;
    }
    cin.clear();

    cout << "Элементы множества B через пробел:" << endl;

    set<int> B;

    while (cin >> num) {
        B.insert(num);
        if (cin.peek() == '\n') break;
    }

    set<int> in_only_A;
    for (int element : A) {
        if (B.find(element) == B.end()) {
            in_only_A.insert(element);
        }
    }

    cout << "Элементы которые есть только в A: ";
    for (int element : in_only_A) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
