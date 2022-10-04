#ifndef __LIST_H__
#define __LIST_H__

#include <iterator>
#include <ostream>

namespace ds {

// size should not be negative
typedef unsigned long size_t;

/** List abstract class. */
template <typename Item> class List {
public:
  virtual size_t size() const = 0;
  virtual Item &get(int i) = 0;
  virtual const Item &get(int i) const = 0;
  virtual void insert(const Item &x, int i) = 0;
  virtual Item remove(int i) = 0;
  virtual void addFirst(const Item &x) = 0;
  virtual void addLast(const Item &x) = 0;
  virtual Item &getFirst() = 0;
  virtual Item &getLast() = 0;
  virtual const Item &getFirst() const = 0;
  virtual const Item &getLast() const = 0;
  virtual Item removeFirst() = 0;
  virtual Item removeLast() = 0;

  friend std::ostream &operator<<(std::ostream &os, const List &l) {
    os << "[";
    for (size_t i = 0; i < l.size(); i += 1) {
      if (i != 0) {
        os << ",";
      }
      os << l.get(i);
    }
    os << "]";
    return os;
  }
};

} // namespace ds

#endif // __LIST_H__