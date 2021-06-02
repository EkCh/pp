#include <string>
#include "animal_atd.h"
#pragma once
namespace animals 
{
	enum pref { PREDATOR, HERBIVORE, INSECTIVORE };
	// �����
	struct beast 
	{
		type key;
		std::string name;    // ��������
		pref p; 
		long age;
	};
} // end animals namespace