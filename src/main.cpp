#include <iostream>

#include "E0.h"

using namespace std;

int main(int argc, char *argv[]) {
    string key = "100111";
    string msg = "11011101110000110111110110001011111001111100011111001101";

    E0 e = E0(key, msg);
    cout << e.decrypt() << endl;
}