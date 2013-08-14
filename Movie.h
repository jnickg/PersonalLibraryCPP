#pragma once

#include "item.h"

class Movie :
	public Item
{
private:
	int		scenes;
public:
	int getScenes() const;
	ostream& print(ostream& out) const;

	Movie(void);
	Movie(const string& title, const string& director, const int nScenes);
	~Movie(void);
};

ostream& operator<<(ostream& out, const Movie* const movie);