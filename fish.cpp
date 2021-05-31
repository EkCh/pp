#include <fstream>
#include <iostream>
#include "fish_atd.h"
using namespace std;
namespace animals 
{
	// Ввод параметров 
	fish* fish_in(ifstream& ifst)
	{
		fish* f = new fish;
		int h;
		string tmp_name = "";
		long tmp_age = 0;

		ifst >> tmp_name;
		if (ifst.fail())
		{
			cout << "Error! Unexpected end of input!" << endl;
			exit(1);
		}
		f->name = tmp_name;

		ifst >> h;
		if (ifst.fail())
		{
			cout << "Error! Unexpected end of input!" << endl;
			exit(1);
		}
		f->h = habitat(h);

		ifst >> tmp_age;
		if (ifst.fail())
		{
			cout << "Error! Unexpected end of input!" << endl;
			exit(1);
		}
		f->age = tmp_age;

		return f;
	}

	int NameSize(fish* f)
	{
		return (f->name.size());
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
		ofst << "Age: " << f->age << endl;
		ofst << "Name size: " << NameSize(f) << endl;
	}
} // end animals namespace