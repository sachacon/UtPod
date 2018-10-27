// header class specification file for the song class 
#include <string>

class Song
{
    private:
        string title;
        string artist;
        int size;
 
    public:
        Song(string artist, string title, string size);
        
        string getTitle(){
            return title;
        }
        string getArtist(){
            return artist;
        }
        int getSize(){
	    return size;
        }
	
     //	~Song();
};

