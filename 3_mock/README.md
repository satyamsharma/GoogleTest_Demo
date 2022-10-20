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

```sh
# run the generated executable
./ClientMain
```

## Run test

```sh
# same as before
./InflationTracker_test
```
