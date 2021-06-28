cmake_minimum_required(VERSION 3.19)
project(134_Chelaru_Paul_Proiect3_tema7)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(134_Chelaru_Paul_Proiect3_tema7
        Card.cpp
        Card.h
        ContBancar.cpp
        ContBancar.h
        ContCurent.cpp
        ContCurent.h
        ContEconomii.cpp
        ContEconomii.h
        GestionareConturi.h
        main.cpp
        Menu.cpp
        Menu.h
        Persoana.cpp
        Persoana.h)
