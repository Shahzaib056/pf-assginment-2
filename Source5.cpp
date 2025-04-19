#include <iostream>
using namespace std;

int getMax(int nums[], int length) {
    int largest = nums[0];
    for (int i = 1; i < length; i++)
        if (nums[i] > largest)
            largest = nums[i];
    return largest;
}

int main() {
    int data[5];
    cout << "Enter 5 integers" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> data[i];
    }
    int result = getMax(data, 5);
    cout << "Maximum element: " << result << endl;
    return 0;
}
