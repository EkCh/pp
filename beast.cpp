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
		long tmp_age = 0;

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
		if (p < 0 || p > 2)
		{
			cout << "Error! The range is <0-2>!" << endl;
			exit(1);
		}
		bst->p = pref(p);

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
		bst->age = tmp_age;

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
		ofst << "Age: " << bst->age << endl;
	}
} // end animals namespace