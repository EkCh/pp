#include <fstream>
#include "fish_atd.h"
using namespace std;
namespace animals {
	// Ввод параметров 
	fish* fish_in(ifstream& ifst)
	{
		fish* f = new fish;
		int h;
		ifst >> f->name >> h;
		f->h = habitat(h);
		return f;
	}
	// Вывод параметров 
	void fish_out(struct fish* f, ofstream& ofst)
	{
		ofst << "It is fish: " << f->name << ", it lives in ";
		switch (f->h) {
		case RIVER: 
			ofst << "river" << endl;
			break;
		case SEA: 
			ofst << "sea" << endl;
			break;
		case LAKE: 
			ofst << "lake" << endl;
			break;
		}
	}
} // end animals namespace