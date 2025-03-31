#include <unistd.h>
#include <stdlib.h>

/*
	- lire document : a hauteur de BUFFER_SIZE -> buffer
	- check pour '\n'
	- stocker dans remainder
	- vider buffer

	relire buffer ft_strjoin avec remainder
	- check pour '\n'
		- quand '\n' -> sortir Line 
		- clean remainder
	- check '/0'
	- quand '\0' fin de lecture
