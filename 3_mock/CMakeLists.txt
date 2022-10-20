cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 17)

project(ssharma_googleTestDemo)

# execute CMakeLists.txt in third-party/googletest
add_subdirectory(third-party/googletest)
# Instead of using git submodule, CMake native commands
# `FetchContent` or `ExternalProject_Add` can also be used

# create libPriceDatabaseAPI.a
add_library(PriceDatabaseAPI PriceDatabaseAPI.cpp)

# create libInflationTracker.a
add_library(InflationTracker InflationTracker.cpp)

# create InflationTracker_test
add_executable(InflationTracker_test InflationTracker_test.cpp)
target_link_libraries(
    InflationTracker_test
    InflationTracker
    PriceDatabaseAPI
    gtest
    gmock
    pthread
)

# create client driver
add_executable(ClientMain main.cpp)
target_link_libraries(
    ClientMain
    InflationTracker
    PriceDatabaseAPI
)