//Opdracht 1 voor OBOPA 2019 door Tim Peeters
#include <iostream>
#include "School.h"

int main()
{
	srand(time(0));

	School hku = School(); //Creeer nieuw school object.

	hku.defineObjects(); //Creeer objecten in de school zoals modules, docenten en studenten.
	hku.assignObjects(); //Wijs studenten en docenten toe aan modules.


	hku.printList();
	/*Print een lijst met modules en docenten, de studenten die bij deze module zitten.
	 Print vervolgens ook een lijst met studenten en hun totaal aantal EC's.*/


	system("pause"); //Wacht voor input voordat de EC van een module wordt verandert.
	hku.changeModuleEC(); //Verander module EC en reset behaalde EC's.

	hku.printList(); 

	system("pause"); //Wacht voor input vordat student uit module wordt verwijderd.
	hku.removeFromModule(); //Verwijder een student uit een van de modules.

	hku.printList();

	return 0;
}


