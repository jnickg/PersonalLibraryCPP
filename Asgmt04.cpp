#include "memoryleakdetect.h"		// needs to be first #include in the .cpp file

// make no changes to this code, except to have it
// print out your actual name instead of "I. Forgot"

#include <iostream>
#include "Library.h"

using namespace std;

static Library	*library;

static void printItemSet(ostream& out, const ItemSet *itemSet)
{
    if (itemSet != NULL && itemSet->size() > 0)
		for (ItemSet::const_iterator i = itemSet->begin(); i != itemSet->end(); i++)
			out << i->getPtr() << endl;
	else
		out << "none" << endl << endl;
}

int main(int argc, char **argv)
{
    ostream&	out(cout);		// output stream we'll be using
    const Item	*item;

    out << "CS261 - Assignment 4 - Nick Giampietro" << endl << endl;

	// create library instance
	library = new Library();

    // add items to library
    out << ">>>>>> adding items to library:" << endl << endl;
    item = library->addBook("The Curious Incident of the Dog in the Night-Time", "Mark Haddon", 240);
    if (item != NULL) {
        library->addKeywordsForItem(item, 2, "autism", "Asperger's Syndrome");
		out << item << endl;
        }
    item = library->addBook("Starship Troopers", "Robert A. Heinlein", 325);
    if (item != NULL) {
        library->addKeywordsForItem(item, 3, "science fiction", "war", "weapons");
		out << item << endl;
        }
    item = library->addBook("The Moon Is A Harsh Mistress", "Robert A. Heinlein", 389);
    if (item != NULL) {
        library->addKeywordsForItem(item, 3, "science fiction", "moon", "social structures");
		out << item << endl;
        }
    item = library->addBook("Fear and Loathing in Las Vegas", "Hunter S. Thompson", 224);
    if (item != NULL) {
        library->addKeywordsForItem(item, 3, "sixties", "gonzo", "drugs");
		out << item << endl;
        }

	// DELETE
	 printItemSet(out, library->booksByAuthor("Robert A. Heinlein"));
	// DELETE

    item = library->addMusicAlbum("Europe In '72", "Grateful Dead", 12);
    if (item != NULL) {
        library->addKeywordsForItem(item, 4, "acid rock", "sixties", "jam bands", "cosmic");
        library->addBandMembers(item, 7, "Jerry Garcia", "Bill Kreutzman", "Keith Godcheaux",
										 "Donna Godcheaux", "Phil Lesh", "Bob Weir", "Mickey Hart");
		out << item << endl;
        }
    item = library->addMusicAlbum("Steal Your Face", "Grateful Dead", 12);
    if (item != NULL) {
        library->addKeywordsForItem(item, 4, "acid rock", "sixties", "jam bands", "cosmic");
        library->addBandMembers(item, 7, "Jerry Garcia", "Bill Kreutzman", "Keith Godcheaux",
										 "Donna Godcheaux", "Phil Lesh", "Bob Weir", "Mickey Hart");
		out << item << endl;
        }
    item = library->addMusicAlbum("From the Mars Hotel", "Grateful Dead", 12);
    if (item != NULL) {
        library->addKeywordsForItem(item, 4, "acid rock", "sixties", "jam bands", "cosmic");
        library->addBandMembers(item, 7, "Jerry Garcia", "Bill Kreutzman", "Keith Godcheaux",
										 "Donna Godcheaux", "Phil Lesh", "Bob Weir", "Mickey Hart");
		out << item << endl;
        } 
	item = library->addMusicAlbum("Don't Let Go", "Jerry Garcia Band", 15);
    if (item != NULL) {
        library->addKeywordsForItem(item, 2, "acid rock", "jam bands");
        library->addBandMembers(item, 4, "Jerry Garcia", "Keith Godcheaux", "Donna Godcheaux", "John Kahn");
		out << item << endl;
        }
    item = library->addMusicAlbum("Time Out", "Dave Brubeck Quartet", 7);
    if (item != NULL) {
        library->addKeywordsForItem(item, 3, "jazz", "unusual time signatures", "fifties");
        library->addBandMembers(item, 4, "Dave Brubeck", "Paul Desmond", "Joe Morello", "Eugene Wright");
		out << item << endl;
        }
    item = library->addMusicAlbum("Newborn Light", "Urszula Dudziak", 7);
    if (item != NULL) {
        library->addKeywordsForItem(item, 3, "jazz", "scat singing", "cosmic");
        library->addBandMembers(item, 2, "Urszula Dudziak", "Adam Makowicz");
		out << item << endl;
        }
    item = library->addMovie("Lost In Translation", "Sofia Coppola", 14);
    if (item != NULL) {
        library->addKeywordsForItem(item, 3, "Japan", "loneliness", "time");
        library->addCastMembers(item, 2, "Bill Murray", "Scarlett Johansson");
		out << item << endl;
        }
    item = library->addMovie("Groundhog Day", "Harold Ramis", 14);
    if (item != NULL) {
        library->addKeywordsForItem(item, 3, "newscaster", "groundhog", "time");
        library->addCastMembers(item, 2, "Bill Murray", "Andie MacDowell");
		out << item << endl;
        }
    item = library->addMovie("Monterey Pop", "D.A. Pennebaker", 14);
    if (item != NULL) {
        library->addKeywordsForItem(item, 3, "sixties", "rock", "concert");
        library->addCastMembers(item, 5, "Jimi Hendrix", "Janis Joplin", "Hugh Masakela",
										 "Jefferson Airplane", "Country Joe and the Fish");
		out << item << endl;
        }

	out << ">>>>>> printing items from library" << endl << endl;

    // print books, music albums, movies
    out << ">>> books:" << endl << endl;
    printItemSet(out, library->books());
    out << ">>> music albums:" << endl << endl;
    printItemSet(out, library->musicAlbums());
    out << ">>> movies:" << endl << endl;
    printItemSet(out, library->movies());

    // print items for keyword
    out << ">>> items for keyword: science fiction" << endl << endl;
    printItemSet(out, library->itemsForKeyword("science fiction"));
    out << ">>> items for keyword: jazz" << endl << endl;
    printItemSet(out, library->itemsForKeyword("jazz"));
    out << ">>> items for keyword: cosmic" << endl << endl;
    printItemSet(out, library->itemsForKeyword("cosmic"));
    out << ">>> items for keyword: autism" << endl << endl;
    printItemSet(out, library->itemsForKeyword("autism"));
    out << ">>> items for keyword: sixties" << endl << endl;
    printItemSet(out, library->itemsForKeyword("sixties"));
    out << ">>> items for keyword: time" << endl << endl;
    printItemSet(out, library->itemsForKeyword("time"));
    out << ">>> items for keyword: fifties" << endl << endl;
    printItemSet(out, library->itemsForKeyword("fifties"));
    out << ">>> items for keyword: forties" << endl << endl;
    printItemSet(out, library->itemsForKeyword("forties"));
	out << endl << endl;

    // items for artist
    out << ">>> books by Robert A. Heinlein:" << endl << endl;
    printItemSet(out, library->booksByAuthor("Robert A. Heinlein"));
    out << ">>> books by Mark Haddon:" << endl << endl;
    printItemSet(out, library->booksByAuthor("Mark Haddon"));
    out << ">>> music by the Grateful Dead:" << endl << endl;
    printItemSet(out, library->musicByBand("Grateful Dead"));
    out << ">>> music by Kiss:" << endl << endl;
    printItemSet(out, library->musicByBand("Kiss"));
    out << ">>> movies by Sofia Coppola:" << endl << endl;
    printItemSet(out, library->moviesByDirector("Sofia Coppola"));
    out << ">>> music by Jerry Garcia:" << endl << endl;
    printItemSet(out, library->musicByMusician("Jerry Garcia"));
    out << ">>> movies with Bill Murray:" << endl << endl;
    printItemSet(out, library->moviesByActor("Bill Murray"));
	out << endl << endl;

	delete library;

	// report on memory leaks in the Output Window
	#ifdef _DEBUG
	if (argc == 2) {
		_CrtSetReportMode( _CRT_WARN , _CRTDBG_MODE_FILE );
		_CrtSetReportFile( _CRT_WARN , _CRTDBG_FILE_STDERR );
		}
	_CrtDumpMemoryLeaks();
	#endif

	return 0;
}
