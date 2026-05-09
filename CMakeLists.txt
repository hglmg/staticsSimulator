cmake_minimum_required(VERSION 3.16)

project(staticsSimulator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(staticsSimulator main.cpp
    punkt.h punkt.cpp
    pret.h pret.cpp
    podpora.h podpora.cpp
    obciazeniepunktowe.h obciazeniepunktowe.cpp
    obciazeniekonstrukcyjne.h obciazeniekonstrukcyjne.cpp
    silnikobliczeniowy.h silnikobliczeniowy.cpp
    aplikacjasymulatora.h aplikacjasymulatora.cpp
    kontenersiatki.h kontenersiatki.cpp
    obliczenie.h obliczenie.cpp
)
 
include(GNUInstallDirs)
install(TARGETS staticsSimulator
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
