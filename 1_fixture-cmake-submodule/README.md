# Submodule-CMake-Fixtures

## Setting up googletest as submodule

```sh
# in the git repo, create a dir for storing external libraries
# traditionally, it is either 'third-party' or 'external'
mkdir third-party
cd third-party
git submodule add git@github.com:google/googletest.git
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

## Run test

```sh
# same as before
./vectorInt_test
```

## Running client code

```sh
# build client code with calculaor library
g++ main.cpp calculator.cpp -o client

# run the generated executable
./client
```

## Test Fixtures

`Test suites` allow grouping together similar unit tests.
`Test fixtures` allow grouping together similar unit test with common setup and teardown procedure

## Test Macros

### *Unary*

ASSERT_TRUE(condition)
ASSERT_FALSE(condition)

### *Binary*

ASSERT_EQ(val1,val2)
ASSERT_NE(val1,val2)
ASSERT_LT(val1,val2)
ASSERT_LE(val1,val2)
ASSERT_GT(val1,val2)
ASSERT_GE(val1,val2)

### *String*

ASSERT_STREQ(str1,str2)
ASSERT_STRNE(str1,str2)
ASSERT_STRCASEEQ(str1,str2)
ASSERT_STRCASENE(str1,str2)

### *Floating point*

#### Due to rounding errors, it is very unlikely that two floating-point values will match exactly, so EXPECT_EQ is not suitable

ASSERT_FLOAT_EQ(val1,val2)
ASSERT_DOUBLE_EQ(val1,val2)
ASSERT_NEAR(val1,val2,abs_error)

NOTE: Each aforementioned macro also has `EXPECT` version. `ASSERT` are fatal, whereas `EXPECT` are non-fatal testcases

For detail use cases, please refer to: <http://google.github.io/googletest/reference/assertions.html>
