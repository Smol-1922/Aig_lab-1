#include"List.h"
#include"NodeBRTree.h"
template <typename Data>
List<Data>::List()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}
template <typename Data>
List<Data>::~List()
{
	clear();
}
template <typename Data>
void List<Data>::reset_list()
{
	tail = nullptr;
	head = nullptr;
}
template <typename Data>
unsigned int List<Data>::get_size()
{
	return size;
}
template <typename Data>
void List<Data>::push_back(Data date)
{
	if (size == 0) {
		head = new ListNode(date);
		tail = head;
	}
	else {
		tail->next = new ListNode(date);
		tail = tail->next;
	}
	size++;
}
template <typename Data>
void List<Data>::push_front(Data date)
{
	if (size == 0) {
		head = new ListNode(date);
		tail = head;
	}
	else {
		head = new ListNode(date, head);
	}
	size++;
}
template <typename Data>
void List<Data>::pop_back() {
	if (size == 0) return;
	if (size == 1) {
		delete head;
		reset_list();
	}
	else {
		Node* current = head;
		while (current->next != tail) {
			current = current->next;
		}
		current->next = nullptr;
		delete tail;
		tail = current;
	}
	size--;
}
template <typename Data>
void  List<Data>::pop_front() {
	if (size == 0) {
		return;
	}
	if (size == 1) {
		delete head;
		reset_list();
	}
	else {
		ListNode* current = head;
		head = head->next;
		delete current;
	}
	size--;
}
template <typename Data>
void List<Data>::print_to_console() {
	if (size == 0) {
		return;
	}
	else {
		unsigned int index = get_size();
		ListNode* current = head;
		while (index != 0) {
			std::cout << current->value << " ";
			current = current->next;
			index--;
		}
		std::cout << std::endl;
	}
}
template <typename Data>
void List<Data>::clear()
{
	while (size != 0)
	{
		pop_front();
	}
}
template <typename Data>
bool List<Data>::isEmpty() {
	if (size != 0) {
		return 0;
	}
	return 1;
}
template <typename Data>
Data List<Data>::at(unsigned int index)
{
	if (index >= size) {
		throw std::out_of_range("Index is greater than list size");
	}
	else {
		ListNode* current = head;
		unsigned int counter = 0;
		while (counter != index) {
			current = current->next;
			counter++;
		}
		return current->data;
	}
}