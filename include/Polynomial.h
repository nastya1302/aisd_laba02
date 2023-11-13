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
	};
	
	template<typename T>
	class LinkedList {
	private:
		Node<T>* begin;
		Node<T>* end;
		//int count;

	public:
		LinkedList(): begin(nullptr), end(nullptr){}
		

		Node<T>* get_begin() { return begin; }
		Node<T>* get_end() { return end; }
		
		//LinkedList(const LinkedList<T>& _list);
		//LinkedList<T>& operator=(const LinkedList& _list);
		//~LinkedList();

		void push_tail(const T& _data, const int _degree) {
			Node<T>* new_node = new Node<T>;
			new_node->data = _data;
			new_node->degree = _degree;
			if (end != NULL) {
				end->next = new_node;
				begin->prev = new_node;
			}
			else if (end == NULL) {
				begin = new_node;
			}
			new_node->next = begin;
			new_node->prev = end;
			end = new_node;
		}
		
		//void push_tail(const LinkedList& _list);
		
		void push_head(const T& _data, const int _degree) {
			Node<T>* new_node = new Node<T>;
			new_node->data = _data;
			new_node->degree = _degree;
			if (begin != NULL) {
				end->next = new_node;
				begin->prev = new_node;
			}
			else if (begin == NULL) {
				end = new_node;
			}
			new_node->next = begin;
			new_node->prev = end;
			begin = new_node;
		}

		//void push_head(const LinkedList& _list);
		//void pop_head();
		//void pop_tail();
		//void delete_node(T& _data, const int _degree);
		//Node operator[](int _index);
		//void set_node(const T _data, const int _degree, int _index);
	};

	template<typename T>
	ostream& operator<<(ostream& os, LinkedList<T>& a) {
		Node<T>* cur = a.get_begin();
		do {
			cout << cur->data << " " << cur->degree << endl;
			cur = cur->next;
		} while (cur != a.get_begin());
		return os;
	}
}
