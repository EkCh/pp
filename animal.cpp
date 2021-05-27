#include <fstream>
#include "animal_atd.h"
#include "fish_atd.h"
#include "bird_atd.h"
#include "beast_atd.h"

using namespace std;
namespace animals {
	// Сигнатуры требуемых внешних функций
	fish* fish_in(ifstream& ifst);
	bird* bird_in(ifstream& ifst);
	beast* beast_in(ifstream& ifst);
	// Ввод параметров из файла
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
		case 3:
			an = (animal*)beast_in(ifst);
			an->key = BEAST;
			break;

		default:
			return 0;
		}
		ifst >> an->age;
		return an;
	}
	// Сигнатуры требуемых внешних функций.
	void fish_out(struct fish* f, ofstream& ofst);
	void bird_out(struct bird* b, ofstream& ofst);
	void beast_out(struct beast* bst, ofstream& ofst);
	
	// Вывод параметров в поток
	bool OutAnimal(animal* a, ofstream& ofst)
	{
		if (a->key == FISH)
		{
			fish_out((fish*)a, ofst);
			ofst << " Age: " << a->age << endl;
			return true;
		}
		else if (a->key == BIRD)
		{
			bird_out((bird*)a, ofst);
			ofst << " Age: " << a->age << endl;
			return true;
		}
		else if (a->key == BEAST)
		{
			beast_out((beast*)a, ofst);
			return true;
		}
		else
		{
			ofst << "Incorrect animal!" << endl;
			return false;
		}
	}
} // end animals namespace