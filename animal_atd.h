#include <string>
#pragma once
namespace animals {
	enum type { FISH, BIRD, BEAST };
	// ���������, ���������� ���� ��������� ��������
	struct animal {
		type key; // ����
		std::string name;
		long age; //  �������
	};

} // end animals namespac

