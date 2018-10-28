// implementation of the UtPod class from UtPod.h
#include <string>
#include "UtPod.h"
using namespace std;

UtPod::UtPod(){
    memSize = MAX_MEMORY;
}

UtPod::UtPod(int size){
    if(size <= 0 || size > 512){
	memSize = MAX_MEMORY;
    }else{
	memSize = size;
    }
}

int UtPod::addSong(Song const &s){

}

int UtPod::removeSong(Song const &s){

}

void UtPod::shuffle(){

}

void UtPod::showSongList(){

}

void UtPod::sortSongList(){

}

void UtPod::clearMemory(){

}

int UtPod::getTotalMemory(){

}

// Destructor calls clear memory function
UtPod::~UtPod(){
    clearMemory();
}



