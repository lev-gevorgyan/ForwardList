#ifndef FORWARDLIST_H
#define FORWARDLIST_H

#include <iostream>

#include "Node.h"

template<typename T>
class ForwardList
{
public:

	void push_back(const T&);
	void push_front(const T&);
	void insert(const T&, size_t);

	void print() const; //only for TEST

	Node<T>* getHead() const { return m_head; }
	void setHead(Node<T>* node) { m_head = node; }

private:
	Node<T>* m_head{ nullptr };
};


template<typename T>
void ForwardList<T>::push_back(const T& data)
{
	Node<T>* node = new Node<T>;
	node->data = data;

	if (!getHead())
	{
		setHead(node);
	}
	else {
		Node<T>* cur = getHead();
		while (cur->next)
			cur = cur->next;
		cur->next = node;
	}
}

template<typename T>
void ForwardList<T>::push_front(const T& data)
{
	Node<T>* node = new Node<T>;
	node->data = data;
	
	if (!getHead())
	{
		setHead(node);
	}
	else {
		node->next = m_head;
		setHead(node);
	}
}

template<typename T>
void ForwardList<T>::insert(const T& data, size_t pos)
{
	Node<T>* node = new Node<T>;
	node->data = data;

	if (!getHead())
	{
		setHead(node);
	} 
	else {
		Node<T>* cur{ m_head };
		Node<T>* prev{ nullptr };
		Node<T>* next{ nullptr };

		while (pos)
		{
			if (pos == 1)
			{
				prev = cur;
				next = cur->next;
			}
			cur = cur->next;
			--pos;
		}

		prev->next = node;
		node->next = next;
	}
}

// for test
template<typename T>
void ForwardList<T>::print() const
{
	Node<T>* tmp = getHead();
	while (tmp)
	{
		std::cout << tmp->data << std::endl;
		tmp = tmp->next;
	}
}

#endif // !FORWARDLIST_H