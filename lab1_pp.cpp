#include "container_atd.h"
#include <iostream>
#include <fstream>

using namespace std;
namespace animals 
{
	// Сигнатуры требуемых внешних функций
	void Init(container* c);
	void Clear(container* c);
	void In(container* c, ifstream& ifst);
	void Out(container* c, ofstream& ofst);
	void OutFish(container* c, ofstream& ofst);
	void Sort(int size, struct node* head);
}
using namespace animals;

int main(int argc, char* argv[]) 
{
	if (argc != 3) 
	{
		cout << "incorrect command line! "
			"Waited: command infile outfile" << endl;

		exit(1);
	}

	ifstream ifst(argv[1]);
	if (!ifst)
	{
		cout << "No input file found!" << endl;
		return 0;
	}

	ofstream ofst(argv[2]);
	if (!ofst)
	{
		cout << "No output file found!" << endl;
		return 0;
	}

	cout << "Start" << endl;
	container* c = new container;
	Init(c);
	In(c, ifst);

	ofst << "Filled container. " << endl;
	Out(c, ofst);

	Sort(c->size, c->head);
	ofst << "\nSorted container. " << endl;
	Out(c, ofst);
	
	ofst << "\nFiltered container." << endl;
	OutFish(c, ofst);

	Clear(c);
	ofst << "Empty container. " << endl;

	Out(c, ofst);
	cout << "Stop" << endl;

	return 0;
}