/*
 * Container.h
 *
 *  Created on: Jul 28, 2016
 *      Author: renaud
 */

#ifndef DATA_CONTAINER_H_
#define DATA_CONTAINER_H_

namespace PACKING {

class Container {
public:
	Container(long height, long length, long width)
	: m_length(length)
	, m_width(width)
	, m_height(height)
	{

	}
	virtual ~Container()
	{

	}

	long getHeight() const {
		return m_height;
	}

	long getLength() const {
		return m_length;
	}


	long getWidth() const {
		return m_width;
	}

private:
	long         m_length;    //!< length of the container
	long         m_width;     //!< width of the container
	long         m_height;    //!< height of the container
};

} /* namespace PACKING */

#endif /* DATA_CONTAINER_H_ */
