#pragma once
#include "Service.h"
#include "Repo.h"
#include <iostream>
using namespace std;

class UI {
private:
	ServiceRepoTemplate serv;
public:
	UI();
	~UI();
	UI(ServiceRepoTemplate service);
	
	void run();
};