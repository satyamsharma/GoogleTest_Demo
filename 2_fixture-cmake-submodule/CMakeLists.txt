cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 17)

project(ssharma_googleTestDemo)

# execute CMakeLists.txt in third-party/googletest
add_subdirectory(third-party/googletest)

# create libvectorInt.a
add_library(vectorInt vectorInt.cpp)

# create vectorInt_test
add_executable(vectorInt_test vectorInt_test.cpp)

# statically link gtest and libvectorInt.a into vectorInt_test
target_link_libraries(
	vectorInt_test
	vectorInt
	gtest
)
