cmake_minimum_required(VERSION 3.24)
project(Project_CLion)

set(CMAKE_CXX_STANDARD 17)

#find_package(OpenMP REQUIRED)
#if(OPENMP_FOUND)
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
#endif()

add_executable(Project_CLion main.cpp interface.cpp interface.h sysinfo.cpp sysinfo.h Fibonacci.cpp Fibonacci.h BigInt.cpp BigInt.h workloads.cpp workloads.h)