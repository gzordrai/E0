#ifndef E0_H
#define E0_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class E0 {
    private:
        vector<int> key;
        string message;

    public:
        E0(const string &key, const string &message);
        E0(const vector<int> &key, const string &message);
};

#endif