#include <iostream>
#include <Polynomial.h>

using namespace std;
using namespace polynomial;

int main() {
	LinkedList<int> list;
	list.push_head(1, 2);
	list.push_tail(1, 3);
	list.push_head(3, 4);
	cout << list;
	return 0;
}