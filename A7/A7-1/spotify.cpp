#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "person.h"
#include "music.h"
#include "state.h"
#include "spotify.h"
#include "exception.h"
using namespace std;


void Spotify::signup(UserData _user_data, string _password)
{
	if( not_registered(_user_data.username) )
	{
		Person* p ;
		if(_user_data.userType == _Admin)
			p = new Admin(_user_data , _password);
	
		else if(_user_data.userType == _Artist)
		{
			p = new Artist(_user_data , _password);
			library.add_artist((Artist*)p);
		}
	
		else if(_user_data.userType == _Normal)
			p = new Normal(_user_data , _password);
	
		else if(_user_data.userType == _Editor)
			p = new Editor(_user_data , _password);
	
		users.push_back(p);
	}
	else
		throw AlreadyExists();
}
bool Spotify::not_registered(string username)
{
	for(int i=0; i<users.size() ; i++)
		if(users[i]->get_name() == username )
			return false;
	return true;
}
void Spotify::deactive_users()
{
	for(int i=0 ; i<users.size() ; i++)
		if( users[i]->is_active() )
			users[i]->deactive();
}
void Spotify::login(string _username, string _password)
{
	deactive_users();
	bool found=false;
	for(int i=0 ; i<users.size() ; i++)
	{
		if(users[i]->is_same_person( _username, _password))
		{
			users[i]->active();
			found=true;
			break;
		}
	}
	if(!found)
		throw InvalidCredentials();
}

void Spotify::add_music(string _name, string _file_path)
{
	Person *p = find_active_person();
	if(p->is_artist())
	{
		Music* m = new Music( _name, _file_path ,(Artist*) p);
		p->add_music(m);
		library.add_music(m);
	}	
	else
	{
		throw NotAuthorized();
	}	
}
void Spotify::add_album(string _artist_name , string _album_name)
{
	Person *p = find_active_person();
	if(p->is_artist())
	{
		Album* a = new Album( _album_name ,(Artist*) p);
		p->add_album(a);
		library.add_album(a);
	}	
	else
	{
		throw NotAuthorized();
	}
}
Person* Spotify::find_active_person()
{
	for(int i=0 ; i<users.size() ; i++)
		if(users[i]->is_active())
			return users[i];
}
UserData Spotify::get_user_detils(string username)
{
	for(int i=0 ; i<users.size() ; i++)
		if(users[i]->same_username(username))
			return users[i]->get_details();

	throw MethodNotAvailable();
}
void Spotify::enter_browser_mode()
{
	mode = "Browser";
}
void Spotify::go_to_home()
{
	if(mode == "Browser")
		state = new Home ;
	else
		throw MethodNotAvailable();
}
void Spotify::go_to_playlists()
{
	
	if(mode == "Browser" && state->is_home())
	{
		delete state;
		state = new PlayLists_state ;
		Person *p = find_active_person();
		state->go_to_playlists(p);
	}
	else 
		throw MethodNotAvailable();
}
void Spotify::go_to_library()
{
	
	if(mode == "Browser" && state->is_home())
	{
		delete state;
		state = new Library_state ;
		state->go_to_library(library);
	}
	else
		throw MethodNotAvailable();
		
}
void Spotify::go_to_album()
{
	if(mode == "Browser")
	{
		Album* a = state->get_album();
		delete state;
		state = new Album_state ;
		state->go_to_album(a);
	}
	else
		throw MethodNotAvailable();
}
void Spotify::go_to_artist()
{
	if(mode == "Browser")
	{
		Artist* a = state->get_artist();
		delete state;
		state = new Artist_state;
		state->go_to_artist(a);
	}
	else
		throw MethodNotAvailable();
}
void Spotify::select(string _name)
{
	if(mode == "Browser")
	{
		Person *person = find_active_person();
		if(library.has_this_music(_name)||(library.include_this_music(_name) && person->is_admin() ))
		{

			delete state;
			state = new Music_state ;
			// cout<<"inside"<<endl;
			Music *m = library.find_music(_name);
			// cout<<m->is_accepted()<<endl;
			state->go_to_music(m);
		}
		else if(library.has_this_album(_name) ||(library.include_this_music(_name) && person->is_admin() ))
		{
			delete state;
			state = new Album_state ;
			Album *a = library.find_album(_name);
			state->go_to_album(a);
		}
		else if(library.has_this_artist(_name))
		{
			delete state;
			state = new Artist_state ;
			Artist *a = library.find_artist(_name);
			state->go_to_artist(a);
		}
		else if(person->has_this_playlist(_name))
		{
			Play_List* p = person->get_this_playlist(_name);
			delete state;
			state = new PlayList_state;
			state->go_to_playlist(p);
		}
		else
			throw ItemDoesNotExists();
	}
	else
		throw MethodNotAvailable();
}

List Spotify::list()
{
	if(mode == "Browser")
	{
		return state->list();
	}
	else
		throw MethodNotAvailable();
}
List Spotify::list_playlists()
{
	if(mode == "Browser")
	{
		return state->list_playlists();
	}
	else
		throw MethodNotAvailable();
}

List Spotify::list_artists()
{
	if(mode == "Browser")
	{
		return state->list_artists();
	}
	else
		throw MethodNotAvailable();
}
string Spotify::get_artist()
{
	if(mode == "Browser")
	{
		return state->get_artist_name();
	}
	else
		throw MethodNotAvailable();
}
string Spotify::get_name()
{
	if(mode == "Browser")
	{
		return state->get_name();
	}
	else
		throw MethodNotAvailable();
}
string Spotify::get_complete_name()
{
	if(mode == "Browser")
	{
		Person *person = find_active_person();
		return state->get_complete_name(person);
	}
	else
		throw MethodNotAvailable();
}
string Spotify::get_album()
{
	if(mode == "Browser")
	{
		return state->get_album_name();
	}
	else
		throw MethodNotAvailable();
}
List Spotify::list_musics()
{
	if(mode == "Browser")
	{
		return state->list_musics();
	}
	else
		throw MethodNotAvailable();
}
List Spotify::list_musics_comp_name()
{
	if(mode == "Browser")
	{
		return state->list_musics_comp_name();
	}
	else
		throw MethodNotAvailable();
}
List Spotify::list_albums()
{
	if(mode == "Browser")
	{
		return state->list_albums();
	}
	else
		throw MethodNotAvailable();
}
List Spotify::list_albums_comp_name()
{
	if(mode == "Browser")
	{
		return state->list_albums_comp_name();
	}
	else
		throw MethodNotAvailable();
}
void Spotify::rate(int score) 
{
	if(mode == "Browser")
	{
		if(score>=1 && score<=10)
		{
			Person *p = find_active_person();
			state->rate(score ,p );
		}
		else
			throw InvalidArguments();
	}
	else
		throw MethodNotAvailable(); 
}
int Spotify::get_rate()
{
	if(mode == "Browser")
	{
		Person *p = find_active_person();
		return state->get_rate(p);
	}
	else
		throw MethodNotAvailable();
}
int Spotify::get_user_rate()
{
	if(mode == "Browser")
	{
		return state->get_user_rate(users);
	}
}
int Spotify::get_critic_rate()
{
	if(mode == "Browser")
	{
		return state->get_critic_rate(users);
	}
	else
		throw MethodNotAvailable();
}
void Spotify::create_playlist(string _name)
{
	if(mode == "Browser")
	{
		Person *person = find_active_person();
		if(! person->has_this_playlist(_name))
		{
			Play_List * p = new Play_List(_name);
			person->add_playlist(p);
		}
		else
			throw AlreadyExists();
	}
	else
		throw MethodNotAvailable(); 
}
void Spotify::clear_playlist(string _name)
{
	if(mode == "Browser")
	{
		Person *person = find_active_person();
		person->clear_playlist(_name);
	}
	else
		throw MethodNotAvailable();
}
void Spotify::remove(string music_complete_name)
{
	if(mode == "Browser")
	{
		Person *person = find_active_person();
		state->remove( person , music_complete_name );
	}
	else
		throw MethodNotAvailable();
}

List Spotify::search(string name)
{
	List temp1 , temp2;
	int counter = count(name , '-');
	if(counter == 0)
	{
		temp2 = library.artist_list();
		for(int i= 0 ; i<temp2.size() ; i++)
			if(temp2[i] == name)
				temp1.push_back(temp2[i]);
	}
	else if(counter == 1)
	{
		temp1 = library.get_albums_comp_name(name);
		for(int i=0 ; i<users.size() ; i++)
		{
			temp2 = users[i]->get_playlist_comp_name();
			for(int i= 0 ; i<temp2.size() ; i++)
				if(temp2[i] == name)
					temp1.push_back(temp2[i]);
		}
	}
	else if(counter == 2)
	{
		temp2 = library.music_comp_name_list();
		for(int i= 0 ; i<temp2.size() ; i++)
			if(temp2[i] == name)
				temp1.push_back(temp2[i]);
	}
	sort( temp1.begin(),temp1.end() );
	temp1.erase( unique( temp1.begin(), temp1.end() ), temp1.end() );
	return temp1;
}
int Spotify::count(string name , char delimeter)
{
	int counter=0;
	for(int i=0 ; i<name.size() ; i++)
		if(name[i] == delimeter)
			counter++;
	return counter;
}
void Spotify::go_to(string name)
{
	if(mode == "Browser")
	{
		bool exist=false;
		Person *person = find_active_person();
		if(name == "queue")
		{
			exist=true;
			Queue* q = person->get_queue();
			delete state;
			state = new Queue_state;
			state->go_to_queue(q);
		}
		else
		{
			if(person->has_this_playlist(name))
			{
				exist=true;
				Play_List* p=person->get_this_playlist(name);
				delete state;
				state = new PlayList_state;
				state->go_to_playlist(p);
			}
			else
				throw ItemDoesNotExists();
		}
		if(!exist)
			throw ItemDoesNotExists();
	}
	else 
		throw MethodNotAvailable();
}
void Spotify::verify_user(string name)
{
	Person *person = find_active_person();
	if(person->is_admin())
	{
		Person* p = find_person(name);
		p->accept();
	}
	else 
		throw MethodNotAvailable();

}
Person* Spotify::find_person(string name)
{
	for(int i=0 ; i<users.size() ; i++)
		if(users[i]->get_name() == name)
			return users[i];
	throw ItemDoesNotExists();
}
void Spotify::validate()
{
	Person *person = find_active_person();
	if(person->is_admin())
		state->validate();
	else
		throw NotAuthorized();
}
void Spotify::play()
{
	if(mode == "Browser")
	{
		mode = "play";
		state->play();
	}
	else
		throw MethodNotAvailable();
}
void Spotify::next()
{
	if(mode == "play")
		state->next();
	else
		MethodNotAvailable();
}
void Spotify::previous()
{
	if(mode == "play")
		state->previous();
	else
		throw MethodNotAvailable();
}
void Spotify::pause()
{
	if(mode == "play")
		state->pause();
	else
		throw MethodNotAvailable();
}
void Spotify::shuffle()
{
	if(mode == "play")
		state->shuffle();
	else
		throw MethodNotAvailable();
}
void Spotify::repeat_one()
{
	if(mode == "play")
		state->repeat_one();
	else
		throw MethodNotAvailable();
}
void Spotify::repeat()
{
	if(mode == "play")
		state->repeat();
	else
		throw MethodNotAvailable();
}
void Spotify::add_to(string name)
{
	if(mode == "Browser")
	{
		bool exist=false;
		Person *person = find_active_person();
		if(name == "queue")
		{
			exist = true;
			state->add_to_this_queue(person->get_queue());
		}
		else if(count(name , '-') == 1)
		{
			string t="-";
			string user_name = name.substr(0, name.find(t));
			name.erase(0, name.find(t) + t.length());
			if(person->is_artist() && user_name == person->get_name())
			{
				if(person->has_this_album(name))
				{
					exist = true;
					Album* a = ((Artist*)person)->get_this_album(name);
					state->add_to_this_album(a);
				}
			}
			else if(user_name == person->get_name())
			{
				if(person->has_this_playlist(name))
				{
					exist = true;
					Play_List* p = person->get_this_playlist(name);
					state->add_to_this_playlist(p);
				}
			}
			else
				throw NotAuthorized();
		}
		else if(!exist)
			throw ItemDoesNotExists();
	}
	else
		throw MethodNotAvailable();
}
void Spotify::order_item(string music_name, int index)
{
	if(mode=="Browser")
	{
		state->order_item(music_name , index);
	}
	else
		throw MethodNotAvailable();
}