#ifndef __NODE_H__
#define __NODE_H__

namespace ds {

template <typename ItemType>
class Node {
public:
  ItemType item;
  Node *next;

  Node(ItemType i, Node *n = nullptr) {
    item = i;
    next = n;
  }
};

} // namespace ds

#endif // __NODE_H__
