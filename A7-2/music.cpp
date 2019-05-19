#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "person.h"
#include "music.h"
#include "exception.h"
using namespace std;


Music::Music(string _name, string _file_path , Artist* p)
	:artist(p)
{
	name = _name ;
	file_path = _file_path ;
	accepted = false ;
}
string Music::artist_name()
{
	return artist->get_name();
}
string Music::get_name()
{
	return name;
}
string Music::album_name()
{
	return album->get_name();
}
Artist* Music::get_artist()
{
	return artist;
}
Album* Music::get_album()
{
	return album;
}
void Music::accept()
{
	accepted=true;
}
void Music::rate(int score , Person* p)
{
	rates[p->get_name()]=score;
}
int Music::get_rate(Person* p)
{
	return rates[p->get_name()];
}



bool List_Of_Musics::has_this_music(string name)
{
	for(int i=0 ; i<list.size() ; i++)
	{
		// if(list[i]->is_accepted())
			if(list[i]->get_name() == name)
				return true;
	}
	return false;
}
Music* List_Of_Musics::find_music(string name)
{
	for(int i=0 ; i<list.size() ; i++)
		//if(list[i]->is_accepted())
			if(list[i]->get_name() == name)
				return list[i];
}
List List_Of_Musics::music_list()
{
	List temp;
	for(int i =0 ; i<list.size() ; i++)
		//if(list[i]->is_accepted())
			temp.push_back(list[i]->get_name());

	return temp;
}
List List_Of_Musics::music_comp_name_list()
{
	List temp;
	string temp2;
	for(int i =0 ; i<list.size() ; i++)
	{
		// if(list[i]->is_accepted())
		// {
			temp2=list[i]->artist_name();
			temp2+="-";
			temp2+=list[i]->album_name();
			temp2+="-";
			temp2+=list[i]->get_name();
			temp.push_back(temp2);
		// }
	}
	return temp;
}
string List_Of_Musics::get_name()
{
	return name;
}
void List_Of_Musics::clear()
{
	list.clear();
}
void List_Of_Musics::remove_music(string name)
{
	int i;
	for(i=0 ; i<list.size() ;i++)
		// if(list[i]->is_accepted())
			if(list[i]->get_name() == name)
				break;
	vector<Music*> temp;
	for(int j=0 ; j<list.size() ;j++)
		if(j != i)
			temp.push_back(list[j]);
	list.clear();
	list = temp;
}
vector<Music*> List_Of_Musics::get_musics()
{
	return list;
}
void List_Of_Musics::add_music(Music* m)
{
	if(!has_this_music(m->get_name()))
		list.push_back(m);
}
void List_Of_Musics::add_album(Album* a)
{
	for(int i=0 ; i<a->list.size() ; i++)
		if(!has_this_music(a->list[i]->get_name()))
			list.push_back(a->list[i]);
}
void Album::add_album(Album* a)
{
	for(int i=0 ; i<a->list.size() ; i++)
		if(!has_this_music(a->list[i]->get_name()))
		{
			list.push_back(a->list[i]);
			a->list[i]->set_album(this);
		}
}

string Album::get_comp_name()
{
	string temp = artist_name();
	temp+="-";
	temp += get_name();
	return temp;
}


List Play_List::list_albums()
{
	List temp;
	for(int i = 0 ; i<list.size() ; i++)
		// if(list[i]->is_accepted())
			temp.push_back(list[i]->album_name());
	return temp;
}
List Play_List::list_albums_comp_name()
{
	List temp;
	for(int i = 0 ; i<list.size() ; i++)
		// if(list[i]->is_accepted())
	{
		string temp2=list[i]->artist_name();
		temp2+="-";
		temp2+=list[i]->album_name();
		temp.push_back(temp2);
	}
	return temp;
}
void Play_List::order_item(string music_name , int index)
{
	if(index < 0 || index >=list.size())
		throw InvalidArguments();
	Music* temp = find_music(music_name);
	list.insert(list.begin()+index , temp);
}
List Queue::list_albums()
{
	List temp;
	for(int i = 0 ; i<list.size() ; i++)
		// if(list[i]->is_accepted())
			temp.push_back(list[i]->album_name());
	return temp;
}
List Queue::list_albums_comp_name()
{
	List temp;
	for(int i = 0 ; i<list.size() ; i++)
		// if(list[i]->is_accepted())
	{
		string temp2=list[i]->artist_name();
		temp2+="-";
		temp2+=list[i]->album_name();
		temp.push_back(temp2);
	}
	return temp;
}

string Album::artist_name()
{
	return artist->get_name();
}

Artist* Album::get_artist()
{
	return artist;
}
void Album::rate(int score , Person* p)
{
	rates[p->get_name()]= score;
}
int Album::get_rate(Person* p)
{
	return rates[p->get_name()];
}
bool Album::has_this_artist(Person* p)
{
	if(artist->get_name() == p->get_name())
		return true;
	else
		return false;
}
void Album::accept()
{
	accepted=true;
	for(int i=0 ; i< list.size() ; i++)
		list[i]->accept();
}




void Library::add_music(Music* music)
{
	musics.push_back(music);
}
void Library::add_album(Album* album)
{
	albums.push_back(album);
}
List Library::artist_list()
{
	List temp;
	for(int i = 0 ; i< artists.size() ; i++)
	{
		temp.push_back(artists[i]->get_name());
	}
	return temp;
}
List Library::music_list()
{
	List temp1;
	for(int i=0; i<musics.size() ; i++)
		// if(musics[i]->is_accepted())
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
List Library::album_list()
{
	List temp;
	for(int i=0; i<albums.size() ; i++)
		// if(albums[i]->is_accepted())
			temp.push_back(albums[i]->get_name());
	return temp;
}
bool Library::has_this_music(string _name)
{
	for(int i = 0 ; i< musics.size() ; i++)
		// if(musics[i]->is_accepted())
			if(musics[i]->get_name() == _name)
				return true;
	return false;
}
bool Library::include_this_music(string _name)
{
	for(int i = 0 ; i< musics.size() ; i++)
		if(musics[i]->get_name() == _name)
			return true;
	return false;
}
Music* Library::find_music(string _name)
{
	for(int i=0 ; i <musics.size() ; i++ )
		//if(musics[i]->is_accepted())
			if(musics[i]->get_name() == _name)
					return musics[i];

	for(int i=0 ; i <albums.size() ; i++ )
		//if(albums[i]->is_accepted())
			if(albums[i]->has_this_music(_name))
				return albums[i]->find_music(_name);
}
bool Library::has_this_album(string _name)
{
	for(int i = 0 ; i< albums.size() ; i++)
		// if(albums[i]->is_accepted())
			if(albums[i]->get_name() == _name)
				return true;
	return false;
}
bool Library::include_this_album(string _name)
{
	for(int i = 0 ; i< albums.size() ; i++)
		if(albums[i]->get_name() == _name)
			return true;
	return false;
}
Album* Library::find_album(string _name)
{
	for(int i=0 ; i <albums.size() ; i++ )
		// if(albums[i]->is_accepted())
			if(albums[i]->get_name() == _name)
				return albums[i];
}
bool Library::has_this_artist(string _name)
{
	List artists=artist_list();
	for(int i = 0 ; i< artists.size() ; i++)
		if(artists[i] == _name)
			return true;
	return false;
}
Artist* Library::find_artist(string _name)
{
	int i;
	List artists_list=artist_list();
	for(i = 0 ; i< artists_list.size() ; i++)
		if(artists_list[i] == _name)
			break;
	if(i < musics.size()-1)
		return musics[i]->get_artist();
	else
	{
		i=i-musics.size();
		return albums[i]->get_artist();

	}
}
List Library::music_comp_name_list()
{
	List temp1;
	string temp11;
	for(int i=0; i<musics.size() ; i++)
	{
		// if(musics[i]->is_accepted())
		// {
			temp11=musics[i]->artist_name();
			//cout<<"musics[i]->artist_name()"<<endl;
			temp11+="-";
			temp11+=musics[i]->album_name();
			temp11+="-";
			temp11+=musics[i]->get_name();
			temp1.push_back(temp11);
		// }
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
List Library::albums_list_comp_name()
{
	List temp;
	for(int i= 0 ; i<albums.size() ; i++)
		// if(albums[i]->is_accepted())
			temp.push_back(albums[i]->get_comp_name());
	return temp;
}
List Library::get_albums_comp_name(string name)
{
	List temp;
	for(int i= 0 ; i<albums.size() ; i++)
		// if(albums[i]->is_accepted())
			if(albums[i]->get_comp_name() == name)
				temp.push_back(albums[i]->get_comp_name());
	return temp;
}

void Library::add_artist(Artist* a)
{
	artists.push_back(a);
}

