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
	Item* thisItem = (Item*)const_cast<Item *>(item);

	va_start(keywords, nKeywords);
	for (int i = 0; i < nKeywords; i++)
	{
		keyword = va_arg(keywords, char*);
		// Necessary to use addToMap, which takes strings
		kw = keyword;
		item->getKeywrd()->insert(kw);

		addToMap(keywordM, *thisItem, 1, kw);
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

// No longer needed, since addKeywordsForItem now does const_cast of item
//void Library::addToMapc(STIMap &map, const Item* const val, int n_args, ...)
//{
//	//cur is current argument being used in the looop
//	//val is the item to be inserted into the map
//	Item* thisItem = const_cast<Item*>(val);
//	//map is the map to be modified
//	va_list arrrg;
//    va_start(arrrg, n_args);
//    for(int i = 0; i < n_args; i++) {
//		string cur = va_arg(arrrg, string);
//		if (map.find(cur) != map.end())
//		{
//			ItemSet *vis = map[cur];
//			vis->insert(thisItem);
//			map[cur] = vis;
//		}
//		else
//		{
//			ItemSet *vis = new ItemSet;
//			vis->insert(thisItem);
//			map[cur] = vis;
//		}
//    }
//    va_end(arrrg);
//}

void Library::addToMap(STIMap &map, Item &val, int n_args, ...)
{
	//cur is current argumen5t being used in the looop
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
	Item *book = new Book(title, author, nPages);
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
	Item *album = new MusicAlbum(title, band, nSongs);
	albumS.insert(album);
	addToMap(muArtist, *album, 1, band);
	return album;
}

void Library::addBandMembers(const Item* const musicAlbum, const int nBandMembers, ...)
{
	// the code in this function demonstrates how to handle a vararg in C++
	va_list		bmemb;
	char		*keyword;
	string		kw;

	// Necessary to pass the const Item* const item
	// as an argument in addToMap, in the below for loop
	Item* thisItem = (Item*)const_cast<Item *>(musicAlbum);

	va_start(bmemb, nBandMembers);
	for (int i = 0; i < nBandMembers; i++)
	{
		keyword = va_arg(bmemb, char*);
		// Necessary to use addToMap, which takes strings
		kw = keyword;
		musicAlbum->getContrib()->insert(kw);

		addToMap(muContrib, *thisItem, 1, kw);
	}
	va_end(bmemb);
}

const ItemSet* Library::musicByBand(const string& band) const
{
	return muArtist[band];
}

const ItemSet* Library::musicByMusician(const string& musician) const
{
	if(muContrib.find(musician) != muContrib.end())
	{
		return muContrib[musician];
	}
	else return NULL;
}

const ItemSet* Library::musicAlbums() const
{
	return &albumS;
}

// movie-related functions

const Item* Library::addMovie(const string& title, const string& director, const int nScenes)
{
	Item *movie = new Movie(title, director, nScenes);
	movieS.insert(movie);
	addToMap(moArtist, *movie, 1, director);
	return movie;
}

void Library::addCastMembers(const Item* const movie, const int nCastMembers, ...)
{
	// the code in this function demonstrates how to handle a vararg in C++
	va_list		cstmemb;
	char		*keyword;
	string		kw;

	// Necessary to pass the const Item* const item
	// as an argument in addToMap, in the below for loop
	Item* thisItem = (Item*)const_cast<Item *>(movie);

	va_start(cstmemb, nCastMembers);
	for (int i = 0; i < nCastMembers; i++)
	{
		keyword = va_arg(cstmemb, char*);
		// Necessary to use addToMap, which takes strings
		kw = keyword;
		movie->getContrib()->insert(kw);

		addToMap(moContrib, *thisItem, 1, kw);
	}
	va_end(cstmemb);
}

const ItemSet* Library::moviesByDirector(const string& director) const
{
	return moArtist[director];
}

const ItemSet* Library::moviesByActor(const string& actor) const
{
	if(moContrib.find(actor) != moContrib.end())
	{
		return moContrib[actor];
	}
	else return NULL;
}

const ItemSet* Library::movies() const
{
	return &movieS;
}

static void deleteItemSetContents(ItemSet& itemSet)
{
	auto i = itemSet.rbegin();
	while (i != itemSet.rend())
	{
		Item *temp = i->getPtr();
		//itemSet.erase(i++);
		delete temp;
		i++;
	}
	//for (auto i = itemSet.begin(), e = itemSet.end(); i != e; )
	//{
	//	Item *temp = i->getPtr();
	//	itemSet.erase(i++);
	//	delete temp;
	//}
	itemSet.clear();
}

static void deleteItemSetContentsALT(ItemSet& itemSet)
{
	auto i = itemSet.begin();
	while (i != itemSet.end())
	{
		Item *temp = i->getPtr();
		delete temp;
		i++;
	}
	itemSet.clear();
}

static void deleteMapContents(STIMap& s2ism)
{
	auto i = s2ism.rbegin();
	while (i != s2ism.rend())
	{
		ItemSet *is = i->second;
		delete is;
		i++;
	}
	s2ism.clear();
}

Library::~Library()
{
	deleteItemSetContents(bookS);
	deleteItemSetContents(albumS);
	deleteItemSetContents(movieS);
	deleteMapContents(keywordM);
	deleteMapContents(boArtist);
	deleteMapContents(muArtist);
	deleteMapContents(moArtist);
	deleteMapContents(moContrib);
	deleteMapContents(muContrib);
}

