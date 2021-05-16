#pragma once

#include <vector>
#include <iostream>
#include <stdexcept>


template<class T>
class TwoWayList
{
private:
	class Node
	{
		friend
			class TwoWayList<T>;
	private:
		T value;
		Node* next_node = nullptr;
		Node* prev_node = nullptr;
		void set_next(Node* next) noexcept
		{
			next_node = next;
		}

		void set_prev(Node* prev) noexcept
		{
			prev_node = prev;
		}
	public:
		Node(T val) noexcept
			:value(val)
		{

		}

		~Node() = default;

		T get_val() const noexcept
		{
			return value;
		}

		Node* get_next() const noexcept
		{
			return next_node;
		}

		Node* get_prev() const noexcept
		{
			return prev_node;
		}

		bool operator==(Node* node) const noexcept  // niepotrzebne
		{
			return (get_val() == node->get_val());
		}

		bool operator!=(Node* node) const noexcept // niepotrzebne
		{
			return (get_val() != node->get_val());
		}
	};
	
	Node* beg_nod;
	Node* end_nod;
	int len = 0;
public:
	class Iterator;

	TwoWayList() noexcept
		:beg_nod(nullptr), end_nod(nullptr)
	{

	}

	TwoWayList(const std::vector<T>& nodes) noexcept
	{
		for (auto& v : nodes)
		{
			append(v);
		}
	}

	TwoWayList(const T& beg) noexcept
	{
		Node* new_node = new Node(beg);
		beg_nod = new_node;
		end_nod = new_node;
		len = 1;
	}

	size_t size() const noexcept
	{
		return len;
	}

	Node* get_node(int index) const  // supposed to be private, left public for tests
	{
		try
		{
			if (index < 0 || index > len - 1)
			{
				throw std::invalid_argument("");
			}
			TwoWayList<T>::Iterator iter = this->begin();
			for (int i = 0; i < index; i++)
				iter++;
			return iter.get_node();
		}
		catch (std::invalid_argument& e)
		{
			throw std::invalid_argument("");		//jak inaczej
			std::cerr << "Index out of range (get_node)" << std::endl;
			return 0;
		}
	}

	T get_val(int index) const
	{
		try
		{
			return (this->get_node(index))->get_val();
		}
		catch (std::invalid_argument& e)
		{
			std::cerr << "Index out of range (get_val)" << std::endl;
			return 0;
		}
	}

	void append_to_empty(const T& elem) noexcept
	{
		Node* new_node = new Node(elem);
		beg_nod = new_node;
		end_nod = new_node;
		len = 1;
	}

	void append(const T& elem) noexcept
	{
		if (len == 0)
		{
			append_to_empty(elem);
		}
		else
		{
			Node* new_node = new Node(elem);
			(*end_nod).set_next(new_node);
			new_node->set_prev(end_nod);
			end_nod = new_node;
			len++;
		}
	}

	void add_to_begin(const T& elem) noexcept
	{
		if (len == 0)
		{
			append_to_empty(elem);
		}
		else
		{
			Node* new_node = new Node(elem);
			(*beg_nod).set_prev(new_node);
			new_node->set_next(beg_nod);
			beg_nod = new_node;
			len++;
		}

	}

	void insert(Iterator iter, const T& elem) noexcept
	{
		if (iter == beg_nod)
		{
			add_to_begin(elem);
		}
		else if (iter == end_nod)
		{
			append(elem);
		}
		else
		{
			Node* new_node = new Node(elem);
			Node* f_node = iter.get_node()->get_prev();
			Node* s_node = iter.get_node();
			new_node->set_next(s_node);
			new_node->set_prev(f_node);
			f_node->set_next(new_node);
			s_node->set_prev(new_node);
			len++;
		}
	}

	void destroy() noexcept
	{
		Node* current_nod = beg_nod;
		while (current_nod != nullptr)
		{
			Node* tmp = current_nod;
			current_nod = current_nod->get_next();
			delete tmp;
		}
		beg_nod = nullptr;
		end_nod = nullptr;
		len = 0;
	}

	void remove_first() noexcept
	{
		if (len == 1)
		{
			destroy();
		}
		else
		{
			Node* successor = get_node(1);
			successor->set_prev(nullptr);
			beg_nod = successor;
			len--;
		}
	}

	void remove_last() noexcept
	{
		if (len == 1)
		{
			destroy();
		}
		else
		{
			Node* successor = get_node(len - 2);
			successor->set_next(nullptr);
			end_nod = successor;
			len--;
		}
	}

	void remove(Iterator iter) noexcept
	{
		if (len == 0)
		{
			throw std::invalid_argument("List is empty");
		}
		else
		{
			Node* f_node = iter.get_node()->get_prev();
			Node* s_node = iter.get_node()->get_next();
			if (f_node != nullptr)
				f_node->set_next(s_node);
			else
				beg_nod = s_node;
			if (s_node != nullptr)
				s_node->set_prev(f_node);
			else
				end_nod = f_node;
			len--;
		}
	}

	Node* pop() noexcept
	{
		try
		{
			if (len > 0)
			{
				Node* result = end_nod;
				remove_last();
				return result;
			}
			else
			{
				throw std::invalid_argument("");
			}
		}
		catch (std::invalid_argument& e)
		{
			std::cerr << "Cannot pop from an empty list" << std::endl;
		}
	}

	class Iterator
	{
		friend 
			class TwoWayList<T>;
	private:
		Node* current;
		bool direction = true;  // if true then it moves from left to right
	public:
		Iterator(Node* node) noexcept
			:current(node)
		{
		}

		Iterator(Iterator const& iter) noexcept
			:current(iter.current)
		{
		}

		~Iterator() = default;

		void reverse() noexcept
		{
			if (direction == true)
				direction = false;
			else if (direction == false)
				direction = true;
		}

		Node* get_node() const noexcept
		{
			return current;
		}

		T operator*() const
		{
			return current->get_val();
		}

		Iterator operator++(int) //postincrement
		{
			Iterator copy(*this);
			++(*this);
			return copy;
		}

		Iterator& operator++() //preincrement
		{
			try
			{
				if (direction == true)
				{
					Node* next = current->get_next();
					if (current == nullptr)
						throw std::range_error("Iterator pointing at the end of the list");
					current = next;
				}
				else if (direction == false)
				{
					Node* next = current->get_prev();
					if (current == nullptr)
						throw std::range_error("Iterator pointing at the end of the list");
					current = next;
				}
			}
			catch (std::range_error& e)
			{
				std::cerr << std::endl << "Iterator pointing at the end of the list" << std::endl;
			}
			return *this;
		}

		Iterator operator--(int) //postdecrement
		{
			Iterator copy(*this);
			--(*this);
			return copy;
		}

		Iterator& operator--() //predecrement
		{
			try
			{
				if (direction == true)
				{
					Node* next = current->get_prev();
					if (current == nullptr)
						throw std::range_error("");
					current = next;
				}
				else if (direction == false)
				{
					Node* next = current->get_next();
					if (current == nullptr)
						throw std::range_error("Iterator pointing at the end of the list");
					current = next;
				}
			}
			catch (std::range_error& e)
			{
				std::cerr << std::endl << "Iterator pointing at the end of the list" << std::endl;
			}
			return *this;
		}

		void operator+=(int n)
		{
			for (int i = 0; i < n; i++)
			{
				(*this)++;
			}
		}

		void operator-=(int n)
		{
			for (int i = 0; i < n; i++)
			{
				(*this)--;
			}
		}

		bool operator==(Iterator iter) const noexcept
		{
			return (current == iter.current);
		}

		bool operator!=(Iterator iter) const noexcept
		{
			return !(current == iter.current);
		}
	};

	Iterator begin() const
	{
		Iterator iter(beg_nod);
		return iter;
	};

	Iterator end() const
	{
		Iterator iter(end_nod);
		return iter;
	}

};
