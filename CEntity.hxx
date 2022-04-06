#pragma once
#include "CIf.hxx"
#include "C.hxx"

class CEntity : public CIf {
public:
  CEntity(int param);
  const C& getEntity() const;
  int falsifyIdent() const;

private:
  class Impl;
  struct ImplDeleter {
    void operator()(CEntity::Impl *p);
  };
  std::unique_ptr<Impl> pImpl_;
};