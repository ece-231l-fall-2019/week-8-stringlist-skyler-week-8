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
		std::cout << "Constructor\n";
		_front = 0;
		_back = 0;
		_size = 0;
	}

	// copy constructor
	StringList(const StringList&);

	// destructor
	~StringList()
	{
		clear();
	}

	// copy operator
	StringList& operator=(const StringList&);

	std::string& front()
	{
		std::cout << "front()\n";
		return _front->str;
	}

	std::string& back()
	{
		std::cout << "back()\n";
		return _back->str;
	}

	void push_front(std::string str)
	{
		std::cout << "push_front()\n";
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
		std::cout << "push_back()\n";
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
		std::cout << "pop_front()\n";
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

