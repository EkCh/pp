#include "animal_atd.h"
#include <string>
#pragma once
namespace animals {
	enum habitat { RIVER, SEA, LAKE };
	// рыбы
	struct fish {
		type key;
		std::string name;    // название
		habitat h; // место проживания
		long age;
	};
} // end animals namespace
