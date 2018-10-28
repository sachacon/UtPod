// this is the implementation of the song.h header and song class
#include <string>
#include "song.h"
using namespace std;

// Implementations of constructors
Song::Song(){
   artist = "";
   title = "";
   size = 0;
}

Song::Song(string _artist, string _title, int  _size){
    artist = _artist;
    title = _title;
    size = _size;
}

// Implementation of setting variables
void Song::setArtist(string _artist){
    artist = _artist;
}

void Song::setTitle(string _title){
    title = _title;
}

void Song::setSize(int _size){
    size = _size;
}

// Implementation of getting variables
string Song::getArtist() const {
    return artist;
}

string Song::getTitle() const {
    return title;
}

int Song::getSize() const {
    return size;
}

// Implementation of song class operators
// rhs is an object so use dot operator
// > operator means first song is greater than second,  
bool Song::operator >(Song const &rhs){
    if (artist < rhs.artist){
	return (true);
    }
    else if (title < rhs.title){
	return (true);
    }
    else if (size < rhs.size){
	return (true);
    }else{
	return (false);
    }
}

bool Song::operator ==(Song const &rhs){
    return (artist == rhs.artist && 
	    title == rhs.title &&
	    size == rhs.size);
}

bool Song::operator <(Song const &rhs){
    if (artist > rhs.artist){
	return (true);
    }
    else if (title > rhs.title){
	return (true);
    }
    else if (size > rhs.size){
	return (true);
    }else{
	return (false);
    }
}



