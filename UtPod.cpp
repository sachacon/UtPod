// implementation of the UtPod class from UtPod.h
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "UtPod.h"
#include "song.h"
using namespace std;

UtPod::UtPod(){
    // default constructor, set to default MAX_MEMORY
    memSize = MAX_MEMORY;
    songs = NULL;
}

UtPod::UtPod(int size){
    // if size is 0, neg, or > 512, then set to MAX_MEMORY
    if(size <= 0 || size > 512){
	memSize = MAX_MEMORY;
    }else{
	memSize = size;
    }
    songs = NULL;
}

int UtPod::addSong(Song const &s){
    // if not enough memory, return error number
    if (s.getSize() > getRemainingMemory()){
	return(NO_MEMORY);
    }
    else{
	// insert at beginning of list 
	SongNode *p = new SongNode;
	p->s = s;
	if(songs == NULL){
	    p->next = NULL;
	    songs = p;
	}else{
	p->next = songs;
	songs = p;
	}
    }	
    return(SUCCESS);
}

int UtPod::removeSong(Song const &s){
    bool found = false;
    // if UtPod is empty, nothing to remove
    if(songs == NULL){
	return(NOT_FOUND);
    }
    else{
	SongNode *p = songs;
	SongNode *tail = songs;
	// if there's only one song and it matches input
	if(p->next == NULL && p->s == s){
	    delete p;
	    songs = NULL;
	}

	// go through list, and delete song node
	// go until first instance of song, then stop
	else{	
  	    while(p != NULL && !found){
	        if(p->s == s){
		    SongNode *temp = p;
		    tail->next = temp->next;
		    delete p;
		    found = true;
	        }
	        tail = p;
	        p = p->next;
	    }
	}
    }

    // return code based upon success
    if(found){
	return(SUCCESS);
    }else{
	return(NOT_FOUND);
    }
}

void UtPod::shuffle(){
    // shuffle in linked list in random order
    // find number of songs in the list
    SongNode *p = songs;
    int song_count = 0, i = 0, node_count = 0;
    if(songs != NULL){
	while(p != NULL){
	   song_count++;
	   p = p->next;
	} 
    }
   
    // if there's more than 2 songs, swap songs 
    if(song_count > 2){
	Song temp; 
	SongNode *n1, *n2;
 	long node1, node2;
        unsigned int currentTime = (unsigned)time(0);
        srand(currentTime);
	for(i = 0; i < 3; i++){
            node1 = (rand() % song_count);
	    node2 = (rand() % song_count);
	    cout << node1 << " " << node2 << endl;	    
	    p = songs;
	    while(p != NULL){
		if(node_count == node1){
		    n1 = p;
		}
		if(node_count == node2){
	 	    n2 = p;  
		}
		node_count++;
		p = p->next;	
	    }
	    temp = n1->s;
	    n1->s = n2->s;
	    n2->s = temp;	
	}	
    }
}

void UtPod::showSongList(){
    // go through list, print out songs 
    if(songs == NULL){
	cout << "UtPod is empty" << endl;
	return;
    }
    else{
	SongNode *p = songs;
	while(p != NULL){
   	    cout << p->s.getTitle() << ", by " << p->s.getArtist() 
		 << ", Size: " << p->s.getSize() << " MB" << endl;
	    p = p->next;
	}
    }
}

void UtPod::sortSongList(){
    // sort song list from artist, title, then size from least to greatest
    SongNode *p = songs; 
    int song_count = 0;
    while(p != NULL){
	song_count++;
	p = p->next;
    }
    if(song_count < 3){
	return;
    }
    else{
        bool sorted = false;
        SongNode *current_song, *next_song;
        Song temp;
        while(!sorted){
	    sorted = true;
	    current_song = songs;
	    next_song = songs;
	    next_song = next_song->next;
	    while(next_song != NULL){
	        if(current_song->s > next_song->s){
		    temp = current_song->s;
		    current_song->s = next_song->s;
		    next_song->s = temp;
		    sorted = false;	   
	        }
	        next_song = next_song->next;
	        current_song = current_song->next;
    	    }
        }
    }
}

void UtPod::clearMemory(){
    // delete nodes from linked list with delete operator
    SongNode *p = songs;
    SongNode *next;
    while(p != NULL){
	next = p->next;
	delete p;
	p = next;
    }
}

int UtPod::getRemainingMemory(){
    // add up current memory, subtract from total memory
    int RemainMem = memSize;
    if(songs != NULL){
        SongNode *p = songs;
        while(p != NULL){
	    RemainMem = RemainMem - p->s.getSize();
	    p = p->next;	
        }
    }
    return (RemainMem);    
}

// Destructor calls clear memory function
UtPod::~UtPod(){
    clearMemory();
}



