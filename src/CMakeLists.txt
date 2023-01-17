cmake_minimum_required(VERSION 3.24)

add_executable(uniTeller_ru
        main.cpp
        Ident.cpp
        )

target_include_directories(uniTeller_ru PUBLIC ${INCLUDE_DIR})
