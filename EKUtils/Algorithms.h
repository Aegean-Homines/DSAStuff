#pragma once

namespace EKUtil {

	static void Swap(int & x, int & y) {
		if ((x != y) || (&x == &y) ){
			x = x ^ y;
			y = x ^ y;
			x = x ^ y;
		}
	}

	class Algorithms {
	public:

		template<typename ContainerType>
		void static Quicksort ( ContainerType& container, unsigned lowestIndex, unsigned highestIndex );

	private:

		template<typename ContainerType>
		void static QuicksortRec ( ContainerType& container, unsigned lowestIndex, unsigned highestIndex );

		template<typename T>
		static unsigned Partition ( T& container, unsigned low, unsigned high );
	};


}


#include "Algorithms.cpp"
