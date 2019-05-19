#ifndef _MUSIC_H_
#define _MUSIC_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "person.h"
using namespace std;

typedef vector<string> List;

class Music{
public:
	Music(string _name, string _file_path , Artist* p);
	string artist_name();
	string get_name();
	string album_name();
	Artist* get_artist();
	Album* get_album();
	void set_album(Album* a){album = a;}
	void rate(int score , Person* p);
	int get_rate(Person* p);
	bool is_accepted(){return accepted;}
	void accept();
	void play(){}
private:
	string name;
	string file_path;
	Artist* artist;
	Album* album;
	bool accepted;
	map<string , int> rates;
	
};

class List_Of_Musics{
public:
	List_Of_Musics(string _name):name(_name){}
	List music_list();
	List music_comp_name_list();
	string get_name();
	bool has_this_music(string name);
	Music* find_music(string name);
	void clear();
	void remove_music(string music_name );
	vector<Music*> get_musics();
	void add_music(Music* m);
	void add_album(Album* a);
	int get_size(){return list.size();}


protected:
	string name;
	vector<Music*> list;
};

class Play_List:public List_Of_Musics{

public:
	Play_List(string name):List_Of_Musics(name){}
	List list_albums();
	List list_albums_comp_name();
	void order_item(string music_name ,int index);
};

class Queue:public List_Of_Musics{
public:
	Queue(string name):List_Of_Musics(name){}
	List list_albums();
	List list_albums_comp_name();
};

class Album:public List_Of_Musics{
public:
	Album(string _name , Artist* _artist):List_Of_Musics(_name) , artist(_artist) , accepted(false){}
	string artist_name();
	string get_comp_name();
	Artist* get_artist();
	void rate(int score , Person* p);
	int get_rate(Person* p);
	bool has_this_artist( Person * p) ;
	bool is_accepted(){return accepted;}
	void accept();
	void add_album(Album* a);
private:
	Artist* artist;
	bool accepted;
	map<string , int> rates;
};

class Library{
public:
	void add_music(Music* music);
	void add_album(Album* album);
	List artist_list();
	List music_list();
	List music_comp_name_list();
	List album_list();
	List albums_list_comp_name();
	List get_albums_comp_name(string name);
	bool has_this_music(string name);
	bool include_this_music(string name);
	Music* find_music(string name);
	bool has_this_album(string name);
	bool include_this_album(string name);
	Album* find_album(string name);
	bool has_this_artist(string name);
	Artist* find_artist(string name);
	void add_artist(Artist* a);
private:
	vector<Music*> musics;
	vector<Album*> albums;
	vector<Artist*> artists;
};

#endif

