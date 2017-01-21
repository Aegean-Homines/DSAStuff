#include "List.h"
#include <iostream>
#include <list>

struct anan {
	long baban;
};

// Test Functions decl
// TODO: When you're done, wrap everything up in a DLL
// Then create a test project
void TestList();

void main() {
	TestList();
}

// Function for list tests
void TestList(){
	List<int> list;

	// Fill list from behind
	// This might be the dirtiest comment I've ever written
	for (int i = 0; i < 10; ++i) {
		list.PushBack(i);
	}

	list.Print();

	// Remove elements from behind
	for (int i = 0; i < 10; ++i) {
		list.PopBack();
	}

	list.Print();

	// Fill list from front
	for (int i = 0; i < 10; ++i) {
		list.PushFront(i);
	}

	list.Print();

	// Remove all from front
	for (int i = 0; i < 10; ++i) {
		list.PopFront();
	}

	list.Print();

	// TESTING CLEAR
	for (int i = 0; i < 5; ++i) {
		list.PushFront(i);
	}

	list.Print();
	list.Clear();
	list.Print();

	for (int i = 0; i < 5; ++i) {
		list.PushBack(i);
	}

	list.Print();
	list.Clear();
	list.Print();

	// TESTING INSERT REMOVE
	std::cout << "TESTING INSERT REMOVE" << std::endl;
	for (int i = 0; i < 5; ++i) {
		list.PushFront(i);
	}
	list.Print();
	// Insert and remove the same element
	list.Insert(3, 2);
	list.Print();
	list.Remove(2);
	list.Print();
}