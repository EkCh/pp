#include <string>
#pragma once
namespace animals {
	enum type { FISH, BIRD };
	// структура, обобщающая всех имеющихся животных
	struct animal {
		type key; // ключ
		std::string name;
	};

} // end animals namespac

