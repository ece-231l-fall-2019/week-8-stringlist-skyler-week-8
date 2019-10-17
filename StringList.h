#include <iostream>
#include <string>

class StringList {
	private:
	size_t _size;
	typedef struct llist {
		std::string str;
		struct llist *next;
		struct llist *prev;
	} llist;

	llist *_back;
	llist *_front;
	llist *ptr2;
	public:

	// default constructor
	StringList()
	{
		_front = 0;
		_back = 0;
		_size = 0;
	}

	// copy constructor
	StringList(const StringList& other)
	{
		_front = other._front;
		_back = other._back;
		_size = other._size;
	}
	// destructor
	~StringList()
	{
		clear();
	}

	// copy operator
	StringList& operator=(const StringList& other)
	{
		this->_front = other._front;
		this->_back = other._back;
		_size = other._size;
		return *this;
	}

	std::string& front()
	{
		return _front->str;
	}

	std::string& back()
	{
		return _back->str;
	}

	void printData(bool addr = 0)
	{
		std::cout << std::endl << "Object at Address " << this << ":\n";
		llist *ptr = new llist;
		for(ptr = _front; ptr != 0; ptr = ptr->next)
		{
			if(!addr)
				std::cout << ptr->str << std::endl;
			else
				std::cout << "At address " << ptr << ": " << ptr->str << std::endl;
		}
		std::cout << std::endl;
		delete ptr;
	}

	void push_front(std::string str)
	{
		llist *newItem = new llist;
		newItem->str = str;
		newItem->next = _front;
		if(newItem->next == 0)
		{
			_back = newItem;
			newItem->prev = 0;
		}
		else
			newItem->next->prev = newItem;
		_front = newItem;
		_size++;
	}

	void push_back(std::string str)
	{
		llist *newItem = new llist;
		newItem->str = str;
		newItem->prev = _back;
		if(newItem->prev == 0)
		{
			_front = newItem;
			newItem->next = 0;
		}
		else
			newItem->prev->next = newItem;
		_back = newItem;
		_size++;
	}

	bool empty() const
	{
		return (_front == _back);
	}

	int size()
	{
		return _size;
	}

	void clear()
	{
		while (!empty())
		{
			pop_front();
			_size--;
		}
	}

	void pop_front()
	{
		// ptr2 = _front;
		// _front = ptr2->next;
		if(_front->next != 0)
		{
			_front = _front->next;
			_front->prev = NULL;
		}
		else
		{
			_front = 0;
		}
		_size--;
	}
	void pop_back()
	{
		// ptr2 = _back;
		// _back = ptr2->prev;
		if(_back->prev != 0)
		{
			_back = _back->prev;
			_back->next = NULL;
		}
		else
		{
			_back = 0;
		}
		_size--;
	}

	void reverse()
	{
		llist *ptr = new llist;
		llist *tmp = new llist;
		for(ptr = _front; ptr->next != 0; ptr = ptr->next)
		{
			tmp = ptr->next;
			ptr->next = ptr->prev;
			ptr->prev = tmp;
		}
		tmp = _back;
		_back = _front;
		_front = tmp;
		delete tmp;
		delete ptr;
	}

	void unique()
	{
		llist *ptr = new llist;
		clear();
		for(ptr = _front; ptr->next != NULL; ptr = ptr->next)
		{
			if (ptr->str != ptr->next->str)
			{
				push_front(ptr->str);
			}
		}

	}
};
