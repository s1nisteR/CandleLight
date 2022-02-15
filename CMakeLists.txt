cmake_minimum_required(VERSION 3.21)
project(CandleLight)

set(CMAKE_CXX_STANDARD 17)

include_directories(include src thirdparty/uriparser/include thirdparty/cpr/include thirdparty/lexbor/source/)

set(URIPARSER_BUILD_TESTS OFF)
set(URIPARSER_BUILD_DOCS OFF)
set(URIPARSER_ENABLE_INSTALL ON)
set(BUILD_SHARED_LIBS OFF)
add_subdirectory(thirdparty/uriparser)


option(LEXBOR_BUILD_SHARED OFF)
add_subdirectory(thirdparty/lexbor)


add_subdirectory(thirdparty/cpr)


add_executable(CandleLight src/main.cpp src/clURI.cpp)
target_link_libraries(CandleLight PUBLIC uriparser cpr lexbor_static)
