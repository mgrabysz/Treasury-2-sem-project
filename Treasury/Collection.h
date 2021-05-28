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
