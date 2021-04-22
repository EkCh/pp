#pragma once
namespace animals {
	enum type { FISH, BIRD };
	// структура, обобщающая всех имеющихся животных
	struct animal {
		type key; // ключ
		long age; //  возраст
	};

} // end animals namespac

