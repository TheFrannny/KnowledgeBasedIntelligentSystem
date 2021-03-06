cmake_minimum_required(VERSION 3.21)
project(Project3)

set(CMAKE_CXX_STANDARD 23)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)

include_directories(${GTK4_INCLUDE_DIRS})
link_directories(${GTK4_LIBRARY_DIRS})

add_definitions(${GTK4_CFLAGS_OTHER})
option(USE_CLASP "add Clasp and potassco libaries to compile" ON)
if(USE_CLASP)
    find_library(LIB1 clasp ${CMAKE_SOURCE_DIR}/lib)
    find_library(LIB2 potassco ${CMAKE_SOURCE_DIR}/lib)
    find_path(LIB_INCLUDE clasp/config.h potassco/platform.h ${CMAKE_SOURCE_DIR}/include)
    include_directories(${LIB_INCLUDE})
endif()

file(GLOB SOURCES "src/*.cpp")
add_executable(Project3 ${SOURCES})
target_link_libraries(Project3 PUBLIC ${GTK4_LIBRARIES} ${LIB1} ${LIB2})
