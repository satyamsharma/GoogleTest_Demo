# Minimal setup

## Installing googletest

```sh
# clone the code
git clone git@github.com:google/googletest.git

# build the googletest library
cd googletest
cmake CMakeLists.txt
make

# copy gmock and gtest libraries (and headers) into the system
sudo make install
```

> cmake can be installed using `brew`, `pip`, `apt-get` or your favorite package manager for your system

## Running client code

```sh
# build client code with calculaor library
g++ main.cpp calculator.cpp -o client

# run the generated executable
./client
```

## Running test code

```sh
# build test code with calculator library
# note: googletest requires at least c++14 standard
g++ -std=c++14 calculator_test.cpp calculator.cpp -lgtest -o calculator_test

# run the generated executable
./calculator_test
```
