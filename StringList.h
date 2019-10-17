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
		clear();
		llist* ptr = other._front;
		while(ptr != 0)
		{
			push_back(ptr->str);
			ptr = ptr->next;
		}
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
		//TODO: Rewrite this for push_front
		llist *newItem = new llist;
		newItem->str = str;
		newItem->prev = 0;
		newItem->next = _front;
		if(_front != 0)
			_front->prev = newItem;
		if(_back == 0)
			_back = newItem;
		_front = newItem;
		_size++;
	}

	void push_back(std::string str)
	{
		llist *newItem = new llist;
		newItem->str = str;
		newItem->next = 0;
		newItem->prev = _back;
		if(_back != 0)
			_back->next = newItem;
		if(_front == 0)
			_front = newItem;
		_back = newItem;
		_size++;
	}

	bool empty() const
	{
		return (_front == 0)&&(_back == 0);
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
		}
	}

	void pop_front()
	{
		llist* saveptr = _front;
		_front = _front->next;
		if(_front)
		{
			_front->prev = _front->prev->prev;
		}
		else
			_back = 0;
		delete saveptr;
		_size--;
	}
	void pop_back()
	{
		llist* saveptr = _back;
		_back = _back->prev;
		if(_back)
			_back->next = _back->next->next;
		else
			_front = 0;
		delete saveptr;
		_size--;
	}

	void reverse()
	{
		llist *ptr = new llist;
		llist *tmp = new llist;
		for(ptr = _front; ptr != 0; ptr = ptr->next)
		{
			tmp = ptr->next;
			ptr->next = ptr->prev;
			ptr->prev = tmp;
		}
		tmp = _back;
		_back = _front;
		_front = tmp;
		// delete tmp;
		// delete ptr;
	}

	void unique()
	{
		for(llist* ptr = _front; ptr != 0; ptr=ptr->next)
		{
			while((ptr->next != 0)&&(ptr->str==ptr->next->str))
			{
				llist* saveptr = ptr->next;
				ptr->next = saveptr->next;
				if(saveptr->next != 0)
					saveptr->next->prev = ptr;
				else
					_back = ptr;
				delete saveptr;
				_size--;
			}
		}
	}
};
