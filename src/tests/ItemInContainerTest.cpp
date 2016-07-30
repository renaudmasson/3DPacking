#include "../data/Item.h"
#include "../data/Container.h"
#include "../algorithm/ItemPosition.h"
#include "../algorithm/ItemsInContainer.h"
#include "../algorithm/ExtremPoint.h"

#include <gtest/gtest.h>

using namespace PACKING;

TEST(FindExtremPoint, Origin)
{
	Item item(10,10,10,false);
    Container container(100,30,25);
    ItemsInContainer containerState(container);
    auto *firstEp = containerState.findFirstPossiblePoint(item);
    EXPECT_TRUE(firstEp != nullptr);
    EXPECT_TRUE(firstEp->getX() == 0);
    EXPECT_TRUE(firstEp->getY() == 0);
    EXPECT_TRUE(firstEp->getZ() == 0);
}

TEST(Insert, Origin)
{
	Item item(10,10,10,false);
    Container container(100,30,25);
    ItemsInContainer containerState(container);

    auto *firstEp = containerState.findFirstPossiblePoint(item);
    if(firstEp)
    {
    	containerState.insertNodeAtPoint(item, *firstEp);
    }
    EXPECT_TRUE(containerState.getExtremPoints().size() == 3);

}

TEST(Insert, TwoInsert)
{
	Item item(10,10,10,false);
    Container container(100,30,25);
    ItemsInContainer containerState(container);

    auto *firstEp = containerState.findFirstPossiblePoint(item);
    if(firstEp)
    {
    	containerState.insertNodeAtPoint(item, *firstEp);
    }
    auto *secondEp = containerState.findFirstPossiblePoint(item);
    if(secondEp)
	{
		containerState.insertNodeAtPoint(item, *secondEp);
	}
    EXPECT_TRUE(containerState.getItemPositions().back()->getX() == 0 && containerState.getItemPositions().back()->getY() == 0 && containerState.getItemPositions().back()->getZ() == 10);
}

TEST(Insert, Multiple)
{
	std::vector<Item> items;
	items.push_back(Item(20,10,25,false));
	items.push_back(Item(10,10,15,false));
	items.push_back(Item(10,10,15,false));
	items.push_back(Item(10,10,15,false));
	items.push_back(Item(10,10,15,false));
	items.push_back(Item(20,10,5,false));


    Container container(25,100,30);
    ItemsInContainer containerState(container);

    auto nbInserted = containerState.insertItems(items);

    EXPECT_EQ(nbInserted, 6);
    EXPECT_EQ(containerState.getMaxLength(), 20);
}

TEST(Insert, Many)
{
	std::vector<Item> items;
	for(long i = 0; i < 300; ++i)
	{
		items.push_back(Item(5,3,5,false));
	}
	Container container(25,100,30);
	ItemsInContainer containerState(container);

	auto nbInserted = containerState.insertItems(items);

	EXPECT_EQ(nbInserted, 300);
}
