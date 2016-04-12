#include "monom.h"

monom::monom(double c, short d)
{
	coefficient = c;
	degree = d;
}

monom::monom(const monom& x)
{
	coefficient = x.GetCoefficient();
	degree = x.GetDegree();
}

double monom::GetCoefficient() const
{
	return coefficient;
}

short monom::GetDegree() const
{
	return degree;
}

void monom::SetCoefficient(double c)
{
	coefficient = c;
}

void monom::SetDegree(short d)
{
	degree = d;
}

monom& monom::operator=(const monom& right)
{
	if (this == &right) {
		return *this;
	}
	coefficient = right.GetCoefficient();
	degree = right.GetDegree();
	return *this;
}

bool operator==(const monom& left,const monom& right)//сравненеи степеней!
{
	if (left.GetDegree() != right.GetDegree())
	{
		return false;
	}
	if (left.GetCoefficient() != right.GetCoefficient())
	{
		
	}
	return true;
}

bool operator!=(const monom& left, const monom& right)
{
	return !(left == right);
}

bool operator < (const monom& left, const monom& right)
{
	if (left.GetDegree() <= right.GetDegree())
	{
		return  true;
	}
	return false;
}

bool operator > (const monom& left,const monom& right)
{
	if (left.GetDegree() >= right.GetDegree()) {
		return  true;
	}
	return false;
}

monom operator + (const monom& left, const monom& right)
{
	if (left != right)
	{
		throw("Different degrees.");
	}
	monom res(left.GetCoefficient() + right.GetCoefficient(),left.GetDegree());
	return res;
}

monom operator - (const monom& left, const monom& right) {
	if (left != right) {
		throw("Different degrees.");
	}
	monom res(left.GetCoefficient() - right.GetCoefficient(), left.GetDegree());
	return res;
}

monom operator*(const monom& left, const monom& right)
{
	int x1, y1, z1;
	int x2, y2, z2;
	x1 = left.GetDegree() / 100;
	y1 = (left.GetDegree() / 10) %10;
	z1 = left.GetDegree()%10;
	x2 = right.GetDegree() / 100;
	y2 = (right.GetDegree() / 10) % 10;
	z2 = right.GetDegree() % 10;
	if ((x1 + x2>9 || x1 + x2<0) ||
		(y1 + y2>9 || y1 + y2<0) || 
		(z1 + z2>9 || z1 + z2<0))
	{
		throw("Different degrees.");
	}
	monom res(left.GetCoefficient() * right.GetCoefficient(), left.GetDegree()+right.GetDegree());
	return res;
}