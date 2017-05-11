#include <vector>
#include "EKUtils/List.h"
#include "EKUtils/Utils.h"
#include "EKUtils/Algorithms.h"

// Test Functions decl
// Then create a test project
void TestList();
void TestQS();
void TestSwap();

void main() {
	TestQS();
}

// Function for list tests
void TestList(){
	EKUtil::List<int> list;

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
	EKUtil::LOG("TESTING INSERT REMOVE");
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

void TestQS()
{
	std::vector<int> myVec;

	EKUtil::LOG("TEST EMPTY SORTING");
	EKUtil::PrintContainer(myVec);
	EKUtil::Algorithms::Quicksort(myVec, 0, myVec.size() - 1);
	EKUtil::PrintContainer(myVec);

	myVec.push_back(5);
	myVec.push_back(0);

	EKUtil::LOG("TEST NORMAL SORTING");
	EKUtil::PrintContainer(myVec);
	EKUtil::Algorithms::Quicksort(myVec, 0, myVec.size() - 1);
	EKUtil::PrintContainer(myVec);
	myVec.push_back(10);
	EKUtil::Algorithms::Quicksort(myVec, 0, myVec.size() - 1);
	EKUtil::PrintContainer(myVec);



	EKUtil::LOG("TEST SIGNED SORTING");
	myVec.push_back(-10);
	EKUtil::PrintContainer(myVec);
	EKUtil::Algorithms::Quicksort(myVec, 0, myVec.size() - 1);
	EKUtil::PrintContainer(myVec);

	EKUtil::LOG("TEST SAME SORTING");
	myVec.push_back(6);
	myVec.push_back(6);
	EKUtil::PrintContainer(myVec);
	EKUtil::Algorithms::Quicksort(myVec, 0, myVec.size() - 1);
	EKUtil::PrintContainer(myVec);





}

void TestSwap ( ) {
	int a = -5;
	int b = 5;

	EKUtil::Swap(a, b);

	EKUtil::LOG("a: ", a, "b: ", b);

}
