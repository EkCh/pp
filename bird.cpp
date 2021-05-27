#include <fstream>
#include "bird_atd.h"
using namespace std;
namespace animals {
	// ���� ���������� 
	bird* bird_in(ifstream& ifst)
	{
		bird* b = new bird;
		int m;
		ifst >> b->name >> m;
		b->m = migr(m);
		return b;
	}

	int NameSize(bird* b)
	{
		return (b->name.size());
	}

	// ����� ���������� 
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