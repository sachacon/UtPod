// header class specification file for the song class 

class Song
{
    private:
        char title;
        char artist;
        int size;
 
    public:
        Song();
        
        char getTitle(){
            return title;
        }
        char getArtist(){
            return artist;
        }
        int getSize(){
	    return(size);
        }
	
	~Song();
};

