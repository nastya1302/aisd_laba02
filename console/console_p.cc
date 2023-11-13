#include <iostream>
#include <Polynomial.h>

using namespace std;
using namespace polynomial;

int main() {
	LinkedList<int> list;
	list.push_head(3, 4);
	list.push_tail(5, 6);
	list.push_head(1, 2);

	//LinkedList<int> _list;
	//_list.push_head(9, 10);
	//_list.push_tail(11, 12);
	//_list.push_head(7, 8);

	//list.push_tail(_list);
	cout << list;
	return 0;
}