#include <iostream>
using namespace std;
void vowelCount(char arr[]);
int main() {
	const int size = 100;
	char input[size]{};
	cout << "Enter a Char Array :";
	cin.getline( input, 100);

	vowelCount(input);

	return 0;
}
void vowelCount(char arr[]) {
	int count = 0;
	int x = 0;
	while (arr[x] != '\0') {
		char ch = arr[x];
		if (ch =='A' || ch == 'E' || ch == 'I' || ch == 'O' ||ch == 'U' ||
			ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		{
			count++;
		}
		x++;
	}
	
	cout << "Total Vowels are :" << count << endl;
}