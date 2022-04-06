#pragma once
#include "AIf.hxx"
#include "A.hxx"

class AEntity : public AIf {
public:
  AEntity(int id);
  AEntity(const AIf& rhs);
  AEntity& operator=(const AEntity& rhs) = default;
  int ident() const;
  const A& getEntity() const;

private:
  class Impl;
  struct ImplDeleter {
    void operator()(AEntity::Impl *p);
  };
  std::unique_ptr<Impl> pImpl_;
};