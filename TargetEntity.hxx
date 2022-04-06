#pragma once
#include "TargetIf.hxx"
#include "Target.hxx"
#include "AIf.hxx"
#include "BIf.hxx"
//#include "CIf.hxx"

template<class T1, class T2>
class TargetEntity : public TargetIf<T1, T2> {
public:
  TargetEntity(
    const AIf& a_if, const BIf& b_if, const T2& t2
  );
  TargetEntity(const TargetIf<T1,T2>& rhs);

  typename TargetIf<T1,T2>::COMPARE compare(const TargetIf<T1,T2> &rhs) const;
  const T2* pickup(int key) const;
  const Target<T1,T2>& getEntity() const;
  int ident() const;

private:
  class Impl;
  struct ImplDeleter {
    void operator()(TargetEntity::Impl *p);
  };
  std::unique_ptr<Impl> pImpl_;
};