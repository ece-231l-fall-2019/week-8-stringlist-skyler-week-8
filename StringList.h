/* Commented the lines that valgrind doesn't like, using the command "valgrind -v --leak-check=full ./runtests"
   Each line corresponds to a pointer creation, so fixing those is a top priority. */

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
		delete _front;
		delete _back;
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
		this->_size = other._size;
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

	//Used for address debugging
	/*
	void printData(bool addr = 0)
	{
		std::cout << "Object at Address " << this << ":\n";
		llist *ptr = new llist;
		for(ptr = _front; ptr != 0; ptr = ptr->next)
		{
			if(!addr)
			{
				if(ptr->str != "")
					std::cout << ptr->str << std::endl;
				else
					std::cout << "-" << std::endl;
			}
			else
			{
				if(ptr->str != "")
					std::cout << "At address " << ptr << ": " << ptr->str << std::endl;
				else
					std::cout << "-" << std::endl;
			}
		}
		std::cout << std::endl;
		delete ptr;
	}
	*/

	void push_front(std::string str)
	{
		llist *newItem = new llist; // Valgrind doesn't like this line
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
		llist *newItem = new llist; //Valgrind doesn't like this line
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

	size_t size()
	{
		return _size;
	}

	void clear()
	{
		while (!empty())
		{
			pop_front();
		}
		_size = 0;
	}

	void pop_front()
	{
//		llist* ptr = _front;
		_front = _front->next;
		if(_front)
		{
			if(_front->prev)
				_front->prev = _front->prev->prev;
		}
		else
			_back = 0;
//		delete ptr;
		_size--;
	}
	void pop_back()
	{
//		llist* ptr = _back;
		_back = _back->prev;
		if(_back)
		{
			if(_back->next)
				_back->next = _back->next->next;
		}
		else
			_front = 0;
//		delete ptr;
		_size--;
	}

	void reverse()
	{
		llist *ptr = new llist; //Valgrind doesn't like this line
		llist *tmp = new llist; //Or this line
		for(ptr = _front; ptr != 0; ptr = ptr->next)
		{
			tmp = ptr->next;
			ptr->next = ptr->prev;
			ptr->prev = tmp;
		}
		tmp = _back;
		_back = _front;
		_front = tmp;
		tmp = NULL;
//		delete tmp;
//		delete ptr;
	}

	void unique()
	{
		for(llist* ptr = _front; ptr != 0; ptr=ptr->next)
		{
			while((ptr->next != 0)&&(ptr->str==ptr->next->str))
			{
				_size--;
				llist* saveptr = ptr->next;
				ptr->next = saveptr->next;
				if(saveptr->next != 0)
					saveptr->next->prev = ptr;
				else
					_back = ptr;
				delete saveptr;
			}
		}
	}
};
