/*
 * Vector.h
 *
 *  Created on: Jul 28, 2016
 *      Author: renaud
 */

#ifndef ALGORITHM_VECTOR_H_
#define ALGORITHM_VECTOR_H_

namespace PACKING {

enum Direction
{
	X_AXIS,
	Y_AXIS,
	Z_AXIS
};

class Vector {
public:
	Vector(long x, long y, long z, Direction direction)
	: m_x(x)
	, m_y(y)
	, m_z(z)
	, m_direction(direction)
	{

	}

	virtual ~Vector()
	{

	}

	Direction getDirection() const {
		return m_direction;
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
	long            m_x;
	long            m_y;
	long            m_z;
	Direction       m_direction;

};

} /* namespace PACKING */

#endif /* ALGORITHM_VECTOR_H_ */
