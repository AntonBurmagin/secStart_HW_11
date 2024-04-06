#include <iostream>

std::string encrypt(std::string str, int key) {
    key %= 26;
    for (int i = 0; i < str.length(); i++) {
        if(str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z') {
            if ((str[i] <= 'Z' && (str[i] + key) > 'Z') || (str[i] <= 'z' && (str[i] + key) > 'z')) {
                key -= 26;
            }
        }
        str[i] += key;
    }
    return str;
}

bool isCorrectEmail (std::string str) {
    int at = str.find('@');
    std::string left = str.substr(0, at);
    std::string right = str.substr(at+1, str.length() - at);
    std::cout << left << " " << right << std::endl;

    if (at != str.rfind('@') || left.length() < 1 || left.length() > 64 || right.length() < 1 || right.length() > 63) {
        return false;
    }

    std::string leftSymbols = "!#$%&'*+-/=?^_`{|}~.";
    for (int i = 0; i < left.length(); i++) {
        std::cout << "left\n";
        if((left[i] >= 'A' && left[i] <= 'Z') || (left[i] >= 'a' && left[i] <= 'z') 
        || (left[i] >= '0' && left[i] <= '9') || (leftSymbols.find(left[i]) != -1)) 
        {
            if ((left[i] == '.' && i == 0) || (left[i] == '.' && i != left.length()-1 && left[i+1] == '.')) {
                return false;
            }
            continue;
        }
        return false;
    }

    std::string rightSymbols = "-.";
    for (int i = 0; i < right.length(); i++) {
        std::cout << "right\n";
        if((right[i] >= 'A' && right[i] <= 'Z') || (right[i] >= 'a' && right[i] <= 'z') 
        || (right[i] >= '0' && right[i] <= '9') || (rightSymbols.find(right[i]) != -1)) 
        {
            if ((right[i] == '.' && i == right.length()-1) || (right[i] == '.' && right[i+1] == '.')) {
                return false;
            }
            continue;
        }
        std::cout << (rightSymbols.find(right[i]) != -1) << std::endl;
        std::cout << "right index: " << i << std::endl;
        return false;
    }
    return true;
}

int main() {
    // lesson 11.6.1
    /*std::string str;
    int key;
    while (true) {
        std::cout << "Text and key:\n";
        std::cin >> str >> key;
        std::cout << encrypt(str, key) << std::endl;
    } */

    // lesson 11.6.2
    std::string email;
    while (true) {
        std::cout << "Email:\n";
        std::cin >> email;
        if (isCorrectEmail(email)) {
            std::cout << "Yes!\n";
        } else {
            std::cout << "No!\n";
        }
    }


}