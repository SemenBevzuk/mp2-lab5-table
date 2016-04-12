#include "table.h"
#include <gtest.h>

TEST(TableSort, can_create_table_sort) {
	ASSERT_NO_THROW(SortedTable t);
}
TEST(TableSort, can_find_in_empty) {
	SortedTable t;
	EXPECT_EQ(NULL, t.GetNode("a"));
}
TEST(TableSort, can_insert) {
	SortedTable t;
	Polinom p;
	p.AddElement(monom(1, 100));
	t.Insert("a", &p);
	EXPECT_EQ(1, t.GetNode("a")->operator[](0).GetCoefficient());
}
TEST(TableSort, can_insert_2) {
	SortedTable t;
	Polinom p,d;
	p.AddElement(monom(1, 100));
	d.AddElement(monom(2, 200));
	t.Insert("a", &p);
	t.Insert("b", &d);
	EXPECT_EQ(1, t.GetNode("a")->operator[](0).GetCoefficient());
	EXPECT_EQ(2, t.GetNode("b")->operator[](0).GetCoefficient());
}
TEST(TableSort, can_insert_3) {
	SortedTable t;
	Polinom p, d, g;
	p.AddElement(monom(1, 100));
	d.AddElement(monom(2, 200));
	g.AddElement(monom(3, 300));
	t.Insert("aaa", &g);
	t.Insert("a", &p);
	t.Insert("aa", &d);
	
	EXPECT_EQ(1, t.GetNode("a")->operator[](0).GetCoefficient());
	EXPECT_EQ(2, t.GetNode("aa")->operator[](0).GetCoefficient());
	EXPECT_EQ(3, t.GetNode("aaa")->operator[](0).GetCoefficient());
}

TEST(TableSort, can_delete) {
	SortedTable t;
	Polinom p, d, g;
	p.AddElement(monom(1, 100));
	d.AddElement(monom(2, 200));
	g.AddElement(monom(3, 300));
	t.Insert("aaa", &g);
	t.Insert("a", &p);
	t.Insert("aa", &d);
	t.Delete("aa");

	EXPECT_EQ(1, t.GetNode("a")->operator[](0).GetCoefficient());
	EXPECT_EQ(3, t.GetNode("aaa")->operator[](0).GetCoefficient());
}

TEST(TableSort, can_get_mem) {
	SortedTable t;
	Polinom p, d, g;
	p.AddElement(monom(1, 100));
	string s= "a";
	for (int i = 0; i < 11; i++)
	{
		t.Insert(s, &p);
		s += "a";
	}
	EXPECT_EQ(11, t.GetCountData());
}

TEST(TableSort, can_insert_orderly) {
	SortedTable t;
	Polinom p, d;
	p.AddElement(monom(1, 100));
	d.AddElement(monom(3, 300));
	t.Insert("aaa", &p);
	t.Insert("a",&d);
	EXPECT_EQ(3, t.GetNode("a")->operator[](0).GetCoefficient());
	EXPECT_EQ(1, t.GetNode("aaa")->operator[](0).GetCoefficient());
}

TEST(TableSort, can_insert_orderly_2) {
	SortedTable t;
	Polinom p, d, r;
	p.AddElement(monom(1, 100));
	d.AddElement(monom(2, 300));
	r.AddElement(monom(3, 400));
	t.Insert("aaa", &r);
	t.Insert("a", &p);
	t.Insert("aa", &d);
	EXPECT_EQ(1, t.GetNode("a")->operator[](0).GetCoefficient());
	EXPECT_EQ(2, t.GetNode("aa")->operator[](0).GetCoefficient());
	EXPECT_EQ(3, t.GetNode("aaa")->operator[](0).GetCoefficient()); 
}