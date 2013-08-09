#pragma once

#include "item.h"

class Book :
	public Item
{
public:
	int			pages;

	Book(void);
	Book(const string& title, const string& author, const int nPages);
	~Book(void);
};

ostream& operator<<(ostream& out, const Book* const book);


