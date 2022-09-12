#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "rectangleobject.h"
#include "gamebounds.h"


using namespace testing;

TEST(RectangleObject, Collision)
{
    sf::Clock clock;
    sf::Time time;
    RectangleObject object1;
    GameBounds bounds;
    sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();
    sf::Vector2f velocity = sf::Vector2f(2000,0);

    bounds.setSize(videoMode);
    bounds.setOrigin();
    bounds.setPosition(videoMode);

    object1.setSize(sf::Vector2f(20,20));
    object1.setPosition(videoMode.width/2, videoMode.height/2);
    object1.setVelocity(velocity);


    bool test;

        do
        {
            time = clock.restart();
            object1.move(velocity.x*time.asSeconds(), velocity.y*time.asSeconds());
            test =  object1.accesscollisionSensor().at(RectangleObject::Sensors::Right).getGlobalBounds().intersects(bounds.accessBounds().at(GameBounds::Bounds::Right).getGlobalBounds());
        }while(!test);
        EXPECT_TRUE(test);

        velocity.x = -2000;
        object1.setVelocity(velocity);
        object1.setPosition(videoMode.width/2, videoMode.height/2);
        do
        {
            time = clock.restart();
            object1.move(velocity.x*time.asSeconds(), velocity.y*time.asSeconds());
            test =  object1.accesscollisionSensor().at(RectangleObject::Sensors::Left).getGlobalBounds().intersects(bounds.accessBounds().at(GameBounds::Bounds::Left).getGlobalBounds());
        }while(!test);
        EXPECT_TRUE(test);

        velocity.x = 0;
        velocity.y = -2000;
        object1.setVelocity(velocity);
        object1.setPosition(videoMode.width/2, videoMode.height/2);
        do
        {
            time = clock.restart();
            object1.move(velocity.x*time.asSeconds(), velocity.y*time.asSeconds());
            test =  object1.accesscollisionSensor().at(RectangleObject::Sensors::Top).getGlobalBounds().intersects(bounds.accessBounds().at(GameBounds::Bounds::Top).getGlobalBounds());
        }while(!test);
        EXPECT_TRUE(test);

        velocity.y = 2000;
        object1.setVelocity(velocity);
        object1.setPosition(videoMode.width/2, videoMode.height/2);
        do
        {
            time = clock.restart();
            object1.move(velocity.x*time.asSeconds(), velocity.y*time.asSeconds());
            test =  object1.accesscollisionSensor().at(RectangleObject::Sensors::Bottom).getGlobalBounds().intersects(bounds.accessBounds().at(GameBounds::Bounds::Bottom).getGlobalBounds());
        }while(!test);
        EXPECT_TRUE(test);
}

TEST(RectangleObject, CollisionCloseObject)
{
    RectangleObject object1, object2, object3, object4;
    sf::Clock clock;
    sf::Time time;
    sf::Vector2f velocity = sf::Vector2f(2000,0);

    object1.setSize(sf::Vector2f(20,20));
    object2.setSize(sf::Vector2f(20,200));
    object3.setSize(sf::Vector2f(20,200));
    object4.setSize(sf::Vector2f(20,200));

    object1.setVelocity(velocity);
    object1.setPosition(0,0);
    object2.setPosition(500,0);
    object3.setPosition(501,0);
    object4.setPosition(502,0);

    object1.resetMinDistCollision();
    object1.functionCollisionX = []{EXPECT_TRUE(false);};
    bool testColl1 = false, testColl2 = false, testColl3 =false;
    do
    {
        time = clock.restart();
        object1.move(velocity.x*time.asSeconds(), velocity.y*time.asSeconds());
        testColl1 = object1.accesscollisionSensor().at(RectangleObject::Sensors::Right).getGlobalBounds().intersects(object2.getGlobalBounds());
        testColl2 = object1.accesscollisionSensor().at(RectangleObject::Sensors::Right).getGlobalBounds().intersects(object3.getGlobalBounds());
        testColl3 = object1.accesscollisionSensor().at(RectangleObject::Sensors::Right).getGlobalBounds().intersects(object4.getGlobalBounds());
        if(testColl3 && testColl2 && testColl1)
        {
               if(object1.checkMinDistCollisionX(object2))
                   object1.functionCollisionX = []{EXPECT_TRUE(true);};
               if(object1.checkMinDistCollisionX(object3))
                   object1.functionCollisionX = []{EXPECT_TRUE(false);};
               if(object1.checkMinDistCollisionX(object4))
                   object1.functionCollisionX = []{EXPECT_TRUE(false);};
        }
    }while(!testColl1 || !testColl2 || !testColl3);
    object1.functionCollisionX();

    object1.resetMinDistCollision();
    object1.functionCollisionX = []{EXPECT_TRUE(false);};
    testColl1 = false, testColl2 = false, testColl3 =false;
    object1.setPosition(0,0);
    do
    {
        time = clock.restart();
        object1.move(velocity.x*time.asSeconds(), velocity.y*time.asSeconds());
        testColl3 = object1.accesscollisionSensor().at(RectangleObject::Sensors::Bottom).getGlobalBounds().intersects(object4.getGlobalBounds());
        testColl2 = object1.accesscollisionSensor().at(RectangleObject::Sensors::Bottom).getGlobalBounds().intersects(object3.getGlobalBounds());
        testColl1 = object1.accesscollisionSensor().at(RectangleObject::Sensors::Bottom).getGlobalBounds().intersects(object2.getGlobalBounds());
        if(testColl3 && testColl2 && testColl1)
        {
           if(object1.checkMinDistCollisionX(object4))
               object1.functionCollisionX = []{EXPECT_TRUE(false);};
           if(object1.checkMinDistCollisionX(object3))
               object1.functionCollisionX = []{EXPECT_TRUE(false);};
           if(object1.checkMinDistCollisionX(object2))
               object1.functionCollisionX = []{EXPECT_TRUE(true);};
        }
    }while(!testColl1 || !testColl2 || !testColl3);
    object1.functionCollisionX();

    object1.resetMinDistCollision();
    object1.functionCollisionY = []{EXPECT_TRUE(false);};
    testColl1 = false, testColl2 = false, testColl3 =false;
    object2.setSize(sf::Vector2f(200,20));
    object3.setSize(sf::Vector2f(200,20));
    object4.setSize(sf::Vector2f(200,20));
    velocity.x = 0;
    velocity.y = 2000;
    object1.setVelocity(velocity);
    object1.setPosition(0,0);
    object2.setPosition(0,500);
    object3.setPosition(0,501);
    object4.setPosition(0,502);
    do
    {
        time = clock.restart();
        object1.move(velocity.x*time.asSeconds(), velocity.y*time.asSeconds());
        testColl1 = object1.accesscollisionSensor().at(RectangleObject::Sensors::Bottom).getGlobalBounds().intersects(object2.getGlobalBounds());
        testColl2 = object1.accesscollisionSensor().at(RectangleObject::Sensors::Bottom).getGlobalBounds().intersects(object3.getGlobalBounds());
        testColl3 = object1.accesscollisionSensor().at(RectangleObject::Sensors::Bottom).getGlobalBounds().intersects(object4.getGlobalBounds());
        if(testColl3 && testColl2 && testColl1)
        {
           if(object1.checkMinDistCollisionX(object2))
               object1.functionCollisionY = []{EXPECT_TRUE(true);};
           if(object1.checkMinDistCollisionX(object3))
               object1.functionCollisionY = []{EXPECT_TRUE(false);};
           if(object1.checkMinDistCollisionX(object4))
               object1.functionCollisionY = []{EXPECT_TRUE(false);};
        }
    }while(!testColl1 || !testColl2 || !testColl3);
    object1.functionCollisionY();

    object1.resetMinDistCollision();
    object1.functionCollisionY = []{EXPECT_TRUE(false);};
    testColl1 = false, testColl2 = false, testColl3 = false;
    object1.setPosition(0,0);
    do
    {
        time = clock.restart();
        object1.move(velocity.x*time.asSeconds(), velocity.y*time.asSeconds());
        testColl3 = object1.accesscollisionSensor().at(RectangleObject::Sensors::Bottom).getGlobalBounds().intersects(object4.getGlobalBounds());
        testColl2 = object1.accesscollisionSensor().at(RectangleObject::Sensors::Bottom).getGlobalBounds().intersects(object3.getGlobalBounds());
        testColl1 = object1.accesscollisionSensor().at(RectangleObject::Sensors::Bottom).getGlobalBounds().intersects(object2.getGlobalBounds());
        if(testColl3 && testColl2 && testColl1)
        {
               if(object1.checkMinDistCollisionY(object4))
                   object1.functionCollisionY = []{EXPECT_TRUE(false);};
               if(object1.checkMinDistCollisionY(object3))
                   object1.functionCollisionY = []{EXPECT_TRUE(false);};
               if(object1.checkMinDistCollisionY(object2))
                   object1.functionCollisionY = []{EXPECT_TRUE(true);};
        }
    }while(!testColl1 || !testColl2 || !testColl3);
    object1.functionCollisionY();

}
