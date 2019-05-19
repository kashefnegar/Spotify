#ifndef _GERDABIFY_H_
#define _GERDABIFY_H_

#include <string>
#include "spotify.h"
using namespace std;

typedef vector<string> List;

struct UserData;

class GerdabifyAPI{
public:
	void enterBrowserMode();
	void goToHome();
	void goToPlayLists();
	void goToLibrary();
	void goToAlbum();
	void goToArtist();
	void select(string _name);
	List list();
	List listMusics();
    List listMusicsCompName();
	List listAlbums();
    List listAlbumsCompName();
	List listPlaylists();
	List listArtists();
    List search(string name);
	void signup(UserData _user_data, string _password);
    void login(string _username, string _password);
    void addMusic(string _name, string _file_path);
    void addAlbum(string _artist_name, string _album_name);
    string getArtist();
    string getAlbum();
    UserData getUserDetails(string username);
    string getName();
    string getCompleteName();
    void rate(int score);
    int getRate();
    int getUserRate();
    int getCriticRate();
    void createPlaylist(string _name);
    void clearPlaylist(string _name);
    void remove(string music_complete_name);
    void goTo(string name);
    void verifyUser(string name);
    void validate();
    void play();
    void next();
    void previous();
    void pause();
    void shuffle();
    void repeatOne();
    void repeat();
    void addTo(string name);
    void orderItem(string music_name, int index);
private:
	Spotify spotify;
};

#endif