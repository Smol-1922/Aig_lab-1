#ifndef stack_H
#define stack_H
#include"BRTree.h"
#include"NodeBRTree.h"
template <typename Key, typename Value>
class stack
{
private:
	class stackNode {
	public:
		Node<Key, Value>* date;
		stackNode* next;

		stackNode(Node<Key, Value>* date = nullptr, stackNode* next = nullptr)
		{
			this->date = date;
			this->next = next;
		};
		~stackNode()
		{

		}

	};
public:
	stackNode* head;
	stackNode* tail;
	unsigned int size;
	stack();
	~stack();
	void clear();
	bool isEmpty();
	void push(Node<Key, Value>* date);
	void pop_front();
	void pop_back();
	void reset_list();
};
#endif