/*
 * ExtremPoint.h
 *
 *  Created on: Jul 28, 2016
 *      Author: renaud
 */

#ifndef ALGORITHM_EXTREMPOINT_H_
#define ALGORITHM_EXTREMPOINT_H_

#include <memory>

namespace PACKING {

class ExtremPoint {
public:
	ExtremPoint(long x, long y, long z)
	: m_x(x)
	, m_y(y)
	, m_z(z)
	{

	}

	virtual ~ExtremPoint() {}

	bool equals(const ExtremPoint &other) const
	{
		return m_x==other.m_x && m_y==other.m_y && m_z==other.m_z;
	}

	long getX() const {
		return m_x;
	}

	long getY() const {
		return m_y;
	}

	long getZ() const {
		return m_z;
	}

private:

	long    m_x;
	long    m_y;
	long    m_z;
};

class ExtremPointComparator
{
public:
	bool operator()(const std::unique_ptr<ExtremPoint>& a, const std::unique_ptr<ExtremPoint>& b)
	{
		if(a->getX() < b->getX())
		{
			return true;
		}
		else if(a->getX() == b->getX())
		{
			if(a->getY() < b->getY())
			{
				return true;
			}
			else if(a->getY() == b->getY())
			{
				if(a->getZ() < b->getZ())
				{
					return true;
				}
			}
		}
		return false;
	}
};

} /* namespace PACKING */

#endif /* ALGORITHM_EXTREMPOINT_H_ */
