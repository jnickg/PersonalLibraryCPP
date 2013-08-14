#pragma once

#include "item.h"

class MusicAlbum :
	public Item
{
private:
	int		songs;
public:
	int getSongs() const;
	ostream& print(ostream& out) const;

	MusicAlbum(void);
	MusicAlbum(const string& title, const string& band, const int nSongs);
	~MusicAlbum(void);
};

ostream& operator<<(ostream& out, const MusicAlbum* const album);
