#include "Ui.h"
#include <iostream>
using namespace std;

int main()
{
	bool stop = false;

	reT re = 5;
	imT im = 2;

	Ui zahl = Ui(re, im);
	
	zahl.printZahl(0);


	return 0;
}