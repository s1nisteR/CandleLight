cmake_minimum_required(VERSION 3.21)
cmake_policy(SET CMP0126 NEW)
cmake_policy(SET CMP0077 NEW)
project(CandleLight)

set(CMAKE_CXX_STANDARD 17)


include_directories(include src thirdparty/uriparser/include thirdparty/cpr/include thirdparty/lexbor/source/ thirdparty/termcolor/include)

set(URIPARSER_BUILD_TESTS OFF CACHE BOOL "Disable build tests" FORCE)
set(URIPARSER_BUILD_DOCS OFF CACHE BOOL "Do not build docs" FORCE)
set(URIPARSER_ENABLE_INSTALL ON CACHE BOOL "Do not install" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Do not build as a shared library" FORCE)
add_subdirectory(thirdparty/uriparser)


set(LEXBOR_BUILD_SHARED OFF CACHE BOOL "Do not build as a shared library" FORCE)
add_subdirectory(thirdparty/lexbor)


add_subdirectory(thirdparty/cpr)


add_executable(CandleLight src/main.cpp src/clURI.cpp src/clParser.cpp src/clParser.h)
target_link_libraries(CandleLight PUBLIC uriparser cpr lexbor_static)
