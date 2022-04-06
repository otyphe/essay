#pragma once

class A {
public:
  A(int id);
  A(const A& rhs) = default;
  A& operator=(const A& rhs) = default;
  int ident() const;
private:
  int id_;
};