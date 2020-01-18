#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
	Author: Federico Matteoni
	Created: 18/01/2020 22.40
*/

/*
	0 ADD
	1 SUB
	2 MUL
	3 DIV
	4 AND
	5 OR
	6 NOT
	7 LOAD
	8 STORE
	9 EXCHANGE
	10 IF>
	11 IF<
	12 IF=
	13 IF<=
	14 IF>=
	15 IF>0
	16 IF<0
	17 IF=0
	18 IF<=0
	19 IF>=0
	20 GOTO
	21 CLEAR
	22 SHR
	23 SHL
	24 ADDI
	25 SUBI
*/
int parseCommand(char *buff) {
	if (strcmp(buff, "ADD") == 0) 		{ return 0; }
	else if (strcmp(buff, "ADDI") == 0)	{ return 24; }
	else if (strcmp(buff, "SUB") == 0)	{ return 1; }
	else if (strcmp(buff, "MUL") == 0)	{ return 2; }
	else if (strcmp(buff, "DIV") == 0)	{ return 3; }
	
	return -1;
}

int main(int argc, char *argv[]) {
	FILE *inputfile;
	char *buff, *params;
	int cmd, code;
	
	if (argc != 2) { printf("Usage: %s <D-RISC file>", argv[0]); return -1;}
	
	inputfile = fopen(argv[1], "r");
	
	do {
		buff = malloc(10*sizeof(char));
		params = malloc(20*sizeof(char));
		code = fscanf(inputfile, "%s", buff);
		
		if (code != EOF && code > 0) {
			cmd = parseCommand(buff);
			fgets(params, 20, inputfile);
			//printf("%d\t%s\n", cmd, params);
			
			free(buff);
			free(params);
		}
	} while (code != EOF);
	
	fclose(inputfile);
	free(buff);
	
	return 0;
}
