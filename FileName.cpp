#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// Генерує масив випадкових чисел від -50 до 50
void generateArray(int a[], int size, int index = 0) {
    if (index == size) return;
    a[index] = rand() % 101 - 50;
    generateArray(a, size, index + 1);
}

// Виводить масив на екран
void printArray(const int a[], int size, int index = 0) {
    if (index == size) {
        cout << endl;
        return;
    }
    cout << setw(4) << a[index];
    printArray(a, size, index + 1);
}

// Знаходить перший непарний елемент для порівняння
int findFirstOddElement(const int a[], int size, int index = 0) {
    if (index == size) return -1;
    if (a[index] % 2 != 0) return index;
    return findFirstOddElement(a, size, index + 1);
}

// Знаходить індекс найменшого непарного елемента
int findMinOddIndex(const int a[], int size, int minIndex, int currentIndex = 0) {
    if (currentIndex == size) return minIndex;
    if (a[currentIndex] % 2 != 0 && (minIndex == -1 || a[currentIndex] < a[minIndex])) {
        minIndex = currentIndex;
    }
    return findMinOddIndex(a, size, minIndex, currentIndex + 1);
}

// Замінює елемент за вказаним індексом на нуль
void replaceElement(int a[], int index, int currentIndex = 0) {
    if (currentIndex > index) return;
    if (currentIndex == index) {
        a[index] = 0;
        return;
    }
    replaceElement(a, index, currentIndex + 1);
}

int main() {
    srand(static_cast<unsigned>(time(0)));
    const int n = 20;
    int a[n];

    generateArray(a, n);

    printArray(a, n);

    int i = findFirstOddElement(a, n);

    if (i != -1) {
        i = findMinOddIndex(a, n, i);
        cout << "Index of lowest odd element: " << i << endl;
        cout << "Lowest odd element: " << a[i] << endl;
        replaceElement(a, i);

        printArray(a, n);
    }
    else {
        cout << "Odd elements not found." << endl;
    }

    return 0;
}
