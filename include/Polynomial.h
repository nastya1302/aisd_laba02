#pragma once
#include <iostream>

using namespace std;

namespace polynomial {	
	template<typename T>
	struct Node {
		T data;
		int degree;
		Node<T>* next;
		Node<T>* prev;
		
		Node(): data(0), degree(0), next(nullptr), prev(nullptr){}
		Node(T _data, int _degree) : data(_data), degree(_degree), next(nullptr), prev(nullptr) {}
	};
	
	template<typename T>
	class LinkedList {
	private:
		Node<T>* head;
		Node<T>* tail;

	public:
		LinkedList(): head(nullptr), tail(nullptr){}
		
		Node<T>* get_head() { return head; }
		Node<T>* get_tail() { return tail; }

		LinkedList(const LinkedList<T>& _list) {
			head = nullptr;
			tail = nullptr;
			Node<T>* cur = _list.head;
			do {
				Node<T>* node = new Node(cur->data, cur->degree);
				push_tail(node);
				cur = cur->next;
			} while (cur != _list.head);
		}

		~LinkedList() {
			while (head != tail){
				Node<T>* cur = head;
				head = head->prev;
				delete cur;
			}
			delete tail;
		}

		LinkedList<T>& operator=(const LinkedList<T>& _list) {
			swap(_list);
			return *this;
		}

		void swap(LinkedList<T>& _list) {
			std::swap(head, _list.head);
		}

		void push_tail(Node<T>* t) {
			if (tail != NULL) {
				tail->next = t;
				head->prev = t;
			}
			else if (tail == NULL) {
				head = t;
			}
			t->next = head;
			t->prev = tail;
			tail = t;
		}
		
		void push_tail(const LinkedList& _list) {
			if (_list.tail == NULL) {
				cout << "The list is empty" << endl;
			}
			else if (tail == NULL) {
				head = _list.head;
				tail = _list.tail;
			}
			else {
				_list.tail->next = head;
				head->prev = _list.tail;
				_list.head->prev = tail;
				tail->next = _list.head;
				tail = _list.tail;
			}
		}
		
		void push_head(Node<T>* h) {
			if (head != NULL) {
				tail->next = h;
				head->prev = h;
			}
			else if (head == NULL) {
				tail = h;
			}
			h->next = head;
			h->prev = tail;
			head = h;
		}

		void push_head(const LinkedList<T>& _list) {
			if (_list.head == NULL) {
				cout << "The list is empty." << endl;
			}
			else if (head == NULL) {
				head = _list.head;
				tail = _list.tail;
			}
			else {
				_list.tail->next = head;
				head->prev = _list.tail;
				_list.head->prev = tail;
				tail->next = _list.head;
				head = _list.head;
			}
		}

		void pop_head() {
			if (head == NULL) {
				cout << "The list is empty" << endl;
			}
			else {
				Node<T>* cur = head;
				head = head->next;
				head->prev = tail;
				tail->next = head;
				delete cur;
			}
		}

		void pop_tail() {
			if (tail == NULL) {
				cout << "The list is empty" << endl;
			}
			else {
				Node<T>* cur = tail;
				tail = tail->prev;
				head->prev = tail;
				tail->next = head;
				delete cur;
			}
		}

		void delete_node(T _data, const int _degree) {
			if (head == NULL) {
				cout << "The list is empty" << endl;
			}
			else {
				Node<T>* cur = head;
				do {
					if (_data == cur->data && _degree == cur->degree) {
						if (cur == head) {
							cur = cur->next;
							this->pop_head();
						}
						else if (cur == tail) {
							cur = cur->next;
							this->pop_tail();
						}
						else {
							Node<T>* ptr = cur;
							cur = cur->next;
							cur->prev = ptr->prev;
							ptr->prev->next = cur;
							delete ptr;
						}
					}
					else {
						cur = cur->next;
					}
				} while (cur != head);
			}
		}

		//Node operator[](int _index);
		//void set_node(const T _data, const int _degree, int _index);

		int count_elem(Node<T>* h) {
			int count = 0;
			if (h != NULL) {
				Node<T>* cur = h;
				do {
					count++;
					cur = cur->next;
				} while (cur != h);
			}
			return count;
		}
	};

	template<typename T>
	ostream& operator<<(ostream& os, LinkedList<T>& a) {
		Node<T>* cur = a.get_head();
		do {
			cout << cur->data << " " << cur->degree << endl;
			cur = cur->next;
		} while (cur != a.get_head());
		return os;
	}
}