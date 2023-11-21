#include <iostream>
#include <Polynomial.h>

using namespace std;
using namespace polynomial;

int main() {
	LinkedList<int> list;
	Node<int>* a = new Node(1, 2);
	Node<int>* b = new Node(3,4);
	Node<int>* c = new Node(5,6);
	
	list.push_head(b);
	list.push_tail(c);
	list.push_head(a);

	LinkedList<int> _list;
	Node<int>* d = new Node(7,8);
	Node<int>* e = new Node(9,10);
	Node<int>* f = new Node(11,12);
	_list.push_head(e);
	_list.push_tail(f);
	_list.push_head(d);

	list.delete_node(1, 2);
	//list.delete_node(5, 6);

	//list.pop_head();
	//list.pop_tail();
	//list = _list;
	//LinkedList<int> _list2(list);
	//list.push_tail(_list);
	
	cout << list;
	return 0;
}