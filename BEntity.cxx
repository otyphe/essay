#include "BEntity.hxx"

class BEntity::Impl {
public:
  Impl();
  const B& getEntity() const;
private:
  std::unique_ptr<B> entity_;
};

void BEntity::ImplDeleter::operator()(BEntity::Impl *p){
  delete p;
  return;
}

BEntity::Impl::Impl() {
  entity_.reset(new B());
  return;
}

const B& BEntity::Impl::getEntity() const {
  return *entity_;
}

//---------------------------------

BEntity::BEntity() {
  pImpl_.reset(new Impl());
  return;
}

const B& BEntity::getEntity() const {
  return pImpl_->getEntity();
}

//---------------------------------

std::unique_ptr<BIf> BIf::instantiate() {
  std::unique_ptr<BIf> instance(new BEntity());
  return std::move(instance);
}