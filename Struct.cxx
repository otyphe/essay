#include "Struct.hxx"

SampleStruct::SampleStruct(int input) {
  some_data_ = input * 3;
  return; 
}

int SampleStruct::falsifyIdent() const {
  return some_data_ + 1;
}