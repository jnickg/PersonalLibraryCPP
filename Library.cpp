#include "memoryleakdetect.h"		// needs to be first #include in the .cpp file
#include <cstdarg>					// support macros for vararg
#include <iostream>
#include "Library.h"

// general functions

void Library::addKeywordsForItem(const Item* const item, int nKeywords, ...)
{
	// the code in this function demonstrates how to handle a vararg in C++
	va_list		keywords;
	char		*keyword;
	string		kw;

	// Necessary to pass the const Item* const item
	// as an argument in addToMap, in the below for loop
	// Item* thisItem = (Item*)const_cast<Item *>(item);

	va_start(keywords, nKeywords);
	for (int i = 0; i < nKeywords; i++)
	{
		keyword = va_arg(keywords, char*);
		kw = keyword;
		item->getKeywrd()->insert(kw);

		// passing through thisItem doesn't work; causes unhandled exception.
		// addToMap(keywordM, *thisItem, 1, keyword);
		
		// Works on this side but doesn't allow "item" to be inserted into
		// ItemSet (inside addToMapc).
		addToMapc(keywordM, item, 1, keyword);
	}
	va_end(keywords);
}

const ItemSet* Library::itemsForKeyword(const string& keyword) const
{
	if(keywordM.find(keyword) != keywordM.end())
	{
		return keywordM[keyword];
	}
	else return NULL;
}

void Library::addToMapc(STIMap &map, const Item* const val, int n_args, ...)
{
	//cur is current argument being used in the looop
	//val is the item to be inserted into the map
	//map is the map to be modified
	va_list arrrg;
    va_start(arrrg, n_args);
    for(int i = 0; i < n_args; i++) {
		string cur = va_arg(arrrg, string);
		if (map.find(cur) != map.end())
		{
			ItemSet *vis = map[cur];
			vis->insert(*val);
			map[cur] = vis;
		}
		else
		{
			ItemSet *vis = new ItemSet;
			vis->insert(&val);
			map[cur] = vis;
		}
    }
    va_end(arrrg);
}

void Library::addToMap(STIMap &map, Item &val, int n_args, ...)
{
	//cur is current argument being used in the looop
	//val is the item to be inserted into the map
	//map is the map to be modified
	va_list arrrg;
    va_start(arrrg, n_args);
    for(int i = 0; i < n_args; i++) {
		string cur = va_arg(arrrg, string);
		if (map.find(cur) != map.end())
		{
			ItemSet *vis = map[cur];
			vis->insert(&val);
			map[cur] = vis;
		}
		else
		{
			ItemSet *vis = new ItemSet;
			vis->insert(&val);
			map[cur] = vis;
		}
    }
    va_end(arrrg);
}

// book-related functions

const Item* Library::addBook(const string& title, const string& author, const int nPages)
{
	Item	*book = new Book(title, author, nPages);
	bookS.insert(book);
	addToMap(boArtist, *book, 1, author);
	return book;
}

const ItemSet* Library::booksByAuthor(const string& author) const
{
	return boArtist[author];
}

const ItemSet* Library::books() const
{
	// TODO: is there a problem witht he way this returns?
	// (const ItemSet* == &bookS) ? no : yes
	return &bookS;
}

// music-related functions

const Item* Library::addMusicAlbum(const string& title, const string& band, const int nSongs)
{
	// your code here
	return NULL;
}

void Library::addBandMembers(const Item* const musicAlbum, const int nBandMembers, ...)
{
	// your code here
}

const ItemSet* Library::musicByBand(const string& band) const
{
	// your code here
	return NULL;
}

const ItemSet* Library::musicByMusician(const string& musician) const
{
	// your code here
	return NULL;
}

const ItemSet* Library::musicAlbums() const
{
	// your code here
	return NULL;
}

// movie-related functions

const Item* Library::addMovie(const string& title, const string& director, const int nScenes)
{
	// your code here
	return NULL;
}

void Library::addCastMembers(const Item* const movie, const int nCastMembers, ...)
{
	// your code here
}

const ItemSet* Library::moviesByDirector(const string& director) const
{
	// your code here
	return NULL;
}

const ItemSet* Library::moviesByActor(const string& actor) const
{
	// your code here
	return NULL;
}

const ItemSet* Library::movies() const
{
	// your code here
	return NULL;
}

static void deleteMapContents(STIMap& s2ism)
{
	// your code here
}

static void deleteItemSetContents(ItemSet& itemSet)
{
	// your code here
}

Library::~Library()
{
	// your code here
}

