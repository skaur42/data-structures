#ifndef __SORTED_ALIST_H__
#define __SORTED_ALIST_H__

#include "SortedList.h"

// use factor 2
#define RFACTOR 2

namespace ds {

/** Array-based sorted list. */
template <typename ItemType> class SortedAList : public SortedList<ItemType> {
private:
  /** The underlying array. */
  ItemType *items;

  /** Stores the current size of the list. */
  size_t count;

  /** Max number of items allowed. */
  size_t maxCnt;

public:
  /**
   * Construct a new SortedAList object.
   *
   * @param initSize initial size of the underlying array; default 100
   */
  SortedAList(size_t initSize = 100) {
    count = 0;
    maxCnt = initSize;
    items = new ItemType[maxCnt];
  }

  /**
   * Construct a new SortedAList object from a sorted array.
   * This constructor is used for testing.
   */
  SortedAList(ItemType arr[], size_t n) {
    maxCnt = count = n;
    items = new ItemType[maxCnt];
    for (size_t i = 0; i < n; i++) {
      items[i] = arr[i];
    }
  }

  /** Destroy the SortedAList object. */
  ~SortedAList() { delete[] items; }

  /** Return the number of elements in the sorted list. */
  size_t size() const override { return count; }

  /** Return the i-th item in the sorted list .*/
  ItemType get(int i) const override { return items[i]; }

  /** Return the smallest item. */
  ItemType smallest() const override { return items[0]; }

  /** Return the greatest item. */
  ItemType greatest() const override { return items[count - 1]; }

  /** Put element "it" into the sorted array list. */
  void put(const ItemType &it) override{};
};

} // namespace ds

#endif // __SORTED_ALIST_H__
