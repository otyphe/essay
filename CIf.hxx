#pragma once
#include <memory>

struct CIf {
  virtual ~CIf(){}
  virtual int falsifyIdent() const = 0;
  // Target を部分特殊化するのがいいかな
  static std::unique_ptr<CIf> instantiate(int param);
};
