#include <iostream>
using namespace std;

void checkPalindrome(char word[]);

int main() {
    char userInput[100]{};
    cout << "Enter Word: ";
    cin >> userInput;
    checkPalindrome(userInput);
    return 0;
}

void checkPalindrome(char word[]) {
    int size = 0;
    bool isPalindrome = true;

    while (word[size] != '\0') {
        size++;
    }

    int j = size - 1;
    for (int i = 0; i < size / 2; i++) {
        if (word[i] != word[j]) {
            isPalindrome = false;
            break;
        }
        j--;
    }

    if (isPalindrome) {
        cout << "This is a Palindrome" << endl;
    }
    else {
        cout << "This is Not a Palindrome" << endl;
    }
}
