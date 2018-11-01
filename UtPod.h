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
       * input parms - 
       * output parms - 
       */ 
      int addSong(Song const &s);

      /* int removeSong
       * attemps to remove a song from the UtPod
       * removes the first instance of a song if multiple instances
       * returns 0 if successful, returns 01 if nothing removed
       * input parms-
       * output parms-
       */
      int removeSong(Song const &s);

      /* void shuffle - shuffles song into random order
       * will do nothing if there are less than two songs in list
       * input parms - 
       * output parms - 
       */ 
      void shuffle();

      /* void showSongList - prints current list of songs from first to last
       * format - Title, Artist, size in MB (one song per line)
       * input parms - 
       * output parms - 
       */
      void showSongList();

      /* void sortSongList
       * sorts the songs in ascending order
       * will do nothing if there are less than two songs in list
       * input parms - 
       * output parms - 
       */
      void sortSongList();

      /* void clearMemory
       * clears all the songs from memory
       * inputs parms - 
       * output parms - 
       */
      void clearMemory();

      /* int getTotalMemory - returns the total amount of memory 
       * in the UtPod, will do nothing if less than two songs in list
       * input parms - 
       * output parms -
       */
      int getTotalMemory() {
         return memSize;
      }
      
      /* getRemainingMemory - returns the amount of memory 
       * available for adding new songs
       * input parms - 
       * output parms -
       */ 
      int getRemainingMemory();

      ~UtPod();

};

#endif //UTPOD_UTPOD_H
