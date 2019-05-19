#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "person.h"
#include "music.h"
#include "exception.h"

using namespace std;

Person::Person(UserData _user_data , string _password)
{
	user_data = _user_data;
	password = _password;
	activated = false;
	accepted = false;
	queue = new Queue("queue");
}
Person::Person(Person* p)
{
	user_data =p->user_data;
	password = p->password;
	activated = p->activated;
}
bool Person::is_same_person(string _username, string _password)
{
	return user_data.username == _username && password == _password ;
}
void Person::active()
{
	activated = true;
}
void Person::accept()
{
	accepted = true;
}
void Person::deactive()
{
	activated = false;
}
bool Person::is_active()
{
	return activated;
}
bool Person::same_username(string _username)
{
	return user_data.username == _username;
}
UserData Person::get_details()
{
	if(accepted)
		return user_data ;
	else
	{
		UserData temp = user_data;
		temp.userType = _Normal;
		return temp;
	}
}
vector<Play_List*> Person::get_playlist()
{
	return play_lists;
}
string Person::get_name()
{
	return user_data.username;
}
bool Person::has_this_playlist(string name)
{
	for(int i=0 ; i<play_lists.size() ; i++)
		if(play_lists[i]->get_name() == name)
			return true;
	return false;
}
void Person::add_playlist(Play_List* p)
{
	play_lists.push_back(p);
}
void Person::clear_playlist(string name)
{
	for(int i=0 ; i<play_lists.size() ;i++)
		if(play_lists[i]->get_name() == name)
			play_lists[i]->clear();
}
Play_List* Person::get_this_playlist(string _name)
{
	for(int i=0 ; i<play_lists.size() ; i++)
		if(play_lists[i]->get_name() == _name)
			return play_lists[i];
	throw ItemDoesNotExists();
}
Queue* Person::get_queue()
{
	return queue;
}

List Person::get_playlist_comp_name()
{
	List temp;
	for(int i = 0 ; i<play_lists.size() ; i++)
	{
		string temp2=get_name();
		temp2+="-";
		temp2+=play_lists[i]->get_name();
		temp.push_back(temp2);
	}
	return temp;
}

bool Artist::is_artist()
{
	return accepted ;
}
void Artist::add_music(Music* m)
{
	bool exsit=false;
	for(int i=0; i<musics.size() ; i++)
		if(musics[i]->get_name() == m->get_name())
			exsit=true;
	if(!exsit)
		musics.push_back(m);
}
void Artist::add_album(Album* a)
{
	bool exsit=false;
	for(int i=0; i<albums.size() ; i++)
		if(albums[i]->get_name() == a->get_name())
			exsit=true;
	if(!exsit)
		albums.push_back(a);
}
List Artist::album_list()
{
	List temp;
	for(int i=0; i<albums.size() ; i++)
		//if(albums[i]->is_accepted())
			temp.push_back(albums[i]->get_name());
	return temp;
}
List Artist::music_list()
{
	List temp1;
	for(int i=0; i<musics.size() ; i++)
		//if(musics[i]->is_accepted())
			temp1.push_back(musics[i]->get_name());

	List temp2;
	for(int i=0; i<albums.size() ; i++)
	{
		// if(albums[i]->is_accepted())
		// {
			temp2 = albums[i]->music_list();
			for(int j=0 ; j<temp2.size() ; j++)
				temp1.push_back (temp2[j]);
		// }
	}
	sort( temp1.begin(),temp1.end() );
	temp1.erase( unique( temp1.begin(), temp1.end() ), temp1.end() );

	return temp1;
}
List Artist::list_musics_comp_name()
{
	List temp1;
	for(int i=0; i<musics.size() ; i++)
	{
		//if(musics[i]->is_accepted())
			string temp=musics[i]->artist_name();
			temp+="-";
			temp+=musics[i]->album_name();
			temp+="-";
			temp+=musics[i]->get_name();
			temp1.push_back(temp);

	}
	List temp2;
	for(int i=0; i<albums.size() ; i++)
	{
		// if(albums[i]->is_accepted())
		// {
			temp2 = albums[i]->music_comp_name_list();
			for(int j=0 ; j<temp2.size() ; j++)
				temp1.push_back (temp2[j]);
		// }
	}
	sort( temp1.begin(),temp1.end() );
	temp1.erase( unique( temp1.begin(), temp1.end() ), temp1.end() );
	return temp1;
}
void Artist::rate(int score ,Person* p)
{
	rates[p->get_name()] = score;
}
int Artist::get_rate(Person* p)
{
	return rates[p->get_name()];
}
vector<Music*> Artist::get_musics()
{
	vector<Music*> temp , temp2;
	for(int i =0 ; i<musics.size() ; i++)
		temp.push_back(musics[i]);
	for(int i =0 ; i<albums.size() ; i++)
	{
		temp2 = albums[i]->get_musics();
		bool exsit=false;
		for(int i=0; i<temp.size() ; i++)
		{	
			for(int j=0 ; j<temp2.size() ; j++)
				if(temp2[i]->get_name() == temp[j]->get_name())
					exsit=true;
			if(!exsit)
				temp.push_back(temp2[i]);
		}
	}
	return temp;
}
bool Artist::has_this_album(string name)
{
	for(int i=0 ; i<albums.size() ; i++)
		if(albums[i]->get_name() == name)
			return true;
	return false;
}
Album* Artist::get_this_album(string name)
{
	for(int i=0 ; i<albums.size() ; i++)
		if(albums[i]->get_name() == name)
			return albums[i];
}
