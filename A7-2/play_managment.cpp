#include <vector>
#include "music.h"
#include "play_managment.h"

using namespace std;


void Play_managment::play(Music* music)
{
	list.clear();
	list.push_back(music);
	start_playing();
}
void Play_managment::play(vector<Music*> _list)
{
	list.clear();
	for(int i=0 ; i<_list.size(); i++)
		list.push_back(_list[i]);
	start_playing();
}
void Play_managment::start_playing()//doesn't work!
{
	for(int i=0 ; i<list.size() ; i++)
		list[i]->play();
}
void Play_managment::shuffle()
{
	_shuffle=true;
}
void Play_managment::repeat_one()
{
	_repeat_one=true;
}
void Play_managment::repeat()
{
	_repeat_all=true;
}