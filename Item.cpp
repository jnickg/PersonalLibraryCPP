#include "memoryleakdetect.h"		// needs to be first #include in the .cpp file
#include "Item.h"

Item::Item(const string& title, const string& artist)
{
	this->title		= title;
	
	this->artist	= artist;
	
	contrib			= new set<string>();
	contrib->insert("nobody");

	keywrd			= new set<string>();
	keywrd->insert("none");
}

Item::Item()
{
	title = "";

	artist = "";

	contrib			= new set<string>();
	contrib->insert("nobody");

	keywrd			= new set<string>();
	keywrd->insert("none");
}

Item::~Item()
{
	delete contrib;
	delete keywrd;
}

string& Item::getTitle()
{
	return this->title;
}

string& Item::getArtist()
{
	return this->artist;
}

set<string>* Item::getContrib()
{
	return this->contrib;
}

set<string>* Item::getKeywrd()
{
	return this->keywrd;
}

bool operator<(const Item& i1, const Item& i2)
{
	// TODO: ask Boff about how to access private members
	string	t1 = i1.title;
	string	t2 = i2.title;
	string	a1 = i1.artist;
	string	a2 = i2.artist;
	bool	rtn;
	int		cmp = t1.compare(t2);

	if (cmp == 0)
	{
		cmp = a1.compare(a2);
		if ((cmp == 0) || (cmp > 0))
		{
			rtn = false;
		}
		else
		{
			rtn = true;
		}
	}
	else if (cmp > 0)
	{
		rtn = false;
	}
	else
	{
		rtn = true;
	}

	return rtn;
}

bool operator<(const ItemPtr& ip1, const ItemPtr& ip2)
{
	if(*ip1.getPtr() < *ip2.getPtr()) return true;
	else return false;
}

ostream& operator<<(ostream& out, const Item* const item)
{
	// your code here
	return out;
}
