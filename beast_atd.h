#include <string>
#include "animal_atd.h"
#pragma once
namespace animals 
{
	enum pref { PREDATOR, HERBIVORE, INSECTIVORE };
	// звери
	struct beast 
	{
		type key;
		std::string name;    // название
		pref p; 
		long age;
	};
} // end animals namespace