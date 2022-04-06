#include "AEntity.hxx"

class AEntity::Impl {
public:
  Impl(int id);
  int ident() const;
  const A& getEntity() const;
  Impl(const AIf& rhs);
private:
  std::unique_ptr<A> entity_;
};

void AEntity::ImplDeleter::operator()(AEntity::Impl *p){
  delete p;
  return;
}

AEntity::Impl::Impl(int id) {
  entity_.reset(new A(id));
  return;
}

AEntity::Impl::Impl(const AIf& rhs) {
  entity_.reset(new A(dynamic_cast<const AEntity &>(rhs).getEntity()));
  return;
}

const A& AEntity::Impl::getEntity() const {
  return *entity_;
}

int AEntity::Impl::ident() const {
  return entity_->ident();
}

//---------------------------------

AEntity::AEntity(int id) {
  pImpl_.reset(new Impl(id));
  return;
}

AEntity::AEntity(const AIf &rhs) {
  pImpl_.reset(new Impl(rhs));
}

int AEntity::ident() const {
  return pImpl_->ident();
}

const A& AEntity::getEntity() const {
  return pImpl_->getEntity();
}

//---------------------------------

std::unique_ptr<AIf> AIf::instantiate(int id) {
  std::unique_ptr<AIf> instance(new AEntity(id));
  return std::move(instance);
}

std::unique_ptr<AIf> AIf::clone(const AIf &rhs) {
  std::unique_ptr<AIf> instance(new AEntity(rhs));
  return std::move(instance);
}