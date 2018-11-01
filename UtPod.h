//
// Created by Sergio Chacon on 10/22/2018.
//

#ifndef UTPOD_UTPOD_H
#define UTPOD_UTPOD_H
#include "song.h"

//UtPod class declaration
class UtPod
{
   private:
      static const int MAX_MEMORY = 512;
      static const int SUCCESS = 0;
      static const int NO_MEMORY = -1;
      static const int NOT_FOUND = -2;

      struct SongNode
      {
         Song s;
         SongNode *next;
      };

      SongNode *songs;  //the head pointer

      int memSize;
      
   public:
      // Default constructor, sets memory size to MAX_MEMORY
      UtPod();

      // Constructor with size parameter
      // If size is greater than MAX_MEMORY or less than or equal to 0, set size to MAX_MEMORY
      UtPod(int size);

      /* int addSong
       * attempts to add new song to the UtPod
       * returns a 0 if successful, -1 if not enough memory
       * preconditions - s is a valid song
       * input parms - valid song class passed by reference 
       * output parms - returns 0 if successfull, -1 if not enough memory
       */ 
      int addSong(Song const &s);

      /* int removeSong
       * attemps to remove a song from the UtPod
       * removes the first instance of a song if multiple instances
       * returns 0 if successful, returns -1 if nothing removed
       * input parms- valid song class passed by reference
       * output parms- returns 0 if successfull, -1 if not found or empty 
       */
      int removeSong(Song const &s);

      /* void shuffle - shuffles song into random order
       * will do nothing if there are less than two songs in list
       * input parms - no inputs
       * output parms - song is shuffled in a random order
       */ 
      void shuffle();

      /* void showSongList - prints current list of songs from first to last
       * format - Title, Artist, size in MB (one song per line)
       * input parms - no inputs
       * output parms - prints songs to screen, does nothing if empty
       */
      void showSongList();

      /* void sortSongList
       * sorts the songs in ascending order
       * will do nothing if there are less than two songs in list
       * input parms - no inputs
       * output parms - nothing if empty, sorts by artist, then title, then size
       */
      void sortSongList();

      /* void clearMemory
       * clears all the songs from memory
       * inputs parms - no inputs
       * output parms - nodes are deleted, songs set to NULL
       */
      void clearMemory();

      /* int getTotalMemory - returns the total amount of memory 
       * in the UtPod, will do nothing if less than two songs in list
       * input parms - no inputs
       * output parms - prints out total size of UtPod, private variable
       */
      int getTotalMemory() {
         return memSize;
      }
      
      /* getRemainingMemory - returns the amount of memory 
       * available for adding new songs
       * input parms - no inputs
       * output parms - prints total memory - sum of song memory
       */ 
      int getRemainingMemory();
      // Destructor, calls clearMemory()
      ~UtPod();

};

#endif //UTPOD_UTPOD_H
