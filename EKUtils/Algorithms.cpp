#ifndef ALGORITHMS_CPP_
#define ALGORITHMS_CPP_

#include "Algorithms.h"

namespace EKUtil {

	template < typename ContainerType >
	void Algorithms::Quicksort(ContainerType& container, unsigned lowestIndex, unsigned highestIndex) {
		if (lowestIndex == highestIndex || container.empty())
			return;

		Algorithms::QuicksortRec(container, lowestIndex, highestIndex);
	}

	template < typename ContainerType >
	void Algorithms::QuicksortRec(ContainerType& container, unsigned lowestIndex, unsigned highestIndex) {
		if (lowestIndex < highestIndex) {
			unsigned pivotIndex = Algorithms::Partition(container, lowestIndex, highestIndex);
			Algorithms::QuicksortRec(container, lowestIndex, pivotIndex);
			Algorithms::QuicksortRec(container, pivotIndex + 1, highestIndex);
		}
	}

	template < typename T >
	unsigned Algorithms::Partition(T& container, unsigned low, unsigned high) {
		int pivot = container[low];
		unsigned leftWall = low;

		for (unsigned i = low + 1; i <= high; ++i) {
			if (container[i] < pivot)
				Swap(container[i], container[leftWall++]);
		}

		Swap(pivot, container[leftWall]);

		return leftWall;
	}

}

#endif