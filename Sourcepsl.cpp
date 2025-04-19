#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void addPlayer();
void viewAllPlayers();
void searchPlayer();
void updateStats();
void deletePlayer();

int main() {
    int choice;
    do {
        cout << "\n------ PSL MANAGEMENT SYSTEM ------\n";
        cout << "1. Add Player\n";
        cout << "2. View All Players\n";
        cout << "3. Search Player (By Name/Team)\n";
        cout << "4. Update Player Stats\n";
        cout << "5. Delete Player Record\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) addPlayer();
        else if (choice == 2) viewAllPlayers();
        else if (choice == 3) searchPlayer();
        else if (choice == 4) updateStats();
        else if (choice == 5) deletePlayer();
        else if (choice != 6) cout << "Invalid option!\n";

    } while (choice != 6);

    return 0;
}

void addPlayer() {
    string name, team, role;
    int runs, wickets;

    cout << "Enter Player Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Team Name: ";
    getline(cin, team);
    cout << "Enter Role (Batsman/Bowler/All-rounder): ";
    getline(cin, role);
    cout << "Enter Total Runs: ";
    cin >> runs;
    cout << "Enter Total Wickets: ";
    cin >> wickets;

    ofstream fout("players.txt", ios::app);
    fout << name << "," << team << "," << role << "," << runs << "," << wickets << endl;
    fout.close();

    cout << "Player record added successfully!\n";
}

void viewAllPlayers() {
    ifstream file("players.txt");
    if (!file) {
        cout << "File not found.\n";
        return;
    }

    string line;
    cout << "Name\t\tTeam\t\tRole\t\tRuns\tWickets\n";
    cout << "-------------------------------------------------------------\n";
    while (getline(file, line)) {
        size_t pos = 0;
        string data[5];
        int i = 0;
        while ((pos = line.find(",")) != string::npos && i < 5) {
            data[i++] = line.substr(0, pos);
            line.erase(0, pos + 1);
        }
        data[i] = line;

        cout << data[0] << "\t\t" << data[1] << "\t\t" << data[2]
            << "\t" << data[3] << "\t" << data[4] << endl;
    }
    file.close();
}

void searchPlayer() {
    string keyword;
    cout << "Enter Player Name or Team Name to Search: ";
    cin.ignore();
    getline(cin, keyword);

    ifstream file("players.txt");
    string line;
    bool found = false;

    while (getline(file, line)) {
        string data[5];
        size_t pos = 0;
        int i = 0;
        while ((pos = line.find(",")) != string::npos && i < 5) {
            data[i++] = line.substr(0, pos);
            line.erase(0, pos + 1);
        }
        data[i] = line;

        if (data[0] == keyword || data[1] == keyword) {
            cout << "\nPlayer Found:\n";
            cout << "Name: " << data[0] << "\nTeam: " << data[1]
                << "\nRole: " << data[2] << "\nRuns: " << data[3]
                << "\nWickets: " << data[4] << endl;
            found = true;
        }
    }

    if (!found)
        cout << "No matching player found.\n";

    file.close();
}

void updateStats() {
    string name;
    cout << "Enter Player Name to Update: ";
    cin.ignore();
    getline(cin, name);

    ifstream fin("players.txt");
    ofstream fout("temp.txt");
    string line;
    bool updated = false;

    while (getline(fin, line)) {
        string data[5];
        size_t pos = 0;
        int i = 0;
        while ((pos = line.find(",")) != string::npos && i < 5) {
            data[i++] = line.substr(0, pos);
            line.erase(0, pos + 1);
        }
        data[i] = line;

        if (data[0] == name) {
            cout << "Enter Updated Runs: ";
            cin >> data[3];
            cout << "Enter Updated Wickets: ";
            cin >> data[4];
            updated = true;
        }

        fout << data[0] << "," << data[1] << "," << data[2] << "," << data[3] << "," << data[4] << endl;
    }

    fin.close();
    fout.close();

    if (updated) {
        remove("players.txt");
        rename("temp.txt", "players.txt");
        cout << "Player stats updated successfully.\n";
    }
    else {
        remove("temp.txt");
        cout << "Player not found.\n";
    }
}

void deletePlayer() {
    string name;
    cout << "Enter Player Name to Delete: ";
    cin.ignore();
    getline(cin, name);

    ifstream fin("players.txt");
    ofstream fout("temp.txt");
    string line;
    bool deleted = false;

    while (getline(fin, line)) {
        string data[5];
        size_t pos = 0;
        int i = 0;
        while ((pos = line.find(",")) != string::npos && i < 5) {
            data[i++] = line.substr(0, pos);
            line.erase(0, pos + 1);
        }
        data[i] = line;

        if (data[0] != name) {
            fout << data[0] << "," << data[1] << "," << data[2] << "," << data[3] << "," << data[4] << endl;
        }
        else {
            deleted = true;
        }
    }

    fin.close();
    fout.close();

    if (deleted) {
        remove("players.txt");
        rename("temp.txt", "players.txt");
        cout << "Player record deleted successfully.\n";
    }
    else {
        remove("temp.txt");
        cout << "Player not found.\n";
    }
}