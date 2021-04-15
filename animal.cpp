#include <fstream>
#include "animal_atd.h"
#include "fish_atd.h"
#include "bird_atd.h"

using namespace std;
namespace animals {
	// ��������� ��������� ������� �������
	fish* fish_in(ifstream& ifst);
	bird* bird_in(ifstream& ifst);
	// ���� ���������� �� �����
	animal* In(ifstream& ifst)
	{
		animal* an;
		int k;
		ifst >> k;
		switch (k) {
		case 1:
			an = (animal*)fish_in(ifst);
			an->key = FISH;
			break;
		case 2:
			an = (animal*)bird_in(ifst);
			an->key = BIRD;
			break;

		default:
			return 0;
		}
		return an;
	}
	// ��������� ��������� ������� �������.
	void fish_out(struct fish* f, ofstream& ofst);
	void bird_out(struct bird* b, ofstream& ofst);
	
	// ����� ���������� � �����
	bool OutAnimal(animal* a, ofstream& ofst)
	{
		if (a->key == FISH)
		{ 
			fish_out((fish*)a, ofst);
			return true;
		}
		else if (a->key == BIRD)
		{
			bird_out((bird*)a, ofst);
			return true;
		}
		else
		{
			ofst << "Incorrect animal!" << endl;
			return false;
		}
	}
} // end animals namespace