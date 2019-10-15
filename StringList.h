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

	void push_front(std::string str)
	{
		llist *newItem = new llist;
		newItem->str = str;
		newItem->next = _front;
		newItem->prev = 0;
		if(newItem->next != 0)
			newItem->next->prev = newItem;
		_front = newItem;
		_size++;
	}


	void push_back(std::string str)
	{
		llist *newItem = new llist;
		newItem->str = str;
		newItem->prev = _back;
		newItem->next = 0;
		if(newItem->prev != 0)
			newItem->prev->next = newItem;
		_back = newItem;
		_size++;
	}

	void pop_front()
	{
		llist *front = _front;
		_front = front->next;
		delete front;
		_size--;
	}

	bool empty() const
	{
		return (_front == _back) == 0;
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

	void pop_back()
	{
	}

	void reverse()
	{
	}

	void unique()
	{
	}
};
