// FCAI – Programming 1 – 2022 - Assignment 2
// Program Name: SimpleSubstitutionCipher_ID5.cpp
// Program Description: A program that takes a message, cipher and decipher it by a key
// Last Modification Date: 29/03/2022
// Author: Aliaa Adel Abdellatif Hassan
// ID: 20210515  Group:A
// Purpose:being able to encrypt and decrypt messages


#include <iostream>
using namespace std;

// create the cipher plain by including the key
string getLangAfterCipher(string key, string lang) {
    string langAfterCipher = lang;

    string temp = lang;
    for (int i = 0; i < 5; i++) {
        temp.erase(remove(temp.begin(), temp.end(), key[i]), temp.end());
    }
    langAfterCipher = key + temp;
    return langAfterCipher;
}
// check the correctness of the key
bool validKey(string key) {
    if (key.size() != 5) {
        cout << "Size is bigger or smaller than 5 " << endl;
        return false;
    } else {
        for (int i = 0; i < 5; i++) {
            if (isdigit(key[i])) {
                cout << "Key contains numbers plz re-enter a valid one  " << endl;
                return false;
            }
        }
    }
    return true;
}

// encrypt the given message
string getCiphredMsg(string msg,string ourCipher) {
    string plainAlphabet = "abcdefghijklmnopqrstuvwxyz";
    string cipheredMessage ="";
    for (int i = 0; i < msg.size(); i++) {
        if(msg.at(i)==' '){
            cipheredMessage += ' ';

        }else {
            int indexInAlphabet = plainAlphabet.find(msg.at(i));
            cipheredMessage += ourCipher.at(indexInAlphabet);
        }
    }
    return cipheredMessage;
}
// decrypt the encrypted message
string deCipher(string msg,string ourCipher){
    string plainAlphabet = "abcdefghijklmnopqrstuvwxyz";
    string deCipheredMessage ="";
    for (int i = 0; i < msg.size(); i++) {
        if(msg.at(i)==' '){
            deCipheredMessage += ' ';

        }else {
            int indexInOurCipher = ourCipher.find(msg.at(i));
            deCipheredMessage += plainAlphabet.at(indexInOurCipher);
        }
    }
    return deCipheredMessage;
}

int main() {
    string plainAlphabet = "abcdefghijklmnopqrstuvwxyz";
    string key, message;
    do {
        cout << "Enter the message plz : " << endl;
        getline(cin, message);
    } while (message.empty());
    do {
        cout << "Enter the key plz : " << endl;
        cin >> key;
    } while (key.empty() || !validKey(key));
    string langAfter = getLangAfterCipher(key, plainAlphabet);
    cout << "Language After Applying Cipher : " << langAfter << endl;


    string cipheredMessage = getCiphredMsg(message,langAfter);
    cout<<"Message After Ciphered : "<<cipheredMessage<<endl;


    string deCipheredMessage = deCipher(cipheredMessage,langAfter);
    cout<<"Message After DeCiphered : "<<deCipheredMessage<<endl;

    return 0;
}
