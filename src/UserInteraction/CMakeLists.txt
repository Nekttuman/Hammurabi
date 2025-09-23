add_library(UserInteraction STATIC
    UserInteraction.cpp
)

target_include_directories(UserInteraction PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(UserInteraction PRIVATE Game)