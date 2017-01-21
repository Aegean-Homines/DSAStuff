#ifndef MY_LIST_H_
#define MY_LIST_H_

#include <iostream>

template <typename T>
struct ListElement {
	T element;
	ListElement* next;
	ListElement* prev;

	ListElement(T const & element)
		: element(element), next(nullptr), prev(nullptr)
	{}
};

template <typename T>
class List {
public:
	List() 
		: front(nullptr), back(nullptr), size(0)
	{}

	// interface for the client
	// Add element to the back of the list
	void PushBack(T const & element) {
		Insert(element, size);
	}

	// Remove element from the back of the list
	void PopBack() {
		Remove(size);
	}

	// Add element to the front of the list
	void PushFront(T const & element) {
		Insert(element, 0);
	}

	// Remove element from the front of the list
	void PopFront() {
		Remove(0);
	}

	// Insert element at index
	void Insert(T const & element, unsigned int index) {
		if (index > size) {
			return;
		}

		if (size == 0) { // First Insertion
			front = new ListElement<T>(element);
			front->prev = nullptr;
			back = front;
			front->next = back;
			++size;
			return;
		}

		if (index == 0) { //PushFront
			front->prev = new ListElement<T>(element);
			front->prev->next = front;
			front = front->prev;
		}
		else if (index == size) { //PushBack
			back->next = new ListElement<T>(element);
			back->next->prev = back;
			back = back->next;
			back->next = nullptr;
		}
		else { //Push inbetween (O(n))
			ListElement<T>* insertionPlace = front;
			for (unsigned int i = 0; i < index; ++i)
				insertionPlace = insertionPlace->next;

			ListElement<T>* newElement = new ListElement<T>(element);
			insertionPlace->prev->next = newElement;
			newElement->prev = insertionPlace->prev;
			insertionPlace->prev = newElement;
			newElement->next = insertionPlace;
		}

		++size;
	}

	// Remove element at index
	void Remove(unsigned int index) {
		if (index > size || size == 0) {
			return;
		}
		ListElement<T>* elementToBeRemoved;
		if (index == 0) {//PopFront
			elementToBeRemoved = front;
			front = front->next;
			if(front)
				front->prev = nullptr;
		}
		else if (index == size) { //PopBack
			elementToBeRemoved = back;
			back = back->prev;
			if(back)
				back->next = nullptr;
		}
		else {// Remove inbetween (O(n))
			elementToBeRemoved = front;
			for (int i = 0 ; i != index; ++i)
				elementToBeRemoved = elementToBeRemoved->next;

			elementToBeRemoved->prev->next = elementToBeRemoved->next;
			elementToBeRemoved->next->prev = elementToBeRemoved->prev;
		}

		--size;
		delete elementToBeRemoved;
	}

	// Remove all elements
	void Clear() {
		std::cout << "CLEARING THE LIST" << std::endl;
		ListElement<T>* iter = front;
		for (unsigned int i = 0; i < size; ++i) {
			front = front->next;
			delete iter;
			iter = front;
		}
		std::cout << "LIST CLEARED!" << std::endl;
		size = 0;
	}

	// Print all elements
	void Print() {
		ListElement<T>* iter = front;
		std::cout << std::endl;
		std::cout << "PRINTING LIST" << std::endl;
		for (unsigned int i = 0; i < size; ++i) {
			std::cout << iter->element << std::endl;
			iter = iter->next;
		}
		std::cout << "END OF LIST" << std::endl;
		std::cout << std::endl;
	}

private:
	ListElement<T>* front;
	ListElement<T>* back;

	unsigned int size;
};

#endif