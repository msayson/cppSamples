#include "mergeSort.h"
#include <cassert>

void testMergeSingleElement() {
   int list[2];
   list[0] = 5;
   list[1] = 3;
   merge(list, 0, 0, 0); //left=[], right=[5]
   //merge on single element moves nothing
   assert(list[0] == 5);
   assert(list[1] == 3);
}

//If left list is empty, should take all elements from right list
void testMergeEmptyLeftList() {
   int list[3];
   list[0] = 4;
   list[1] = 3;
   list[2] = 8;
   merge(list, 1, 1, 2); //left=[],right=[3,8]
   //merge uses all elements from right, expect same array
   assert(list[0] == 4);
   assert(list[1] == 3);
   assert(list[2] == 8);
}

void testMergeTwoOutOfOrderElements() {
   int list[2];
   list[0] = 5;
   list[1] = 3;
   merge(list, 0, 1, 1); //left=[5], right=[3]
   //merge should insert 3 before 5
   assert(list[0] == 3);
   assert(list[1] == 5);
}

void testMergeTwoSortedSublists() {
   int list[5];
   list[0] = 2;
   list[1] = 4; //left = [2,4]
   list[2] = 0;
   list[3] = 3;
   list[4] = 6; //right = [0,3,6]
   merge(list, 0, 2, 4);

   //expect [0,2,3,4,6]
   assert(list[0] == 0);
   assert(list[1] == 2);
   assert(list[2] == 3);
   assert(list[3] == 4);
   assert(list[4] == 6);
}

void testMergeSortSingleElement() {
   int list[1];
   list[0] = 4;
   mergeSort(list, 0, 0);
   assert(list[0] == 4);
}

void testMergeSortFromReverseOrder() {
   int list[3];
   list[0] = 3;
   list[1] = 2;
   list[2] = 1;
   mergeSort(list, 0, 2);
   assert(list[0] == 1);
   assert(list[1] == 2);
   assert(list[2] == 3);
}

void testMergeSortRandomOrder() {
   int list[5];
   list[0] = 2;
   list[1] = 1;
   list[2] = 3;
   list[3] = 5;
   list[4] = 4;
   mergeSort(list, 0, 4);
   assert(list[0] == 1);
   assert(list[1] == 2);
   assert(list[2] == 3);
   assert(list[3] == 4);
   assert(list[4] == 5);
}

void testMerge() {
   testMergeSingleElement();
   testMergeEmptyLeftList();
   testMergeTwoOutOfOrderElements();
   testMergeTwoSortedSublists();
}

void testMergeSort() {
   testMergeSortSingleElement();
   testMergeSortFromReverseOrder();
   testMergeSortRandomOrder();
}

int main(int argc, char** argv) {
   testMerge();
   testMergeSort();
}
