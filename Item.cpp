#include "memoryleakdetect.h"		// needs to be first #include in the .cpp file
#include "Item.h"

Item::Item(const string& title, const string& artist)
{
	this->title		= title;
	
	this->artist	= artist;
	
	contrib			= new set<string>();

	keywrd			= new set<string>();
}

Item::Item()
{
	title = "";

	artist = "";

	contrib			= new set<string>();

	keywrd			= new set<string>();
}

Item::~Item()
{
	contrib->clear();
	delete contrib;
	keywrd->clear();
	delete keywrd;
}

string Item::getTitle() const
{
	return this->title;
}

string Item::getArtist() const
{
	return this->artist;
}

set<string>* Item::getContrib() const
{
	return this->contrib;
}

set<string>* Item::getKeywrd() const
{
	return this->keywrd;
}

void Item::addContrib(int n_args, ...)
{
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
	va_list arrrg;
    va_start(arrrg, n_args);
    for(int i = 0; i < n_args; i++) {
		string cur = va_arg(arrrg, string);
		keywrd->insert(cur);
    }
    va_end(arrrg);
}

ostream& Item::print(ostream& out) const
{
	out << this;
	return out;
}

bool operator<(const Item& i1, const Item& i2)
{
	string	t1 = i1.getTitle();
	string	t2 = i2.getTitle();
	string	a1 = i1.getArtist();
	string	a2 = i2.getArtist();
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

// Make this virtual so that correct << operator gets called?
ostream& operator<<(ostream& out, const Item* const item)
{
	item->print(out);
	//if(typeid(*item).name() == "Book")
	//{
	//	//turn it into a book and do
	//	//out << book;
	//	//return out;
	//}


	// Format keywords, from getKeywrd() return type (set<string>)
	//string	kwrd;
	//bool	first = true;
	//for(string s: *item->getKeywrd())
	//{
	//	kwrd.append(first ? "" : ", ");
	//	kwrd.append(s);
	//	if (first) first=false;
	//}
	//out
	//<< "-Item-\n"
	//<< "artist:   " << item->getArtist() << "\n"
	//<< "title:    " << item->getTitle() << "\n"
	//<< "keywords: " << kwrd 
	//<< endl;
	
	return out;
}

