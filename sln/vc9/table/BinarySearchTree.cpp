#include "table.h"
#include <iostream>


BinarySearchTree_Element::BinarySearchTree_Element(NodeTable* d) {
	data = d;
	left = NULL;
	right = NULL;
}

BinarySearchTree_Element::BinarySearchTree_Element() {
	data = NULL;
	left = NULL;
	right = NULL;
}

BinarySearchTree_Element::BinarySearchTree_Element(BinarySearchTree_Element& obj) {
	data = obj.GetData();
	left = obj.GetLeft();
	right = obj.GetRight();
}

BinarySearchTree_Element* BinarySearchTree_Element::GetLeft() const {
	return left;
}

BinarySearchTree_Element* BinarySearchTree_Element::GetRight() const {
	return right;
}


void BinarySearchTree_Element::SetData(NodeTable* d) {
	data = d;
}


void BinarySearchTree_Element::SetLeft(BinarySearchTree_Element* l) {
	left = l;
}

void BinarySearchTree_Element::SetRight(BinarySearchTree_Element* r) {
	right = r;
}

string BinarySearchTree_Element::GetName() const {
	return data->GetKey();
}

NodeTable* BinarySearchTree_Element::GetData() {
	return data;
}

BinarySearchTree::BinarySearchTree() {
	root = new BinarySearchTree_Element;
}

BinarySearchTree::BinarySearchTree(NodeTable* data) {
	root = new BinarySearchTree_Element;
	root->SetData(data);
}

//void BinarySearchTree::TLRwalk(BinarySearchTree_Element* r) {
//	if (r != NULL) {
//		cout << r->GetName() << " ";
//		TLRwalk(r->GetLeft());
//		TLRwalk(r->GetRight());
//	}
//}
//
//void BinarySearchTree::LTRwalk(BinarySearchTree_Element* r) {
//	if (r != NULL) {
//		TLRwalk(r->GetLeft());
//		TLRwalk(r->GetRight());
//		cout << r->GetName() << " ";
//	}
//}

void BinarySearchTree::Insert(NodeTable* node)
{
	if (root->GetData() == NULL) 
	{
		root->SetData(node);
		return;
	}

	BinarySearchTree_Element* tmp = new BinarySearchTree_Element(node);
	Insert(root,tmp);
}

void BinarySearchTree::Delete(string key)
{
	if (root->GetData() == NULL) {
		return;
	}
	
	if (root->GetName() == key)
	{
		if (root->GetRight() != NULL || root->GetLeft() != NULL) {
			root = Merge(root->GetLeft(), root->GetRight());
			return;
		}
		root->SetData(NULL);
		return;
	}
	Delete(root, key);
}

BinarySearchTree_Element* BinarySearchTree::Search(BinarySearchTree_Element* r, string key) {
	if (r==NULL ||r->GetData() == NULL) return NULL;

	if (key == r->GetName()) {
		return r;
	}
	if (key < r->GetName()) {
		return Search(r->GetLeft(), key);
	}
	return Search(r->GetRight(), key);
}

BinarySearchTree_Element* BinarySearchTree::FindMax(BinarySearchTree_Element* r) {
	if (r->GetRight() == NULL) {
		return r;
	}
	return FindMax(r->GetRight());
}

BinarySearchTree_Element* BinarySearchTree::FindMin(BinarySearchTree_Element* r) {
	if (r->GetLeft() == NULL) {
		return r;
	}
	return FindMin(r->GetLeft());
}

//BinarySearchTree_Element* BinarySearchTree::FindNext(BinarySearchTree_Element* r) {
//	if (r->GetRight() != NULL) {
//		return FindMin(r->GetRight());
//	}
//	BinarySearchTree_Element* res = r->GetParent();
//	while (res != NULL && r == res->GetRight()) {
//		r = res;
//		res = res->GetParent();
//	}
//	return res;
//}
//
//BinarySearchTree_Element* BinarySearchTree::FindPrevious(BinarySearchTree_Element* r) {
//	if (r->GetLeft() != NULL) {
//		return FindMax(r->GetLeft());
//	}
//	BinarySearchTree_Element* res = r->GetParent();
//	while (res != NULL && r == res->GetLeft()) {
//		r = res;
//		res = res->GetParent();
//	}
//	return res;
//}

void BinarySearchTree::Insert(BinarySearchTree_Element* r, BinarySearchTree_Element* new_node) {
	if (new_node->GetName() > r->GetName()) {
		if (r->GetRight() != NULL) {
			Insert(r->GetRight(), new_node);
			return;
		}
		else {
			r->SetRight(new_node);
			return;//
		}
	}
	if (r->GetLeft() != NULL) {
		Insert(r->GetLeft(), new_node);
		return;//
	}
	else {
		r->SetLeft(new_node);
		return;//
	}
}

NodeTable* BinarySearchTree::Search(string key) {
	BinarySearchTree_Element* res = Search(root, key);
	if (res==NULL)
	{
		return NULL;
	}
	return res->GetData();
}

BinarySearchTree_Element* BinarySearchTree::Merge(BinarySearchTree_Element* l, BinarySearchTree_Element* r) {
	if (r == NULL || r->GetData() == NULL)
	{
		return l;
	}
	if (l == NULL || l->GetData() == NULL) {
		return r;
	}
	FindMin(r)->SetLeft(l);
	return r;
}

void BinarySearchTree::Delete(BinarySearchTree_Element* r, string key) {

	if (key < r->GetName()) {
		if (r->GetLeft()->GetName()==key)
		{
			r->SetLeft(Merge(r->GetLeft()->GetLeft(), r->GetLeft()->GetRight()));
		}
		else {
			Delete(r->GetLeft(), key);
			return;
		}
	}
	if (key > r->GetName()) {
		if (r->GetRight()->GetName() == key) {
			r->SetRight(Merge(r->GetRight()->GetLeft(), r->GetRight()->GetRight()));
		}
		else {
			Delete(r->GetRight(), key);
			return;
		}
	}
}

