#include "ForwardList.h"

int main()
{
	ForwardList<int> list;

	list.push_back(6);
	list.push_front(4);
	list.insert(5, 1);

	list.print(); //print ONLY for TEST
}