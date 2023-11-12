#pragma once
#include <iostream>

using namespace std;

namespace polynomial {
	
	template<typename T>
	struct Node {
		T data;
		Node<T>* next;
		Node<T>* prev;
		Node(): data(), next(nullptr), prev(nullptr){}
	};
	
	template<typename T>
	class LinkedList {
	private:
		Node<T>* begin;
		Node<T>* end;
		int count;

	public:
		LinkedList();
		LinkedList(const LinkedList& _list);
		LinkedList<T>& operator=(const LinkedList& _list);
		~LinkedList();
		void push_tail(const T& _data);
		void push_tail(const LinkedList& _list);
		void push_head(const T& _data);
		void push_head(const LinkedList& _list);
		void pop_head();
		void pop_tail();
		void delete_node(T& _data);
		T operator[](int _index);
		void set_node(const T _data, int _index);
	};
}
