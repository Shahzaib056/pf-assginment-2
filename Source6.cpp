#include <iostream>
using namespace std;
void showMax(int data[], int count);
int main() {
    const int count = 5;
    int numbers[count] = { 0 };

    for (int index = 0; index < count; index++) {
        cout << "Enter number at index " << index << " : ";
        cin >> numbers[index];
    }
     showMax(numbers, count);
     return 0;
}
void showMax(int data[], int count) {
    int big = 0;
    for (int j = 0; j < count; j++) {
        if (big < data[j]) {
            big = data[j];
        }
    }
    cout << "Maximum Number is :" << big << endl;
}
