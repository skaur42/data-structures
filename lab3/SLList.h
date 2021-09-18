#ifndef __SLLIST_H__
#define __SLLIST_H__

#include "Node.h"
#include <cassert>
#include <functional>

// size should not be negative
typedef unsigned long size_t;

namespace ds {

template <typename ItemType> class TestDriver; // for autograding; please ignore

/** Singly linked list. */
template <typename ItemType>
class SLList {
  friend class TestDriver<ItemType>; // for autograding; please ignore

private:
  /** Pointer pointing to the sentinel node. */
  Node<ItemType> *sentinel;

  /** Stores the current size of the list. */
  size_t count;

public:
  /** Construct a new SLList object. */
  SLList() {
    sentinel = new Node<ItemType>(ItemType(), nullptr);
    count = 0;
  }

  /** Add x at the beginning of the list. */
  void addFirst(ItemType x) {
    count += 1;
    sentinel->next = new Node<ItemType>(x, sentinel->next);
  }

  /** Return the first element. */
  ItemType &getFirst() const {
    assert(sentinel->next != nullptr);
    return sentinel->next->item;
  }

  /** Return the number of elements in list. */
  size_t size() const { return count; }

  /** Append the list with x. */
  void addLast(ItemType x) {
    count += 1;
    Node<ItemType> *p = sentinel;
    while (p->next != nullptr) {
      p = p->next;
    }
    p->next = new Node<ItemType>(x, nullptr);
  }

  SLList(const SLList<ItemType> &other);
  ~SLList();
  ItemType &get(int i) const;
  ItemType removeFirst();
  ItemType removeLast();
};

/** Copy constructor. */
template <typename ItemType>
SLList<ItemType>::SLList(const SLList<ItemType> &other) {
  // TODO: create a list that is identical to `other`
  count = other.count;
  Node<ItemType> *p1 = sentinel = new Node<ItemType>(ItemType(), nullptr);
  Node<ItemType> *p2 = other.sentinel->next;
  while(p2 != nullptr){
    p1 = p1->next = new Node<ItemType>(p2->item, nullptr);
    p2 = p2->next;
  } 
}

/** Destroy the SLList object. */
template <typename ItemType>
SLList<ItemType>::~SLList() {
  // TODO:
  count = 0;
  while (sentinel != nullptr) {
        Node<ItemType> *temp = sentinel;
        sentinel = sentinel->next;
        delete temp;
    }
}

/** Return the i-th item in list. */
template <typename ItemType>
ItemType &SLList<ItemType>::get(int i) const {
   // TODO:
  Node<ItemType> *p = sentinel->next;
  for(int j = 0; j < i; j++) {
      p = p->next;
    }
    return p->item;
}

/** Delete and return the first item of the list. */
template <typename ItemType>
ItemType SLList<ItemType>::removeFirst() {
  // TODO:
  Node<ItemType> *p = sentinel;
  sentinel = sentinel->next;
  delete p;
  count -= 1;

  return sentinel->next->item;
    
}

/** Delete and return the last item of the list. */
template <typename ItemType>
ItemType SLList<ItemType>::removeLast() {
  // TODO:
  
  Node<ItemType> *p1 = sentinel;
  Node<ItemType> *p2 = p1->next;
  while(p2->next != nullptr){
    p1 = p1->next;
    p2 = p2->next;
  }
  p1->next = nullptr;
  Node <ItemType> *temp = p2->item;
  delete p2;
  count -= 1;
  
  return temp;
  
}

} // namespace ds

#endif // __SLLIST_H__
