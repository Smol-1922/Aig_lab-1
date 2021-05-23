#ifndef List_H
#define List_H
template <typename Data>
class List
{
public:
	List();
	~List();
	void reset_list();
	void push_back(Data); // adding to the end of the list
	void push_front(Data); // adding to the top of the list
	void pop_back(); // deleting the last element
	void pop_front(); // deleting the first element
	unsigned int get_size(); // getting the list size
	void print_to_console(); // output list items to the console using a separator
	void clear(); // deleting all list items
	bool isEmpty(); // checking if the list is empty
	Data at(unsigned int index);
private:
	class ListNode {
	public:
		Data data;
		ListNode* next;

		ListNode(Data data, ListNode* next = nullptr)
		{
			this->data = data;
			this->next = next;
		};
		~ListNode()
		{

		}

	};
	ListNode* tail;
	ListNode* head;
	unsigned int size;
};
#endif
