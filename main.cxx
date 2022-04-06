#include <gtest/gtest.h>
#include "Target.hxx"
#include "Struct.hxx"
#include "A.hxx"
#include "B.hxx"
#include "C.hxx"
#include "CIf.hxx"
#include "TargetIf.hxx"
#include "PseudoTargetEntity.hxx"

class SampleTest : public ::testing::Test {
protected:
  virtual ~SampleTest();
  virtual void SetUp();
  virtual void TearDown();
};

SampleTest::~SampleTest() {}
void SampleTest::SetUp() {}
void SampleTest::TearDown() {}

template<class T1, class T2>
int sampleUser1(const TargetIf<T1,T2>& target) {
  return target.ident();
}

TEST_F(SampleTest, RealSample1) {

  std::unique_ptr<AIf> a_if = AIf::instantiate(25);
  std::unique_ptr<BIf> b_if = BIf::instantiate();
  std::unique_ptr<CIf> c_if = CIf::instantiate(8);
  std::unique_ptr<TargetIf<struct SampleStruct, CIf>> target
    = TargetIf<struct SampleStruct, CIf>::instantiate(
      *a_if, *b_if, *c_if);
    
  EXPECT_EQ(sampleUser1(*target), 25);
}

TEST_F(SampleTest, RealSample2) {

  std::unique_ptr<AIf> a_if = AIf::instantiate(25);
  std::unique_ptr<BIf> b_if = BIf::instantiate();
  std::unique_ptr<CIf> c_if = CIf::instantiate(10);
  std::unique_ptr<TargetIf<struct SampleStruct, CIf>> target
    = TargetIf<struct SampleStruct, CIf>::instantiate(
      *a_if, *b_if, *c_if);
  std::unique_ptr<TargetIf<struct SampleStruct, CIf>> target2
    = TargetIf<struct SampleStruct, CIf>::clone(*target);    
  EXPECT_EQ(sampleUser1(*target2), 25);

  TargetIf<struct SampleStruct, CIf>::COMPARE val
    = TargetIf<struct SampleStruct, CIf>::COMPARE::EQUAL;
  EXPECT_EQ(target->compare(*target2), val);
}



TEST_F(SampleTest, PseudoSample1) {

  std::unique_ptr<AIf> a_if = AIf::instantiate(35);
  std::unique_ptr<BIf> b_if = BIf::instantiate();
  std::unique_ptr<CIf> c_if = CIf::instantiate(14);
  std::unique_ptr<TargetIf<struct SampleStruct, CIf>> target(
    new PseudoTargetEntity<struct SampleStruct, CIf>(*a_if, *b_if, *c_if));
    
  EXPECT_EQ(sampleUser1(*target), 843);
}


int main(int argc, char **argv) {
  ::testing::GTEST_FLAG(color) = "yes";
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();

}