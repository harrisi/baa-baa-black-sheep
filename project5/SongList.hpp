//
//  SongList.hpp
//  project5
//
//  Created by Ian Harris on 16/8/8.
//  Copyright © 2016 Ian Harris. All rights reserved.
//

#ifndef SongList_hpp
#define SongList_hpp

#include <iostream>

// XXX: SongID?

class Song {
public: // XXX: Set to private.
  char *title;
  char *artist;
  char *album;
  unsigned int minutes;
  unsigned int seconds;
public:
//  Song();
  char *getTitle();
  void setTitle(const char *);
  char *getArtist();
  void setArtist(const char *);
  unsigned int getMinutes();
  void setMinutes(const unsigned int);
  unsigned int getSeconds();
  void setSeconds(const unsigned int);
  char *getAlbum();
  void setAlbum(const char *);
  ~Song();
};

struct SongNode {
public:
  Song *data;
  SongNode *next;
  SongNode *prev;
};

class SongList {
private:
  SongNode *head;
  SongNode *tail;
public:
  SongList();
  void add(Song*);
  void print();
  ~SongList();
};

#endif /* SongList_hpp */
