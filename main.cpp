#include <iostream>

using namespace std;

string getLangAfterCipher(string key, string lang) {
    string langAfterCipher = lang;

    string  temp =lang;
    for(int i=0;i<5;i++){
      temp.erase(remove(temp.begin(),temp.end(),key[i]),temp.end());
    }
    langAfterCipher = key +temp;
    return langAfterCipher;
}

bool  validKey(string key){
    if(key.size() != 5) {
        cout<<"Size is bigger or smaller than 5 "<<endl;
        return false;
    }else {
        for(int i=0;i<5;i++){
            if(isdigit(key[i])) {
                cout<<"Key contains numbers plz re-enter a valid one  "<<endl;
                return false;
            }
        }
    }
    return true;
}

int main() {
    string plainAlphabet = "abcdefghijklmnopqrstuvwxyz";
    string key ,message ;
    do {
        cout << "Enter the message plz : " << endl;
        cin >> message;
    } while (message.empty());
    do {
        cout << "Enter the key plz : " << endl;
        cin >> key;
    }while (key.empty() || !validKey(key));
    string  langAfter = getLangAfterCipher(key, plainAlphabet);
    cout<<"Language After Applying Cipher : "<<langAfter<<endl;
    string ciphredMessage = message;
    for(int i:0;i<message.size();i++){
        if(message[i]==" "){
            deCiphred[i]=" "
        }else {

        }
    }
    return 0;
}
