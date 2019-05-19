#include <string>
#include "spotify.h"
#include "gerdabify.h"
using namespace std;



void GerdabifyAPI::signup(UserData _user_data, string _password)
{
	spotify.signup(_user_data, _password);
}
void GerdabifyAPI::login(string _username, string _password)
{
	spotify.login(_username, _password);
}

void GerdabifyAPI::addMusic(string _name, string _file_path)
{
	spotify.add_music( _name, _file_path);
}

void GerdabifyAPI::addAlbum(string _artist_name, string _album_name)
{
	spotify.add_album(_artist_name , _album_name);
}
UserData GerdabifyAPI::getUserDetails(string username)
{
	return spotify.get_user_detils(username);
}
void GerdabifyAPI::enterBrowserMode()
{
	spotify.enter_browser_mode();
}
void GerdabifyAPI::goToHome()
{
	spotify.go_to_home();
}
void GerdabifyAPI::goToPlayLists()
{
	spotify.go_to_playlists();
}
void GerdabifyAPI::goToLibrary()
{
	spotify.go_to_library();
}
List GerdabifyAPI::list()
{
	return spotify.list();
}
string GerdabifyAPI::getArtist()
{
	return spotify.get_artist();
}
string GerdabifyAPI::getName()
{
	return spotify.get_name();
}
string GerdabifyAPI::getAlbum()
{
	return spotify.get_album();
}
List GerdabifyAPI::listArtists()
{
	return spotify.list_artists();
}
List GerdabifyAPI::listPlaylists()
{
	return spotify.list_playlists();
}
List GerdabifyAPI::listMusics()
{
	return spotify.list_musics();
}
List GerdabifyAPI::listMusicsCompName()
{
	return spotify.list_musics_comp_name();
}
List GerdabifyAPI::listAlbums()
{
	return spotify.list_albums();
}
List GerdabifyAPI::listAlbumsCompName()
{
	return spotify.list_albums_comp_name();
}
void GerdabifyAPI::select(string _name)
{
	return spotify.select(_name);
}
void GerdabifyAPI::goToAlbum()
{
	spotify.go_to_album();
}
void GerdabifyAPI::goToArtist()
{
	spotify.go_to_artist();
}
string GerdabifyAPI::getCompleteName()
{
	return spotify.get_complete_name();
}
void GerdabifyAPI::rate(int score)
{
	spotify.rate(score);
}
int GerdabifyAPI::getRate()
{
	return spotify.get_rate();
}
int GerdabifyAPI::getUserRate()
{
	return spotify.get_user_rate();
}
int GerdabifyAPI::getCriticRate()
{
	return spotify.get_critic_rate();
}
void GerdabifyAPI::createPlaylist(string _name)
{
	spotify.create_playlist(_name);
}
void GerdabifyAPI::clearPlaylist(string _name)
{
	spotify.clear_playlist(_name);
}
void GerdabifyAPI::remove(string music_complete_name)
{
	spotify.remove(music_complete_name);
}
List GerdabifyAPI::search(string name)
{
	return spotify.search(name);
}
void GerdabifyAPI::goTo(string name)
{
	spotify.go_to(name);
}
void GerdabifyAPI::verifyUser(string name)
{
	spotify.verify_user(name);
}
void GerdabifyAPI::validate()
{
	spotify.validate();
}
void GerdabifyAPI::play()
{
	spotify.play();
}
void GerdabifyAPI::next()
{
	spotify.next();
}
void GerdabifyAPI::previous()
{
	spotify.previous();
}
void GerdabifyAPI::pause()
{
	spotify.pause();
}

void GerdabifyAPI::shuffle()
{
	spotify.shuffle();
}
void GerdabifyAPI::repeatOne()
{
	spotify.repeat_one();
}
void GerdabifyAPI::repeat()
{
	spotify.repeat();
}
void GerdabifyAPI::addTo(string name)
{
	spotify.add_to(name);
}
void GerdabifyAPI::orderItem(string music_name, int index)
{
	spotify.order_item(music_name , index);
}