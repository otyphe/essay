#pragma once
class C {
public:
  C(int param);
  C(const C& rhs);
  int falsifyIdent() const;

private:
  int param_;
};