#ifndef NodeBRTree_H
#define NodeBRTree_H
#include<iostream>
template <typename Key, typename Value>
class Node {
public:
	Key key;
	Value value;
	char colour;
	Node* Lnext;
	Node* Rnext;
	Node* parent;
	Node(Key key, Value value, char colour = 'b', Node* parent = nullptr, Node* Lnext = nullptr, Node* Rnext = nullptr)
	{
		this->parent = parent;
		this->key = key;
		this->value = value;
		this->colour = colour;
		this->Lnext = Lnext;
		this->Rnext = Rnext;
	};
	Node(char colour = 'b', Node* parent = nullptr, Node* Lnext = nullptr, Node* Rnext = nullptr)
	{
		this->parent = parent;
		this->colour = colour;
		this->Lnext = Lnext;
		this->Rnext = Rnext;
	};
	~Node()
	{
		value = NULL;
		key = NULL;
		colour = NULL;
		Lnext = nullptr;
		Rnext = nullptr;
		parent = nullptr;

	}

};
#endif