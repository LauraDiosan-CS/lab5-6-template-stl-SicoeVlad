#include "repo.h"
#include "Service.h"
#include "Ui.h" 
#include <cstring>
#include "Test.h"
using namespace std;



int main()
{
	allTests();
	Repo<Produs> repo = Repo<Produs> ();
	ServiceRepoTemplate serv = ServiceRepoTemplate(repo);
	UI ui = UI(serv);
	ui.run();
	return 0;
}