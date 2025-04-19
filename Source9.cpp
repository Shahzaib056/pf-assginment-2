#include <iostream>
using namespace std;

void transferElements(int source[], int target[], int length);

int main() {
    const int length = 10;
    int original[length] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int duplicate[length] = { 0 };

    transferElements(original, duplicate, length);

    cout << "Duplicate Array: ";
    for (int i = 0; i < length; i++) {
        cout << duplicate[i] << " ";
    }

    return 0;
}

void transferElements(int source[], int target[], int length) {
    int index = 0;
    while (index < length) {
        target[index] = source[index];
        index++;
    }
}
