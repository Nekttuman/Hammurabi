add_library(Serialisation STATIC
    Serialisation.cpp
)

target_include_directories(Serialisation PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})