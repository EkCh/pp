#pragma once
#ifndef __container_atd__
#define __container_atd__
#include "animal_atd.h"
namespace animals {
	
	struct animal;

	// список
	struct node
	{
		animal* a;
		node* next;
	};

	struct container
	{
		long size;
		node* head;

	};
} // end animals namespace
#endif