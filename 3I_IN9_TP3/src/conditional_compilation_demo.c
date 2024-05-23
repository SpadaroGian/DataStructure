#include<stdio.h>

int main(int argc, char *argv[]){
	/*
	 * Cette directive de préprocesseur #ifndef vérifie si la
	 * constante VERSION n'a pas été définie. Si c'est le cas,
	 * le code compilé inclura la ligne suivante.
	 */
#ifndef VERSION
	printf("Version par defaut.\n");
	
	/*
	 * Cette directive de préprocesseur #elif vérifie si la
	 * constante VERSION a été définie comme étant égale à 2.
	 * Si c'est le cas, le code compilé inclura la ligne suivante.
	 */
#elif VERSION==2
	printf("Version 2.0 du code.\n");
	
	/*
	 * Cette directive de préprocesseur #elif vérifie si la
	 * constante VERSION a été définie comme étant égale à 3.
	 * Si c'est le cas, le code compilé inclura la ligne suivante.
	 */
#elif VERSION==3
	printf("Version 3.0 du code.\n");
	
	/*
	 * Si aucune des conditions précédentes n'est vraie,
	 * le code compilé inclura la ligne suivante.
	 */
#else
	printf("Imposible d'arrivé ici normalemen !\n");
#endif
}

