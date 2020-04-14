#pragma once
#include "service.h"

class TesteService {
	private:
		void teste_add_and_del_service();
		void teste_update_service();
		void teste_findElem_service();
		void teste_findByName_service();
		void teste_verificare_status_service();
	public:
		TesteService();
		void teste_service();
		~TesteService();
};