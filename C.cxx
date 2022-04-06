#include "C.hxx"

C::C(int param)
: param_(param) {
  return;
}

C::C(const C& rhs) {
  return;
}

int C::falsifyIdent() const {
  return param_ * 2;
}
