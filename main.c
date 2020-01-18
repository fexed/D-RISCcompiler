#include <stdio.h>
#include <stdlib.h>

/**
	Author: Federico Matteoni
	Created: 18/01/2020 22.40
*/
int main(int argc, char *argv[]) {
	FILE *inputfile;
	char *buff;
	
	if (argc != 2) { printf("Usage: %s <D-RISC file>", argv[0]); return -1;}
	
	inputfile = fopen(argv[1], "r");
	buff = malloc(50*sizeof(char));
	fscanf(inputfile, "%s", buff);
	printf("1. %s", buff);
	fclose(inputfile);
	free(buff);
	
	return 0;
}
