#include"List.h"
#include"NodeBRTree.h"
#include"stack.h"
#include <stdexcept>
#include<iostream>
template <typename Key, typename Value>
RBTree<Key, Value>::RBTree()
{
	Root = nil;
}
template <typename Key, typename Value>
RBTree<Key, Value>::~RBTree()
{
	clear(Root);
	nil = nullptr;
	Root = nullptr;
}
template <typename Key, typename Value>
Node<Key, Value>* RBTree<Key, Value>::get_nil()
{
	return nil;
}
template <typename Key, typename Value>
void RBTree<Key, Value>::preorder(Node<Key, Value>* node) {
	if (node == nullptr || node == nil) return;
	preorder(node->Lnext);
	preorder(node->Rnext);
	delete node;
}
template <typename Key, typename Value>
void RBTree<Key, Value>::clear() {
	preorder(Root);
	delete nil;
	nil = nullptr;
	Root = nullptr;
}
template <typename Key, typename Value>
void RBTree<Key, Value>::left_rotate(Node<Key, Value>* x) {
	Node<Key, Value>* y;
	y = x->Rnext;
	x->Rnext = y->Lnext;
	if (y->Lnext != nil) {
		y->Lnext->parent = x;
	}
	if (y !=nil) {
		y->parent = x->parent;
	}
	if (x->parent == nil) {
		Root = y;
	}
	else if (x == x->parent->Lnext)
	{
		x->parent->Lnext = y;
	}
	else
	{
		x->parent->Rnext = y;
	}
	y->Lnext = x;
	x->parent = y;
}
template <typename Key, typename Value>
void RBTree<Key, Value>::right_rotate(Node<Key, Value>* x) {
	Node<Key, Value>* y = new Node<Key, Value>;
	y = x->Lnext;
	x->Lnext = y->Rnext;
	if (y->Rnext != nil) {
		y->Rnext->parent = x;
	}
	if (y != nil) {
		y->parent = x->parent;
	}
	if (x->parent == nil) {
		Root = y;
	}
	else if (x == x->parent->Rnext)
	{
		x->parent->Rnext = y;
	}
	else
	{
		x->parent->Lnext = y;
	}
	y->Rnext = x;
	x->parent = y;
}
template <typename Key, typename Value>
void RBTree<Key, Value>::insert(Key key, Value value)
{
	if (Root == nil) {
		Node<Key, Value>* kkk = new Node<Key, Value>(key, value, 'b', nil, nil, nil);
		Root = kkk;
	}
	else {
		Node<Key, Value>* iter;
		iter = Root;
		for (;;) {
			if (key <= iter->key) {
				if (iter->Lnext == nil) {
					iter->Lnext = new Node<Key, Value>(key, value, 'r', iter, nil, nil);
					Insert_fixup(iter->Lnext);
					break;
				}
				iter = iter->Lnext;
			}
			else {
				if (iter->Rnext == nil) {
					iter->Rnext = new Node<Key, Value>(key, value, 'r', iter, nil, nil);
					Insert_fixup(iter->Rnext);
					break;
				}
				iter = iter->Rnext;
			}
		}
	}
}
template <typename Key, typename Value>
void RBTree<Key, Value>::Insert_fixup(Node<Key, Value>* newNode) {

	while (newNode != Root && newNode->parent->colour == 'r')
	{
		if (newNode->parent == newNode->parent->parent->Lnext) {
			Node<Key, Value>* y;
			y = newNode->parent->parent->Rnext;
			if (y->colour == 'r') {
				newNode->parent->colour = 'b';
				y->colour = 'b';
				newNode->parent->parent->colour = 'r';
				newNode = newNode->parent->parent;
			}
			else {
				if (newNode == newNode->parent->Rnext) {
					newNode = newNode->parent;
					left_rotate(newNode);
				}
				newNode->parent->colour = 'b';
				newNode->parent->parent->colour = 'r';
				right_rotate(newNode->parent->parent);
			}
		}
		else {
			Node<Key, Value>* y;
			y = newNode->parent->parent->Lnext;
			if (y->colour == 'r') {
				newNode->parent->colour = 'b';
				y->colour = 'b';
				newNode->parent->parent->colour = 'r';
				newNode = newNode->parent->parent;
			}
			else {
				if (newNode == newNode->parent->Lnext) {
					newNode = newNode->parent;
					right_rotate(newNode);
				}
				newNode->parent->colour = 'b';
				newNode->parent->parent->colour = 'r';
				left_rotate(newNode->parent->parent);
			}
		}
	}
	Root->colour = 'b';
}
template <typename Key, typename Value>
void  RBTree<Key, Value>::Remove_fixup(Node<Key, Value>* x) {
	while (x != Root && x->colour == 'b')
	{
		if (x == x->parent->Lnext) {
			Node<Key, Value>* w;
			w = x->parent->Rnext;
			if (w->colour == 'r') {
				w->colour = 'b';
				x->parent->colour = 'r';
				left_rotate(x->parent);
				w = x->parent->Rnext;
			}
			if (w->Lnext->colour == 'b' && w->Rnext->colour == 'b') {
				w->colour = 'r';
				x = x->parent;
			}
			else
			{
				if (w->Rnext->colour == 'b') {
					w->Lnext->colour = 'b';
					w->colour = 'r';
					right_rotate(w);
					w = x->parent->Rnext;
				}
				w->colour = x->parent->colour;
				x->parent->colour = 'b';
				w->Rnext->colour = 'b';
				left_rotate(x->parent);
				x = Root;
			}
		}
		else
		{
			Node<Key, Value>* w;
			w = x->parent->Lnext;
			if (w->colour == 'r') {
				w->colour = 'b';
				x->parent->colour = 'r';
				right_rotate(x->parent);
				w = x->parent->Lnext;
			}
			if (w->Rnext->colour == 'b' && w->Lnext->colour == 'b') {
				w->colour = 'r';
				x = x->parent;
			}
			else
			{
				if (w->Lnext->colour == 'b') {
					w->Rnext->colour = 'b';
					w->colour = 'r';
					left_rotate(w);
					w = x->parent->Lnext;
				}
				w->colour = x->parent->colour;
				x->parent->colour = 'b';
				w->Lnext->colour = 'b';
				right_rotate(x->parent);
				x = Root;
			}
		}
	}
	x->colour = 'b';
}
template <typename Key, typename Value>
void  RBTree<Key, Value>::remove(Key key) {
	Node<Key, Value>* y;
	Node<Key, Value>* Z;
	Node<Key, Value>* X;
	Z = find(key);
	y = Z;
	char y_o_colour = y->colour;
	if (Z->Lnext == nil) {
		X = Z->Rnext;
		transplant(Z, Z->Rnext);
	}
	else if (Z->Rnext == nil)
	{
		X = Z->Lnext;
		transplant(Z, Z->Lnext);
	}
	else
	{
		y = y->Rnext;
		while (y->Lnext != nil)
		{
			y = y->Lnext;
		}
		y_o_colour = y->colour;
		X = y->Rnext;
		if (y->parent == Z) {
			X->parent = y;
		}
		else
		{
			transplant(y, y->Rnext);
			y->Rnext = Z->Rnext;
			y->Rnext->parent = y;
		}
		transplant(Z, y);
		y->Lnext = Z->Lnext;
		y->Lnext->parent = y;
		y->colour = Z->colour;
	}
	if (y_o_colour == 'b') {
		Remove_fixup(X);
	}
}
template <typename Key, typename Value>
void  RBTree<Key, Value>::transplant(Node<Key, Value>* U, Node<Key, Value>* V)
{
	if (U->parent == nil) {
		Root = V;
	}
	else if (U == U->parent->Lnext) {
		U->parent->Lnext = V;
	}
	else
	{
		U->parent->Rnext = V;
	}
	V->parent = U->parent;
}
template <typename Key, typename Value>
List<Key>* RBTree<Key, Value>::get_keys()
{
	if (Root == nil) {
		throw("There is no element");
	}
	stack<Key, Value> stackKey;
	List<Key>* listKey = new List<Key>;
	stackKey.push(Root);
	bool flag = true;
	Node<Key, Value>* temp = stackKey.head->date;
	while (!stackKey.isEmpty()) {
		listKey->push_back(temp->key);
		if (temp->Rnext != nil) {
			if (flag) {
				stackKey.pop_front();
				flag = false;
			}
			stackKey.push(temp->Rnext);
		}
		if (temp->Lnext != nil) {
			temp = temp->Lnext;
		}
		else
		{

			if (flag) {
				stackKey.pop_front();
			}
			if (!stackKey.isEmpty()) {
				temp = stackKey.head->date;
			}
			flag = true;
		}
	}
	return listKey;
}
template <typename Key, typename Value>
List<Value>* RBTree<Key, Value>::get_values()
{
	if (Root == nil) {
		throw("There is no element");
	}
	stack<Key, Value> stackValue;
	List<Key>* listValue = new List<Key>;
	stackValue.push(Root);
	bool flag = true;
	Node<Key, Value>* temp = stackValue.head->date;
	while (!stackValue.isEmpty()) {
		listValue->push_back(temp->value);
		if (temp->Rnext != nil) {
			if (flag) {
				stackValue.pop_front();
				flag = false;
			}
			stackValue.push(temp->Rnext);
		}
		if (temp->Lnext != nil) {
			temp = temp->Lnext;
		}
		else
		{

			if (flag) {
				stackValue.pop_front();
			}
			if (!stackValue.isEmpty()) {
				temp = stackValue.head->date;
			}
			flag = true;
		}
	}
	return listValue;
}
template <typename Key, typename Value>
void RBTree<Key, Value>::print() {
	List<Key>* ListKey = get_keys();
	List<Value>* ListValue = get_values();
	for (int i = 0; i < ListKey->get_size(); i++) {
		std::cout << ListKey->at(i) << "-" << ListValue->at(i) << std::endl;
	}
}
