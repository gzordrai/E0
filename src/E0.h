#ifndef E0_H
#define E0_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class E0 {
    private:
        string key;
        string message;
        string createKey(const string &key);
        char intToAscii(int code);

    public:
        E0(const string &key, const string &message);
        string encrypt();
        string decrypt();
};

#endif