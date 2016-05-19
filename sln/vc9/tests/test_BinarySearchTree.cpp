#include "table.h"
#include <gtest.h>

TEST(BinarySearchTree_Element, can_create_empty_BinarySearchTree_Element) {
	BinarySearchTree_Element test;
	EXPECT_EQ(NULL, test.GetRight());
	EXPECT_EQ(NULL, test.GetLeft());
	EXPECT_EQ(NULL, test.GetData());
}
TEST(BinarySearchTree_Element, can_create_BinarySearchTree_Element) {
	Polinom p;
	p.AddElement(monom(1,100));
	BinarySearchTree_Element test(new NodeTable("a", &p));

	EXPECT_EQ(NULL, test.GetRight());
	EXPECT_EQ(NULL, test.GetLeft());
	EXPECT_EQ("a", test.GetName());
}

TEST(BinarySearchTree, can_create_empty_BinarySearchTree) {
	ASSERT_NO_THROW(BinarySearchTree test);
}

TEST(BinarySearchTree, can_create_BinarySearchTree) {
	string s = "a";
	monom m(1, 100);
	Polinom a;
	a.AddElement(m);
	NodeTable n(s, &a);
	BinarySearchTree test(&n);
	EXPECT_EQ("a", test.Search("a")->GetKey());
}

TEST(BinarySearchTree, can_Insert) {
	BinarySearchTree test;
	Polinom p;
	p.AddElement(monom(1, 100));
	test.Insert(new NodeTable("a", &p));
	EXPECT_EQ("a", test.Search("a")->GetKey());
}

TEST(BinarySearchTree, can_Insert_and_Search) {
	BinarySearchTree test;
	Polinom p,d;
	p.AddElement(monom(1, 100));
	d.AddElement(monom(2,200));
	test.Insert(new NodeTable("a", &p));
	test.Insert(new NodeTable("b", &d));
	EXPECT_EQ("a", test.Search("a")->GetKey());
	EXPECT_EQ("b", test.Search("b")->GetKey());
}

TEST(BinarySearchTree, can_delete) {
	BinarySearchTree test;
	Polinom p, d;
	p.AddElement(monom(1, 100));
	test.Insert(new NodeTable("a", &p));
	test.Delete("a");
	EXPECT_EQ(NULL, test.Search("a"));
}