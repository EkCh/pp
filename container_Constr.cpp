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

	int NameSize(animal* a);

	bool Compare(animal* a1, animal* a2)
	{
		return NameSize(a1) < NameSize(a2);
	}

	node* GetNode(node* head, int index)
	{
		struct node* returnNode = head;

		for (int i = 0; i < index; i++)
		{
			returnNode = returnNode->next;
		}
		return returnNode;
	}

	void Swap(node* head, int index_first, int index_second)
	{
		struct node* temp = new node;

		temp->a = GetNode(head, index_first)->a;
		GetNode(head, index_first)->a = GetNode(head, index_second)->a;
		GetNode(head, index_second)->a = temp->a;
	}

	void Sort(int size, struct node* head)
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (Compare(GetNode(head, i)->a, GetNode(head, j)->a))
				{
					Swap(head, i, j);
				}
			}
		}
	}

	void Out(struct container* s, ofstream& ofst)
	{		
		ofst << "Container contains " << s->size << " elements. " << endl;
		
		for (int i = 0; i < s->size; i++) 
		{
			ofst << i << ": ";
			OutNode(s->head, i, ofst);
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