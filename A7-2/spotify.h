#ifndef _SPOTIFY_H_
#define _SPOTIFY_H_


#include <string>
#include <vector>
#include "music.h"
using namespace std;

enum UserType ;
typedef vector<string> List;
struct UserData;
class Person;
class State;

class Spotify{
public:
	void enter_browser_mode();
	void go_to_home();
	void go_to_playlists();
	void go_to_library();
	void go_to_album();
	void go_to_artist();
	void select(string _name);
	List list();
	List list_musics();
	List list_musics_comp_name();
	List list_albums();
	List list_albums_comp_name();
	List list_playlists();
	List list_artists();
	void signup(UserData _user_data, string _password);
	void deactive_users();
	void login(string _username, string _password);
	void add_music(string _name, string _file_path);
	void add_album(string _artist_name , string _album_name);
	Person* find_active_person();
	Person* find_person(string name);
	UserData get_user_detils(string username);
	string get_artist();
	string get_album();
	string get_name();
	string get_complete_name();
	void rate(int score);
	int get_rate();
	int get_user_rate();
	int get_critic_rate();
	bool not_registered(string username);
	void create_playlist(string _name);
	void clear_playlist(string _name);
	void remove(string music_complete_name);
	List search(string name);
	int count(string name , char delimeter);
	void go_to(string name);
	void verify_user(string name);
	void validate();
	void play();
	void next();
    void previous();
    void pause();
    void shuffle();
    void repeat_one();
    void repeat();
    void add_to(string name);
    void order_item(string music_name, int index);
private:
	vector <Person*> users;
	Library library;
	State* state;
	string mode;
};


#endif