#include <string>
#pragma once
namespace animals {
	enum type { FISH, BIRD };
	// ���������, ���������� ���� ��������� ��������
	struct animal {
		type key; // ����
		std::string name;
	};

} // end animals namespac

