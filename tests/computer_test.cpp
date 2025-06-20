#include "../include/computer.h"
#include <gtest/gtest.h>

class TestComputer : public ::testing::Test {
public:
  TestComputer() {}
};

TEST_F(TestComputer, GeneratedCodeHasValidLengthAndColors) {
  // Generate and test a code 25 times
  for (int i = 0; i < 25; i++) {
    Computer comp = Computer(4);
    auto code = comp.code;

    // Check correct length
    EXPECT_EQ(code.size(), comp.codeLength);

    // Check each peg is in valid enum range
    for (const auto &peg : code) {
      EXPECT_TRUE(peg >= CodePeg::Blue &&
                  peg <= CodePeg::Purple); // Adjust based on enum
    }
  }
}
