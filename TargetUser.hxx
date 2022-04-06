#pragma once
#include "TargetIf.hxx"

// これ必要？
template<class T1, class T2>
class TargetUser {
public:
  TargetUser(const TargetIf<T1,T2> &target);
  
private:
  const TargetIf<T1,T2> &target_;
};