# E0
Encryption protocol using 4 LFSR

## Installation

Download the project then run the Makefile (`src/Makefile`).

```bash
mingw-make
mingw32-make
mingw64-make
...

Check your c++ compiler doc if it is not mingw...
```

## Usage
Launch the executable `E0.exe`(`src/E0.exe`).

```bash
C:.
│   .gitignore
│   LICENSE
│   README.md
│
└───src
        E0.cpp
        E0.exe
        E0.h
        E0.o
        main.cpp
        main.o
        Makefile
```

## Library usage
Download the `E0.cpp` and `E0.h` files

```cpp
#include <string>

#include "E0.h"

string key = "100111";
string message = "11111110110100110111111110011001";
E0 e0 = E0(key, message);

e0.decrypt(); //abcd

e0.setMessage("abcd");
e0.encrypt(); //11111110110100110111111110011001

e0.setKey("111001");
e0.encrypt(); //10000110100011100010010001011011

e0.setMessage("10000110100011100010010001011011");
e0.decrypt(); //abcd

```

## License
[Apache 2.0](https://www.apache.org/licenses/LICENSE-2.0)