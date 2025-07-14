# This CMakeLists.txt is adapted and minimized from the following:
#
#    https://github.com/mortinger91/cpp-cmake-template/blob/master/projectFolder/CMakeLists.txt
#    https://google.github.io/googletest/quickstart-cmake.html
# 


cmake_minimum_required(VERSION 3.31 FATAL_ERROR)


project(
    "tgmock_20250714"
    DESCRIPTION "tgmock_20250714"
    HOMEPAGE_URL "https://github.com/kinchungwong/tgmock_20250714"
)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) # Windows only
FetchContent_MakeAvailable(googletest)


set(CMAKE_CXX_VISIBILITY_PRESET hidden)
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
endif()


# Dependencies
# find_package(OpenCV REQUIRED PATHS "${CMAKE_SOURCE_DIR}/opencv_build" NO_DEFAULT_PATH)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/int")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/lib")

add_executable(${PROJECT_NAME} src/main.cpp)
add_subdirectory(src)

# Link libraries to main executable, including third party dependencies
target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
        ${PROJECT_NAME}_LIB
)

# Tests are built as a separate executable; see tests/CMakeLists.txt
option(BUILD_TESTS "Build tests" ON)
if (BUILD_TESTS)
    add_subdirectory(tests)
endif()
