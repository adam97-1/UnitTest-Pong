
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../Pong/inc/player.h"


using namespace testing;

TEST(Player, Points)
{
    Player player;
    std::srand(std::time(NULL));
    int rand = std::rand();

    EXPECT_EQ(player.getPoints(), 0);

    player.setPoints(-999);
    EXPECT_EQ(-999, player.getPoints());

    player.setPoints(999);
    EXPECT_EQ(999, player.getPoints());

    player.setPoints(rand);
    EXPECT_EQ(rand, player.getPoints());

    player.setPoints(0);
    player.addPoints(10);
    EXPECT_EQ(10, player.getPoints());

    player.addPoints(-10);
    EXPECT_EQ(0, player.getPoints());

    player.addPoints(rand);
    EXPECT_EQ(rand, player.getPoints());

    player.addPoints(-rand);
    EXPECT_EQ(0, player.getPoints());

    player.addPoints(0);
    EXPECT_EQ(0, player.getPoints());
}

