#include "table.h"
#include <gtest.h>

TEST(TableHash, can_create_table_hash) {
	ASSERT_NO_THROW(HashTable t);
}

//TEST(TableHash, can_find_hashfunc_a) {
//	HashTable t;
//	int hash = t.hashfunc("a");
//	EXPECT_EQ(7, hash);
//}
//TEST(TableHash, can_find_hashfunc_ab) {
//	HashTable t;
//	int hash = t.hashfunc("ab");
//	EXPECT_EQ(5, hash);
//}
TEST(TableHash, can_Insert_1) {
	HashTable t;
	Polinom p;
	p.AddElement(monom(1, 100));
	t.Insert("a", &p);
	EXPECT_EQ(1, t.GetNode("a")->operator[](0).GetCoefficient());
}
TEST(TableHash, can_Insert_whith_collision) {
	HashTable t;
	Polinom p,d;
	p.AddElement(monom(1, 100));
	d.AddElement(monom(2, 200));
	t.Insert("a", &p);
	t.Insert("k", &d);
	EXPECT_EQ(1, t.GetNode("a")->operator[](0).GetCoefficient());
	EXPECT_EQ(2, t.GetNode("k")->operator[](0).GetCoefficient());
}

TEST(TableHash, can_not_find) {
	HashTable t;
	EXPECT_EQ(NULL, t.GetNode("a"));
}

TEST(TableHash, can_delete) {
	HashTable t;
	Polinom p;
	p.AddElement(monom(1, 100));
	t.Insert("a", &p);
	t.Delete("a");
	EXPECT_EQ(NULL, t.GetNode("a"));
}

TEST(TableHash, can_delete_2) {
	HashTable t;
	Polinom p,d;
	p.AddElement(monom(1, 100));
	d.AddElement(monom(2, 200));
	t.Insert("a", &p);
	t.Insert("b", &d);
	t.Delete("a");
	EXPECT_EQ(NULL, t.GetNode("a"));
	EXPECT_EQ(2, t.GetNode("b")->operator[](0).GetCoefficient());
}

