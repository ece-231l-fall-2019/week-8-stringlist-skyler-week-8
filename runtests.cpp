#include <iostream>
#include "dbg.h"

// change the value below to 1 to run tests against your StringList class.
// change the value below to 0 to run tests against the built in std::list.

#if 1
#include "StringList.h"
#else
#include <list>
#include <string>
typedef std::list<std::string> StringList;
#endif

void Assert(bool cond, std::string message)
{
	if (cond)
		std::cout << "Pass: " << message << std::endl;
	else
		std::cerr << "FAIL: " << message << std::endl;
}

int main()
{
	// TODO:
	// Write *at least* 15 more tests to fully test
	// your class.

	StringList a;

	a.push_back("A");
	a.push_back("B");
	a.push_front("C");
	a.push_front("D");
	a.push_back("E");
	Assert(a.size() == 5, "size method");
	Assert(a.front() == "D", "front method");
	a.pop_front();
	Assert(a.front() == "C", "pop_front method");
	Assert(a.back() == "E", "back method");
	a.pop_back();
	Assert(a.back() == "B", "pop_back method");
	a.pop_front();
	Assert(a.front() == "A", "front method");
	a.pop_back();
	Assert(a.back() == "A", "back method");

	StringList b;
	b.push_back("R");
	b.push_front("P");
	a.clear();
	Assert(a.empty(), "empty method");
	a.push_back("K");
	Assert(a.front() == "K", "One item front method");
	Assert(a.back() == "K", "One item back method");
	a = b;
	Assert(a.back() == "R", "= method, test back val");
	Assert(a.front() == "P", "= method test front val");

	b.push_front("P");
	b.push_back("R");
	b.unique();

	Assert(b.size() == 2 && b.back() == "R" && b.front() == "P", \
			"unique method.()");
	b.reverse();
	Assert(b.back() == "P" && b.front() == "R", "reverse method");
	a.reverse();
	Assert(a.front() == b.front() && a.back() == b.back(), \
			"reverse method test 2");
	a.clear();
	Assert(a.size() == 0,"clear test 2");
	b.pop_back();
	b.pop_front();
	Assert(a.size() == b.size(), "clear using pop methods");

	a.push_front("Y");
	a.push_front("L");
	StringList c = a;

	Assert(c.front() == a.front(), "= operator method");

	Assert(c.front() == "L" && c.back() == "Y", "push_front method");
	a.push_back("M");
	Assert(a.back() == "M", "push back");
	c.clear();
	Assert(c.empty(), "clear and empty methods");
	a.clear();
	Assert(c.size() == a.size(), "clear and size methods");
	return 0;
}
