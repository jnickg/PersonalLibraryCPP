#include "memoryleakdetect.h"		// needs to be first #include in the .cpp file
#include "Book.h"

Book::Book(void) :
	Item(),
	pages(0)
{

}

Book::Book(const string& title, const string& author, const int nPages) :
	Item(title, author),
	pages(nPages)
{

}

Book::~Book(void)
{

}

ostream& operator<<(ostream& out, const Book* const book)
{
	string	kwrd;
	bool	first = true;
	for(string s: *book->keywrd)
	{
		kwrd.append(first ? "" : ", ");
		kwrd.append(s);
	}
	out
		<< "-Book-\n"
		<< "author:   " << book->artist << "\n"
		<< "# pages:  " << book->pages << "\n"
		<< "title:    " << book->title << "\n"
		<< "keywords: " << kwrd 
		<< endl;
	return out;
}
