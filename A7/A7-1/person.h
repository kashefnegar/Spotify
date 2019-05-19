#ifndef _PERSON_H_
#define _PERSON_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Music;
class Album;
class Play_List;
class Queue;

typedef vector<string> List;

enum UserType {_Admin, _Artist, _Editor, _Normal};
struct UserData
{
    string firstname;
    string lastname;
    string username;
    UserType userType;
};

class Person{
public:
	Person(UserData _user_data , string _password);
	Person(Person* p);
	bool is_same_person(string _username, string _password);
	void active();
	void accept();
	bool is_active();
	void deactive();
	virtual bool is_artist()=0;
	virtual bool is_editor()=0;
	virtual bool is_admin()=0;
	virtual void add_music(Music* m)=0;
	virtual void add_album(Album* a)=0;
	bool same_username(string _username);
	UserData get_details();
	vector<Play_List*> get_playlist();
	string get_name();
	List get_playlist_comp_name();
	bool has_this_playlist(string name);
	void add_playlist(Play_List* p);
	void clear_playlist(string name);
	Play_List* get_this_playlist(string name);
	Queue* get_queue();
	bool has_this_album(string name){}
	Album* get_this_album(string name){}

protected:
	UserData user_data;
	string password;
	bool activated;
	bool accepted;
	vector<Play_List*> play_lists;
	Queue* queue;
};

class Normal:public Person{
public:
	Normal(UserData _user_data , string _password):Person(_user_data,_password) {};
	bool is_artist(){return false;}
	bool is_editor(){return false;}
	bool is_admin(){return false; }
	void add_music(Music* m){/**/}
	void add_album(Album* a){/**/}
};
class Artist: public Person{
public:
	Artist(UserData _user_data , string _password):Person(_user_data,_password) {};
	Artist(Artist* artist):Person(artist) {};
	bool is_artist();
	bool is_editor(){return false; }
	bool is_admin(){return false;}
	void add_music(Music* m);
	void add_album(Album* a);
	List album_list();
	List list_albums_comp_name();
	List music_list();
	List list_musics_comp_name();
	void rate(int score , Person* p);
	int get_rate(Person* p);
	vector<Music*> get_musics();
	bool has_this_album(string name);
	Album* get_this_album(string name);
private:
	vector<Music*> musics;
	vector<Album*> albums;
	map<string , int> rates;
};

class Admin:public Person{
public:
	Admin(UserData _user_data , string _password):Person(_user_data,_password) {};
	bool is_artist(){return false;}
	bool is_editor(){return false;}
	bool is_admin(){return true;}///////need varify or not if yes return accepeted
	void add_music(Music* m){/**/}
	void add_album(Album* a){/**/}
};
class Editor:public Person{
public:
	Editor(UserData _user_data , string _password):Person(_user_data,_password) {};
	bool is_artist(){return false; }
	bool is_editor(){return accepted;}
	bool is_admin(){return false;}
	void add_music(Music* m){/**/}
	void add_album(Album* a){/**/}
};

#endif