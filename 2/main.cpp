#include "main.h"
#include <iostream>

int main()
{
	//Aufgabe 1
	//Complex zahl;
	//Reaktion des Compilers: no matching constructor for initialization of 'Complex'

	//Aufgabe 2
	//Complex zahl;
	//Reaktion des Compilers: call to constructor of 'Complex' is ambiguous

	//mit default Constructor
	//Complex zahl;
	//Reaktion des Compilers: call to constructor of 'Complex' is ambiguous

	//Problem mit ambiguos beheben, indem default parameter von kart/polar Konstruktor entfernt werden
	//Folge: Es lässt sich eine komplexe Zahl ohne Parametern erstellen (mittels default constructor)

	//Aufgabe 4
	// float re, im;
	// re = 2;
	// im = 4;
	// Complex zahl(re, im);

	// zahl.getKart(re, im);
	// std::cout<<re<<" "<<im<<std::endl;
	// zahl.getPolar(re, im);
	// std::cout<<re<<" "<<im<<std::endl;

	// sKart kart;
	// kart.re = 1;
	// kart.im = 3;
	// zahl.set(kart);

	// zahl.getKart(re, im);
	// std::cout<<re<<" "<<im<<std::endl;
	// zahl.getPolar(re, im);
	// std::cout<<re<<" "<<im<<std::endl;
	
	//Aufgabe 5
	// float re, im;
	// re = 2;
	// im = 4;
	// Complex zahl(re, im);

	// zahl.getKart(re, im);
	// std::cout<<re<<" "<<im<<std::endl;
	// zahl.getPolar(re, im);
	// std::cout<<re<<" "<<im<<std::endl;

	// double betrag = 5;
	// zahl.set(betrag);
	//äquivalent zu:
	// float betragf = 5;
	// zahl.set((double)betragf); 

	// zahl.getKart(re, im);
	// std::cout<<re<<" "<<im<<std::endl;
	// zahl.getPolar(re, im);
	// std::cout<<re<<" "<<im<<std::endl;

	return 0;
}