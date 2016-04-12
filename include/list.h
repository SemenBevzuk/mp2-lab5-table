#pragma once
#include <stdlib.h>
#include "monom.h"
template <class Type>
class Node {
private:
	Type var;
	Node<Type> *next;
public:
	void SetVar(Type x) {
		var = x;
	}
	void SetNext(Node<Type> *n) {
		next = n;
	}
	Node<Type>* GetNext()
	{
		return next;
	}
	Type GetVar() {
		return var;
	}

	Node() {
		SetVar(Type());  
		SetNext(NULL);
	}

	Node(Type x) {
		SetVar(x);
		SetNext(NULL);
	}
	Node(Type x, Node<Type>* n) {
		SetVar(x);
		SetNext(n);
	}
};

template <class Type>  //� ��������� �������
class List
{
private:
	Node<Type>* fhead; //���������
	Node<Type>* head;
	Node<Type>* tail;

	int length;

public:
	List()
	{
		fhead = new Node<Type>(); //var = momom(0,-1), NEXT = NULL
		head = fhead;
		tail = fhead;
		length = 0;
	}
	Node<Type>* GetHead()
	{
		return head;
	}
	int GetLength()
	{
		return length;
	}
	void SetLength(int i)
	{
		if (i>0) length = i;
	}

	void AddToHead(Type x) {
		Node<Type>* temp;
		if (length == 0)
		{
			temp = new Node<Type>(x, NULL);
			tail = temp;
		}
		else
		{
			temp = new Node<Type>(x, head);
		}
		
		fhead->SetNext(temp);
		head = temp;
		length++;
	}
	
	void AddToTail(Type x) {
		Node<Type>* temp = new Node<Type>(x, NULL);
		if (tail!=NULL) {
			tail->SetNext(temp);
		}
		tail = temp;
		if (head == fhead)
		{
			head = temp;
		}
		length++;
	}

	Node<Type>* At(int pos)
	{
		if (pos<0 || pos>length)
		{
			throw("����� �� ������� ������");
		}
		Node<Type>* current = head;
		for (int i = 0; i < pos; i++)
		{
			current = current->GetNext();
		}
		return current;
	}

	void AddElement(Type x, int pos) // pos-1 search
	{
		if (pos == 0)
		{
			AddToHead(x);
			return;
		}
		Node<Type>* current = At(pos-1);
		Node<Type>* temp = new Node<Type>(x,current->GetNext());
		current->SetNext(temp);
		length++;
	}

	void AddElementOrdered(Type x) {
		Node<Type>* current = head;
		Node<Type>* previous = fhead;
		Node<Type>* temp = new Node<Type>(x);


		if (current == fhead) {
			AddToHead(x);
			return;
		}

		if (x > current->GetVar()) {
			AddToHead(x);
			return;
		}
		if (x< tail->GetVar()) {
			AddToTail(x);
			return;
		}
		
		while (x < current->GetVar())
		{
			previous = current;
			current = current->GetNext();
		}
		
		previous->SetNext(temp);
		temp->SetNext(current);

		length++;
	}

	void DeleteFirst() {
		if (length == 0) return;

		Node<Type> *temp = head;
		head = temp->GetNext();
		fhead->SetNext(head);
		delete temp;
		if (length == 1) {
			head = tail = NULL;
		}
		length--;
	}

	void Delete() {
		while (length != 0) {
			DeleteFirst();
		}
	}

	~List()
	{
		Delete();
	}

	void DeleteElement(Node<monom>* node)
	{
		Node<Type> *previous = fhead;
		Node<Type> *current = head;
		if (node == head)
		{
			DeleteFirst();
			return;
		}
		while (current != NULL)
		{
			if (current == node)
			{
				previous->SetNext(current->GetNext());
				delete(current);
				length--;
				return;
			}
			previous = current;
			current = current->GetNext();
		}
		//��� �������� � ������
	};
};

