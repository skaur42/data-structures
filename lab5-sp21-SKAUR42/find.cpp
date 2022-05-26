#include "SortedList.h"

/**
 * Find the position to insert "target" in sorted list "l", or return the index
 * if "target" is found in "l".
 */
int findInsertPosition(ds::SortedList<int> &list, int target) {
  // NOTE: You should implement the function using *binary search*.
  //       You may assume no duplicates in the list.
  // TODO:
  int left = 0;
  int right = list.size() - 1;
  while(left <= right){
    int mid = left + ((right - left) / 2);
    if(list.get(mid) == target){
      return mid;
    } else if(target < list.get(mid)){
      right = mid - 1;
    } else{
      left = mid + 1;
    }
  }
  return left;
}
