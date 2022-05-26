#ifndef __SORTED_LIST_H__
#define __SORTED_LIST_H__

#include <ostream>

namespace ds {

// size should not be negative
typedef unsigned long size_t;

/** SortedList abstract class. */
template <typename Item> class SortedList {
public:
  virtual size_t size() const = 0;
  virtual Item get(int i) const = 0;
  virtual void put(const Item &it) = 0;
  // virtual Item remove(int i) = 0;
  virtual Item smallest() const = 0;
  virtual Item greatest() const = 0;

  virtual void print(std::ostream &os) const {
    os << "[";
    for (size_t i = 0; i < size(); i += 1) {
      if (i != 0) {
        os << ",";
      }
      os << get(i);
    }
    os << "]";
  }
};

} // namespace ds

#endif // __SORTED_LIST_H__