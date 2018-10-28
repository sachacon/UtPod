// header class specification file for the song class 
#include <string>
using namespace std;

class Song
{
    private:
        string title;
        string artist;
        int size;
 
    public:
	// Constructor
	Song();
        Song(string artist, string title, int size);
       
	// Set Instance Variables
	void setArtist(string _artist);
	void setTitle(string _title);
	void setSize(int _size);
 
	// Get Instance Variables
        string getArtist() const;
        string getTitle() const;
        int getSize() const;

	// Overload Operators for Sorting 
	bool operator >(Song const &rhs);
	bool operator ==(Song const &rhs);
	bool operator <(Song const &rhs);

        // ~Song();
};

