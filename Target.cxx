#include "Target.hxx"
#include "CIf.hxx"
#include "Struct.hxx"

template<class T1, class T2>
Target<T1, T2>::Target(
//    const A& a, const B& b, const T2& t2
    const AIf& a, const BIf& b, const T2& t2
)
: a_(a), b_(b), t2_(t2) {
  for (int i = 0; i < 100; i+= 5) {
      std::unique_ptr<T1> t1(new T1(i));
      data_[i] = std::move(t1);
  }
  return;
}

template<class T1, class T2>
Target<T1,T2>::Target(const Target<T1,T2>& rhs)
: a_(rhs.a_), b_(rhs.b_), t2_(rhs.t2_) {
  for (auto &e : data_) {
    std::unique_ptr<T1> tmp(new T1(*(e.second)));
    data_[e.first] = std::move(tmp);
  }
  return;
}

template<class T1, class T2>
typename Target<T1,T2>::COMPARE
  Target<T1,T2>::compare(const Target<T1,T2>& rhs) const {
  return ident() >  rhs.ident() 
              ? Target::COMPARE::LARGER :
         ident() == rhs.ident() 
              ? Target::COMPARE::EQUAL  :
                Target::COMPARE::SMALLER;
}

template<class T1, class T2>
int Target<T1,T2>::ident() const {
  return a_.ident();
}

// ---- doesn’t compile from here ----
// template<class T1,class T2>
// const CIf* Target<T1, T2>::pickup(int key) const {
//   T1* tmp = data_.at(key).get();
//   std::unique_ptr<T2> t2 = 
// CIf::instantiate(tmp->falsifyIdent());
//   return t2.release();
// }
// ---- doesn’t compile to here ----


template<class T1>
Target<T1,CIf>::Target(const Target<T1,CIf>& rhs)
: a_(rhs.a_), b_(rhs.b_), t2_(rhs.t2_) {
  for (auto &e : data_) {
    std::unique_ptr<T1> tmp(new T1(*(e.second)));
    data_[e.first] = std::move(tmp);
  }
  return;
}

template<class T1>
const CIf* Target<T1, CIf>::pickup(int key) const {
  T1* tmp = data_.at(key).get();
  std::unique_ptr<CIf> t2 = CIf::instantiate(tmp->falsifyIdent());
  return t2.release();
}

template<class T1>
Target<T1, CIf>::Target(
//    const A& a, const B& b, const T2& t2
    const AIf& a, const BIf& b, const CIf& t2
)
//: a_(a), b_(b), t2_(t2) {
: a_(a), b_(b), t2_(t2) {
  for (int i = 0; i < 100; i+= 5) {
      std::unique_ptr<T1> t1(new T1(i));
      data_[i] = std::move(t1);
  }
  return;
}

template<class T1>
typename Target<T1, CIf>::COMPARE
  Target<T1,CIf>::compare(const Target<T1,CIf>& rhs) const {
  return ident() >  rhs.ident() 
              ? Target::COMPARE::LARGER :
         ident() == rhs.ident() 
              ? Target::COMPARE::EQUAL  :
                Target::COMPARE::SMALLER;
}

template<class T1>
int Target<T1,CIf>::ident() const {
  return a_.ident();
}

template class Target<struct SampleStruct, CIf>;
