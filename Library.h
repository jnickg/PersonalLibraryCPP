// do not remove any of the function prototypes from this class definition

#pragma once

#include <map>
#include <set>
#include <string>
#include "Item.h"
#include "Book.h"
#include "MusicAlbum.h"
#include "Movie.h"

using namespace std;

// C++ Standard Library definitions for containers you may need
typedef set<string>				StringSet;	// Great!
typedef set<ItemPtr>			ItemSet;	// see comment in Item.h about use of ItemPtr
typedef map<string,ItemSet*>	STIMap;	// Map of sexually-transmitted infections

class Library
{
private:
	mutable ItemSet		bookS, albumS, movieS;
	mutable STIMap		keywordM, // Keyword map for whole library
						boArtist, // Artist map for books
						muArtist, muContrib, // Artist, Contributor maps for music albums
						moArtist, moContrib; // Artist, Contributor maps for movies
public:
	// general functions
	void addKeywordsForItem(const Item* const item, int nKeywords, ...);
	const ItemSet* itemsForKeyword(const string& keyword) const;
	void addToMap(STIMap &map, Item &val, int n_args, ...);
	// No longer needed, since addKeywordsForItem now does const_cast of item
	//void addToMapc(STIMap &map, const Item* const val, int n_args, ...);
	friend static void deleteItemSetContents(ItemSet& itemSet);
	friend static void deleteItemSetContentsALT(ItemSet& itemSet);
	friend static void deleteMapContents(STIMap& s2ism);

	// book-related functions
	const Item* addBook(const string& title, const string& author, const int nPages);
	const ItemSet* booksByAuthor(const string& author) const;
	const ItemSet* books() const;			// returns set containing all the books

	// music-related functions
	const Item* addMusicAlbum(const string& title, const string& band, const int nSongs);
	void addBandMembers(const Item* const musicAlbum, const int nBandMembers, ...);
	const ItemSet* musicByBand(const string& band) const;
	const ItemSet* musicByMusician(const string& musician) const;
	const ItemSet* musicAlbums() const;		// returns set containing all the music

	// movie-related functions
	const Item* addMovie(const string& title, const string& director, const int nScenes);
	void addCastMembers(const Item* const movie, const int nCastMembers, ...);
	const ItemSet* moviesByDirector(const string& director) const;
	const ItemSet* moviesByActor(const string& actor) const;
	const ItemSet* movies() const;			// returns set containing all the movies

	virtual ~Library();
};



