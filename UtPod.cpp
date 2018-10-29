// implementation of the UtPod class from UtPod.h
#include <string>
#include <iostream>
#include "UtPod.h"
#include "song.h"
using namespace std;

UtPod::UtPod(){
    memSize = MAX_MEMORY;
    songs = NULL;
}

UtPod::UtPod(int size){
    if(size <= 0 || size > 512){
	memSize = MAX_MEMORY;
    }else{
	memSize = size;
    }
    songs = NULL;
}

int UtPod::addSong(Song const &s){
    if (s.getSize() > getRemainingMemory()){
	return(NO_MEMORY);
    }
    else{
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
	/*
    int success = 0;
    bool found = false;
    if(songs == NULL){
	success = -1;
    }
    else{
	SongNode *p = songs;
	while(p != NULL && !found){
	    if(p->s == this->s){
		SongNode *temp;
	    }
	    p = p->next;
	}	
    }
    return (success);
	*/
}

void UtPod::shuffle(){

}

void UtPod::showSongList(){
    if(songs == NULL){
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

}

void UtPod::clearMemory(){

}

int UtPod::getRemainingMemory(){
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



