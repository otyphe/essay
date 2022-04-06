#pragma once
#include "TargetIf.hxx"
#include "Target.hxx"
#include "AIf.hxx"
#include "BIf.hxx"
#include "CIf.hxx"

template<class T1, class T2>
class PseudoTargetEntity : public TargetIf<T1, T2> {
public:
  PseudoTargetEntity(
    const AIf& a_if, const BIf& b_if, const T2& t2
  );
  typename TargetIf<T1,T2>::COMPARE compare(const TargetIf<T1,T2> &rhs) const;
  const T2* pickup(int key) const;
  const Target<T1,T2>& getEntity() const;
  int ident() const;
  
private:
  // nothing to declare here
};

template<class T1>
class PseudoTargetEntity<T1,CIf> : public TargetIf<T1, CIf> {
public:
  PseudoTargetEntity(
    const AIf& a_if, const BIf& b_if, const CIf& t2
  );
  typename TargetIf<T1,CIf>::COMPARE compare(const TargetIf<T1,CIf> &rhs) const;
  const CIf* pickup(int key) const;
  const Target<T1,CIf>& getEntity() const;
  int ident() const;
  
private:
  // nothing to declare here
};