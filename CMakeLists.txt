cmake_minimum_required(VERSION 3.20)
project(hamurabi CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


set(MODULES
    Game
    UserInteraction
    Serialisation
    Random
)

set(MODULE_INCLUDE_DIRS
    src/Game
    src/UserInteraction
    src/Serialisation
    src/Random
)

foreach(MODULE ${MODULES})
    add_subdirectory(src/${MODULE})
endforeach()

add_executable(hamurabi src/main.cpp)

target_include_directories(hamurabi PRIVATE ${MODULE_INCLUDE_DIRS})
target_link_libraries(hamurabi PRIVATE ${MODULES})


# ——— Тесты ———
enable_testing() 

file(GLOB TEST_SOURCES tests/*.cpp)

if(TEST_SOURCES)
    add_executable(my_tests ${TEST_SOURCES})

    target_include_directories(my_tests PRIVATE ${MODULE_INCLUDE_DIRS})
    target_link_libraries(my_tests PRIVATE ${MODULES})

    add_test(NAME AllTests COMMAND my_tests)
endif()