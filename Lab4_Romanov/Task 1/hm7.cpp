#include <iostream>
#include <locale>
using namespace::std;

int kolvo_kratnih(const int* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 3 == 0) {
            count++;
        }
    }
    return count;

}
void findArrayWithMaxKratnih(const int* arrA, const int* arrB, int size) {
    int countA = 0, countB = 0;

    countA = kolvo_kratnih(arrA, size);
    countB = kolvo_kratnih(arrB, size);

    if (countA > countB) {
        cout << "Массив A имеет больше элементов кратных 3: " << countA << endl;
        cout << "Элементы массива A: ";
        for (int i = 0; i < size; i++) {
            cout << arrA[i] << " ";
        }
        cout << "Элементы массива B: ";
        for (int i = 0; i < size; i++) {
            cout << arrB[i] << " ";
        }
    }
    else if (countB > countA) {
        cout << "Массив B имеет больше элементов кратных 3: " << countB << endl;
        cout << "Элементы массива B: ";
        for (int i = 0; i < size; i++) {
            cout << arrB[i] << " ";
        }
        cout << "Элементы массива A: ";
        for (int i = 0; i < size; i++) {
            cout << arrA[i] << " ";
        }
    }
    else {
        cout << "Массивы имеют одинаковое количество элементов кратных 3: " << countA << endl;
        cout << "Элементы массива A: ";
        for (int i = 0; i < size; i++) {
            cout << arrA[i] << " ";
        }
        cout << "Элементы массива B: ";
        for (int i = 0; i < size; i++) {
            cout << arrB[i] << " ";
        }
    }
    cout << endl;
}
int main() {
    setlocale(LC_ALL, "Russian");
    int N;

    cout << "Введите размер массивов (N): ";
    cin >> N;

    int* A = new int[N];
    int* B = new int[N];

    cout << "Введите " << N << " элементов для массива A:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << "Введите " << N << " элементов для массива B:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    findArrayWithMaxKratnih(A, B, N);

    delete[] A;
    delete[] B;

    return 0;
}