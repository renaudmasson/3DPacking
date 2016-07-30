/*
 * ItemsInContainer.cpp
 *
 *  Created on: Jul 28, 2016
 *      Author: renaud
 */

#include "ItemsInContainer.h"
#include "Vector.h"

using namespace PACKING;

#include <memory>

ItemsInContainer::ItemsInContainer(const Container& container)
: m_container(container)
{
	m_extremPoints.insert(std::unique_ptr<ExtremPoint>(new ExtremPoint(0,0,0)));
	m_maxLength = 0;
	m_smallestHeight = 1;
	m_smallestLength = 1;
	m_smallestWidth = 1;
}

ItemsInContainer::~ItemsInContainer() {

}

const ExtremPoint* PACKING::ItemsInContainer::findFirstPossiblePoint(
		const Item& item)
{
	for(auto& point: m_extremPoints)
	{
		if(isPossiblePoint(item, *point.get()))
		{
			return point.get();
		}
	}
	return nullptr;
}

void PACKING::ItemsInContainer::insertNodeAtPoint(const Item& item,
		const ExtremPoint& point)
{
	auto extremX = point.getX() + item.getLength();
	m_itemPositions.push_back(std::unique_ptr<ItemPosition>(new ItemPosition(item, point.getX(), point.getY(), point.getZ())));

	for(auto it = m_extremPoints.begin(); it != m_extremPoints.end(); ++it)
	{
		auto &currPoint = *it;
		if(currPoint.get() == &point)
		{
			m_extremPoints.erase(it);
			break;
		}
	}

	if(extremX > m_maxLength)
	{
		m_maxLength = extremX;
	}
	computeNewExtremPoints(*m_itemPositions.back().get());
}

void PACKING::ItemsInContainer::computeNewExtremPoints(
		const ItemPosition& newPos) {
	computeNewExtremPoints(newPos.getX(), newPos.getY(), newPos.getZ() + newPos.getItem().getHeight());
	computeNewExtremPoints(newPos.getX(), newPos.getY() + newPos.getItem().getWidth(), newPos.getZ());
	computeNewExtremPoints(newPos.getX() + newPos.getItem().getLength(), newPos.getY(), newPos.getZ());
}

void PACKING::ItemsInContainer::computeNewExtremPoints(long x, long y, long z)
{

	Vector vecX(x,y,z,Direction::X_AXIS);
	Vector vecY(x,y,z,Direction::Y_AXIS);
	Vector vecZ(x,y,z,Direction::Z_AXIS);
	long largestX = 0;
	long largestY = 0;
	long largestZ = 0;
	for(auto &pos: m_itemPositions)
	{
		auto endPosX = pos->getX() + pos->getItem().getLength();
		if(pos->intersects(vecX) && endPosX > largestX && endPosX <= x)
		{
			largestX = endPosX;
		}
		auto endPosY = pos->getY() + pos->getItem().getWidth();
		if(pos->intersects(vecY) && endPosY > largestY && endPosY <= y)
		{
			largestY = endPosY;
		}
		auto endPosZ = pos->getZ() + pos->getItem().getHeight();
		if(pos->intersects(vecZ) && endPosZ > largestZ && endPosZ <= z)
		{
			largestZ = endPosZ;
		}
	}
	insertExtremPoint(largestX, y, z);
	insertExtremPoint(x, largestY, z);
	insertExtremPoint(x, y, largestZ);

}

void PACKING::ItemsInContainer::insertExtremPoint(long x, long y, long z)
{
	if(x + m_smallestLength > m_container.getLength()
	|| y + m_smallestWidth > m_container.getWidth()
	|| z + m_smallestHeight > m_container.getHeight())
	{
		return;
	}

	m_extremPoints.insert(std::unique_ptr<ExtremPoint>(new ExtremPoint(x,y,z)));
}

long PACKING::ItemsInContainer::insertItems(const std::vector<Item>& items)
{
	long insertCount = 0;
	for(auto &item: items)
	{
		auto *ep = findFirstPossiblePoint(item);
		if(ep)
		{
			++insertCount;
			insertNodeAtPoint(item, *ep);
		}
	}
	return insertCount;
}

bool PACKING::ItemsInContainer::isPossiblePoint(const Item& item,
		const ExtremPoint& point) const {
	if(point.getX() + item.getLength() > m_container.getLength())
		{
			return false;
		}

	if(point.getY() + item.getWidth() > m_container.getWidth())
		{
			return false;
		}

	if(point.getZ() + item.getHeight() > m_container.getHeight())
		{
			return false;
		}


	ItemPosition pos(item, point.getX(), point.getY(), point.getZ());
	for(auto &otherPosition: m_itemPositions)
	{
		if(pos.intersects(*otherPosition.get()))
		{
			return false;
		}
	}

	if(point.getZ() == 0)
	{
		return true;
	}

	for(auto &otherPosition: m_itemPositions)
		{
			if(otherPosition->fullySupports(pos))
			{
				return true;
			}
		}

	return false;

}
