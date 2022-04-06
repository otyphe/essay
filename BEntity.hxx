#pragma once
#include "BIf.hxx"
#include "B.hxx"

class BEntity : public BIf {
public:
  BEntity();
  const B& getEntity() const;

private:
  class Impl;
  struct ImplDeleter {
    void operator()(BEntity::Impl *p);
  };
  std::unique_ptr<Impl> pImpl_;
};