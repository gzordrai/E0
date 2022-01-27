#include <iostream>
#include <cstdlib>

#include "E0.h"

using namespace std;

int main(int argc, char *argv[]) {
    int choice;
    bool stop = false;
    string key, message;

    cout << "Please enter a key (6 bits):" << endl;
    cin >> key;

    while(key.size() != 6) {
        cout << "Invalid key !" << endl;
        cout << "Please enter a key (6 bits):" << endl;
        cin >> key;
    }

    cout << "Please enter a message to encrypt/decrypt:" << endl;
    cin >> message;

    E0 e0 = E0(key, message);

    while(!stop) {
        do {
            cout << "Please choose an action:\n1 - Change the key\n2 - Change the message to encrypt/decrypt\n3 - Encrypt the message\n4 - Decrypt the message\n5 - Stop" << endl;
            cin >> choice;
        } while(choice < 0 && choice > 5);

        switch(choice) {
            case 1:
                do {
                    cout << "Please enter a key (6 bits):" << endl;
                    cin >> key;
                } while(key.size() != 6);

                e0.setKey(key);
                break;

            case 2:
                cout << "Please enter a message to encrypt/decrypt:" << endl;
                cin >> message;

                e0.setMessage(message);
                break;

            case 3:
                cout << e0.encrypt() << endl;
                break;

            case 4:
                cout << e0.decrypt() << endl;
                break;

            case 5:
                stop = true;
                break;
        }
    }
}