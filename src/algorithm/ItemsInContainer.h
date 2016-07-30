/*
 * ItemsInContainer.h
 *
 *  Created on: Jul 28, 2016
 *      Author: renaud
 */

#ifndef ALGORITHM_ITEMSINCONTAINER_H_
#define ALGORITHM_ITEMSINCONTAINER_H_

#include "ExtremPoint.h"
#include "ItemPosition.h"
#include "../data/Container.h"

#include <memory>
#include <set>
#include <vector>

namespace PACKING {

class ItemsInContainer {
public:
	ItemsInContainer(const Container& container);
	virtual ~ItemsInContainer();

	long insertItems(const std::vector<Item> &items);

	const ExtremPoint* findFirstPossiblePoint(const Item& item);

	void insertNodeAtPoint(const Item& item, const ExtremPoint& point);

	const std::set<std::unique_ptr<ExtremPoint>, ExtremPointComparator > &getExtremPoints() const {
		return m_extremPoints;
	}

	const std::vector<std::unique_ptr<ItemPosition> > &getItemPositions() const {
		return m_itemPositions;
	}

	long getMaxLength() const {
		return m_maxLength;
	}

	void setSmallestHeight(long smallestHeight) {
		m_smallestHeight = smallestHeight;
	}

	void setSmallestLength(long smallestLength) {
		m_smallestLength = smallestLength;
	}

	void setSmallestWidth(long smallestWidth) {
		m_smallestWidth = smallestWidth;
	}

private:

	void computeNewExtremPoints(const ItemPosition& newPos);

	void computeNewExtremPoints(long x, long y, long z);

	void insertExtremPoint(long x, long y, long z);

	bool isPossiblePoint(const Item& item, const ExtremPoint &point) const;

	const Container&                                m_container;     //!< the container.
	std::vector< std::unique_ptr<ItemPosition > >   m_itemPositions; //!< the items positions.
	std::set< std::unique_ptr<ExtremPoint >, ExtremPointComparator >    m_extremPoints;  //!< the extrem points.
	long                                            m_maxLength;
	long                                            m_smallestLength;
	long                                            m_smallestWidth;
	long                                            m_smallestHeight;
};

} /* namespace PACKING */

#endif /* ALGORITHM_ITEMSINCONTAINER_H_ */
