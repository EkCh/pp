#include <fstream>
#include <iostream>
#include "bird_atd.h"
using namespace std;
namespace animals 
{
	// Ввод параметров 
	bird* bird_in(ifstream& ifst)
	{
		bird* b = new bird;
		int m;
		string tmp_name = "";

		ifst >> tmp_name;
		if (ifst.fail())
		{
			cout << "Error! Unexpected end of input!" << endl;
			exit(1);
		}
		b->name = tmp_name;

		ifst >> m;
		if (ifst.fail())
		{
			cout << "Error! Unexpected end of input!" << endl;
			exit(1);
		}
		b->m = migr(m);

		return b;
	}

	int NameSize(bird* b)
	{
		return (b->name.size());
	}

	// Вывод параметров 
	void bird_out(struct bird* b, ofstream& ofst)
	{
		ofst << "It is bird: " << b->name << ", it is ";
		switch (b->m) {
		case MIGRANT: 
			ofst << "migrant" << endl;
			break;
		case NONMIGRANT: 
			ofst << "nonmigrant" << endl;
			break;
		}
		ofst << "Name size: " << NameSize(b) << endl;
	}
} // end animals namespace