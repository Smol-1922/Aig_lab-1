#ifndef BRTree_H
#define BRTree_H
#include"NodeBRTree.h"
#include"stack.h"
#include"List.h"
template <typename Key, typename Value>
class RBTree
{
private:
	Node<Key, Value>* nil = new Node<Key, Value>();
	void Insert_fixup(Node<Key, Value>* newNode);
	void Remove_fixup(Node<Key, Value>* x);
	void left_rotate(Node<Key, Value>* curret);
	void right_rotate(Node<Key, Value>* curret);
public:
	RBTree();
	~RBTree();
	Node<Key, Value>* Root;
	void insert(Key key, Value value); // ���������� �������� � ������ � ���������
	void remove(Key key); // �������� �������� ������ �� �����
	Node<Key, Value>* find(Key key)// ����� �������� �� �����
	{
		if (Root == nullptr) {
			throw "No such element exists";
		}
		else {
			Node<Key, Value>* iter;
			iter = Root;
			for (;;) {
				if (key <= iter->key) {
					if (iter->key == key) {
						return iter;
					}
					if (iter->Lnext == nil) {
						throw "No such element exists";
					}
					iter = iter->Lnext;
				}
				else {
					if (iter->key == key) {
						return iter;
					}
					if (iter->Rnext == nil) {
						throw "No such element exists";
					}
					iter = iter->Rnext;
				}
			}
		}
	}
	void transplant(Node<Key, Value>* U, Node<Key, Value>* V);
	void clear(); // �������� �������������� �������
	void preorder(Node<Key, Value>* node);
	List<Key>* get_keys(); // ���������� ������ ������
	List<Value>* get_values(); // ���������� ������ ��������
	Node<Key, Value>* get_nil();
	void print(); // ����� � �������

};
#endif