# Submodule-CMake-Fixtures

## Setting up googletest as submodule

```sh
# in the git repo, create a dir for storing external libraries
# traditionally, it is either 'third-party' or 'external'
mkdir third-party
cd third-party
git submodule add -f git@github.com:google/googletest.git googletest
```

## Building using CMake

```sh
# create `build` directory
mkdir build
cd build

# generate Makefile using CMake
# here `..` refers to the relative path to CMakeLists.txt
cmake ..
# build libraries and executables
make
```

## Running client code

This code is useless, but it helps appreciate the need for mock testing

```sh
# run the generated executable
./ClientMain
```

## Run Mock tests

```sh
./InflationTracker_test
```

For a future quick refernce refer to: <https://google.github.io/googletest/gmock_cheat_sheet.html>

For a more detailed refernce: <https://google.github.io/googletest/gmock_for_dummies.html>
