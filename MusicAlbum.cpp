#include "memoryleakdetect.h"		// needs to be first #include in the .cpp file
#include "MusicAlbum.h"

MusicAlbum::MusicAlbum(void) :
	Item(),
	songs(0)
{

}

MusicAlbum::MusicAlbum(const string& title, const string& author, const int nSongs) :
	Item(title, author),
	songs(nSongs)
{

}

MusicAlbum::~MusicAlbum(void)
{

}

int MusicAlbum::getSongs() const {
	return songs;
}

ostream& MusicAlbum::print(ostream& out) const
{
	out << this;
	return out;
}

ostream& operator<<(ostream& out, const MusicAlbum* const album)
{
	string	kwrd;
	bool	first = true;
	for(string s: *album->getKeywrd())
	{
		kwrd.append(first ? "" : ", ");
		kwrd.append(s);
		if (first) first=false;
	}

	string	cntrb;
	first = true;
	for(string s: *album->getContrib())
	{
		cntrb.append(first ? "" : ", ");
		cntrb.append(s);
		if (first) first=false;
	}

	out
		<< "-Music Album-\n"
		<< "band:     " << album->getArtist() << "\n"
		<< "# songs:  " << album->getSongs() << "\n"
		<< "members:  " << cntrb << "\n"
		<< "title:    " << album->getTitle() << "\n"
		<< "keywords: " << kwrd 
		<< endl;
	return out;
}
