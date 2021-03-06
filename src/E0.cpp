#include <iostream>
#include <bitset>
#include <string>
#include <vector>
#include <math.h>

#include "E0.h"

using namespace std;

/**
 * @brief Construct a new E0::E0 object
 * 
 * @param key 
 * @param message 
 */
E0::E0(const string &key, const string &message) {
    if(key.size() != 6)
        throw invalid_argument("The key must contain 6 bits !");

    for(const char &c : key) {
        if(c != '0' && c != '1')
            throw invalid_argument("The value of a bit must be 0 or 1 !");
    }

    this->key = key;
    this->message = message;
}

/**
 * @brief Convert int to ascii
 * 
 * @param code Ascii code
 * @return char
 */
char E0::intToAscii(int code) {
    return (char) code;
}

/**
 * @brief Change the key
 * 
 * @param key The encryption key
 */
void E0::setKey(const string key) {
    this->key = key;
}

/**
 * @brief Change the message
 * 
 * @param message The message to encrypt/decrypt
 */
void E0::setMessage(const string message) {
    this->message = message;
}

/**
 * @brief Encrypt a message
 * 
 * @return string 
 */
string E0::encrypt() {
    int i;
    string key = this->key;
    string message;
    string ret;

    for(i = 0; i < (int) (this->message.size()); i++)
        message += ((bitset<8>) this->message[i]).to_string();

    for(i = 0; i < (int) (message.size()); i++)
        key += (key[i] ^ key[i + 2]) ^ (key[i + 4] ^ key[i + 5]) ? '1' : '0';

    for(i = 0; i < (int) message.size(); i++)
        ret += key[i] ^ message[i] ? '1' : '0';

    return ret;
}

/**
 * @brief Decrypt an encrypted message
 * 
 * @return string 
 */
string E0::decrypt() {
    int i, j;
    string key = this->key;
    string message = "";
    string ret = "";

    // creation of the key
    for(i = 0; i < (int) (this->message.size() - this->key.size()); i++)
        key += (key[i] ^ key[i + 2]) ^ (key[i + 4] ^ key[i + 5]) ? '1' : '0';

    // message decoding
    for(i = 0; i < (int) this->message.size(); i++)
        message += key[i] ^ this->message[i] ? '1' : '0';

    // convert bytes to ascii
    for(i = 0; i < (int) (this->message.size() / 8); i++) {
        int c = 0;
        string byte = message.substr(i * 8, 8);

        for(j = 7; j >= 0; j--)
            c += byte[j] == '1' ? pow(2, 7 - j) : 0;

        ret += this->intToAscii(c);
    }

    return ret;
}