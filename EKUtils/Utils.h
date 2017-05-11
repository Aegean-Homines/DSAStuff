#pragma once
#include <iostream>

namespace EKUtil {
	static void LOG() {
		std::cout << std::endl;
	}

	// Helper function for printing lines and debugging (because boy is it necessary)
	template<typename Word, typename ...Rest>
	static void LOG(Word && word, Rest && ...rest) {
		std::cout << word << std::endl;
		LOG(std::forward<Rest>(rest)...);
	}

	template<typename T>
	static void PrintContainer(T & container) {
		for(auto member : container) {
			std::cout << member << " ";
		}

		std::cout << std::endl;
	}
}
