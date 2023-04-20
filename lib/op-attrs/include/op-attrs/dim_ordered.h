#ifndef _FLEXFLOW_OPATTRS_INCLUDE_OPATTRS_FF_STACK_VECTOR_H
#define _FLEXFLOW_OPATTRS_INCLUDE_OPATTRS_FF_STACK_VECTOR_H

#include "utils/stack_vector.h"
#include "op-attrs/ff_dim.h"

namespace FlexFlow {

template <typename Idx, typename T>
struct DimOrdered {
  DimOrdered() = delete;

  DimOrdered(std::vector<T> const &contents)
    : contents(contents.begin(), contents.end())
  { }

  template <typename It>
  DimOrdered(It begin, It end)
    : contents(begin, end)
  { }

  template <size_t MAXSIZE>
  DimOrdered(stack_vector<T, MAXSIZE> const &contents) 
    : contents(contents.begin(), contents.end())
  { }

  T const &at(Idx idx) const {
    return this->contents.at(idx.value());
  }

  T &at(Idx idx) {
    return this->contents.at(idx.value());
  }

  T const &operator[](Idx idx) const {
    return this->at(idx);
  }

  T &operator[](Idx idx) {
    return this->at(idx);
  }

  bool operator==(DimOrdered const &other) const {
    return this->contents == other.contents;
  }

  bool operator!=(DimOrdered const &other) const {
    return this->contents != other.contents;
  }

  bool operator<(DimOrdered const &other) const {
    return this->contents < other.contents;
  }

  using iterator = typename stack_vector<T, MAX_TENSOR_DIM>::iterator;
  using const_iterator = typename stack_vector<T, MAX_TENSOR_DIM>::const_iterator;
  using value_type = T;
  using pointer = value_type *;
  using const_pointer = value_type const *;
  using reference = value_type &;
  using const_reference = value_type const &;

  iterator begin() {
    return this->contents.begin();
  }

  const_iterator begin() const {
    return this->cbegin();
  }

  const_iterator cbegin() const {
    return this->contents.cbegin();
  }

  iterator end() {
    return this->contents.end();
  }

  const_iterator end() const {
    return this->cend();
  }

  const_iterator cend() const {
    return this->contents.cend();
  }

  size_t size() const {
    return this->contents.size();
  }

  size_t num_dims() const {
    return this->size();
  }

  friend struct ::std::hash<DimOrdered>;
private:
  stack_vector<T, MAX_TENSOR_DIM> contents;
};

template <typename T>
using FFOrdered = DimOrdered<ff_dim_t, T>;

}

namespace std {

template <typename Idx, typename T>
struct hash<::FlexFlow::DimOrdered<Idx, T>> {
  size_t operator()(::FlexFlow::DimOrdered<Idx, T> const &t) const {
    return get_std_hash(t.contents);
  }
};

}


#endif