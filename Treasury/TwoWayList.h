//#pragma once
//
//#include <vector>
//#include <iostream>
//#include <stdexcept>
//
//
//template<class T>
//class TwoWayList
//{
//private:
//	class Node
//	{
//		friend
//			class TwoWayList<T>;
//	private:
//		T value;
//		Node* nextNode = nullptr;
//		Node* prevNode = nullptr;
//		void setNext(Node* next) noexcept
//		{
//			nextNode = next;
//		}
//
//		void setPrev(Node* prev) noexcept
//		{
//			prevNode = prev;
//		}
//	
//	public:
//		Node(T val) noexcept
//			:value(val)
//		{
//
//		}
//
//		~Node() = default;
//
//		T getVal() const noexcept
//		{
//			return value;
//		}
//
//		Node* getNext() const noexcept
//		{
//			return nextNode;
//		}
//
//		Node* getPrev() const noexcept
//		{
//			return prevNode;
//		}
//
//		bool operator==(Node* node) const noexcept  // niepotrzebne
//		{
//			return (getVal() == node->getVal());
//		}
//
//		bool operator!=(Node* node) const noexcept // niepotrzebne
//		{
//			return (getVal() != node->getVal());
//		}
//	};
//	
//	Node* begNod;
//	Node* endNod;
//	int len = 0;
//public:
//	class Iterator;
//
//	TwoWayList() noexcept
//		:begNod(nullptr), endNod(nullptr)
//	{
//
//	}
//
//	TwoWayList(const std::vector<T>& nodes) noexcept
//	{
//		for (auto& v : nodes)
//		{
//			append(v);
//		}
//	}
//
//	TwoWayList(const T& beg) noexcept
//	{
//		Node* newNode = new Node(beg);
//		begNod = newNode;
//		endNod = newNode;
//		len = 1;
//	}
//
//	size_t size() const noexcept
//	{
//		return len;
//	}
//
//	Node* getNode(int index) const  // supposed to be private, left public for tests
//	{
//		try
//		{
//			if (index < 0 || index > len - 1)
//			{
//				throw std::invalid_argument("");
//			}
//			TwoWayList<T>::Iterator iter = this->begin();
//			for (int i = 0; i < index; i++)
//				iter++;
//			return iter.getNode();
//		}
//		catch (std::invalid_argument& e)
//		{
//			throw std::invalid_argument("");
//			std::cerr << "Index out of range (get_node)" << std::endl;
//			return 0;
//		}
//	}
//
//	T getVal(int index) const
//	{
//		try
//		{
//			return (this->getNode(index))->getVal();
//		}
//		catch (std::invalid_argument& e)
//		{
//			std::cerr << "Index out of range (get_val)" << std::endl;
//			return 0;
//		}
//	}
//
//	void appendToEmpty(const T& elem) noexcept
//	{
//		Node* newNode = new Node(elem);
//		begNod = newNode;
//		endNod = newNode;
//		len = 1;
//	}
//
//	void append(const T& elem) noexcept
//	{
//		if (len == 0)
//		{
//			appendToEmpty(elem);
//		}
//		else
//		{
//			Node* newNode = new Node(elem);
//			(*endNod).setNext(newNode);
//			newNode->setPrev(endNod);
//			endNod = newNode;
//			len++;
//		}
//	}
//
//	void addToBegin(const T& elem) noexcept
//	{
//		if (len == 0)
//		{
//			appendToEmpty(elem);
//		}
//		else
//		{
//			Node* newNode = new Node(elem);
//			(*begNod).setPrev(newNode);
//			newNode->setNext(begNod);
//			begNod = newNode;
//			len++;
//		}
//
//	}
//
//	void insert(Iterator iter, const T& elem) noexcept
//	{
//		if (iter == begNod)
//		{
//			addToBegin(elem);
//		}
//		else if (iter == endNod)
//		{
//			append(elem);
//		}
//		else if (iter != nullptr)
//		{
//			Node* newNode = new Node(elem);
//			Node* fNode = iter.getNode()->getPrev();
//			Node* sNode = iter.getNode();
//			newNode->setNext(sNode);
//			newNode->setPrev(fNode);
//			fNode->setNext(newNode);
//			sNode->setPrev(newNode);
//			len++;
//		}
//	}
//
//	void destroy() noexcept
//	{
//		Node* currentNod = begNod;
//		while (currentNod != nullptr)
//		{
//			Node* tmp = currentNod;
//			currentNod = currentNod->getNext();
//			delete tmp;
//		}
//		begNod = nullptr;
//		endNod = nullptr;
//		len = 0;
//	}
//
//	void removeFirst() noexcept
//	{
//		if (len == 1)
//		{
//			destroy();
//		}
//		else
//		{
//			Node* successor = getNode(1);
//			successor->setPrev(nullptr);
//			begNod = successor;
//			len--;
//		}
//	}
//
//	void removeLast() noexcept
//	{
//		if (len == 1)
//		{
//			destroy();
//		}
//		else
//		{
//			Node* successor = getNode(len - 2);
//			successor->setNext(nullptr);
//			endNod = successor;
//			len--;
//		}
//	}
//
//	void remove(Iterator iter) noexcept
//	{
//		if (len == 0)
//		{
//			throw std::invalid_argument("List is empty");
//		}
//		else
//		{
//			Node* fNode = iter.getNode()->getPrev();
//			Node* sNode = iter.getNode()->getNext();
//			if (fNode != nullptr)
//				fNode->setNext(sNode);
//			else
//				begNod = sNode;
//			if (sNode != nullptr)
//				sNode->setPrev(fNode);
//			else
//				endNod = fNode;
//			len--;
//		}
//	}
//
//	Node* pop() noexcept
//	{
//		try
//		{
//			if (len > 0)
//			{
//				Node* result = endNod;
//				removeLast();
//				return result;
//			}
//			else
//			{
//				throw std::invalid_argument("");
//			}
//		}
//		catch (std::invalid_argument& e)
//		{
//			std::cerr << "Cannot pop from an empty list" << std::endl;
//		}
//	}
//
//	class Iterator
//	{
//		friend 
//			class TwoWayList<T>;
//	private:
//		Node* current;
//		bool direction = true;  // if true then it moves from left to right
//	public:
//		Iterator(Node* node) noexcept
//			:current(node)
//		{
//		}
//
//		Iterator(Iterator const& iter) noexcept
//			:current(iter.current)
//		{
//		}
//
//		~Iterator() = default;
//
//		void reverse() noexcept
//		{
//			if (direction == true)
//				direction = false;
//			else if (direction == false)
//				direction = true;
//		}
//
//		Node* getNode() const noexcept
//		{
//			return current;
//		}
//
//		T operator*() const
//		{
//			return current->getVal();
//		}
//
//		Iterator operator++(int) //postincrement
//		{
//			Iterator copy(*this);
//			++(*this);
//			return copy;
//		}
//
//		Iterator& operator++() //preincrement
//		{
//			try
//			{
//				if (direction == true)
//				{
//					Node* next = current->getNext();
//					if (current == nullptr)
//						throw std::range_error("Iterator pointing at the end of the list");
//					current = next;
//				}
//				else if (direction == false)
//				{
//					Node* next = current->getPrev();
//					if (current == nullptr)
//						throw std::range_error("Iterator pointing at the end of the list");
//					current = next;
//				}
//			}
//			catch (std::range_error& e)
//			{
//				std::cerr << std::endl << "Iterator pointing at the end of the list" << std::endl;
//			}
//			return *this;
//		}
//
//		Iterator operator--(int) //postdecrement
//		{
//			Iterator copy(*this);
//			--(*this);
//			return copy;
//		}
//
//		Iterator& operator--() //predecrement
//		{
//			try
//			{
//				if (direction == true)
//				{
//					Node* next = current->getPrev();
//					if (current == nullptr)
//						throw std::range_error("");
//					current = next;
//				}
//				else if (direction == false)
//				{
//					Node* next = current->getNext();
//					if (current == nullptr)
//						throw std::range_error("Iterator pointing at the end of the list");
//					current = next;
//				}
//			}
//			catch (std::range_error& e)
//			{
//				std::cerr << std::endl << "Iterator pointing at the end of the list" << std::endl;
//			}
//			return *this;
//		}
//
//		void operator+=(int n)
//		{
//			for (int i = 0; i < n; i++)
//			{
//				(*this)++;
//			}
//		}
//
//		void operator-=(int n)
//		{
//			for (int i = 0; i < n; i++)
//			{
//				(*this)--;
//			}
//		}
//
//		bool operator==(Iterator iter) const noexcept
//		{
//			return (current == iter.current);
//		}
//
//		bool operator!=(Iterator iter) const noexcept
//		{
//			return !(current == iter.current);
//		}
//	};
//
//	Iterator begin() const
//	{
//		Iterator iter(begNod);
//		return iter;
//	};
//
//	Iterator end() const
//	{
//		Iterator iter(endNod);
//		return iter;
//	}
//
//};


// nowa lista

// To jest na nowa TwoWayList

#pragma once

#include <stdexcept>

template <typename T>
class TwoWayList	// T is type of stored object, e.g. Shape* or int
{
private:
	struct Node {
		T data;
		Node* next;
		Node* previous;

		Node(T value) {
			data = value;
			next = nullptr;
			previous = nullptr;
		}
	};

	Node* first;
	Node* last;

public:
	TwoWayList()
	{
		first = nullptr;
		last = nullptr;
	}

	~TwoWayList()
	{
		while (first != nullptr)
		{
			Node* n = first->next;
			delete first;
			first = n;
		}
	}

	class Iterator
	{
		friend TwoWayList;

	private:
		Node* current;
		TwoWayList* collection;

		Iterator(TwoWayList* col, Node* n = nullptr) : collection(col)
		{
			current = n;
		}

	public:
		T& operator*()
		{
			return current->data;
		}

		Iterator& operator++()
		{
			if (current == nullptr)
				throw std::range_error("...");
			current = current->next;
			return *this;
		}

		Iterator& operator--()
		{
			if (current == collection->first)
				throw std::range_error("...");
			if (current == nullptr)
				current = collection->last;
			else
				current = current->previous;
			return *this;
		}

		bool operator!=(Iterator i)
		{
			return current != i.current;
		}

		void change(Iterator& i)
		{
			current = i.current;
		}

	};

	Iterator begin()
	{
		return Iterator(this, first);
	}

	Iterator end()
	{
		return Iterator(this, nullptr);
	}

	void push(T const& value) // add element on the end. Sets iterator to end()
	{
		Node* n = new Node(value);
		n->previous = last;

		if (first == nullptr)
			first = n;
		else
			last->next = n;

		last = n;
	}

	void add(T const& value, Iterator& i) // add element on the position pointed by given iterator
	{
		if (i.current == nullptr) // if i = collection.end()
			push(value);
		else
		{
			Node* n = new Node(value);
			n->next = i.current;
			n->previous = i.current->previous;

			if (i.current == first) // if i = collection.begin()
				first = n;
			else
				i.current->previous->next = n;

			i.current->previous = n;
			i.current = n;
		}
	}

	void del(Iterator& i) // deletes item on the position pointed by given iterator
	{
		if (i.current == nullptr) {
			// code if i = end()
			throw std::range_error("...");
		}

		if (i.current->previous != nullptr)
			i.current->previous->next = i.current->next;
		else
			first = i.current->next;

		if (i.current->next != nullptr)
			i.current->next->previous = i.current->previous;
		else
			last = i.current->previous;

		Node* temp = i.current;
		++i;
		delete temp;
	}

	bool empty() const noexcept
	{
		return first == nullptr;
	}
};

