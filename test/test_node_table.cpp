#include <gtest.h>

#include "table.h"


TEST(TableNode, can_create_table_node) {
	string s = "a";
	monom m(1,100);
	Polinom a;
	a.AddElement(m);
	NodeTable n(s, &a);
	//ASSERT_NO_THROW();
	EXPECT_EQ("a", n.GetKey());
	EXPECT_EQ(m.GetCoefficient(),n.GetElement()->operator[](0).GetCoefficient());
}

TEST(TableNode, test_1) {
	NodeTable a("a", NULL);
	NodeTable b("b", NULL);

	ASSERT_NO_THROW(b=a);
	EXPECT_EQ("a", b.GetKey());
}

TEST(TableSort, can_create_table) {
	ASSERT_NO_THROW(SortedTable table);
}
