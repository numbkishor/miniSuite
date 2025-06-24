#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm> 

using namespace std;

const string LOWER = "abcdefghijklmnopqrstuvwxyz";
const string UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string DIGITS = "0123456789";
const string SPECIAL = "!@#$%^&*()-_=+[]{}|;:,.<>?";

enum CharType { LOWERCASE, UPPERCASE, DIGIT, SPECIAL_CHAR };

char getRandomChar(const string& chars) {
    int index = rand() % chars.size();
    return chars[index];
}

CharType getRandomTypeExcept(CharType lastType) {
    vector<CharType> types = {LOWERCASE, UPPERCASE, DIGIT, SPECIAL_CHAR};
    types.erase(std::remove(types.begin(), types.end(), lastType), types.end());
    int idx = rand() % types.size();
    return types[idx];
}

string generatePassword(int length) {
    if (length <= 0) return "";

    string password;
    CharType lastType = (CharType)(-1);

    for (int i = 0; i < length; ++i) {
        CharType currentType;
        if (i == 0) {
            currentType = (CharType)(rand() % 4);
        } else {
            currentType = getRandomTypeExcept(lastType);
        }

        switch (currentType) {
            case LOWERCASE:
                password += getRandomChar(LOWER);
                break;
            case UPPERCASE:
                password += getRandomChar(UPPER);
                break;
            case DIGIT:
                password += getRandomChar(DIGITS);
                break;
            case SPECIAL_CHAR:
                password += getRandomChar(SPECIAL);
                break;
        }
        lastType = currentType;
    }

    return password;
}

int main() {
    srand(time(0));

    int length;
    cout << "Enter desired password length: ";
    cin >> length;

    if (length <= 0) {
        cout << "Invalid length." << endl;
        return 1;
    }

    string password = generatePassword(length);
    cout << "Generated password: " << password << endl;
    return 0;
}
