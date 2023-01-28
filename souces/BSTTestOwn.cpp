
#include <gtest/gtest.h>
#include "BST.hpp"
#include "string"

TEST(OwnWrittenTests, add)
{
	Bst<std::string, size_t> bst;
	bst.add("after", 1);
	bst.add("before", 5);
	bst.add("david", 8);
	bst.add("node4", 0);
	EXPECT_EQ(bst.size(), 4);
	EXPECT_EQ(bst.at("after"), 1);
	EXPECT_EQ(bst.at("david"), 8);
	EXPECT_EQ(bst.at("node4"), 0);
	EXPECT_THROW(bst.at("test5"), std::runtime_error);
}

TEST(OwnWrittenTests, addNegative)
{
	Bst<int, size_t> bst;
	bst.add(-1, 1);
	bst.add(5, 5);
	bst.add(-8, 8);
	bst.add(0, 0);
	EXPECT_EQ(bst.size(), 4);
	EXPECT_EQ(bst.at(-1), 1);
	EXPECT_EQ(bst.at(-8), 8);
	EXPECT_EQ(bst.at(0), 0);
	EXPECT_THROW(bst.at(9), std::runtime_error);
}

TEST(OwnWrittenTests, addEmpty)
{
	Bst<std::string, size_t> bst;
	bst.add("after", 1);
	EXPECT_EQ(bst.at("after"), 1);
	EXPECT_THROW(bst.at("test5"), std::runtime_error);
}

TEST(OwnWrittenTests, at)
{
	Bst<std::string, size_t> bst;
	bst.add("after", 1);
	bst.add("before", 5);
	bst.add("david", 8);
	bst.add("node4", 0);
	bst.add("butts", 34);
	EXPECT_EQ(bst.at("after"), 1);
	EXPECT_EQ(bst.at("david"), 8);
	EXPECT_EQ(bst.at("node4"), 0);
	EXPECT_EQ(bst.at("butts"), 34);
	EXPECT_THROW(bst.at("test5"), std::runtime_error);
	bst.remove("david");
	EXPECT_THROW(bst.at("david"), std::runtime_error);
}

TEST(OwnWrittenTests, atNegative)
{
	Bst<int, size_t> bst;
	bst.add(-1, 1);
	bst.add(5, 5);
	bst.add(-8, 8);
	bst.add(0, 0);
	EXPECT_EQ(bst.size(), 4);
	EXPECT_EQ(bst.at(-1), 1);
	EXPECT_EQ(bst.at(-8), 8);
	EXPECT_EQ(bst.at(0), 0);
	EXPECT_THROW(bst.at(9), std::runtime_error);
}

TEST(OwnWrittenTests, atEmpty)
{
	Bst<std::string, size_t> bst;
	EXPECT_THROW(bst.at("test5"), std::runtime_error);
	EXPECT_THROW(bst.at("david"), std::runtime_error);
	EXPECT_THROW(bst.at("butts"), std::runtime_error);
	EXPECT_THROW(bst.at("test4"), std::runtime_error);
}

TEST(OwnWrittenTests, addInt)
{
	Bst<size_t, std::string> bst;
	bst.add(1, "after");
	bst.add(5, "before");
	bst.add(8, "david");
	bst.add(0, "node4");
	EXPECT_EQ(bst.size(), 4);
	EXPECT_EQ(bst.at(1),"after");
	EXPECT_EQ(bst.at(8),"david");
	EXPECT_EQ(bst.at(0),"node4");
	EXPECT_THROW(bst.at(28), std::runtime_error);
}

TEST(OwnWrittenTests, addChar)
{
	Bst<char, std::string> bst;
	bst.add('g', "after");
	bst.add('t', "before");
	bst.add('r', "david");
	bst.add('e', "node4");
	EXPECT_EQ(bst.at('g'), "after");
	EXPECT_EQ(bst.at('r'), "david");
	EXPECT_EQ(bst.at('e'), "node4");
	EXPECT_THROW(bst.at('j'), std::runtime_error);
}

TEST(OwnWrittenTests, addDouble)
{
	Bst<double, std::string> bst;
	bst.add(2.3, "after");
	bst.add(4.5, "before");
	bst.add(9.9, "david");
	bst.add(6.5, "node4");
	EXPECT_EQ(bst.at(2.3), "after");
	EXPECT_EQ(bst.at(9.9), "david");
	EXPECT_EQ(bst.at(6.5), "node4");
	EXPECT_THROW(bst.at(64.5), std::runtime_error);
}

TEST(OwnWrittenTests, remove)
{
	Bst<std::string, size_t> bst;
	bst.add("after", 1);
	bst.add("before", 5);
	bst.add("david", 8);
	bst.add("node4", 0);
	bst.remove("david");
	EXPECT_EQ(bst.size(), 3);
	EXPECT_THROW(bst.at("david"), std::runtime_error);
	EXPECT_THROW(bst.remove("david"), std::runtime_error);
	EXPECT_THROW(bst.update("david", 8), std::runtime_error);
}

TEST(OwnWrittenTests, removeNegative)
{
	Bst<int, size_t> bst;
	bst.add(6, 5);
	bst.add(-13, 1);
	bst.add(14, 8);
	bst.add(13, 9);
	bst.add(15, 4);
	bst.add(7, 5);
	bst.add(-8, 6);
	EXPECT_EQ(bst.size(), 7);
	bst.remove(-13);
	EXPECT_EQ(bst.size(), 6);
	EXPECT_THROW(bst.at(-13), std::runtime_error);
	EXPECT_THROW(bst.remove(-13), std::runtime_error);
	EXPECT_THROW(bst.update(-13, 8), std::runtime_error);
}

TEST(OwnWrittenTests, removeEmpty)
{
	Bst<std::string, size_t> bst;
	EXPECT_THROW(bst.remove("david"), std::runtime_error);
}

TEST(OwnWrittenTests, removeInt)
{
	Bst<std::size_t, size_t> bst;
	bst.add(1, 1);
	bst.add(2, 5);
	bst.add(10, 8);
	bst.add(8, 8);
	bst.add(15, 15);
	bst.add(12, 12);
	bst.add(13, 13);
	EXPECT_EQ(bst.size(), 7);
	bst.remove(10);
	EXPECT_EQ(bst.size(), 6);
	EXPECT_THROW(bst.at(10), std::runtime_error);
	EXPECT_THROW(bst.remove(10), std::runtime_error);
	EXPECT_EQ(bst.at(13), 13);
}

TEST(OwnWrittenTests, brackets)
{
	Bst<std::string, size_t> bst;
	bst.add("after", 1);
	bst.add("before", 5);
	bst.add("david", 8);
	bst.add("node4", 0);
	EXPECT_EQ(bst.size(), 4);
	EXPECT_EQ(bst["after"], 1);
	EXPECT_EQ(bst["david"], 8);
	EXPECT_EQ(bst["node4"], 0);
	EXPECT_THROW(bst["test5"], std::runtime_error);
}

TEST(OwnWrittenTests, bracketsEmpty)
{
	Bst<std::string, size_t> bst;
	EXPECT_THROW(bst["test5"], std::runtime_error);
}

TEST(OwnWrittenTests, traverse)
{
	Bst<std::size_t, size_t> bst;
	bst.add(1, 1);
	bst.add(5, 5);
	bst.add(8, 8);
	bst.add(9, 0);
	EXPECT_EQ(bst.size(), 4);
	EXPECT_EQ(bst.traverse({ Direction::RIGHT, Direction::RIGHT }), 8);
	EXPECT_THROW(bst.traverse({ Direction::RIGHT, Direction::RIGHT, Direction::RIGHT, Direction::RIGHT, Direction::LEFT }), std::runtime_error);
}

TEST(OwnWrittenTests, traverseNegative)
{
	Bst<int, int> bst;
	bst.add(6, 5);
	bst.add(-13, -1);
	bst.add(14, 8);
	bst.add(13, 9);
	bst.add(15, 4);
	bst.add(7, 5);
	bst.add(-8, 6);
	EXPECT_EQ(bst.size(), 7);
	EXPECT_EQ(bst.traverse({ Direction::LEFT, Direction::RIGHT }), 6);
	EXPECT_THROW(bst.traverse({ Direction::RIGHT, Direction::RIGHT, Direction::RIGHT, Direction::RIGHT, Direction::LEFT }), std::runtime_error);
}

TEST(OwnWrittenTests, traverse2)
{
	Bst<std::size_t, size_t> bst;
	bst.add(1, 1);
	bst.add(2, 5);
	bst.add(10, 8);
	bst.add(8, 8);
	bst.add(15, 15);
	bst.add(12, 12);
	bst.add(13, 13);
	EXPECT_EQ(bst.size(), 7);
	EXPECT_EQ(bst.traverse({ Direction::RIGHT, Direction::RIGHT, Direction::LEFT }), 8);
	EXPECT_EQ(bst.traverse({ Direction::RIGHT, Direction::RIGHT, Direction::RIGHT, Direction::LEFT }), 12);
	EXPECT_THROW(bst.traverse({ Direction::RIGHT, Direction::RIGHT, Direction::RIGHT, Direction::RIGHT, Direction::LEFT }), std::runtime_error);
}

TEST(OwnWrittenTests, traversempty)
{
	Bst<std::size_t, size_t> bst;
	bst.add(1, 1);
	bst.add(2, 5);
	bst.add(10, 8);
	EXPECT_EQ(bst.traverse({}), 1);
}

TEST(OwnWrittenTests, update)
{
	Bst<std::string, size_t> bst;
	bst.add("after", 1);
	bst.add("before", 5);
	bst.add("david", 8);
	bst.add("node4", 0);
	bst.add("butts", 34);
	bst.update("david", 9);
	EXPECT_EQ(bst.at("after"), 1);
	EXPECT_EQ(bst.at("david"), 9);
	EXPECT_EQ(bst.at("node4"), 0);
	EXPECT_EQ(bst.at("butts"), 34);
	EXPECT_THROW(bst.at("test5"), std::runtime_error);
	bst.remove("david");
	EXPECT_THROW(bst.update("david", 8), std::runtime_error);
}

TEST(OwnWrittenTests, updateEmpty)
{
	Bst<std::string, size_t> bst;
	EXPECT_THROW(bst.update("david", 8), std::runtime_error);
}

TEST(OwnWrittenTests, size)
{
	Bst<std::string, size_t> bst;
	bst.add("after", 1);
	bst.add("before", 5);
	bst.add("david", 8);
	bst.add("node4", 0);
	bst.add("butts", 34);
	EXPECT_EQ(bst.size(), 5);
	bst.update("david", 9);
	EXPECT_EQ(bst.size(), 5);
	EXPECT_EQ(bst.at("after"), 1);
	EXPECT_EQ(bst.at("david"), 9);
	EXPECT_EQ(bst.at("node4"), 0);
	EXPECT_EQ(bst.at("butts"), 34);
	bst.remove("david");
	EXPECT_EQ(bst.size(), 4);
	bst.remove("after");
	EXPECT_EQ(bst.size(), 3);
}

TEST(OwnWrittenTests, sizeEmpty)
{
	Bst<std::string, size_t> bst;
	EXPECT_EQ(bst.size(), 0);
}