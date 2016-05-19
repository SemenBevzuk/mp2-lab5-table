#pragma once

#include "polinom.h"
#include <string>
#include <list>

using namespace std;

class NodeTable
{
private:
	string name;
	Polinom* element;
public:
	NodeTable();
	NodeTable(NodeTable &r);
	NodeTable(string name_, Polinom* elem);

	string GetKey() const;
	Polinom* GetElement() const;
	NodeTable& operator=(const NodeTable &r);
	bool operator==(const NodeTable &r);
};

class Table
{
protected:
	virtual int Find(string key) = 0;
public:	
	virtual void Insert(string key, Polinom *p) = 0;
	virtual void Delete(string key) = 0;
	virtual Polinom* GetNode(string key) = 0 ;
};

class SortedTable: public Table
{
private:
	int count_data;
	int max_size;
	NodeTable* data;

	bool IsFull();
	void AddOrderly(string key, Polinom *p);
	void MoreMem();
	int Find(string key);
public:
	SortedTable();
	int GetCountData();
	void Insert(string key, Polinom *p);
	void Delete(string key);
	Polinom* GetNode(string key);
};

class HashTable : public Table
{
private:
	list<NodeTable> **data;
	int max_size;

	int hashfunc(string s);
	int Find(string key) { return 0; };
public:
	HashTable();

	void Insert(string key, Polinom *p);
	void Delete(string key);
	Polinom* GetNode(string key);
};

class BinarySearchTree_Element
{
private:
	NodeTable* data;
	BinarySearchTree_Element* left;
	BinarySearchTree_Element* right;
public:
	BinarySearchTree_Element(NodeTable* d);
	BinarySearchTree_Element();
	BinarySearchTree_Element(BinarySearchTree_Element &obj);

	BinarySearchTree_Element* GetLeft() const;
	BinarySearchTree_Element* GetRight() const;

	void SetData(NodeTable* d);
	void SetLeft(BinarySearchTree_Element* l);
	void SetRight(BinarySearchTree_Element* r);

	string GetName() const;
	NodeTable* GetData();
};

class BinarySearchTree
{
private:
	BinarySearchTree_Element* root;

	BinarySearchTree_Element* Search(BinarySearchTree_Element* r, string key);

	BinarySearchTree_Element* FindMax(BinarySearchTree_Element* r);
	BinarySearchTree_Element* FindMin(BinarySearchTree_Element* r);

	BinarySearchTree_Element* FindNext(BinarySearchTree_Element* r);
	BinarySearchTree_Element* FindPrevious(BinarySearchTree_Element* r);

	void Insert(BinarySearchTree_Element* r, BinarySearchTree_Element* new_node);
	
	void Delete(BinarySearchTree_Element* r, string key);

	BinarySearchTree_Element* Merge(BinarySearchTree_Element* l, BinarySearchTree_Element* r);

public:
	BinarySearchTree();
	BinarySearchTree(NodeTable* data);
	void TLRwalk(BinarySearchTree_Element* r);//печать
	void LTRwalk(BinarySearchTree_Element* r);//копирование
	
	void Insert(NodeTable* node);
	void Delete(string key);
	NodeTable* Search(string key);
};
