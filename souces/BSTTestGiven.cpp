
#include <gtest/gtest.h>

#include "BST.hpp"

TEST(GivenWrittenTests, GivenTests)
{
  Bst<std::string, size_t> bst;
  EXPECT_EQ(bst.size(), 0);
}