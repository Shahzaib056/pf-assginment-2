#include <iostream>
using namespace std;
int sumis(int str[], int a);
int main() {
    int arr[5];
    cout << "Enter 5 integers" << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    int x=sumarray(arr, 5);
    cout << "Sum of this is :" << x << endl;
}
int sumis(int str[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += str[i];
    return sum;
}

