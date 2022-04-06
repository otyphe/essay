#include "TargetEntity.hxx"
#include "Struct.hxx"
#include "CIf.hxx"

template<class T1, class T2>
class TargetEntity<T1,T2>::Impl {
public:
  Impl(
    const AIf& a_if, const BIf& b_if, const T2& t2
  );
  Impl(const TargetIf<T1,T2>& rhs);
  typename TargetIf<T1, T2>::COMPARE compare(const TargetIf<T1,T2> &rhs) const;
  const T2* pickup(int key) const;
  const Target<T1,T2>& getEntity() const;
  int ident() const;

private:
  std::unique_ptr<Target<T1,T2>> entity_;
};

template<class T1, class T2>
void TargetEntity<T1,T2>::ImplDeleter::operator()(TargetEntity::Impl *p) {
  delete p;
  return;
}

template<class T1, class T2>
TargetEntity<T1,T2>::Impl::Impl(
  const AIf &a_if, const BIf &b_if, const T2& t2
) {
  entity_.reset(new Target<T1,T2>(a_if, b_if, t2));
  return;
}

template<class T1, class T2>
TargetEntity<T1,T2>::Impl::Impl(const TargetIf<T1,T2>& rhs) {
  entity_.reset(new Target<T1,T2>(dynamic_cast<const TargetEntity<T1,T2> &>(rhs).getEntity()));
  return;
}

template<class T1, class T2>
typename TargetIf<T1, T2>::COMPARE TargetEntity<T1,T2>::Impl::compare(
  const TargetIf<T1,T2> &rhs) const {
  return static_cast<typename TargetIf<T1,T2>::COMPARE>(
    entity_->compare(dynamic_cast<const TargetEntity<T1,T2> &>(rhs).getEntity())
  );
}

template<class T1, class T2>
const Target<T1,T2>& TargetEntity<T1,T2>::Impl::getEntity() const {
  return *entity_;
}

template<class T1, class T2>
const T2* TargetEntity<T1,T2>::Impl::pickup(int key) const {
  return entity_->pickup(key);
}

template<class T1, class T2>
int TargetEntity<T1,T2>::Impl::ident() const {
  return entity_->ident();
}

//------------------------------

template<class T1, class T2>
TargetEntity<T1,T2>::TargetEntity(
  const AIf& a_if, const BIf& b_if, const T2& t2) {

  pImpl_.reset(new Impl(a_if, b_if, t2));
  return;
}

template<class T1, class T2>
TargetEntity<T1,T2>::TargetEntity(const TargetIf<T1,T2>& rhs) {
  pImpl_.reset(new Impl(rhs));
  return;
}

template<class T1, class T2>
typename TargetIf<T1, T2>::COMPARE TargetEntity<T1,T2>::compare(
  const TargetIf<T1,T2> &rhs) const {
  return pImpl_->compare(rhs);
}

template<class T1, class T2>
const Target<T1,T2>& TargetEntity<T1,T2>::getEntity() const {
  return pImpl_->getEntity();
}

template<class T1, class T2>
const T2* TargetEntity<T1,T2>::pickup(int key) const {
  return pImpl_->pickup(key);
}

template<class T1, class T2>
int TargetEntity<T1,T2>::ident() const {
  return pImpl_->ident();
}

//------------------------------

template<class T1, class T2>
std::unique_ptr<TargetIf<T1,T2>> TargetIf<T1,T2>::instantiate(
  const AIf& a_if, const BIf& b_if, const T2& t2
) {
  std::unique_ptr<TargetIf<T1,T2>> instance(new TargetEntity<T1,T2>(
    a_if, b_if, t2
  ));
  return std::move(instance);
}

template<class T1, class T2>
std::unique_ptr<TargetIf<T1,T2>> TargetIf<T1,T2>::clone(
  const TargetIf<T1,T2>& rhs
) {
  std::unique_ptr<TargetIf<T1,T2>> instance(new TargetEntity<T1,T2>(rhs));
  return std::move(instance);
}

template std::unique_ptr<TargetIf<struct SampleStruct, CIf>>
  TargetIf<struct SampleStruct, CIf>::instantiate(
    const AIf& a_if, const BIf& b_if, const CIf& c_if
  );

template std::unique_ptr<TargetIf<struct SampleStruct, CIf>>
  TargetIf<struct SampleStruct, CIf>::clone(
    const TargetIf<struct SampleStruct, CIf>& rhs);