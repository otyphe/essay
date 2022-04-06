#pragma once
#include "AIf.hxx"
#include "BIf.hxx"

template<class T1, class T2>
struct TargetIf {
  enum COMPARE {
    EQUAL,
    LARGER,
    SMALLER
  };

  virtual COMPARE compare(const TargetIf &rhs) const = 0;
  virtual const T2* pickup(int key) const = 0;
  virtual int ident() const = 0;
  // テンプレート関数はvirtualたり得ないことの説明用
//  template<class P>
//  virtual P tmp() const = 0;

  static std::unique_ptr<TargetIf> instantiate(
    const AIf& a_if, const BIf& b_if, const T2& t2);
  static std::unique_ptr<TargetIf> clone(const TargetIf& rhs);
};