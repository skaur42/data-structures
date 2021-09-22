#ifndef __BSTMAP_H__
#define __BSTMAP_H__

#include <ostream>
#include <sstream>
#include <string>

namespace ds {

template <typename Key, typename Value> class BSTMapNode {
public:
  Key key;
  Value value;
  BSTMapNode *left;
  BSTMapNode *right;

  BSTMapNode(const Key &k, const Value &v, BSTMapNode *l = nullptr,
             BSTMapNode *r = nullptr) {
    key = k;
    value = v;
    left = l;
    right = r;
  }

  /** The text respresentation of node. */
  std::string text() {
    std::stringstream ss;
    ss << key << ":" << value;
    return ss.str();
  }
};

class BSTPrinter;

template <typename Key, typename Value> class BSTMap {
  friend class BSTPrinter;

private:
  BSTMapNode<Key, Value> *root; // Root of the BST

  BSTMapNode<Key, Value> *putHelp(BSTMapNode<Key, Value> *root,
                                     const Key &ik, const Value &val) {
    if (root == nullptr)
      return new BSTMapNode<Key, Value>(ik, val);
    if (ik < root->key)
      root->left = putHelp(root->left, ik, val);
    else if (ik > root->key)
      root->right = putHelp(root->right, ik, val);
    return root;
  }

  bool findHelp(const BSTMapNode<Key, Value> *root, const Key &sk) const {
    if (root == nullptr)
      return false;
    if (sk < root->key)
      return findHelp(root->left, sk);
    if (sk > root->key)
      return findHelp(root->right, sk);
    else
      return true;
  }

  Value getHelp(BSTMapNode<Key, Value> *root, const Key &sk) const {
    if (root == nullptr)
      return NULL;
    if (sk < root->key)
      return getHelp(root->left, sk);
    if (sk > root->key)
      return getHelp(root->right, sk);
    else
      return root->value;
  }

  BSTMapNode<Key, Value> *removeHelp(BSTMapNode<Key, Value> *root, const Key &sk) {
    // find first node that we want to remove
    if (root == nullptr)
      return NULL;
    if (root->key > sk)
      // go to left subtree
      root->left = removeHelp(root->left, sk);
    else if (root->key < sk)
      // go to right subtree
      root->right = removeHelp(root->right, sk);
    
    while(root->key == sk){
      // case one : root does not have children
      if(root->left == NULL && root->right == NULL){
        delete root;
        return NULL;
      } else if(root->left == NULL){      // case two : root has one child
        BSTMapNode <Key, Value> *temp = root->right;
        delete root;
        return temp;
      } else if(root->right == NULL){
        BSTMapNode <Key, Value> *temp = root->left;
        delete root;
        return temp;
      }else {     // case three: root has two children
        BSTMapNode <Key, Value> *successor = root->right;
        BSTMapNode <Key, Value> *successorP = root;

        // find successor
        while(successor->left != NULL){
          successorP = successor;
          successor = successor->left;
        }
        if(successorP != root)
          successorP->left = successor->right;
        else
          successorP->right = successor->right;
        
        // copy successor key and value to root
        root->key = successor->key;
        root->value = successor->value;

        // delete successor by recursively calling removeHelp
        removeHelp(root->right, root->key);
      }
    }
    BSTMapNode <Key, Value> *r = root;
    return r;
  }

public:
  BSTMap() { root = nullptr; }
  ~BSTMap() { clear(root); }

  /** Delete all nodes. */
  void clear(BSTMapNode<Key, Value> *root) {
    if (root == nullptr)
      return;
    clear(root->left);
    clear(root->right);
    delete root;
  }

  /**
   * Insert the key-value pair `ik` and `val` to the BSTMap.
   *
   * @param ik The key to insert
   * @param val The value corresponding to the key
   */
  void put(const Key &ik, const Value &val) {
    root = putHelp(root, ik, val);
  }

  /**
   * Search for given key in the BSTMap.
   *
   * @param sk The search key
   * @return true if `sk` is in the BSTMap
   */
  bool find(const Key &sk) const { return findHelp(root, sk); }

  Value get(const Key &sk) const;
  void remove(const Key &rk);
};

/**
 * Return the value of the given search key in the BSTMap.
 */
template <typename Key, typename Value>
Value BSTMap<Key, Value>::get(const Key &sk) const {
  // TODO: You may assume that `sk` is in the BSTMap.
    return getHelp(root, sk);
}

/**
 * Remove `rk` from the BST.
 */
template <typename Key, typename Value>
void BSTMap<Key, Value>::remove(const Key &rk) {
  // TODO: You may assume that `rk` is in the BSTMap.
  root = removeHelp(root, rk);
}

} // namespace ds

#endif // __BSTMAP_H__
