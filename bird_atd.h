#include <string>
#include "animal_atd.h"
#pragma once
namespace animals {
	enum migr { MIGRANT, NONMIGRANT };
	// �����
	struct bird {
		type key;
		std::string name;    // ��������
		migr m; // ������������
	};
} // end animals namespace