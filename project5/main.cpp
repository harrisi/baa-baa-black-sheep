#include <iostream>
#include <fstream>
#include <cstring>
#include "SongList.hpp"

void loadFile(SongList&, const char * = ";");
void doMenu(SongList&);

int main() {
  std::cout << "Welcome to Ian's music library program!\n";
  SongList songs;
  loadFile(songs);
  //doMenu(songs);
  songs.print();
  return 0;
}

void loadFile(SongList& song_list, const char *delim) {
  char *in = new char;
  std::ifstream f("/Users/ian/dev/cpp/proj5/project5/project5/songs.txt");
  char *token;
  
  if (!f.is_open()) {
    std::cerr << "Failed to load file.\n";
    // XXX: Define error numbering properly.
    exit(1);
  }
  
  while (f.getline(in, std::numeric_limits<std::streamsize>::max())) {
    Song *tmp = new Song;
    if (f.eof()) break;
    token = strtok(in, delim);
    //std::cout << "title: " << token << '\n';
    strncpy(tmp->title, token, strlen(token));
    token = strtok(nullptr, delim);
    //std::cout << "artist: " << token << '\n';
    strncpy(tmp->artist, token, strlen(token));
    token = strtok(nullptr, delim);
    //std::cout << "minutes: " << token << '\n';
    tmp->minutes = atoi(token);
    token = strtok(nullptr, delim);
    //std::cout << "seconds: " << token << '\n';
    tmp->seconds = atoi(token);
    token = strtok(nullptr, delim);
    //std::cout << "album: " << token << '\n';
    strncpy(tmp->album, token, strlen(token));
    song_list.add(tmp);
  }
  // Entire file should be loaded into memory now.
  
  f.close();
}

void doMenu(SongList& song_list) {
  std::cout << "menu.\n";
}
