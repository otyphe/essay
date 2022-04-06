#pragma once

#include <map>
#include <memory>
//#include "A.hxx"
//#include "B.hxx"
//#include "C.hxx"
#include "AIf.hxx"
#include "BIf.hxx"
#include "CIf.hxx"

template<class T1, class T2>
class Target {
public:
  enum COMPARE {
    EQUAL,
    LARGER,
    SMALLER
  };
//  Target(const A& a, const B& b, const T2& t2);
  Target(const AIf& a, const BIf& b, const T2& t2);
  Target(const Target& rhs);
  Target& operator=(const Target& rhs) = default;

  COMPARE compare(const Target& rhs) const;
  const T2* pickup(int key) const;
  int ident() const;
private:
  std::map<int, std::unique_ptr<T1>> data_;
//  const A& a_;
//  const B& b_;
  const AIf& a_;
  const BIf& b_;
  const T2& t2_;
};

template<class T1>
class Target<T1, CIf> {
public:
  enum COMPARE {
    EQUAL,
    LARGER,
    SMALLER
  };
//  Target(const A& a, const B& b, const T2& t2);
  Target(const AIf& a, const BIf& b, const CIf& t2);
  Target(const Target& rhs);
  Target& operator=(const Target& rhs) = default;

  COMPARE compare(const Target& rhs) const;
  const CIf* pickup(int key) const;
  int ident() const;
private:
  std::map<int, std::unique_ptr<T1>> data_;
//  const A& a_;
//  const B& b_;
  const AIf& a_;
  const BIf& b_;
  const CIf& t2_;
};
