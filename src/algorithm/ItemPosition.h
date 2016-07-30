/*
 * ItemPosition.h
 *
 *  Created on: Jul 28, 2016
 *      Author: renaud
 */

#ifndef ALGORITHM_ITEMPOSITION_H_
#define ALGORITHM_ITEMPOSITION_H_

#include "../data/Item.h"


namespace PACKING {

class Vector;

class ItemPosition {
public:
	ItemPosition(const Item& item, long x, long y, long z)
	: m_item(item)
	, m_x(x)
	, m_y(y)
	, m_z(z)
	{

	}
	virtual ~ItemPosition()
	{

	}

	const Item& getItem() const {
		return m_item;
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

	bool intersects(const Vector& vector) const;

	bool intersects(const ItemPosition& other) const;

	bool fullySupports(const ItemPosition& other) const;

private:

	bool intersectsXAxis(long x) const;

	bool intersectsYAxis(long y) const;

	bool intersectsZAxis(long z) const;

	bool intersectsXAxis(long y, long z) const;

	bool intersectsYAxis(long x, long z) const;

	bool intersectsZAxis(long x, long y) const;



	const Item&    m_item; //!< The item.
	long           m_x;    //!< x position.
	long           m_y;    //!< y position.
	long           m_z;    //!< z position.
};

} /* namespace PACKING */

#endif /* ALGORITHM_ITEMPOSITION_H_ */
