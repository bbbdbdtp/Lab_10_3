#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Friend {
    string fullName;
    string phoneNumber;
    int birthDate[3];
    Friend() {
        birthDate[0] = 0;
        birthDate[1] = 0;
        birthDate[2] = 0;
    }
};

void createFriendList(const string& filename, Friend* friends, int& size) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to open file: " << filename << endl;
        return;
    }

    string line;
    size = 0;
    while (getline(file, line)) {
        if (size >= 100) { // Assuming maximum 100 friends
            cerr << "Maximum limit reached for number of friends." << endl;
            break;
        }

        Friend friendData;
        size_t pos = line.find(';');
        friendData.fullName = line.substr(0, pos);
        line = line.substr(pos + 1);

        pos = line.find(';');
        friendData.phoneNumber = line.substr(0, pos);
        line = line.substr(pos + 1);

        for (int i = 0; i < 3; ++i) {
            pos = line.find(';');
            friendData.birthDate[i] = stoi(line.substr(0, pos));
            line = line.substr(pos + 1);
        }
        friends[size++] = friendData;
    }
    file.close();
}

void printFriend(const Friend& friendData) {
    cout << "Name: " << friendData.fullName << endl;
    cout << "Phone Number: " << friendData.phoneNumber << endl;
    cout << "Birth Date: " << friendData.birthDate[0] << "/" << friendData.birthDate[1] << "/" << friendData.birthDate[2] << endl;
}

string findFriendByPhoneNumber(const Friend* friends, int size, const string& phoneNumber) {
    for (int i = 0; i < size; ++i) {
        if (friends[i].phoneNumber == phoneNumber) {
            cout << "Friend found:\n";
            cout << "Name: " << friends[i].fullName << endl;
            cout << "Phone Number: " << friends[i].phoneNumber << endl;
            cout << "Birth Date: " << friends[i].birthDate[0] << "/" << friends[i].birthDate[1] << "/" << friends[i].birthDate[2] << endl;
            return phoneNumber;
        }
    }
    return "Friend not found for phone number: " + phoneNumber;
}

int main() {
    Friend friends[100];
    int size;
    string filename = "friend_list.txt";

    createFriendList(filename, friends, size);

    string phoneNumber;
    cout << "Enter phone number to search: ";
    cin >> phoneNumber;

    cout << findFriendByPhoneNumber(friends, size, phoneNumber) << endl;

    return 0;
}