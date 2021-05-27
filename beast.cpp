#include <fstream>
#include <iostream>
#include "beast_atd.h"

using namespace std;
namespace animals 
{
	// Ввод параметров 
	beast* beast_in(ifstream& ifst)
	{
		beast* bst = new beast;
		int p;
		string tmp_name = "";

		ifst >> tmp_name;
		if (ifst.fail())
		{
			cout << "Error! Unexpected end of input!" << endl;
			exit(1);
		}
		bst->name = tmp_name;

		ifst >> p;
		if (ifst.fail())
		{
			cout << "Error! Unexpected end of input!" << endl;
			exit(1);
		}
		bst->p = pref(p);

		return bst;
	}

	// Вывод параметров 
	void beast_out(struct beast* bst, ofstream& ofst)
	{
		ofst << "It is beast: " << bst->name << ", it is ";
		switch (bst->p) {
		case PREDATOR:
			ofst << "predator" << endl;
			break;
		case HERBIVORE:
			ofst << "herbivore" << endl;
			break;
		case INSECTIVORE:
			ofst << "insectivore" << endl;
			break;
		}
	}
} // end animals namespace