#include <gtest.h>
#include "polinom.h"
//#include "monom.h"
// тесты мономов и полиномов

TEST(Polinom, can_create) {
	ASSERT_NO_THROW(Polinom p);
}

TEST(Polinom, can_copy) {
	Polinom a;
	a.AddElement(monom(2,1));

	Polinom b(a);

	EXPECT_EQ(a[0].GetCoefficient(),b[0].GetCoefficient());
	EXPECT_EQ(a.GetLength(), b.GetLength());
}

TEST(Polinom, can_add_two_monoms)
{
	Polinom a;
	a.AddElement(monom(2, 1));
	a.AddElement(monom(5, 10));
	EXPECT_EQ(5, a[0].GetCoefficient());
	EXPECT_EQ(2, a[1].GetCoefficient());
}

TEST(Polinom, can_simplify) {
	Polinom a;
	a.AddElement(monom(3, 100));
	a.AddElement(monom(5, 200));
	a.AddElement(monom(1, 200));

	//	1|200,5|200,3|100

	a.Simplify();
	EXPECT_EQ(2,a.GetLength());
	EXPECT_EQ(6, a[0].GetCoefficient());
	EXPECT_EQ(3, a[1].GetCoefficient());
}
TEST(Polinom, can_simplify_2) {
	Polinom a;
	a.AddElement(monom(3, 100));

	a.AddElement(monom(5, 200));

	a.AddElement(monom(1, 200));

	a.AddElement(monom(2, 200));
	std::cout << a[0].GetCoefficient() << std::endl;
	std::cout << a[1].GetCoefficient() << std::endl;
	std::cout << a[2].GetCoefficient() << std::endl;
	std::cout << a[3].GetCoefficient() << std::endl;
	//2|200,1|200,5|200,3|100

	a.Simplify();
	EXPECT_EQ(2, a.GetLength());
	EXPECT_EQ(8, a[0].GetCoefficient());
	EXPECT_EQ(3, a[1].GetCoefficient());
}

TEST(Polinom, can_simplify_3) {
	Polinom a;
	a.AddElement(monom(10, 100));

	a.AddElement(monom(5, 200));

	a.AddElement(monom(1, 200));

	a.AddElement(monom(4, 300));

	a.AddElement(monom(1, 300));
	std::cout << a[0].GetCoefficient() << std::endl;
	std::cout << a[1].GetCoefficient() << std::endl;
	std::cout << a[2].GetCoefficient() << std::endl;
	std::cout << a[3].GetCoefficient() << std::endl;
	std::cout << a[4].GetCoefficient() << std::endl;
	//1|300,4|300,1|200,5|200,10|100

	a.Simplify();
	EXPECT_EQ(3, a.GetLength());
	EXPECT_EQ(5, a[0].GetCoefficient());
	EXPECT_EQ(6, a[1].GetCoefficient());
	EXPECT_EQ(10, a[2].GetCoefficient());
}

TEST(Polinom, can_simplify_whith_null) {
	Polinom a;
	a.AddElement(monom(10, 100));

	a.AddElement(monom(0, 200));

	//10|300

	a.Simplify();
	EXPECT_EQ(1, a.GetLength());
	EXPECT_EQ(10, a[0].GetCoefficient());
}

TEST(Polinom, can_add) {
	Polinom a;
	a.AddElement(monom(1, 100));
	a.AddElement(monom(2, 200));
	Polinom b;
	b.AddElement(monom(1, 100));
	b.AddElement(monom(3, 300));
	Polinom c;

	c = a + b;

	EXPECT_EQ(3, c.GetLength());
	EXPECT_EQ(3, c[0].GetCoefficient());
	EXPECT_EQ(2, c[1].GetCoefficient());
	EXPECT_EQ(2, c[2].GetCoefficient());
}
TEST(Polinom, can_add_2) {
	Polinom a;
	a.AddElement(monom(1, 100));
	a.AddElement(monom(1, 100));
	Polinom b;
	b.AddElement(monom(1, 100));
	b.AddElement(monom(1, 100));
	Polinom c;

	c = a + b;

	EXPECT_EQ(1, c.GetLength());
	EXPECT_EQ(4, c[0].GetCoefficient());
}

TEST(Polinom, can_delete) {
	Polinom a;
	a.AddElement(monom(2, 100));
	Polinom b;
	b.AddElement(monom(0, 100));
	b = a;
	EXPECT_EQ(2, b[0].GetCoefficient());
}

TEST(Polinom, can_add_null) {
	Polinom a;
	a.AddElement(monom(2, 100));
	Polinom b;
	b.AddElement(monom(0, 100));
	Polinom c;

	c = a + b;

	EXPECT_EQ(1, c.GetLength());
	EXPECT_EQ(2, c[0].GetCoefficient());
}

TEST(Polinom, can_add_null_2) {
	Polinom a;
	a.AddElement(monom(2, 100));
	Polinom b;
	b.AddElement(monom(0, 110));
	Polinom c;

	c = a + b;

	EXPECT_EQ(1, c.GetLength());
	EXPECT_EQ(2, c[0].GetCoefficient());
}

TEST(Polinom, can_minus) {
	Polinom a;
	a.AddElement(monom(2, 100));
	a.AddElement(monom(2, 200));
	Polinom b;
	b.AddElement(monom(1, 100));
	b.AddElement(monom(4, 200));
	Polinom c;

	c = a - b;

	EXPECT_EQ(2, c.GetLength());
	EXPECT_EQ(-2, c[0].GetCoefficient());
	EXPECT_EQ(1, c[1].GetCoefficient());
}

TEST(Polinom, can_minus_null) {
	Polinom a;
	a.AddElement(monom(2, 100));
	a.AddElement(monom(3, 200));
	Polinom b;
	b.AddElement(monom(0, 100));
	Polinom c;

	c = a - b;

	EXPECT_EQ(2, c.GetLength());
	EXPECT_EQ(3, c[0].GetCoefficient());
	EXPECT_EQ(2, c[1].GetCoefficient());
}

TEST(Polinom, can_minus_null_2) {
	Polinom a;
	a.AddElement(monom(2, 100));
	a.AddElement(monom(3, 200));
	Polinom b;
	b.AddElement(monom(0, 110));
	Polinom c;

	c = a - b;

	EXPECT_EQ(2, c.GetLength());
	EXPECT_EQ(3, c[0].GetCoefficient());
	EXPECT_EQ(2, c[1].GetCoefficient());
}

TEST(Polinom, can_minus_whith_empty) {
	Polinom a;
	a.AddElement(monom(2, 100));
	a.AddElement(monom(2, 200));
	Polinom b;

	Polinom c = a - b;

	EXPECT_EQ(2, c.GetLength());
	EXPECT_EQ(2, c[0].GetCoefficient());
	EXPECT_EQ(2, c[1].GetCoefficient());
}

TEST(Polinom, can_multiply_polinom_monom) {
	Polinom a;
	a.AddElement(monom(1, 100));
	a.AddElement(monom(2, 200));
	monom b(3,100);

	Polinom c; // 6|300,3|200

	c = a * b;

	EXPECT_EQ(2, c.GetLength());
	EXPECT_EQ(6, c[0].GetCoefficient());
	EXPECT_EQ(3, c[1].GetCoefficient());
	EXPECT_EQ(300, c[0].GetDegree());
	EXPECT_EQ(200, c[1].GetDegree());
}

TEST(Polinom, can_multiply_polinom_const) {
	Polinom a;
	a.AddElement(monom(1, 100));
	a.AddElement(monom(2, 200));
	monom b(2, 000); //константа => моном вида (const, 000)

	Polinom c;

	c = a * b;

	EXPECT_EQ(2, c.GetLength());
	EXPECT_EQ(4, c[0].GetCoefficient());
	EXPECT_EQ(2, c[1].GetCoefficient());
	EXPECT_EQ(200, c[0].GetDegree());
	EXPECT_EQ(100, c[1].GetDegree());
}

TEST(Polinom, can_not_multiply_polinom_whith_large_monom) {
	Polinom a;
	a.AddElement(monom(1, 100));
	a.AddElement(monom(2, 200));
	monom b(3, 900);

	Polinom c; // 6|300,3|200

	EXPECT_ANY_THROW(c = a * b);
}
TEST(Polinom, can_multiply_polinom_whith_polinom) {
	Polinom a;
	a.AddElement(monom(1, 100));
	a.AddElement(monom(1, 10));

	Polinom c = a * a; 

	EXPECT_EQ(3, c.GetLength());
	EXPECT_EQ(1, c[0].GetCoefficient());
	EXPECT_EQ(200, c[0].GetDegree());
	EXPECT_EQ(2, c[1].GetCoefficient());
	EXPECT_EQ(110, c[1].GetDegree());
	EXPECT_EQ(1, c[2].GetCoefficient());
	EXPECT_EQ(20, c[2].GetDegree());

}

TEST(Polinom, can_add_polinoms_whithout_fhead) {
	Polinom a;
	a.AddElement(monom(1, 100));
	a.AddElement(monom(2, 200));
	Polinom b;

	a = a + b;

	EXPECT_EQ(2, a.GetLength());
}

TEST(Polinom, can_add_double) {
	Polinom a;
	a.AddElement(monom(0.5, 100));
	Polinom b;
	b.AddElement(monom(0.5, 100));
	

	a = a + b;

	EXPECT_EQ(1, a.GetLength());
	EXPECT_EQ(1, a[0].GetCoefficient());
}

TEST(Polinom, can_multiply_polinom_double) {
	Polinom a;
	a.AddElement(monom(0.5, 100));

	Polinom c = a * a;

	EXPECT_EQ(1, c.GetLength());
	EXPECT_EQ(0.25, c[0].GetCoefficient());
	EXPECT_EQ(200, c[0].GetDegree());
}