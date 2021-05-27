#include <string>
#pragma once
namespace animals {
	enum type { FISH, BIRD, BEAST };
	// структура, обобщающая всех имеющихся животных
	struct animal {
		type key; // ключ
		std::string name;
		long age; //  возраст
	};

} // end animals namespac

