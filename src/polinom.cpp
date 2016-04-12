#include "polinom.h"
#include <ostream>
#include <iostream>

Polinom::Polinom()
{
	polinom = new List<monom>;
}

Polinom::Polinom(const Polinom& x)
{
	polinom = new List < monom > ;

	Node<monom> *current = x.polinom->GetHead();

	while (current != NULL)
	{
		polinom->AddElementOrdered(current->GetVar());
		current = current->GetNext();
	}
}

void Polinom::AddElement(monom x)
{
	if (x.GetCoefficient()!=0)
	{
		polinom->AddElementOrdered(x);
	}
}

void Polinom::AddElementToTail(monom x)
{
	if (x.GetCoefficient() != 0) 
	{
		polinom->AddToTail(x);
	}
}

int Polinom::GetLength() const
{
	return polinom->GetLength();
}

monom& Polinom::operator[](int pos)
{
	if (pos<0 || pos> GetLength())
	{
		throw("Out of the list.");
	}
	Node<monom>* current = polinom->GetHead();
	for (int i = 0; i < pos; i++)
	{
		current = current->GetNext();
	}
	return current->GetVar();
	
}

Polinom::~Polinom()
{
	delete polinom;
}

void Polinom::Simplify()
{
	if (GetLength() == 1)
	{
		return;
	}
	Node<monom>* current = polinom->GetHead()->GetNext();
	Node<monom>* previous = polinom->GetHead();

	//не обрабатывается предшествующий, пропуск элемента
	//обработка нулевого полинома 
	while (current != NULL)
	{
		if (current->GetVar() == previous->GetVar())
		{
			previous->SetVar(previous->GetVar()+current->GetVar());
			polinom->DeleteElement(current);
			current = previous->GetNext();

			continue;
		}
		if (current==NULL)
		{
			break;
		}
		previous = current;
		current = current->GetNext();
	}
}

Polinom& Polinom::operator = (const Polinom &right) {
	if (this == &right) {
		return *this;
	}
	delete polinom;

	polinom = new List < monom >;

	Node<monom> *current = right.polinom->GetHead();

	while (current != NULL) {
		polinom->AddElementOrdered(current->GetVar());
		current = current->GetNext();
	}
	return *this;
}

Polinom& operator + (const Polinom& left, const Polinom& right)
{
	Polinom *res = new Polinom;

	Node<monom>* current_left = left.polinom->GetHead();
	Node<monom>* current_right = right.polinom->GetHead();

	if (left.GetLength() == 0)
	{
		res->Simplify();
		return *res = right;
	}
	if (right.GetLength()==0)
	{
		res->Simplify();
		return *res = left;
	}
	while (current_left != NULL && current_right !=NULL)
	{
		if (current_left->GetVar()>current_right->GetVar())
		{
			res->AddElementToTail(current_left->GetVar());
			current_left = current_left->GetNext();
		}
		else{
			res->AddElementToTail(current_right->GetVar());
			current_right = current_right->GetNext();
		}
	}
	if (current_left != NULL)
	{
		while (current_left != NULL) {
			res->AddElementToTail(current_left->GetVar());
			current_left = current_left->GetNext();
		}
	}
	else{
		while (current_right != NULL) {
			res->AddElementToTail(current_right->GetVar());
			current_right = current_right->GetNext();
		}
	}
	res->Simplify();
	return *res;
}

Polinom& operator-(const Polinom& left, const Polinom& right)
{
	Polinom *res = new Polinom;
	Node<monom>* current = left.polinom->GetHead();
	if (right.GetLength()==0)
	{
		return *res = left;
	}
	if (left.GetLength() == 0)
	{
		return *res = right*(monom(-1,0));
	}

	*res = left + right*monom(-1,0);
	res->Simplify();

	return *res;
}

Polinom& operator*(const Polinom& left, const monom& right)
{
	Polinom *res = new Polinom;
	Node<monom>* current = left.polinom->GetHead();
	while (current != NULL)
	{
		res->AddElement(current->GetVar()*right);
		current = current->GetNext();
	}
	return *res;
}

Polinom& operator*(const Polinom& left, const Polinom& right)
{
	Polinom *res = new Polinom;
	Polinom temp;
	Node<monom>* current = left.polinom->GetHead();
	Node<monom>* current_right = right.polinom->GetHead();
	while (current != NULL) {
		temp = right*current->GetVar();
		*res += temp;
		current = current->GetNext();
	}
	return *res;
}

Polinom& operator+=(Polinom& left, const Polinom& right)
{
	Node<monom>* current = right.polinom->GetHead();
	current = right.polinom->GetHead();
	while (current != NULL) {
		left.AddElement(current->GetVar());
		current = current->GetNext();
	}
	left.Simplify();

	return left;
}