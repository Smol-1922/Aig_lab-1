#include"BRTree.h"
#include"stack.h"
#include"NodeBRTree.h"
template <typename Key, typename Value>
stack<Key, Value>::stack() {
	head = nullptr;
	tail = nullptr;
	size = 0;
}
template <typename Key, typename Value>
stack<Key, Value>::~stack() {
	clear();
}
template <typename Key, typename Value>
void stack<Key, Value>::clear() {
	while (size != 0)
	{
		pop_front();
	}
}
template <typename Key, typename Value>
bool stack<Key, Value>::isEmpty() {
	if (size != 0) {
		return 0;
	}
	return 1;
}
template <typename Key, typename Value>
void stack<Key, Value>::push(Node<Key, Value>* date) {
	if (size == 0) {
		head = new stackNode(date);
		tail = head;
	}
	else {
		head = new stackNode(date, head);
	}
	size++;
}
template <typename Key, typename Value>
void stack<Key, Value>::pop_front() {
	if (size == 0) {
		return;
	}
	if (size == 1) {
		delete head;
		reset_list();
	}
	else {
		stackNode* current = head;
		head = head->next;
		delete current;
	}
	size--;

}
template <typename Key, typename Value>
void stack<Key, Value>::pop_back() {
	if (size == 0) return;
	if (size == 1) {
		delete head;
		reset_list();
	}
	else {
		stackNode* current = head;
		while (current->next != tail) {
			current = current->next;
		}
		current->next = nullptr;
		delete tail;
		tail = current;
	}
	size--;
}
template <typename Key, typename Value>
void stack<Key, Value>::reset_list()
{
	head = nullptr;
	tail = nullptr;
}

