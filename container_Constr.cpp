#include <fstream>
#include <iostream>
#include "container_atd.h"
using namespace std;
namespace animals 
{
	// Сигнатуры требуемых внешних функций
	animal* In(ifstream& ifst);

	// Ввод содержимого контейнера из указанного потока
	void In(container *c, ifstream& ifst)
	{
		while (!ifst.eof())
		{
			animal* curanimal = In(ifst);
			if (curanimal != 0) 
			{
				c->size++;
				node* curNode = new node;
				curNode->a = curanimal;
				if (c->head != NULL) 
				{
					curNode->next = c->head;
					c->head = curNode;
				}
				else 
				{
					curNode->next = NULL;
					c->head = curNode;
				}
			}
		}
	}

	// Сигнатуры требуемых внешних функций
	bool OutAnimal(animal* a, ofstream& ofst);

	// Вывод содержимого контейнера в указаный поток
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

	void OutFish(container* s, ofstream& ofst)
	{
		node* curNode;

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

	// Инициализация контейнера
	void Init(container *c) 
	{
		c->size = 0;
		c->head = NULL;
	}

	// Очистка контейнера от элементов
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

	void Multimethod(struct container* s, ofstream& ofst)
	{
		struct node* curr_node;
		ofst << "Multimethod" << endl;

		for (int i = 0; i < s->size - 1; i++)
		{
			for (int j = i + 1; j < s->size; j++)
			{
				curr_node = GetNode(s->head, i);
				switch (curr_node->a->key) {
				case FISH:
					curr_node = GetNode(s->head, j);
					switch (curr_node->a->key) {
					case FISH:
						ofst << "Fish and fish" << endl;
						break;
					case BIRD:
						ofst << "Fish and bird" << endl;
						break;
					case BEAST:
						ofst << "Fish and beast" << endl;
						break;
					default:
						ofst << "Unknown key" << endl;
						break;
					}
					break;
				case BIRD:
					curr_node = GetNode(s->head, j);
					switch (curr_node->a->key) {
					case FISH:
						ofst << "Bird and fish" << endl;
						break;
					case BIRD:
						ofst << "Bird and bird" << endl;
						break;
					case BEAST:
						ofst << "Bird and beast" << endl;
						break;
					default:
						ofst << "Unknown key" << endl;
						break;
					}
					break;
				case BEAST:
					curr_node = GetNode(s->head, j);
					switch (curr_node->a->key) {
					case FISH:
						ofst << "Beast and fish" << endl;
						break;
					case BIRD:
						ofst << "Beast and bird" << endl;
						break;
					case BEAST:
						ofst << "Beast and beast" << endl;
						break;
					default:
						ofst << "Unknown key" << endl;
						break;
					}
					break;
				default:
					ofst << "Unknown key" << endl;
					break;
				}

				OutNode(s->head, i, ofst);
				OutNode(s->head, j, ofst);
			}
		}
	}

} // end animals namespace