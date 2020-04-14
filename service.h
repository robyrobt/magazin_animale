#pragma once
#include "repo_file.h"

class Service {
	private:
		RepoFile <Carte> repo;

	public:
		Service();
		Service(RepoFile<Carte>&);
		void setRepo(RepoFile<Carte>&);
		void addCarte(Carte&);
		int findElem(Carte&);
		Carte findByName(const char*);
		int delCarte(Carte&);
		int updataCarte(Carte&, const char*, const char*, const char*);
		int getSise_S();
		deque<Carte> getAll();
		deque<Carte> showBookByAutor(const char*);
		bool verificare_status(Carte&);
		bool raspuns(const char*);
		~Service();
};