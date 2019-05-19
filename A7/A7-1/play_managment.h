#ifndef _PLAY_MANAGMENT_H_

#define _PLAY_MANAGMENT_H_
#include <vector>
using namespace std;
class Music;

class Play_managment{
public:
	void play(Music* music);
	void play(vector<Music*> _list);
	void start_playing();
	void next(){}
    void previous(){}
    void pause(){}
    void shuffle();
    void repeat_one();
    void repeat();

private:

	bool _shuffle;
	bool _repeat_all;
	bool _repeat_one;
	vector<Music*> list;
	
};

#endif