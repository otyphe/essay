#pragma once
#include <memory>

struct BIf {
  virtual ~BIf(){}

  static std::unique_ptr<BIf> instantiate();
};
