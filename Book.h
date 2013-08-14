#pragma once

#include "item.h"

class Book :
	public Item
{
private:
	int			pages;
public:
	int getPages() const;
	ostream& print(ostream& out) const;

	Book(void);
	Book(const string& title, const string& author, const int nPages);
	~Book(void);
};

ostream& operator<<(ostream& out, const Book* const book);


