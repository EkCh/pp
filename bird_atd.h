#include <string>
#include "animal_atd.h"
#pragma once
namespace animals {
	enum migr { MIGRANT, NONMIGRANT };
	// птицы
	struct bird {
		type key;
		std::string name;    // название
		migr m; // перелетность
	};
} // end animals namespace