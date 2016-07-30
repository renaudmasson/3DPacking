/*
 * ItemPosition.cpp
 *
 *  Created on: Jul 28, 2016
 *      Author: renaud
 */

#include "ItemPosition.h"
#include "Vector.h"

#include <cassert>

using namespace PACKING;



bool ItemPosition::intersects(const Vector& vector) const {
	switch(vector.getDirection())
	{
	case X_AXIS: return intersectsXAxis(vector.getY(), vector.getZ());
	case Y_AXIS: return intersectsXAxis(vector.getX(), vector.getZ());
	case Z_AXIS: return intersectsXAxis(vector.getX(), vector.getY());
	default: assert(false);
	}
	return false;

}

bool ItemPosition::intersectsXAxis(long y, long z) const {
	return (  m_y <= y
		   && m_y + m_item.getWidth() > y
		   && m_z <= z
		   && m_z + m_item.getHeight() > z);
}

bool ItemPosition::intersectsYAxis(long x, long z) const {
	return (  m_x <= x
		   && m_x + m_item.getLength() > x
		   && m_z <= z
		   && m_z + m_item.getHeight() > z);
}



bool PACKING::ItemPosition::intersects(const ItemPosition& other) const
{
	return (   (intersectsXAxis(other.m_x) || other.intersectsXAxis(m_x))
			&& (intersectsYAxis(other.m_y) || other.intersectsYAxis(m_y))
			&& (intersectsZAxis(other.m_z) || other.intersectsZAxis(m_z)));


}

bool PACKING::ItemPosition::intersectsXAxis(long x) const
{
	return m_x <= x && m_x + m_item.getLength() > x;
}

bool PACKING::ItemPosition::intersectsYAxis(long y) const
{
	return m_y <= y && m_y + m_item.getWidth() > y;
}

bool PACKING::ItemPosition::intersectsZAxis(long z) const
{
	return m_z <= z && m_z + m_item.getHeight() > z;
}

bool PACKING::ItemPosition::fullySupports(const ItemPosition& other) const
{
	return (   m_z + m_item.getHeight() == other.m_z
		    && m_x <= other.m_x && m_x + m_item.getLength() >= other.m_x + other.m_item.getLength()
			&& m_y <= other.m_y && m_y + m_item.getWidth() >= other.m_y + other.m_item.getWidth());
}

bool ItemPosition::intersectsZAxis(long x, long y) const {
	return (   m_x <= x
			   && m_x + m_item.getLength() > x
			   && m_y <= y
			   && m_y + m_item.getWidth() > y);
}
