add_library(Random STATIC
    Random.cpp
)

target_include_directories(Random PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Random PRIVATE Game)