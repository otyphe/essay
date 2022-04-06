#pragma once
#include <memory>

struct AIf {
  virtual ~AIf(){}
  virtual int ident() const = 0;
  static std::unique_ptr<AIf> instantiate(int id);
  static std::unique_ptr<AIf> clone(const AIf &rhs);
};
