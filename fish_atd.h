#include "animal_atd.h"
#include <string>
#pragma once
namespace animals {
	enum habitat { RIVER, SEA, LAKE };
	// ����
	struct fish {
		type key;
		std::string name;    // ��������
		habitat h; // ����� ����������
		long age;
	};
} // end animals namespace
