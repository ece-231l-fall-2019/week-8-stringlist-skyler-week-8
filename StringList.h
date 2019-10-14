#include <iostream>
#include <string>

class StringList
{
	private:

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
		std::string val = str + size()
		return _data+val;
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
		int size = 0;
		while(_data->next != NULL)
		{
			_data->next++;
			size++;
		}
		return size;
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

