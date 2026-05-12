cmake_minimum_required(VERSION 3.16)

project(staticsSimulator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



add_executable(staticsSimulator main.cpp
    punkt.h punkt.cpp
    pret.h pret.cpp
    podpora.h podpora.cpp
    obciazenie.h obciazenie.cpp

    silnikobliczeniowy.h silnikobliczeniowy.cpp
    aplikacjasymulatora.h aplikacjasymulatora.cpp
    kontenersiatki.h kontenersiatki.cpp
    obliczenie.h obliczenie.cpp
    Konstruktor.h Konstruktor.cpp
    sila.h sila.cpp)

target_include_directories(staticsSimulator PRIVATE
    ${CMAKE_SOURCE_DIR}/Eigen
)
 
include(GNUInstallDirs)
install(TARGETS staticsSimulator
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
