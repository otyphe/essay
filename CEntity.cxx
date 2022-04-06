#include "CEntity.hxx"
class CEntity::Impl {
public:
  Impl(int param);
  const C& getEntity() const;
  int falsifyIdent() const;
private:
  std::unique_ptr<C> entity_;
};

void CEntity::ImplDeleter::operator()(CEntity::Impl *p){
  delete p;
  return;
}

CEntity::Impl::Impl(int param) {
  entity_.reset(new C(param));
  return;
}

const C& CEntity::Impl::getEntity() const {
  return *entity_;
}

int CEntity::Impl::falsifyIdent() const {
  return entity_->falsifyIdent();
}

//---------------------------------

CEntity::CEntity(int param) {
  pImpl_.reset(new Impl(param));
  return;
}

const C& CEntity::getEntity() const {
  return pImpl_->getEntity();
}

int CEntity::falsifyIdent() const {
  return pImpl_->falsifyIdent();
}

//---------------------------------

std::unique_ptr<CIf> CIf::instantiate(int param) {
  std::unique_ptr<CIf> instance(new CEntity(param));
  return std::move(instance);
}