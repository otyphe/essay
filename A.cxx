#include "A.hxx"

A::A(int id) : id_(id) {
  return;
}

int A::ident() const {
  return id_;
}