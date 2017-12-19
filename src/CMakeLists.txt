find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_library(emerald Game.cpp State.cpp)
target_link_libraries(emerald ${SDL2_LIBRARIES})
