#include <iostream>
#include <fstream>
using namespace std;

void getWordCount(const char filePath[]) {
    ifstream fileIn("read.txt");
    string tempWord;
    int totalWords = 0;

    if (!fileIn) {
        cout << "Unable to open file." << endl;
        return;
    }

    while (fileIn >> tempWord) {
        totalWords++;
    }

    fileIn.close();
    cout << "Total words in file: " << totalWords << endl;
}

int main() {
    char userFile[100];
    cout << "Enter file name: ";
    cin >> userFile;

    getWordCount(userFile);

    return 0;
}

