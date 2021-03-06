#include <fstream>
#include <iostream>
#include "bird_atd.h"
using namespace std;
namespace animals 
{
	// ???? ?????????? 
	bird* bird_in(ifstream& ifst)
	{
		bird* b = new bird;
		int m;
		string tmp_name = "";
		long tmp_age = 0;

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
		if (m < 0 || m > 1)
		{
			cout << "Error! The range is <0-1>!" << endl;
			exit(1);
		}
		b->m = migr(m);

		ifst >> tmp_age;
		if (ifst.fail())
		{
			cout << "Error! Unexpected end of input!" << endl;
			exit(1);
		}
		if (tmp_age < 0)
		{
			cout << "Error! Age can not be negative!" << endl;
			exit(1);
		}
		b->age = tmp_age;

		return b;
	}

	int NameSize(bird* b)
	{
		return (b->name.size());
	}

	// ????? ?????????? 
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
		ofst << "Age: " << b->age << endl;
		ofst << "Name size: " << NameSize(b) << endl;
	}
} // end animals namespace