// класс или структура Монома (double коэффициент, целая свернутая степень)
#pragma once

class monom
{
private:
	double coefficient;
	short degree; // xyz, где x,y,z принадлежат [0..9], x - степень x
public:
	monom(double coefficient = 0, short degree = -1);
	monom(const monom &x);
	double GetCoefficient() const;
	short GetDegree() const;
	void SetCoefficient(double c = 0);
	void SetDegree(short d = 0);

	friend bool operator ==(const monom& left, const monom& right);
	friend bool operator !=(const monom& left, const monom& right);
	friend bool operator <(const monom& left, const monom& right);
	friend bool operator >(const monom& left, const monom& right);

	monom& operator = (const monom& right);

	friend monom operator + (const monom& left,const monom& right);
	friend monom operator - (const monom& left,const monom& right);
	friend monom operator * (const monom& left, const monom& right);
};