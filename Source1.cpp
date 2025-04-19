//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//
//void addPlayer();
//void viewAllPlayers();
//void searchPlayer();
//void updatePlayer();
//void deletePlayer();
//
//int main() {
//    int choice;
//    do {
//        cout << "\n----- PSL MANAGEMENT SYSTEM -----\n";
//        cout << "1. Add Player Record\n";
//        cout << "2. View All Player Records\n";
//        cout << "3. Search Player (by Name or Team)\n";
//        cout << "4. Update Player Stats\n";
//        cout << "5. Delete Player Record\n";
//        cout << "6. Exit\n";
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        if (choice == 1) addPlayer();
//        if (choice == 2) viewAllPlayers();
//        if (choice == 3) searchPlayer();
//        if (choice == 4) updatePlayer();
//        if (choice == 5) deletePlayer();
//
//    } while (choice != 6);
//
//    return 0;
//}
//
//void addPlayer() {
//    string name, team, role;
//    int runs, wickets;
//
//    cin.ignore();
//    cout << "Enter Player Name: ";
//    getline(cin, name);
//    cout << "Enter Team Name: ";
//    getline(cin, team);
//    cout << "Enter Role (batsman/bowler/all-rounder): ";
//    getline(cin, role);
//    cout << "Enter Total Runs: ";
//    cin >> runs;
//    cout << "Enter Total Wickets: ";
//    cin >> wickets;
//
//    ofstream fout("players.txt", ios::app);
//    fout << name << "," << team << "," << role << "," << runs << "," << wickets << endl;
//    fout.close();
//}
//
//void viewAllPlayers() {
//    ifstream fin("players.txt");
//    string line;
//    cout << "\nName\t\tTeam\t\tRole\t\tRuns\tWickets\n";
//    cout << "------------------------------------------------------------\n";
//
//    while (getline(fin, line)) {
//        string data[5];
//        int i = 0;
//        int pos = 0;
//
//        while ((pos = line.find(",")) != -1 && i < 5) {
//            data[i++] = line.substr(0, pos);
//            line = line.substr(pos + 1);
//        }
//        if (i < 5) data[i] = line;
//
//        cout << data[0] << "\t" << data[1] << "\t" << data[2] << "\t" << data[3] << "\t" << data[4] << endl;
//    }
//    fin.close();
//}
//
//void searchPlayer() {
//    string key;
//    cin.ignore();
//    cout << "Enter player name or team to search: ";
//    getline(cin, key);
//
//    ifstream fin("players.txt");
//    string line;
//    bool found = false;
//
//    while (getline(fin, line)) {
//        string data[5];
//        int i = 0;
//        int pos = 0;
//
//        while ((pos = line.find(",")) != -1 && i < 5) {
//            data[i++] = line.substr(0, pos);
//            line = line.substr(pos + 1);
//        }
//        if (i < 5) data[i] = line;
//
//        if (data[0] == key || data[1] == key) {
//            cout << "\nPlayer Found:\n";
//            cout << "Name: " << data[0] << "\nTeam: " << data[1] << "\nRole: " << data[2]
//                << "\nRuns: " << data[3] << "\nWickets: " << data[4] << "\n";
//            found = true;
//        }
//    }
//    if (!found) cout << "Player not found.\n";
//    fin.close();
//}
//
//void updatePlayer() {
//    string pname;
//    cin.ignore();
//    cout << "Enter player name to update: ";
//    getline(cin, pname);
//
//    ifstream fin("players.txt");
//    ofstream fout("temp.txt");
//
//    string line;
//    bool updated = false;
//
//    while (getline(fin, line)) {
//        string data[5];
//        int i = 0;
//        int pos = 0;
//
//        while ((pos = line.find(",")) != -1 && i < 5) {
//            data[i++] = line.substr(0, pos);
//            line = line.substr(pos + 1);
//        }
//        if (i < 5) data[i] = line;
//
//        if (data[0] == pname) {
//            cout << "Enter new runs: ";
//            cin >> data[3];
//            cout << "Enter new wickets: ";
//            cin >> data[4];
//            updated = true;
//        }
//
//        fout << data[0] << "," << data[1] << "," << data[2] << "," << data[3] << "," << data[4] << endl;
//    }
//
//    fin.close();
//    fout.close();
//
//    if (updated) {
//        remove("players.txt");
//        rename("temp.txt", "players.txt");
//        cout << "Player stats updated successfully.\n";
//    }
//    else {
//        remove("temp.txt");
//        cout << "Player not found.\n";
//    }
//}
//
//void deletePlayer() {
//    string pname;
//    cin.ignore();
//    cout << "Enter player name to delete: ";
//    getline(cin, pname);
//
//    ifstream fin("players.txt");
//    ofstream fout("temp.txt");
//
//    string line;
//    bool deleted = false;
//
//    while (getline(fin, line)) {
//        string data[5];
//        int i = 0;
//        int pos = 0;
//
//        while ((pos = line.find(",")) != -1 && i < 5) {
//            data[i++] = line.substr(0, pos);
//            line = line.substr(pos + 1);
//        }
//        if (i < 5) data[i] = line;
//
//        if (data[0] != pname) {
//            fout << data[0] << "," << data[1] << "," << data[2] << "," << data[3] << "," << data[4] << endl;
//        }
//        else {
//            deleted = true;
//        }
//    }
//
//    fin.close();
//    fout.close();
//
//    if (deleted) {
//        remove("players.txt");
//        rename("temp.txt", "players.txt");
//        cout << "Player record deleted successfully.\n";
//    }
//    else {
//        remove("temp.txt");
//        cout << "Player not found.\n";
//    }
//}
