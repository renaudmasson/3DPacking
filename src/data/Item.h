/*
 * Item.h
 *
 *  Created on: Jul 28, 2016
 *      Author: renaud
 */

#ifndef DATA_ITEM_H_
#define DATA_ITEM_H_

namespace PACKING {

class Item {
public:
	Item(long height, long length, long width, bool rotatable)
    	: m_length(length)
    	, m_width(width)
    	, m_height(height)
    	, m_rotatable(rotatable)
	{

	}
	virtual ~Item()
	{

	}

	long getHeight() const {
		return m_height;
	}

	long getLength() const {
		return m_length;
	}

	bool isRotatable() const {
		return m_rotatable;
	}

	long getWidth() const {
		return m_width;
	}

private:
	long         m_length;    //!< length of the item
	long         m_width;     //!< width of the item
	long         m_height;    //!< height of the item
	bool         m_rotatable; //!< can width and length be swapped.
};

} /* namespace PACKING */

#endif /* DATA_ITEM_H_ */
