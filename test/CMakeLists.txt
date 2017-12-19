find_package(GTest REQUIRED)

include_directories (${emerald_SOURCE_DIR}/src)

add_executable(game-test GameTest.cpp)
target_link_libraries(game-test gtest_main emerald)
add_test(NAME game_test COMMAND game-test)