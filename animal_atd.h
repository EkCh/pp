#include <string>
#pragma once
namespace animals {
	enum type { FISH, BIRD, BEAST };
	// структура, обобщающая всех имеющихся животных
	struct animal {
		type key; // ключ
<<<<<<< HEAD
		std::string name;
=======
		long age; //  возраст
>>>>>>> new_field
	};

} // end animals namespac

