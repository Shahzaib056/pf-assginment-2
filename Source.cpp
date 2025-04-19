#include <iostream>
using namespace std;
void print(int arr[], int a);
int main() {
    int arr[5];
    cout << "Enter Five integers" << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    print(arr, 5);
}
void print(int arr[], int a) {
    for (int i = 0; i < a; i++)
        cout <<"Element at"<<i+1<<"is"<< arr[i] << " "<<endl;
    cout << endl;
}
