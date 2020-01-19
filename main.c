#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
	Author: Federico Matteoni
	Created: 18/01/2020 22.40
*/

/*
	*0 ADD r r r
	*1 SUB r r r
	*2 MUL
	*3 DIV
	*4 AND
	*5 OR
	*6 NOT
	*7 LOAD r r r
	*8 STORE r r r
	*9 EXCHANGE
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
	*20 GOTO
	*21 CLEAR
	22 SHR
	23 SHL
	24 ADDI r n r
	25 SUBI r n r
*/

int output = -1;

int parseCommand(char *buff) {
	if 		(strcmp(buff, "ADD") == 0) 		{ return 0; }
	else if (strcmp(buff, "ADDI") == 0)		{ return 24; }
	else if (strcmp(buff, "SUB") == 0)		{ return 1; }
	else if (strcmp(buff, "SUBI") == 0)		{ return 25; }
	else if (strcmp(buff, "MUL") == 0)		{ return 2; }
	else if (strcmp(buff, "DIV") == 0)		{ return 3; }
	else if (strcmp(buff, "LOAD") == 0)		{ return 7; }
	else if (strcmp(buff, "STORE") == 0)	{ return 8; }
	else if (strcmp(buff, "EXCHANGE") == 0)	{ return 9; }
	else if (strcmp(buff, "GOTO") == 0)		{ return 20; }
	else if (strcmp(buff, "CLEAR") == 0)	{ return 21; }
	
	return -1;
}

int execCommand(int command, char* params, int* registers) {
	if (command == 0) { //R1 + R2 -> R3
		int R1, R2, R3;
		char* tokens;
		char* save_ptr;
		tokens = strtok_r(params, ",", &save_ptr);
		if (tokens != NULL) { //R1
			tokens = strchr(tokens, 'R');
		 	R1 = atoi(++tokens);
		}
		tokens = strtok_r(NULL, ",", &save_ptr);
		if (tokens != NULL) { //R2
			tokens = strchr(tokens, 'R');
		 	R2 = atoi(++tokens);
		}
		tokens = strtok_r(NULL, ",", &save_ptr);
		if (tokens != NULL) { //R3
			tokens = strchr(tokens, 'R');
		 	R3 = atoi(++tokens);
		}
		registers[R3] = registers[R1] + registers[R2];
		if (output == 0) printf("R%d + R%d -> R%d\n", R1, R2, R3);
	} else if (command == 24) { //R1 + n -> R3
		int R1, R2, R3;
		char* tokens;
		char* save_ptr;
		tokens = strtok_r(params, ",", &save_ptr);
		if (tokens != NULL) { //R1
			tokens = strchr(tokens, 'R');
		 	R1 = atoi(++tokens);
		}
		tokens = strtok_r(NULL, ",", &save_ptr);
		if (tokens != NULL) { //R2
			tokens = strchr(tokens, '#');
		 	R2 = atoi(++tokens);
		}
		tokens = strtok_r(NULL, ",", &save_ptr);
		if (tokens != NULL) { //R3
			tokens = strchr(tokens, 'R');
		 	R3 = atoi(++tokens);
		}
		registers[R3] = registers[R1] + R2;
		if (output == 0) printf("R%d + %d -> R%d\n", R1, R2, R3);
	} else if (command == 1) { //R1 - R2 -> R3
		int R1, R2, R3;
		char* tokens;
		char* save_ptr;
		tokens = strtok_r(params, ",", &save_ptr);
		if (tokens != NULL) { //R1
			tokens = strchr(tokens, 'R');
		 	R1 = atoi(++tokens);
		}
		tokens = strtok_r(NULL, ",", &save_ptr);
		if (tokens != NULL) { //R2
			tokens = strchr(tokens, 'R');
		 	R2 = atoi(++tokens);
		}
		tokens = strtok_r(NULL, ",", &save_ptr);
		if (tokens != NULL) { //R3
			tokens = strchr(tokens, 'R');
		 	R3 = atoi(++tokens);
		}
		registers[R3] = registers[R1] - registers[R2];
		if (output == 0) printf("R%d - R%d -> R%d\n", R1, R2, R3);
	} else if (command == 25) { //R1 - n -> R3
		int R1, R2, R3;
		char* tokens;
		char* save_ptr;
		tokens = strtok_r(params, ",", &save_ptr);
		if (tokens != NULL) { //R1
			tokens = strchr(tokens, 'R');
		 	R1 = atoi(++tokens);
		}
		tokens = strtok_r(NULL, ",", &save_ptr);
		if (tokens != NULL) { //R2
			tokens = strchr(tokens, '#');
		 	R2 = atoi(++tokens);
		}
		tokens = strtok_r(NULL, ",", &save_ptr);
		if (tokens != NULL) { //R3
			tokens = strchr(tokens, 'R');
		 	R3 = atoi(++tokens);
		}
		registers[R3] = registers[R1] - R2;
		if (output == 0) printf("R%d - %d -> R%d\n", R1, R2, R3);
	} else if (command == 21) { //R1 = 0
		int R1;
		char* tokens;
		char* save_ptr;
		tokens = strtok_r(params, ",", &save_ptr);
		if (tokens != NULL) { //R1
			tokens = strchr(tokens, 'R');
		 	R1 = atoi(++tokens);
		}
		registers[R1] = 0;
		if (output == 0) printf("0 -> R%d\n", R1);
	} else if (command == 2) { //R1 * R2 -> R3
		int R1, R2, R3;
		char* tokens;
		char* save_ptr;
		tokens = strtok_r(params, ",", &save_ptr);
		if (tokens != NULL) { //R1
			tokens = strchr(tokens, 'R');
		 	R1 = atoi(++tokens);
		}
		tokens = strtok_r(NULL, ",", &save_ptr);
		if (tokens != NULL) { //R2
			tokens = strchr(tokens, 'R');
		 	R2 = atoi(++tokens);
		}
		tokens = strtok_r(NULL, ",", &save_ptr);
		if (tokens != NULL) { //R3
			tokens = strchr(tokens, 'R');
		 	R3 = atoi(++tokens);
		}
		registers[R3] = registers[R1] * registers[R2];
		if (output == 0) printf("R%d * R%d -> R%d\n", R1, R2, R3);
	} else if (command == 3) { //R1 / R2 -> R3
		int R1, R2, R3;
		char* tokens;
		char* save_ptr;
		tokens = strtok_r(params, ",", &save_ptr);
		if (tokens != NULL) { //R1
			tokens = strchr(tokens, 'R');
		 	R1 = atoi(++tokens);
		}
		tokens = strtok_r(NULL, ",", &save_ptr);
		if (tokens != NULL) { //R2
			tokens = strchr(tokens, 'R');
		 	R2 = atoi(++tokens);
		}
		tokens = strtok_r(NULL, ",", &save_ptr);
		if (tokens != NULL) { //R3
			tokens = strchr(tokens, 'R');
		 	R3 = atoi(++tokens);
		}
		registers[R3] = registers[R1] / registers[R2];
		if (output == 0) printf("R%d / R%d -> R%d\n", R1, R2, R3);
	}
}

void printRegisters(int* registers) {
	int i;
	printf("\n\n***REGISTRI A FINE ESECUZIONE***\n");
	for (i = 0; i < 64; i += 8) {
		printf("R%d = %d\t\t", i, registers[i]);
		printf("R%d = %d\t\t", i+1, registers[i+1]);
		printf("R%d = %d\t\t", i+2, registers[i+2]);
		printf("R%d = %d\t\t", i+3, registers[i+3]);
		printf("R%d = %d\t\t", i+4, registers[i+4]);
		printf("R%d = %d\t\t", i+5, registers[i+5]);
		printf("R%d = %d\t\t", i+6, registers[i+6]);
		printf("R%d = %d\n", i+7, registers[i+7]);
	}
}

int main(int argc, char *argv[]) {
	FILE *inputfile;
	char *buff, *params;
	int cmd, code, i;
	int *registers;
	
	if (argc < 2) { printf("Usage: %s <D-RISC file> [-v]", argv[0]); return -1;}
	if (argc == 3) { if (strcmp(argv[2], "-v") == 0) output = 0; }
	
	inputfile = fopen(argv[1], "r");
	registers = calloc(64, sizeof(int));
	registers[0] = malloc(sizeof(int));
	registers[0] = 0; //R0 contiene sempre 0
	for (i = 1; i < 64; i++) { registers[i] = malloc(sizeof(int)); registers[i] = 0; }
	
	do {
		buff = malloc(10*sizeof(char));
		params = malloc(20*sizeof(char));
		code = fscanf(inputfile, "%s", buff);
		
		if (code != EOF && code > 0) {
			cmd = parseCommand(buff);
			fgets(params, 20, inputfile);
			execCommand(cmd, params, registers);
			
			free(buff);
			free(params);
		}
	} while (code != EOF);
	
	fclose(inputfile);
	free(buff);
	free(params);
	
	printRegisters(registers);
	free(registers);
	
	return 0;
}
