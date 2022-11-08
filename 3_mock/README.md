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

## Demo

There are two relevant classes: `PriceDatabaseAPI` and `InflationTracker` in this demo.

- `PriceDatabaseAPI` , as the name suggests, is a microservice that fetches prices from a remote database.

- `InflationTracker` uses `PriceDatabaseAPI` to retrieve the prices for differnt items and dates and it returns `Average`, `Maximum` and `Median`

One issue is if the remote database becomes unavailable, `PriceDatabaseAPI` will be useless as it could not fetch any data. As a result, One would not be able to test `InflationTracker` as it internally uses the microservice.

## Running client code

NOTE: We will see that the client code is actually useless here but it helps us appreciate the need for mock testing.

```sh
# run the generated executable
./ClientMain
```

Here, *ClientMain* instantiates `PriceDatabaseAPI` with server and port details and passes it to construct `InflationTracker`

`InflationTracker` is then used to calculate `Average` `Maximum`
`Median` for a set of retrived prices.

Since the database is unavailable, ClientMain, when executed, gets stuck waiting

This presents a fundamental issue for testing `InflationTracker` as it indirectly relies on the Database being present.

## Run Mock tests

We create `MockPriceDatabaseAPI` (derived from `PriceDatabaseAPI`) and override the functions we want to mock.

NOTE: The functions that need to be mocked must be polymorphic and therefore be marked `virtual` for all of this to work!

The mock tests, allow us to profile the mocked functions and realize the *Caller's* (`InflationTracke`) behavior : how many times it was called? what were its arguments? what to have as the return value? etc

```sh
./InflationTracker_test
```

For a future quick refernce refer to: <https://google.github.io/googletest/gmock_cheat_sheet.html>

For a more detailed refernce: <https://google.github.io/googletest/gmock_for_dummies.html>

## Responses from the Q/A

### Ordering

In the demo, `InSequence` is used for ordering. This technique, however, is too stringent. A more flexible (but also more verbose) approach would be using `Sequence` <https://google.github.io/googletest/gmock_cook_book.html#PartialOrder>

```sh
  Sequence s1, s2;

  EXPECT_CALL(api, A()).InSequence(s1, s2);
  EXPECT_CALL(api, B()).InSequence(s1);
  EXPECT_CALL(api, C()).InSequence(s2);
  EXPECT_CALL(api, D()).InSequence(s2);
```

```sh
        +--> B()
        |
  A() --|
        |
        +--> C() --> D()
```

In this case, we enforce `A()` to be called before `B() C() D()`, and `C()` to be called before `D()`, but we do not enforce the ordering between to `B()` and `C()` because they follow different sequences, namely `s1` and `s2`, respectively.

### Mocking Non-virtual method

In the demo, we agreed that the methods need to be polymorphic in order for `InflationTracker` class to use `MockPriceDatabaseAPI` (and not `PriceDatabaseAPI`) during mock testing. To remind ourselves, the culprit is `InflationTracker` internally uses the type `PriceDatabaseAPI*` for mAPI.

For non-virtual methods there are two ways:

- Templatize InflationTracker class and set mAPI's type as the template type.

```sh
template <class T>
class InflationTracker
{
...
   T* mAPI;
};
```

and so the client code could instantiate `InflationTracker<PriceDatabaseAPI>` and the test code could instantiate `InflationTracker<MockPriceDatabaseAPI>`

- Use compile time macros

As suggested here: <https://holzcoredump.cc/gmock_non_virtual.html>, we could replace the keyword virtual with a macro to something like `TEST_IFACE` and then set it as either `virtual` or an empty expression depending on whether the code is being compiled for the client or the test. I know this is a dirty way to do it, but, as the author suggested,  this way you can do it without templatizing the class or "updating" the production (binary) code.
