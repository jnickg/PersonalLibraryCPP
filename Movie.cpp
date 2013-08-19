#include "memoryleakdetect.h"		// needs to be first #include in the .cpp file
#include "Movie.h"

Movie::Movie(void) :
	Item(),
	scenes(0)
{

}

Movie::Movie(const string& title, const string& author, const int nScenes) :
	Item(title, author),
	scenes(nScenes)
{

}

Movie::~Movie(void)
{

}

int Movie::getScenes() const {
	return scenes;
}

ostream& Movie::print(ostream& out) const
{
	out << this;
	return out;
}

ostream& operator<<(ostream& out, const Movie* const movie)
{
	string	kwrd;
	bool	first = true;
	for(string s: *movie->getKeywrd())
	{
		kwrd.append(first ? "" : ", ");
		kwrd.append(s);
		if (first) first=false;
	}

	string	cntrb;
	first = true;
	for(string s: *movie->getContrib())
	{
		cntrb.append(first ? "" : ", ");
		cntrb.append(s);
		if (first) first=false;
	}

	out
		<< "-Movie-\n"
		<< "director: " << movie->getArtist() << "\n"
		<< "# scenes: " << movie->getScenes() << "\n"
		<< "cast:     " << cntrb << "\n"
		<< "title:    " << movie->getTitle() << "\n"
		<< "keywords: " << kwrd 
		<< endl;
	return out;
}
