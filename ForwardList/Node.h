#ifndef NODE_H
#define NODE_H

template<typename T>
struct Node
{
	T data{ 0 };
	Node<T>* next{ nullptr };
};

#endif // !NODE_H