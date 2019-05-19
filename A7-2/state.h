#ifndef _STATE_H_
#define _STATE_H_

#include <vector>
#include <string>
#include "person.h"
#include "music.h"
using namespace std;
class Play_managment;

typedef vector<string> List;

class State{
public:
	virtual bool is_home()=0;
	virtual void go_to_library(Library& _library)=0;
	virtual void go_to_playlists(Person* p)=0;
	virtual void go_to_playlist(Play_List* p)=0;
	virtual void go_to_music(Music* m)=0;
	virtual void go_to_album(Album* m)=0;
	virtual void go_to_artist(Artist* m)=0;
	virtual List list()=0;
	virtual List list_musics()=0;
	virtual List list_musics_comp_name()=0;
	virtual List list_artists()=0;
	virtual List list_albums()=0;
	virtual List list_albums_comp_name()=0;
	virtual List list_playlists()=0;

	virtual string get_artist_name()=0;
	virtual string get_name() =0;
	virtual string get_complete_name(Person* p)=0;
	virtual string get_album_name()=0;
	virtual Album* get_album()=0;
	virtual Artist* get_artist()=0;

	virtual void add_to_this_queue(Queue* q)=0;
	virtual void add_to_this_album(Album* a)=0;
	virtual void add_to_this_playlist(Play_List* p)=0;

	virtual void rate(int score , Person* p)=0;
	virtual int get_rate(Person* p)=0;
	virtual int get_user_rate(vector<Person*> & users)=0;
	virtual int get_critic_rate(vector<Person*> & users)=0;
	virtual void remove(Person* p ,string music_complete_name )=0;
	virtual void go_to_queue(Queue* q)=0;
	virtual void validate()=0;
	virtual void play()=0;
	void next();
    void previous();
    void pause();
    void shuffle();
    void repeat_one();
    void repeat();
    virtual void order_item(string music_name, int index)=0;
protected:
	Play_managment* play_managment;

};

class Home : public State{
public:
	bool is_home();
	void go_to_library(Library& _library);
	void go_to_playlists(Person* p);
	void go_to_playlist(Play_List* p);
	void go_to_music(Music* m);
	void go_to_album(Album* a);
	void go_to_artist(Artist* a);
	List list();
	List list_musics();
	List list_musics_comp_name();
	List list_artists();
	List list_albums();
	List list_albums_comp_name();
	List list_playlists();
	string get_artist_name();
	string get_name();
	string get_complete_name(Person* p);
	string get_album_name();
	Album* get_album();
	Artist* get_artist();
	void rate(int score , Person* p);
	int get_rate(Person* p);
	int get_user_rate(vector<Person*> & users);
	int get_critic_rate(vector<Person*> & users);
	void remove(Person* p ,string music_complete_name );
	void go_to_queue(Queue* q);
	void validate();
	void play();
	void add_to_this_queue(Queue* q);
	void add_to_this_album(Album* a);
	void add_to_this_playlist(Play_List* p);
	void order_item(string music_name, int index);
};
class PlayLists_state : public State{
public:
	bool is_home();
	void go_to_library(Library& _library);
	void go_to_playlists(Person* p);
	void go_to_playlist(Play_List* p);
	void go_to_music(Music* m);
	void go_to_album(Album* a);
	void go_to_artist(Artist* a);
	List list();
	List list_musics();
	List list_musics_comp_name();
	List list_artists();
	List list_albums();
	List list_albums_comp_name();
	List list_playlists();
	string get_artist_name();
	string get_name();
	string get_complete_name(Person* p);
	string get_album_name();
	Album* get_album();
	Artist* get_artist();
	void rate(int score , Person* p);
	int get_rate(Person* p);
	int get_user_rate(vector<Person*> & users);
	int get_critic_rate(vector<Person*> & users);
	void remove(Person* p ,string music_complete_name );
	void go_to_queue(Queue* q);
	void validate();
	void play();
	void add_to_this_queue(Queue* q);
	void add_to_this_album(Album* a);
	void add_to_this_playlist(Play_List* p);
	void order_item(string music_name, int index);
private:
	vector<Play_List*> play_lists ;
};
class Library_state : public State{
public:
	bool is_home();
	void go_to_library(Library& _library);
	void go_to_playlists(Person* p);
	void go_to_playlist(Play_List* p);
	void go_to_music(Music* m);
	void go_to_album(Album* a);
	void go_to_artist(Artist* a);
	List list();
	List list_musics();
	List list_musics_comp_name();
	List list_artists();;
	List list_albums();
	List list_albums_comp_name();
	List list_playlists();
	string get_artist_name();
	string get_name();
	string get_complete_name(Person* p);
	string get_album_name();
	Album* get_album();
	Artist* get_artist();
	void rate(int score , Person* p);
	int get_rate(Person* p);
	int get_user_rate(vector<Person*> & users);
	int get_critic_rate(vector<Person*> & users);
	void remove(Person* p ,string music_complete_name );
	void go_to_queue(Queue* q);
	void validate();
	void play();
	void add_to_this_queue(Queue* q);
	void add_to_this_album(Album* a);
	void add_to_this_playlist(Play_List* p);
	void order_item(string music_name, int index);
private:
	Library* library;
};
class Artist_state : public State{
public:
	bool is_home();
	void go_to_library(Library& _library);
	void go_to_playlists(Person* p);
	void go_to_playlist(Play_List* p);
	void go_to_music(Music* m);
	void go_to_album(Album* a);
	void go_to_artist(Artist* a);
	List list();
	List list_musics();
	List list_musics_comp_name();
	List list_artists();
	List list_albums();
	List list_albums_comp_name();
	List list_playlists();
	string get_artist_name();
	string get_name();
	string get_complete_name(Person* p);
	string get_album_name();
	Album* get_album();
	Artist* get_artist();
	void rate(int score , Person* p);
	int get_rate(Person* p);
	int get_user_rate(vector<Person*> & users);
	int get_critic_rate(vector<Person*> & users);
	void remove(Person* p ,string music_complete_name );
	void go_to_queue(Queue* q);
	void validate();
	void play();
	void add_to_this_queue(Queue* q);
	void add_to_this_album(Album* a);
	void add_to_this_playlist(Play_List* p);
	void order_item(string music_name, int index);
private:
	Artist* artist;
};
class Album_state : public State{
public:
	bool is_home();
	void go_to_library(Library& _library);
	void go_to_playlists(Person* p);
	void go_to_playlist(Play_List* p);
	void go_to_music(Music* m);
	void go_to_album(Album* a);
	void go_to_artist(Artist* a);
	List list();
	List list_musics();
	List list_musics_comp_name();
	List list_artists();
	List list_albums();
	List list_albums_comp_name();
	List list_playlists();
	string get_artist_name();
	string get_name();
	string get_complete_name(Person* p);
	string get_album_name();
	Album* get_album();
	Artist* get_artist();
	void rate(int score , Person* p);
	int get_rate(Person* p);
	int get_user_rate(vector<Person*> & users);
	int get_critic_rate(vector<Person*> & users);
	void remove(Person* p ,string music_complete_name );
	void go_to_queue(Queue* q);
	void validate();
	void play();
	void add_to_this_queue(Queue* q);
	void add_to_this_album(Album* a);
	void add_to_this_playlist(Play_List* p);
	void order_item(string music_name, int index);
private:
	Album* album;
};
class Music_state : public State{
public:
	bool is_home();
	void go_to_library(Library& _library);
	void go_to_playlists(Person* p);
	void go_to_playlist(Play_List* p);
	void go_to_music(Music* m);
	void go_to_album(Album* a);
	void go_to_artist(Artist* a);
	List list();
	List list_musics();
	List list_musics_comp_name();
	List list_artists();
	List list_albums();
	List list_albums_comp_name();
	List list_playlists();
	string get_artist_name();
	string get_name();
	string get_complete_name(Person* p);
	string get_album_name();
	Album* get_album();
	Artist* get_artist();
	void rate(int score , Person* p);
	int get_rate(Person* p);
	int get_user_rate(vector<Person*> & users);
	int get_critic_rate(vector<Person*> & users);
	void remove(Person* p ,string music_complete_name );
	void go_to_queue(Queue* q);
	void validate();
	void play();
	void add_to_this_queue(Queue* q);
	void add_to_this_album(Album* a);
	void add_to_this_playlist(Play_List* p);
	void order_item(string music_name, int index);
private:
	Music * music;
};
class PlayList_state : public State{
public:
	bool is_home();
	void go_to_library(Library& _library);
	void go_to_playlists(Person* p);
	void go_to_playlist(Play_List* p);
	void go_to_music(Music* m);
	void go_to_album(Album* a);
	void go_to_artist(Artist* a);
	List list();
	List list_musics();
	List list_musics_comp_name();
	List list_artists();
	List list_albums();
	List list_albums_comp_name();
	List list_playlists();
	string get_artist_name();
	string get_name();
	string get_complete_name(Person* p);
	string get_album_name();
	Album* get_album();
	Artist* get_artist();
	void rate(int score , Person* p);
	int get_rate(Person* p);
	int get_user_rate(vector<Person*> & users);
	int get_critic_rate(vector<Person*> & users);
	void remove(Person* p ,string music_complete_name );
	void go_to_queue(Queue* q);
	void validate();
	void play();
	void add_to_this_queue(Queue* q);
	void add_to_this_album(Album* a);
	void add_to_this_playlist(Play_List* p);
	void order_item(string music_name, int index);
private:
	Play_List* play_list;
};

class Queue_state : public State{
public:
	bool is_home();
	void go_to_library(Library& _library);
	void go_to_playlists(Person* p);
	void go_to_playlist(Play_List* p);
	void go_to_music(Music* m);
	void go_to_album(Album* a);
	void go_to_artist(Artist* a);
	List list();
	List list_musics();
	List list_musics_comp_name();
	List list_artists();
	List list_albums();
	List list_albums_comp_name();
	List list_playlists();
	string get_artist_name();
	string get_name();
	string get_complete_name(Person* p);
	string get_album_name();
	Album* get_album();
	Artist* get_artist();
	void rate(int score , Person* p);
	int get_rate(Person* p);
	int get_user_rate(vector<Person*> & users);
	int get_critic_rate(vector<Person*> & users);
	void remove(Person* p ,string music_complete_name );
	void go_to_queue(Queue* q);
	void validate();
	void play();
	void add_to_this_queue(Queue* q);
	void add_to_this_album(Album* a);
	void add_to_this_playlist(Play_List* p);
	void order_item(string music_name, int index);
private:
	Queue* queue;
};

#endif