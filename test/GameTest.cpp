#include "Game.h"
#include "gtest/gtest.h"

TEST(GameTest, Constructor) {
    Game g("Game", 1, 2, nullptr);
    EXPECT_EQ(g.title, "Game");
    EXPECT_EQ(g.width, 1);
    EXPECT_EQ(g.height, 2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}