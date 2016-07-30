#include "../data/Item.h"
#include "../algorithm/ItemPosition.h"
#include "../algorithm/Vector.h"

#include <gtest/gtest.h>

using namespace PACKING;

TEST(Intersect, NoXIntersection)
{
	Item item(10,10,10,false);
    ItemPosition pos(item,0,0,0);
    Vector vec(5,10,10,X_AXIS);
    EXPECT_FALSE(pos.intersects(vec));
}

TEST(Intersect, XIntersection)
{
	Item item(10,10,10,false);
    ItemPosition pos(item,0,0,0);
    Vector vec(10,5,5,X_AXIS);
    EXPECT_TRUE(pos.intersects(vec));
}

TEST(Intersect, NoYIntersection)
{
	Item item(10,10,10,false);
    ItemPosition pos(item,0,0,0);
    Vector vec(10,5,10,Y_AXIS);
    EXPECT_FALSE(pos.intersects(vec));
}

TEST(Intersect, YIntersection)
{
	Item item(10,10,10,false);
    ItemPosition pos(item,0,0,0);
    Vector vec(5,10,5,Y_AXIS);
    EXPECT_TRUE(pos.intersects(vec));
}


TEST(Intersect, NoZIntersection)
{
	Item item(10,10,10,false);
    ItemPosition pos(item,0,0,0);
    Vector vec(10,10,5,Z_AXIS);
    EXPECT_FALSE(pos.intersects(vec));
}

TEST(Intersect, ZIntersection)
{
	Item item(10,10,10,false);
    ItemPosition pos(item,0,0,0);
    Vector vec(5,5,10,Z_AXIS);
    EXPECT_TRUE(pos.intersects(vec));
}

TEST(IntersectItems, Intersects)
{
	Item item(10,10,10,false);
    ItemPosition posa(item,0,0,0);
    ItemPosition posb(item,5,5,0);
    EXPECT_TRUE(posa.intersects(posb));
}


TEST(IntersectItems, NoIntersects)
{
	Item item(10,10,10,false);
    ItemPosition posa(item,0,0,0);
    ItemPosition posb(item,10,10,0);
    EXPECT_FALSE(posa.intersects(posb));
}

TEST(FullySupport, DoNotTouch)
{
	Item item(10,10,10,false);
    ItemPosition posa(item,0,0,0);
    ItemPosition posb(item,0,0,11);
    EXPECT_FALSE(posa.fullySupports(posb));
}


TEST(FullySupport, YesSameSize)
{
	Item item(10,10,10,false);
    ItemPosition posa(item,0,0,0);
    ItemPosition posb(item,0,0,10);
    EXPECT_TRUE(posa.fullySupports(posb));
}


TEST(FullySupport, YesNotSameSize)
{
	Item itemA(10,10,10,false);
	Item itemB(8,8,8,false);
    ItemPosition posa(itemA,0,0,0);
    ItemPosition posb(itemB,0,0,10);
    EXPECT_TRUE(posa.fullySupports(posb));
}


TEST(FullySupport, NoTooSmall)
{
	Item itemA(10,10,10,false);
	Item itemB(8,8,8,false);
    ItemPosition posa(itemB,0,0,8);
    ItemPosition posb(itemA,0,0,0);
    EXPECT_FALSE(posa.fullySupports(posb));
}
