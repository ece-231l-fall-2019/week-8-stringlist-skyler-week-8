#include <iostream>
#include <string>

class StringList
{
	private:
	size_t _size;
	typedef struct llist {
		std::string str;
		struct llist *next;
	} llist;

	llist *_data;

	public:

	// default constructor
	StringList()
	{
		_data = 0;
		_size = 0;
	}

	// copy constructor
	StringList(const StringList&);

	// destructor
	~StringList()
	{
		while(!empty())
			pop_front();
	}

	// copy operator
	StringList& operator=(const StringList&);

	std::string& front()
	{
		return _data->str;
	}

	std::string& back()
	{
		while(true)
		{
			if (_data->next == NULL)
				return _data->str;
			else
				_data->next++;
		}
	}

	void push_front(std::string str)
	{
		llist *newItem = new llist;
		newItem->str = str;
		newItem->next = _data;
		_data = newItem;
	}

	void pop_front()
	{
		llist *front = _data;
		_data = front->next;
		delete front;
	}

	bool empty() const
	{
		return _data == 0;
	}

	int size()
	{
		return _size;
	}

	void clear()
	{
		while (!empty())
			pop_front();
	}

	void push_back()
	{
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

