#include "PseudoTargetEntity.hxx"
#include "Struct.hxx"
#include "CIf.hxx"

template<class T1, class T2>
PseudoTargetEntity<T1,T2>::PseudoTargetEntity(
  const AIf& , const BIf& , const T2& ) {
  // nothing to do
  return;
}

template<class T1, class T2>
typename TargetIf<T1, T2>::COMPARE PseudoTargetEntity<T1,T2>::compare(
  const TargetIf<T1,T2> &) const {
  return TargetIf<T1,T2>::COMPARE::EQUAL;
}

template<class T1, class T2>
int PseudoTargetEntity<T1,T2>::ident() const {
  return 530;
}

//------------------------------
template<class T1, class T2>
std::unique_ptr<TargetIf<T1,T2>> TargetIf<T1,T2>::instantiate(
  const AIf& a_if, const BIf& b_if, const T2& t2
) {
  std::unique_ptr<TargetIf<T1, T2>> instance(
    new PseudoTargetEntity<struct SampleStruct, CIf>(a_if, b_if, t2)
  );
  return std::move(instance);
}

template std::unique_ptr<TargetIf<struct SampleStruct, CIf>>
  TargetIf<struct SampleStruct, CIf>::instantiate(
    const AIf& a_if, const BIf& b_if, const CIf& c_if
  );

//---------------------------

template<class T1>
PseudoTargetEntity<T1,CIf>::PseudoTargetEntity(
  const AIf& , const BIf& , const CIf& ) {
  // nothing to do
  return;
}

template<class T1>
const CIf* PseudoTargetEntity<T1,CIf>::pickup(int key) const {
  std::unique_ptr<CIf> instance = CIf::instantiate(20);
  return instance.release();
}

template<class T1>
int PseudoTargetEntity<T1,CIf>::ident() const {
  return 843;
}

template<class T1>
typename TargetIf<T1, CIf>::COMPARE PseudoTargetEntity<T1,CIf>::compare(
  const TargetIf<T1,CIf> &) const {
  return TargetIf<T1,CIf>::COMPARE::SMALLER;
}
