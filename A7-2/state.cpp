#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "state.h"
#include "exception.h"
#include "play_managment.h"

using namespace std;

bool Home::is_home()
{
	return true;
}
bool PlayLists_state::is_home()
{
	return false;
}
bool Library_state::is_home()
{
	return false;
}
bool Artist_state::is_home()
{
	return false;
}
bool Album_state::is_home()
{
	return false;
}
bool Music_state::is_home()
{
	return false;
}
bool PlayList_state::is_home()
{
	return false;
}
bool Queue_state::is_home()
{
	return false;
}




void Home::go_to_library(Library& _library)
{
	
}
void PlayLists_state::go_to_library(Library& _library)
{
	
}
void Library_state::go_to_library(Library& _library)
{	
	library = & _library;
}
void Artist_state::go_to_library(Library& _library)
{
	
}
void Album_state::go_to_library(Library& _library)
{
	
}
void Music_state::go_to_library(Library& _library)
{
	
}
void PlayList_state::go_to_library(Library& _library)
{
	
}
void Queue_state::go_to_library(Library& _library)
{
	
}





void Home::go_to_playlists(Person* p)
{
	
}
void PlayLists_state::go_to_playlists(Person* p)
{
	play_lists=p->get_playlist();
}
void Library_state::go_to_playlists(Person* p)
{

}
void Artist_state::go_to_playlists(Person* p)
{
	
}
void Album_state::go_to_playlists(Person* p)
{
	
}
void Music_state::go_to_playlists(Person* p)
{
	
}
void PlayList_state::go_to_playlists(Person* p)
{
	
}
void Queue_state::go_to_playlists(Person* p)
{
	
}





void Home::go_to_playlist(Play_List* p)
{
	
}
void PlayLists_state::go_to_playlist(Play_List* p)
{

}
void Library_state::go_to_playlist(Play_List* p)
{

}
void Artist_state::go_to_playlist(Play_List* p)
{
	
}
void Album_state::go_to_playlist(Play_List* p)
{
	
}
void Music_state::go_to_playlist(Play_List* p)
{
	
}
void PlayList_state::go_to_playlist(Play_List* p)
{
	play_list = p;
}
void Queue_state::go_to_playlist(Play_List* p)
{
}





void Home::go_to_music(Music* m)
{
	
}
void PlayLists_state::go_to_music(Music* m)
{

}
void Library_state::go_to_music(Music* m)
{

}
void Artist_state::go_to_music(Music* m)
{
	
}
void Album_state::go_to_music(Music* m)
{
	
}
void Music_state::go_to_music(Music* m)
{
	music = m;
}
void PlayList_state::go_to_music(Music* m)
{
	
}
void Queue_state::go_to_music(Music* m)
{
	
}





void Home::go_to_artist(Artist* a)
{
	
}
void PlayLists_state::go_to_artist(Artist* a)
{

}
void Library_state::go_to_artist(Artist* a)
{

}
void Artist_state::go_to_artist(Artist* a)
{
	artist = a ;
}
void Album_state::go_to_artist(Artist* a)
{
	
}
void Music_state::go_to_artist(Artist* a)
{
	
}
void PlayList_state::go_to_artist(Artist* a)
{
	
}
void Queue_state::go_to_artist(Artist* a)
{
	
}




void Home::go_to_album(Album* a)
{
	
}
void PlayLists_state::go_to_album(Album* a)
{

}
void Library_state::go_to_album(Album* a)
{

}
void Artist_state::go_to_album(Album* a)
{
	
}
void Album_state::go_to_album(Album* a)
{
	album = a ;
}
void Music_state::go_to_album(Album* a)
{
	
}
void PlayList_state::go_to_album(Album* a)
{
	
}
void Queue_state::go_to_album(Album* a)
{
	
}




void Home::go_to_queue(Queue* q)
{
	
}
void PlayLists_state::go_to_queue(Queue* q)
{

}
void Library_state::go_to_queue(Queue* q)
{

}
void Artist_state::go_to_queue(Queue* q)
{
	
}
void Album_state::go_to_queue(Queue* q)
{
	
}
void Music_state::go_to_queue(Queue* q)
{
	
}
void PlayList_state::go_to_queue(Queue* q)
{
	
}
void Queue_state::go_to_queue(Queue* q)
{
	queue = q;
}





List Home::list()
{
	List temp;
	temp.push_back("library");
	temp.push_back("playlists");
	return temp;
}
List PlayLists_state::list()
{
	return list_playlists();
}
List Library_state::list()
{
	List temp;
	temp = library->artist_list();
	sort( temp.begin(),temp.end() );
	temp.erase( unique( temp.begin(), temp.end() ), temp.end() );
	return temp;
}
List Artist_state::list()
{
	List temp;
	temp = artist->album_list();
	return temp;
}
List Album_state::list()
{
	List temp;
	temp= album->music_list();
	return temp;
}
List Music_state::list()
{
	throw MethodNotAvailable();
}
List PlayList_state::list()
{
	List temp;
	temp = play_list->music_list();
	return temp;
}
List Queue_state::list()
{
	List temp;
	temp = queue->music_list();
	return temp;
}





string Home::get_artist_name()
{
	throw MethodNotAvailable();
}
string PlayLists_state::get_artist_name()
{
	throw MethodNotAvailable();
}
string Library_state::get_artist_name()
{
	throw MethodNotAvailable();
}
string Artist_state::get_artist_name()
{
	throw MethodNotAvailable();
}
string Album_state::get_artist_name()
{
	return album->artist_name();
}
string Music_state::get_artist_name()
{
	return music->artist_name();
}
string PlayList_state::get_artist_name()
{
	throw MethodNotAvailable();
}
string Queue_state::get_artist_name()
{
	throw MethodNotAvailable();
}





string Home::get_name()
{
	return "home";
}
string PlayLists_state::get_name()
{
	return "playlists";
}
string Library_state::get_name()
{
	return "library";
}
string Artist_state::get_name()
{
	return artist->get_name();
}
string Album_state::get_name()
{
	return album->get_name();
}
string Music_state::get_name()
{
	return music->get_name();
}
string PlayList_state::get_name()
{
	return play_list->get_name();
}
string Queue_state::get_name()
{
	return "queue";
}





string Home::get_complete_name(Person* p)
{
	return "home";
}
string PlayLists_state::get_complete_name(Person* p)
{
	return "playlists";
}
string Library_state::get_complete_name(Person* p)
{
	return "library";
}
string Artist_state::get_complete_name(Person* p)
{
	return artist->get_name();
}
string Album_state::get_complete_name(Person* p)
{
	string temp = album->artist_name();
	temp+="-";
	temp+=album->get_name();
	return temp;
}
string Music_state::get_complete_name(Person* p)
{
	string temp = music->artist_name();
	temp+="-";
	temp+=music->album_name();
	temp+="-";
	temp+=music->get_name();
	return temp;
}
string PlayList_state::get_complete_name(Person* p)
{
	string temp = p->get_name();
	temp+="-";
	temp+= play_list->get_name();
	return temp;
}
string Queue_state::get_complete_name(Person* p)
{
	return "queue";
}





string Home::get_album_name()
{
	throw MethodNotAvailable();
}
string PlayLists_state::get_album_name()
{
	throw MethodNotAvailable();
}
string Library_state::get_album_name()
{
	throw MethodNotAvailable();
}
string Artist_state::get_album_name()
{
	throw MethodNotAvailable();
}
string Album_state::get_album_name()
{
	throw MethodNotAvailable();
}
string Music_state::get_album_name()
{
	return music->album_name();
}
string PlayList_state::get_album_name()
{
	throw MethodNotAvailable();
}
string Queue_state::get_album_name()
{
	throw MethodNotAvailable();
}





List Home::list_artists()
{
	throw MethodNotAvailable();
}
List PlayLists_state::list_artists()
{
	throw MethodNotAvailable();
}
List Library_state::list_artists()
{
	return list();
}
List Artist_state::list_artists()
{
	throw MethodNotAvailable();
}
List Album_state::list_artists()
{
	throw MethodNotAvailable();
}
List Music_state::list_artists()
{
	throw MethodNotAvailable();
}
List PlayList_state::list_artists()
{
	throw MethodNotAvailable();
}
List Queue_state::list_artists()
{
	throw MethodNotAvailable();
}





List Home::list_playlists()
{
	throw MethodNotAvailable();
}
List PlayLists_state::list_playlists()
{
	List temp;
	for(int i=0 ; i<play_lists.size() ; i++)
		temp.push_back(play_lists[i]->get_name());
	return temp;
}
List Library_state::list_playlists()
{
	throw MethodNotAvailable();
}
List Artist_state::list_playlists()
{
	throw MethodNotAvailable();
}
List Album_state::list_playlists()
{
	throw MethodNotAvailable();
}
List Music_state::list_playlists()
{
	throw MethodNotAvailable();
}
List PlayList_state::list_playlists()
{
	throw MethodNotAvailable();
}
List Queue_state::list_playlists()
{
	throw MethodNotAvailable();
}





List Home::list_musics()
{
	throw MethodNotAvailable();
}
List PlayLists_state::list_musics()
{
	List temp1 , temp2;
	for(int i=0 ; i<play_lists.size() ; i++)
	{
		temp1 = play_lists[i]->music_list();
		for(int j=0 ; i<temp1.size() ; j++)
			temp2.push_back(temp1[j]);
	}
}
List Library_state::list_musics()
{
	List temp = library->music_list();
	return temp;
}
List Artist_state::list_musics()
{ 
	List temp = artist -> music_list();
	return temp;
}
List Album_state::list_musics()
{
	return list();
}
List Music_state::list_musics()
{
	throw MethodNotAvailable();
}
List PlayList_state::list_musics()
{
	return list();
}
List Queue_state::list_musics()
{
	return list();
}



List Home::list_musics_comp_name()
{
	throw MethodNotAvailable();
}
List PlayLists_state::list_musics_comp_name()
{
	List temp1 , temp2;
	for(int i=0 ; i<play_lists.size() ; i++)
	{
		temp1 = play_lists[i]->music_list();
		for(int j=0 ; i<temp1.size() ; j++)
			temp2.push_back(temp1[j]);
	}
}
List Library_state::list_musics_comp_name()
{
	List temp = library->music_comp_name_list();
	return temp;
}
List Artist_state::list_musics_comp_name()
{ 
	List temp = artist -> list_musics_comp_name();
	return temp;
}
List Album_state::list_musics_comp_name()
{
	return album->music_comp_name_list();
}
List Music_state::list_musics_comp_name()
{
	throw MethodNotAvailable();
}
List PlayList_state::list_musics_comp_name()
{
	return play_list->music_comp_name_list();
}
List Queue_state::list_musics_comp_name()
{
	return queue->music_comp_name_list();
}



List Home::list_albums()
{
	throw MethodNotAvailable();
}
List PlayLists_state::list_albums()
{
	List temp1 ,temp2;
	for(int i=0 ; i<play_lists.size() ; i++)
	{
		temp2= play_lists[i]->list_albums();
		for(int j=0 ; j< temp2.size() ; j++)
			temp1.push_back(temp2[j]);
	}
	return temp1;
}
List Library_state::list_albums()
{
	return library->album_list();
}
List Artist_state::list_albums()
{ 
	return list();
}
List Album_state::list_albums()
{
	throw MethodNotAvailable();
}
List Music_state::list_albums()
{
	throw MethodNotAvailable();
}
List PlayList_state::list_albums()
{
	return play_list->list_albums();
}
List Queue_state::list_albums()
{
	return queue->list_albums();
}




List Home::list_albums_comp_name()
{
	throw MethodNotAvailable();
}
List PlayLists_state::list_albums_comp_name()
{
	List temp1 ,temp2;
	for(int i=0 ; i<play_lists.size() ; i++)
	{
		temp2= play_lists[i]->list_albums_comp_name();
		for(int j=0 ; j< temp2.size() ; j++)
			temp1.push_back(temp2[j]);
	}
	return temp1;
}
List Library_state::list_albums_comp_name()
{
	return library->albums_list_comp_name();
}
List Artist_state::list_albums_comp_name()
{ 
	return list_albums_comp_name();
}
List Album_state::list_albums_comp_name()
{
	throw MethodNotAvailable();
}
List Music_state::list_albums_comp_name()
{
	throw MethodNotAvailable();
}
List PlayList_state::list_albums_comp_name()
{
	return play_list->list_albums_comp_name();
}
List Queue_state::list_albums_comp_name()
{
	return queue->list_albums_comp_name();
}





Album* Home::get_album()
{
	throw MethodNotAvailable();
}
Album* PlayLists_state::get_album()
{
	throw MethodNotAvailable();
}
Album* Library_state::get_album()
{
	throw MethodNotAvailable();
}
Album* Artist_state::get_album()
{ 
	throw MethodNotAvailable();
}
Album* Album_state::get_album()
{
	throw MethodNotAvailable();
}
Album* Music_state::get_album()
{
	return music->get_album();
}
Album* PlayList_state::get_album()
{
	throw MethodNotAvailable();
}
Album* Queue_state::get_album()
{
	throw MethodNotAvailable();
}




Artist* Home::get_artist()
{
	throw MethodNotAvailable();
}
Artist* PlayLists_state::get_artist()
{
	throw MethodNotAvailable();
}
Artist* Library_state::get_artist()
{
	throw MethodNotAvailable();
}
Artist* Artist_state::get_artist()
{
	throw MethodNotAvailable();
}
Artist* Album_state::get_artist()
{
	return album->get_artist();
}
Artist* Music_state::get_artist()
{
	return music->get_artist();
}
Artist* PlayList_state::get_artist()
{
	throw MethodNotAvailable();
}
Artist* Queue_state::get_artist()
{
	throw MethodNotAvailable();
}





void Home::rate(int score , Person* p)
{
	throw MethodNotAvailable(); 
}
void PlayLists_state::rate(int score , Person* p)
{
	throw MethodNotAvailable(); 
}
void Library_state::rate(int score , Person* p)
{
	throw MethodNotAvailable(); 
}
void Artist_state::rate(int score , Person* p)
{
	artist->rate(score , p);
}
void Album_state::rate(int score , Person* p)
{
	album->rate(score , p);
}
void Music_state::rate(int score , Person* p)
{
	music->rate(score , p);
}
void PlayList_state::rate(int score , Person* p)
{
	throw MethodNotAvailable();	
}
void Queue_state::rate(int score , Person* p)
{
	throw MethodNotAvailable();	
}





int Home::get_rate(Person* p)
{
	throw MethodNotAvailable();
}
int PlayLists_state::get_rate(Person* p)
{
	throw MethodNotAvailable();
}
int Library_state::get_rate(Person* p)
{
	throw MethodNotAvailable();
}
int Artist_state::get_rate(Person* p)
{
	return artist->get_rate( p);
}
int Album_state::get_rate(Person* p)
{
	return album->get_rate(p);
}
int Music_state::get_rate(Person* p)
{
	return music->get_rate( p);
}
int PlayList_state::get_rate(Person* p)
{
	throw MethodNotAvailable();
}
int Queue_state::get_rate(Person* p)
{
	throw MethodNotAvailable();
}






int Home::get_user_rate(vector<Person*> & users)
{
	throw MethodNotAvailable();
}
int PlayLists_state::get_user_rate(vector<Person*> & users)
{
	throw MethodNotAvailable();
}
int Library_state::get_user_rate(vector<Person*> & users)
{
	throw MethodNotAvailable();
}
int Artist_state::get_user_rate(vector<Person*> & users)
{
	int sum = 0 , count = 0 ;
	for(int i=0 ; i<users.size() ; i++)
		if(! users[i] ->is_editor())
		{
			sum+=artist->get_rate(users[i]);
			count++;
		}
	if(count > 0)
		return sum / count;
	else
		return 0;
}
int Album_state::get_user_rate(vector<Person*> & users)
{
	int sum = 0 , count = 0 ;
	for(int i=0 ; i<users.size() ; i++)
		if(! users[i] ->is_editor())
		{
			sum+=album->get_rate(users[i]);
			count++;
		}
	if(count > 0)
		return sum / count;
	else
		return 0;
}
int Music_state::get_user_rate(vector<Person*> & users)
{
	int sum = 0 , count = 0 ;
	for(int i=0 ; i<users.size() ; i++)
		if(! users[i] ->is_editor())
		{
			sum+=music->get_rate(users[i]);
			count++;
		}
	if(count > 0)
		return sum / count;
	else
		return 0;
}
int PlayList_state::get_user_rate(vector<Person*> & users)
{
	throw MethodNotAvailable();
}
int Queue_state::get_user_rate(vector<Person*> & users)
{
	throw MethodNotAvailable();
}





int Home::get_critic_rate(vector<Person*> & users)
{
	throw MethodNotAvailable();
}
int PlayLists_state::get_critic_rate(vector<Person*> & users)
{
	throw MethodNotAvailable();
}
int Library_state::get_critic_rate(vector<Person*> & users)
{
	throw MethodNotAvailable();
}
int Artist_state::get_critic_rate(vector<Person*> & users)
{
	int sum = 0 , count = 0 ;
	for(int i=0 ; i<users.size() ; i++)
		if( users[i] ->is_editor() )
		{
			sum+=artist->get_rate(users[i]);
			count++;
		}
	if(count > 0)
		return sum / count;
	else
		return 0;
}
int Album_state::get_critic_rate(vector<Person*> & users)
{
	int sum = 0 , count = 0 ;
	for(int i=0 ; i<users.size() ; i++)
		if( users[i] ->is_editor())
		{
			sum+=album->get_rate(users[i]);
			count++;
		}
	if(count > 0)
		return sum / count;
	else
		return 0;
}
int Music_state::get_critic_rate(vector<Person*> & users)
{
	int sum = 0 , count = 0 ;
	for(int i=0 ; i<users.size() ; i++)
		if( users[i] ->is_editor())
		{
			sum+=music->get_rate(users[i]);
			count++;
		}
	if(count > 0)
		return sum / count;
	else
		return 0;
}
int PlayList_state::get_critic_rate(vector<Person*> & users)
{
	throw MethodNotAvailable();
}
int Queue_state::get_critic_rate(vector<Person*> & users)
{
	throw MethodNotAvailable();
}





void Home::remove(Person* p , string music_complete_name)
{
	
}
void PlayLists_state::remove(Person* p , string music_complete_name)
{

}
void Library_state::remove(Person* p , string music_complete_name)
{

}
void Artist_state::remove(Person* p , string music_complete_name)
{
	
}
void Album_state::remove(Person* p , string music_complete_name)
{
	string t="-";
	music_complete_name.erase(0, music_complete_name.find(t) + t.length());
	music_complete_name.erase(0, music_complete_name.find(t) + t.length());
	string music_name = music_complete_name;
	if(album->has_this_artist(p))
		album->remove_music( music_name );
	else
		throw NotAuthorized();
}
void Music_state::remove(Person* p , string music_complete_name)
{
	
}
void PlayList_state::remove(Person* p , string music_complete_name)
{
	string t="-";
	music_complete_name.erase(0, music_complete_name.find(t) + t.length());
	music_complete_name.erase(0, music_complete_name.find(t) + t.length());
	string music_name = music_complete_name;
	if(p->has_this_playlist(play_list->get_name()))
		play_list->remove_music(music_name);
	else
		throw NotAuthorized();
}
void Queue_state::remove(Person* p , string music_complete_name)
{

}





void Home::validate()
{
	throw MethodNotAvailable();
}
void PlayLists_state::validate()
{
	throw MethodNotAvailable();
}
void Library_state::validate()
{
	throw MethodNotAvailable();
}
void Artist_state::validate()
{
	artist->accept();
}
void Album_state::validate()
{
	album->accept();
}
void Music_state::validate()
{
	music->accept();
}
void PlayList_state::validate()
{
	throw MethodNotAvailable();
}
void Queue_state::validate()
{
	throw MethodNotAvailable();
}



void Home::play()
{
	throw MethodNotAvailable();
}
void PlayLists_state::play()
{
	throw MethodNotAvailable();
}
void Library_state::play()
{	
	throw MethodNotAvailable();
}
void Artist_state::play()
{
	play_managment->play(artist->get_musics());
}
void Album_state::play()
{
	play_managment->play(album->get_musics());
}
void Music_state::play()
{
	play_managment->play(music);
}
void PlayList_state::play()
{
	play_managment->play(play_list->get_musics());
}
void Queue_state::play()
{
	play_managment->play(queue->get_musics());
}





void State::next()
{
	play_managment->next();
}
void State::previous()
{
	play_managment->previous();
}
void State::pause()
{
	play_managment->pause();
}
void State::shuffle()
{
	play_managment->shuffle();
}
void State::repeat_one()
{
	play_managment->repeat_one();
}
void State::repeat()
{
	play_managment->repeat();
}





void Home::add_to_this_queue(Queue* q)
{
	throw MethodNotAvailable();
}
void PlayLists_state::add_to_this_queue(Queue* q)
{
	throw MethodNotAvailable();
}
void Library_state::add_to_this_queue(Queue* q)
{	
	throw MethodNotAvailable();
}
void Artist_state::add_to_this_queue(Queue* q)
{
	throw MethodNotAvailable();
}
void Album_state::add_to_this_queue(Queue* q)
{
	q->add_album(album);
}
void Music_state::add_to_this_queue(Queue* q)
{
	q->add_music(music);
}
void PlayList_state::add_to_this_queue(Queue* q)
{
	throw MethodNotAvailable();
}
void Queue_state::add_to_this_queue(Queue* q)
{
	throw MethodNotAvailable();
}





void Home::add_to_this_album(Album* a)
{
	throw MethodNotAvailable();
}
void PlayLists_state::add_to_this_album(Album* a)
{
	throw MethodNotAvailable();
}
void Library_state::add_to_this_album(Album* a)
{	
	throw MethodNotAvailable();
}
void Artist_state::add_to_this_album(Album* a)
{
	throw MethodNotAvailable();
}
void Album_state::add_to_this_album(Album* a)
{
	a->add_album(album);
}
void Music_state::add_to_this_album(Album* a)
{
	a->add_music(music);
	music->set_album(a);
}
void PlayList_state::add_to_this_album(Album* a)
{
	throw MethodNotAvailable();
}
void Queue_state::add_to_this_album(Album* a)
{
	throw MethodNotAvailable();
}





void Home::add_to_this_playlist(Play_List* p)
{
	throw MethodNotAvailable();
}
void PlayLists_state::add_to_this_playlist(Play_List* p)
{
	throw MethodNotAvailable();
}
void Library_state::add_to_this_playlist(Play_List* p)
{	
	throw MethodNotAvailable();
}
void Artist_state::add_to_this_playlist(Play_List* p)
{
	throw MethodNotAvailable();
}
void Album_state::add_to_this_playlist(Play_List* p)
{
	p->add_album(album);
}
void Music_state::add_to_this_playlist(Play_List* p)
{
	p->add_music(music);
}
void PlayList_state::add_to_this_playlist(Play_List* p)
{
	throw MethodNotAvailable();
}
void Queue_state::add_to_this_playlist(Play_List* p)
{
	throw MethodNotAvailable();
}




void Home::order_item(string music_name , int index)
{
	throw MethodNotAvailable();
}
void PlayLists_state::order_item(string music_name , int index)
{
	throw MethodNotAvailable();
}
void Library_state::order_item(string music_name , int index)
{	
	throw MethodNotAvailable();
}
void Artist_state::order_item(string music_name , int index)
{
	throw MethodNotAvailable();
}
void Album_state::order_item(string music_name , int index)
{
	throw MethodNotAvailable();
}
void Music_state::order_item(string music_name , int index)
{
	throw MethodNotAvailable();
}
void PlayList_state::order_item(string music_name , int index)
{
	string t="-";
	//string artist_name = music_name.substr(0, name.find(t));
	music_name.erase(0, music_name.find(t) + t.length());
	//string album_name = music_name.substr(0, name.find(t));
	music_name.erase(0, music_name.find(t) + t.length());
	if(play_list->has_this_music(music_name))
		play_list->order_item(music_name , index);
	else
		throw ItemDoesNotExists();
}
void Queue_state::order_item(string music_name , int index)
{
	throw MethodNotAvailable();
}

