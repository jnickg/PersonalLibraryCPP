#include "memoryleakdetect.h"		// needs to be first #include in the .cpp file
#include "Item.h"

Item::Item(const string& title, const string& artist)
{
	this->title		= title;
	
	this->artist	= artist;
	
	contrib			= new set<string>();
//	contrib->insert("nobody");

	keywrd			= new set<string>();
//	keywrd->insert("none");
}

Item::Item()
{
	title = "";

	artist = "";

	contrib			= new set<string>();
//	contrib->insert("nobody");

	keywrd			= new set<string>();
//	keywrd->insert("none");
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

void Item::addContrib(int n_args, ...)
{
	// TODO: Check if this works
	va_list arrrg;
    va_start(arrrg, n_args);
    for(int i = 0; i < n_args; i++) {
		string cur = va_arg(arrrg, string);
		contrib->insert(cur);
    }
    va_end(arrrg);
}

void Item::addKeywrd(int n_args, ...)
{
	// TODO: Check if this works
	va_list arrrg;
    va_start(arrrg, n_args);
    for(int i = 0; i < n_args; i++) {
		string cur = va_arg(arrrg, string);
		keywrd->insert(cur);
    }
    va_end(arrrg);
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
	string	kwrd;
	// Is this for each loop correct?
	bool	first = true;
	for(string s: *item->keywrd)
	{
		kwrd.append(first ? "" : ", ");
		kwrd.append(s);
		if (first) first=false;
	}
	out
	<< "-Item-\n"
	<< "artist:   " << item->artist << "\n"
	<< "title:    " << item->title << "\n"
	<< "keywords: " << kwrd 
	<< endl;
	// your code here
	// toString, basically
	return out;
}
