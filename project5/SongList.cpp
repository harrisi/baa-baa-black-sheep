//
//  SongList.cpp
//  project5
//
//  Created by Ian Harris on 16/8/8.
//  Copyright © 2016 Ian Harris. All rights reserved.
//

#include "SongList.hpp"

Song::Song() {
  title = new char;
  artist = new char;
  album = new char;
}

Song::~Song() {
  delete title;
  delete artist;
  delete album;
}

SongList::SongList() {
  head = new SongNode;
  tail = new SongNode;
}

void SongList::add(Song *song) {
  if (!head->next) { // head is null, insert here
    head->data = new Song;
    head->data = song;
//    head->data->title = song->title;
//    head->data->artist = song->artist;
//    head->data->minutes = song->minutes;
//    head->data->seconds = song->seconds;
//    head->data->album = song->album;
    head->next = tail;
    head->prev = NULL;
  } else if (!tail->prev) {
    tail->data = new Song;
    tail->data = song;
//    tail->data->title = song->title;
//    tail->data->artist = song->artist;
//    tail->data->minutes = song->minutes;
//    tail->data->seconds = song->seconds;
//    tail->data->album = song->album;
    tail->prev = head;
    tail->next = NULL;
  } else {
    SongNode *tmp = new SongNode;
    tmp->data = new Song;
    tmp->data = song;
//    tmp->data->title = tail->data->title;
//    tmp->data->artist = tail->data->artist;
//    tmp->data->minutes = tail->data->minutes;
//    tmp->data->seconds = tail->data->seconds;
//    tmp->data->album = tail->data->album;
    tmp->prev = tail->prev;
    tmp->next = tail;
    tmp->prev->next = tmp;
    tail->data = song;
//    tail->data->title = song->title;
//    tail->data->artist = song->artist;
//    tail->data->minutes = song->minutes;
//    tail->data->seconds = song->seconds;
//    tail->data->album = song->album;
    tail->prev = tmp;
    tail->next = NULL;
  }
}

void SongList::print() {
  SongNode *tmp = head;
  int i = 0;
  do {
    std::cout << "Item [" << i << "]:\n"
    << "\tTitle:\t" << tmp->data->title << '\n'
    << "\tArtist:\t" << tmp->data->artist << '\n'
    << "\tDuration:\t" << tmp->data->minutes << ':' << tmp->data->seconds << '\n'
    << "\tAlbum:\t" << tmp->data->album << '\n';
    i++;
  } while ((tmp = tmp->next));
}

SongList::~SongList() {
  // clear up memory
}