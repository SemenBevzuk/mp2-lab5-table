// ����� ������� - ������������� ����������� ������ �������
// ������������ �������� ������, ������� ������, �������� ������,  
// ����� ������, �������� ���������(������� ������������� �������), 
// ��������� ���������
#pragma once
#include "monom.h"
#include "list.h"

class Polinom
{
private:
	List<monom>* polinom;
public:
	Polinom();
	Polinom(const Polinom &x);
	~Polinom();

	void AddElement(monom x);
	void AddElementToTail(monom x);
	int GetLength() const;
	
	void Simplify();

	monom& operator[](int pos);
	friend Polinom& operator + (const Polinom& left, const Polinom& right);
	friend Polinom& operator - (const Polinom& left, const Polinom& right);
	friend Polinom& operator * (const Polinom& left, const monom& right);
	friend Polinom& operator * (const Polinom& left, const Polinom& right);
	friend Polinom& operator += (Polinom& left, const Polinom& right);

	Polinom& operator = (const Polinom &right);
};