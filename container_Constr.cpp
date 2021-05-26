#include <fstream>
#include "container_atd.h"
using namespace std;
namespace animals {
	// ��������� ��������� ������� �������
	animal* In(ifstream& ifdt);
	// ���� ����������� ���������� �� ���������� ������
	void In(container *c, ifstream& ifst)
	{
		while (!ifst.eof())
		{
			animal* curanimal = In(ifst);
			if (curanimal != 0) {
				c->size++;
				node* curNode = new node;
				curNode->a = curanimal;
				if (c->head != NULL) {
					curNode->next = c->head;
					c->head = curNode;
				}
				else {
					curNode->next = NULL;
					c->head = curNode;
				}
			}
		}
	}

	// ��������� ��������� ������� �������
	bool OutAnimal(animal* a, ofstream& ofst);
	// ����� ����������� ���������� � �������� �����
	bool OutNode(struct node* h, int pos, ofstream& ofst)
	{
		node* curNode = h;

		for (int i = 0; i < pos; i++)
		{
			curNode = curNode->next;
		}

		if (!OutAnimal(curNode->a, ofst))
		{
			ofst << "Cannot to output animal!" << endl;
			return false;
		}

		return true;
	}

	void Out(container* s, ofstream& ofst)
		{
		node* curNode;

		ofst << "Container contains " << s->size << " elements. " << endl;

		ofst << "Only fish." << endl;

		for (int i = 0; i < s->size; i++)
		{
			curNode = s->head;
			for (int j = 0; j < i; j++)
			{
				curNode = curNode->next;
			}
			if (curNode->a->key == FISH)
			{
				if (!OutNode(s->head, i, ofst))
				{
					ofst << "Node is broken!" << endl;
				}
			}
		}
		}

	// ������������� ����������
	void Init(container *c) {
		c->size = 0;
		c->head = NULL;
	}
	// ������� ���������� �� ���������
	void Clear(container *c)
	{
		node* curNode = c->head;

		while (curNode != NULL)
		{
			node* temp = curNode->next;
			delete curNode;
			curNode = temp;
		}
		c->head = NULL;
		c->size = 0;
	}
} // end animals namespace