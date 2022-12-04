// 
// File:    algortricks.cpp
// Author:  Your Glorious Instructor
// Purpose:
// Demonstrate some of the more advanced things one can do with the C++ STL Library
// as taken from https://www.cppstories.com/2014/12/top-5-beautiful-c-std-algorithms/

#include "gtest/gtest.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <locale> // isspace
#include <numeric> // iota
#include <vector>
#include <random>
//#include <functional>   // std::not1

/// 
/// A Little C++ pre-processor trickery here to use the runtime metadata to determine 
/// and print the name of the currently executing function.
///  
#ifndef __func__
	#define __func__ __FUNCTION__
#endif

#define PRINT_TEST_TITLE() std::cout << std::endl << "*** " << __func__ << " ***" << std::endl;

template <typename T> void printAll(T start, T end, const std::string &title = "")
{
	if (!title.empty())
		std::cout << title << " : ";

	for (auto i = start; i != end; ++i)
		std::cout << *i << ", ";
	std::cout << std::endl;
}

//
/// X: random shuffle
///
///
/// std::iota fills a range starting a value and then incrementing.
/// Fills a container from the location noted by the template iterator start to
/// the location end, and then uses the shuffle() numeric algorithm to randomly
/// shuffle that data (while using the STL random library to get good random numbers,
/// none of that srand() and rand() silliness).
///
template <typename T, typename V> void generateRand(T start, T end, V startValue)
{
	std::iota(start, end, startValue);
	std::random_device rd;
    std::mt19937 gen(rd());
	std::shuffle(start, end, gen);
}

/// 
/// 1: insertionSort in just two lines of code
///
/// - Rotate(first, middle, last)- takes a range [first, last) and rotates it
/// - so that the middle element becomes the first in that range.
/// 
/// - upper_bound - Returns an iterator pointing to the first element in the
/// - range [first,last) which compares greater than val. The range should be
/// - already sorted (or at least partitioned).
/// 
/// How do those two elements combine into Insertion sort?
///
/// ```c++
/// std::upper_bound(start, i, *i)
//  ```
/// returns position of the first
/// element greater than *i. Then, the range is shifted, so that i-th element
/// becomes first.

template <typename T> void insertionSort(T start, T end)
{
	for (auto i = start; i != end; ++i)
		std::rotate(std::upper_bound(start, i, *i), i, std::next(i));
}

TEST(FANCYALG,InsertionSort) {
	int intArray[5];
	generateRand(intArray, intArray + 5, 1);
	printAll(intArray, intArray + 5, "before");

	insertionSort(intArray, intArray + 5);
	printAll(intArray, intArray + 5, "after");
}


/// 
/// 2. quick sort made with std::algorithm building blocks
///
///  source: http://stackoverflow.com/a/24650627/486617 "Algorithmic building
///  blocks" 
///
/// Remember, use the std::sort() algorithm, which does the same thing.
///
template<class FwdIt, class Compare = std::less<int> >
void quickSort(FwdIt first, FwdIt last, Compare cmp = Compare{})
{
	auto const N = std::distance(first, last);
	if (N <= 1) return; 
	auto const pivot = std::next(first, N / 2);
	std::nth_element(first, pivot, last, cmp);
	quickSort(first, pivot, cmp); // assert(std::is_sorted(first, pivot, cmp));
	quickSort(pivot, last, cmp);  // assert(std::is_sorted(pivot, last, cmp));

	// can be optimized by adding insertionSort call for small ranges (like 7...)
}

TEST(FANCYALG, QuickSortTest) {
	PRINT_TEST_TITLE();

	int intArray[5];
	generateRand(intArray, intArray + 5, 1);
	printAll(intArray, intArray + 5, "before");

	quickSort(intArray, intArray + 5);
	printAll(intArray, intArray + 5, "after");
}

///
/// 3. slide from Cpp Seasoning
///
/// use case: list of items, make continous selection and move that selection into a new 'p' position.
//
template <typename randIter> auto slide(randIter f, randIter l, randIter p) -> std::pair<randIter, randIter>
{
	if (p < f) return { p, std::rotate(p, f, l) };
	if (l < p) return { std::rotate(f, l, p), p };
	return { f, l };
}

TEST(FANCYALG, SlideTest) {
	PRINT_TEST_TITLE();

	int intArray[10] = { 0 };
	intArray[1] = intArray[2] = intArray[3] = 1;
	printAll(std::begin(intArray), std::end(intArray), "initial");

	// move to the right those three '1'

	auto p = slide(intArray + 1, intArray + 4, intArray + 6);
	printAll(std::begin(intArray), std::end(intArray), "to id 6");
	std::cout << "new range from " << std::distance(intArray, p.first) << " to " << std::distance(intArray, p.second) << " position" << std::endl;

	// go back:
	auto p2 = slide(p.first, p.second, intArray + 1);
	printAll(std::begin(intArray), std::end(intArray), "back");
	std::cout << "new range from " << std::distance(intArray, p2.first) << " to " << std::distance(intArray, p2.second) << " position" << std::endl;
}


///
/// 4. gather (cpp seasoning)
///
/// use case: list of items, select some of items (good guys) and move the to position around p.
/// for instance: multiple selection on a list
///
/// problem with std::not1: http://channel9.msdn.com/Events/GoingNative/2013/Cpp-Seasoning#c635149692925101916
///
/// Note the syntax used to define gather, taking advantage of automatic
/// type deduction and using functional specification of return type.
///
///
template <typename I, // I models BidirectionalIterator
	        typename S> // S models UnaryPredicate
	auto gather(I f, I l, I p, S s) -> std::pair < I, I >
{
	using value_type = typename std::iterator_traits<I>::value_type;
	return{ std::stable_partition(f, p, [&](const value_type& x){ return !s(x); }),
			std::stable_partition(p, l, s) };
}

TEST(FANCYALG, GatherTest) {
	PRINT_TEST_TITLE();
	
	int intArray[10] = { 0 };
	intArray[0] = intArray[2] = intArray[7] = intArray[8] = 1;
	printAll(intArray, intArray + 10, "before");
	
	// gather all '1's and move them around 4th place in the array
	auto range = gather(intArray, intArray + 10, intArray + 4, [](int x) { return x == 1; });
	printAll(intArray, intArray + 10, "after");

	std::cout << "selected items from " << std::distance(intArray, range.first) << " to " << std::distance(intArray, range.second) << " position" << std::endl;
}

///
/// 5. trim for strings
///
/// source:
/// http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
///
std::string trimLeft(const std::string &s) {
	auto temp = s;
	temp.erase(std::begin(temp),
             std::find_if(std::begin(temp), 
			 				std::end(temp), 
							[](char c){return !std::isspace(c, std::locale()); })
             );
	return temp;
}

std::string trimRight(const std::string &s) {
	auto temp = s;
	temp.erase(std::find_if(std::rbegin(temp), 
							std::rend(temp),
							[](char c){return !std::isspace(c, std::locale()); }).base(), std::end(temp));
	return temp;
}

std::string trim(const std::string &s) {
	return trimLeft(trimRight(s));
}

TEST(FANCYALG, TRIMTEST) {
	PRINT_TEST_TITLE();

	std::string test = "   Hello World 1   ";
	std::cout << "\"" << test << "\" -> \"" << trimLeft(test) << "\"" << std::endl;
	std::string test2 = "   Hello World 2   ";
	std::cout << "\"" << test2 << "\" -> \"" << trimRight(test2) << "\"" << std::endl;
	std::string test3 = "   Hello World 3   ";
	std::cout << "\"" << test3 << "\" -> \"" << trim(test3) << "\"" << std::endl;
}