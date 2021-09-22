#ifndef __BIGINT_H__
#define __BIGINT_H__

#include "VList.h"
#include <iostream>
#include <string>

namespace ds {

class BigInt {
private:
  VList<int> digits; // stores the digits of the BigInt

public:
  /**
   * Construct a new BigInt object from string.
   *
   * @param val a string of unlimited digits; default is empty string
   */
  BigInt(const std::string &val = "") {
    for (size_t j = 0; j < val.length(); j++) {
      digits.addLast(val[j] - '0');
    }
  };

  /** Print all digits in `bi` to `os`. */
  friend std::ostream &operator<<(std::ostream &os, const BigInt &bi) {
    for (size_t i = 0; i < bi.digits.size(); i++)
      os << bi.digits.get(i);
    return os;
  };

  /** Compares the values of l and r. */
  friend bool operator<(const BigInt &l, const BigInt &r);
  friend bool operator>(const BigInt &l, const BigInt &r);
  friend bool operator<=(const BigInt &l, const BigInt &r);
  friend bool operator>=(const BigInt &l, const BigInt &r);

  /** Return the *sum* of this BigInt and the `other` BigInt. */
  BigInt operator+(const BigInt &other) const;

  /** Return the *absolute difference* between this and the `other` BigInt. */
  BigInt operator-(const BigInt &other) const;
};

} // namespace ds

#endif // __BIGINT_H__
