#ifndef E0_H
#define E0_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class E0 {
    private:
        vector<char> key;
        string message;

    public:
        E0(const string &key, const string &message);
        E0(const vector<char> &key, const string &message);
};

#endif