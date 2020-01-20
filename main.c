#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
	Author: Federico Matteoni
	Created: 18/01/2020 22.40
*/

/*
	**0 ADD r r r
	**1 SUB r r r
	**2 MUL
	**3 DIV
	*4 AND
	*5 OR
	*6 NOT
	*7 LOAD r r r
	*8 STORE r r r
	*9 EXCHANGE
	**10 IF>
	**11 IF<
	**12 IF=
	**13 IF<=
	**14 IF>=
	15 IF>0
	16 IF<0
	17 IF=0
	18 IF<=0
	19 IF>=0
	*20 GOTO
	*21 CLEAR
	22 SHR
	23 SHL
	**24 ADDI r n r
	**25 SUBI r n r
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
	else if (strcmp(buff, "IF>") == 0)		{ return 10; }
	else if (strcmp(buff, "IF<") == 0)		{ return 11; }
	else if (strcmp(buff, "IF=") == 0)		{ return 12; }
	else if (strcmp(buff, "IF<=") == 0)		{ return 13; }
	else if (strcmp(buff, "IF>=") == 0)		{ return 14; }
	else if (strcmp(buff, "IF>0") == 0)		{ return 15; }
	else if (strcmp(buff, "IF<0") == 0)		{ return 16; }
	else if (strcmp(buff, "IF=0") == 0)		{ return 17; }
	else if (strcmp(buff, "IF<=0") == 0)	{ return 18; }
	else if (strcmp(buff, "IF>=0") == 0)	{ return 19; }
	else if (strcmp(buff, "GOTO") == 0)		{ return 20; }
	else if (strcmp(buff, "CLEAR") == 0)	{ return 21; }
	else if (strcmp(buff, "END") == 0)		{ return -2; }
	else return -1;
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
		if (output == 0) printf("%d + %d -> R%d\n", registers[R1], registers[R2], R3);
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
		if (output == 0) printf("%d + #%d -> R%d\n", registers[R1], R2, R3);
		registers[R3] = registers[R1] + R2;
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
		if (output == 0) printf("%d - %d -> R%d\n", registers[R1], registers[R2], R3);
		registers[R3] = registers[R1] - registers[R2];
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
		if (output == 0) printf("%d - #%d -> R%d\n", registers[R1], R2, R3);
		registers[R3] = registers[R1] - R2;
	} else if (command == 21) { //R1 = 0
		int R1;
		char* tokens;
		char* save_ptr;
		tokens = strtok_r(params, ",", &save_ptr);
		if (tokens != NULL) { //R1
			tokens = strchr(tokens, 'R');
		 	R1 = atoi(++tokens);
		}
		if (output == 0) printf("0 -> R%d\n", R1);
		registers[R1] = 0;
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
		if (output == 0) printf("%d * %d -> R%d\n", registers[R1], registers[R2], R3);
		registers[R3] = registers[R1] * registers[R2];
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
		 	if (R2 == 0) return -11;
		}
		tokens = strtok_r(NULL, ",", &save_ptr);
		if (tokens != NULL) { //R3
			tokens = strchr(tokens, 'R');
		 	R3 = atoi(++tokens);
		}
		if (output == 0) printf("%d / %d -> R%d\n", registers[R1], registers[R2], R3);
		registers[R3] = registers[R1] / registers[R2];
	} else if (command == 10) { //IF> R1 R2 tag
		int R1, R2;
		char *tokens, *tag;
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
		tag = strtok_r(NULL, "\n", &save_ptr);
		if (output == 0) printf("%d > %d ? ->%s\n", registers[R1], registers[R2], tag);
		if (registers[R1] > registers[R2]) return -3;
	} else if (command == 11) { //IF< R1 R2 tag
		int R1, R2;
		char *tokens, *tag;
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
		tag = strtok_r(NULL, "\n", &save_ptr);
		if (output == 0) printf("%d < %d ? ->%s\n", registers[R1], registers[R2], tag);
		if (registers[R1] < registers[R2]) return -3;
	} else if (command == 12) { //IF= R1 R2 tag
		int R1, R2;
		char *tokens, *tag;
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
		tag = strtok_r(NULL, "\n", &save_ptr);
		if (output == 0) printf("%d = %d ? ->%s\n", registers[R1], registers[R2], tag);
		if (registers[R1] == registers[R2]) return -3;
	} else if (command == 13) { //IF<= R1 R2 tag
		int R1, R2;
		char *tokens, *tag;
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
		tag = strtok_r(NULL, "\n", &save_ptr);
		if (output == 0) printf("%d <= %d ? ->%s\n", registers[R1], registers[R2], tag);
		if (registers[R1] <= registers[R2]) return -3;
	} else if (command == 14) { //IF>= R1 R2 tag
		int R1, R2;
		char *tokens, *tag;
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
		tag = strtok_r(NULL, "\n", &save_ptr);
		if (output == 0) printf("%d >= %d ? ->%s\n", registers[R1], registers[R2], tag);
		if (registers[R1] >= registers[R2]) return -3;
	} else if (command == 15) { //IF>0 R1 tag
		int R1;
		char *tokens, *tag;
		char* save_ptr;
		tokens = strtok_r(params, ",", &save_ptr);
		if (tokens != NULL) { //R1
			tokens = strchr(tokens, 'R');
		 	R1 = atoi(++tokens);
		}
		tag = calloc(15, sizeof(char));
		tag = strtok_r(NULL, "\n", &save_ptr);
		if (output == 0) printf("%d > 0 ? ->%s\n", registers[R1], tag);
		if (registers[R1] > 0) return -4;
	} else if (command == 16) { //IF<0 R1 tag
		int R1;
		char *tokens, *tag;
		char* save_ptr;
		tokens = strtok_r(params, ",", &save_ptr);
		if (tokens != NULL) { //R1
			tokens = strchr(tokens, 'R');
		 	R1 = atoi(++tokens);
		}
		tag = strtok_r(NULL, "\n", &save_ptr);
		if (output == 0) printf("%d < 0 ? ->%s\n", registers[R1], tag);
		if (registers[R1] < 0) return -4;
	} else if (command == 17) { //IF=0 R1 tag
		int R1;
		char *tokens, *tag;
		char* save_ptr;
		tokens = strtok_r(params, ",", &save_ptr);
		if (tokens != NULL) { //R1
			tokens = strchr(tokens, 'R');
		 	R1 = atoi(++tokens);
		}
		tag = strtok_r(NULL, "\n", &save_ptr);
		if (output == 0) printf("%d = 0 ? ->%s\n", registers[R1], tag);
		if (registers[R1] == 0) return -4;
	} else if (command == 18) { //IF<=0 R1 R2 tag
		int R1;
		char *tokens, *tag;
		char* save_ptr;
		tokens = strtok_r(params, ",", &save_ptr);
		if (tokens != NULL) { //R1
			tokens = strchr(tokens, 'R');
		 	R1 = atoi(++tokens);
		}
		tag = strtok_r(NULL, "\n", &save_ptr);
		if (output == 0) printf("%d <= 0 ? ->%s\n", registers[R1], tag);
		if (registers[R1] <= 0) return -4;
	} else if (command == 19) { //IF>=0 R1 R2 tag
		int R1;
		char *tokens, *tag;
		char* save_ptr;
		tokens = strtok_r(params, ",", &save_ptr);
		if (tokens != NULL) { //R1
			tokens = strchr(tokens, 'R');
		 	R1 = atoi(++tokens);
		}
		tag = strtok_r(NULL, "\n", &save_ptr);
		if (output == 0) printf("%d >= 0 ? ->%s\n", registers[R1], tag);
		if (registers[R1] >= 0) return -4;
	} else if (command == 20) { //GOTO
		if (output == 0) printf("GOTO %s\n", params);
		return -2;
	}
	
	return -1;
}

void printRegisters(int* registers) {
	int i;
	printf("\n\n\t\t\t\t\t\tRegistri a fine esecuzione\n\n");
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

int lookFor(char* needle, char** haystack, int haystackLen) {
	int i;
	for (i = 0; i < haystackLen; i++) {
		if (haystack[i] != NULL){
			if (strcmp(needle, haystack[i]) == 0) return i;
		}
	}
	return -1;
}

int main(int argc, char *argv[]) {
	FILE *inputfile;
	char **tags, **commands, **params, *control, *paramsCpy;
	int cmd, i, newi, lines = 0;
	int *registers;
	
	if (argc < 2) { printf("Usage: %s <D-RISC file> [-v]", argv[0]); return -1;}
	if (argc == 3) { if (strcmp(argv[2], "-v") == 0) output = 0; }
	
	inputfile = fopen(argv[1], "r");
	registers = calloc(64, sizeof(int));
	registers[0] = malloc(sizeof(int));
	registers[0] = 0; //R0 contiene sempre 0
	for (i = 1; i < 64; i++) { registers[i] = malloc(sizeof(int)); registers[i] = 0; }
	commands = malloc(sizeof(char));
	params = malloc(sizeof(char));
	tags = malloc(sizeof(char));
	
	if (output == 0) printf("Inizio lettura e analisi del programma.\n");
	char *buff = malloc(20*sizeof(char));;
	do {
		lines++;
		
		tags = realloc(tags, lines*(30*sizeof(char)));
		tags[lines-1] = malloc(30*sizeof(char));
		
		commands = realloc(commands, lines*(30*sizeof(char)));
		commands[lines-1] = malloc(30*sizeof(char));
		
		params = realloc(params, lines*(30*sizeof(char)));
		params[lines-1] = malloc(30*sizeof(char));
		
		control = fgets(buff, 30, inputfile);
		if (control != NULL) {
			if (strchr(buff, ':') != NULL) {
				memcpy(tags[lines-1], strtok(buff, ":") , 30);
				memcpy(commands[lines-1], strtok(NULL, " "), 30);
				memcpy(params[lines-1], strtok(NULL, "\n"), 30);
			} else if (strcmp(buff, "END") == 0) {
				tags[lines-1] = NULL;
				memcpy(commands[lines-1], strtok(buff, " "), 30);
				params[lines-1] = NULL;
			} else {
				tags[lines-1] = NULL;
				memcpy(commands[lines-1], strtok(buff, " "), 30);
				memcpy(params[lines-1], strtok(NULL, "\n"), 30);
			}
			if (output == 0) {
				printf("%d.%s\t[%s]\t%s\n", lines-1, (tags[lines-1] == NULL) ? "" : tags[lines-1], commands[lines-1], (params[lines-1] == NULL) ? "" : params[lines-1]);
			}
		}
	} while (control != NULL);
	free(buff);
	fclose(inputfile);
	if (output == 0) printf("Lettura del programma completata, %d righe lette.\nInizio esecuzione\n", lines-1);
	
	for (i = 0; i < lines; i++) {
		if (output == 0) printf("%d.\t", i);
		cmd = parseCommand(commands[i]);
		if (cmd == -2) break; //END
		paramsCpy = malloc((strlen(params[i])+1)*sizeof(char)); //TODO fix
		memcpy(paramsCpy, params[i], strlen(params[i]));
		newi = execCommand(cmd, paramsCpy, registers);
		free(paramsCpy);
		if (newi == -2) {
			newi = lookFor(params[i], tags, lines);
			if (newi != -1) i = newi-1;
		} else if (newi == -3) {
			paramsCpy = calloc((strlen(params[i])+1), sizeof(char));
			memcpy(paramsCpy, params[i], strlen(params[i]));
			strtok(paramsCpy, ",");
			strtok(NULL, ",");
			paramsCpy = strtok(NULL, "\n");
			newi = lookFor(++paramsCpy, tags, lines);
			if (newi != -1) i = newi-1;
		} else if (newi == -4) {
			paramsCpy = calloc((strlen(params[i])+1), sizeof(char));
			memcpy(paramsCpy, params[i], strlen(params[i]));
			strtok(paramsCpy, ",");
			paramsCpy = strtok(NULL, "\n");
			newi = lookFor(++paramsCpy, tags, lines);
			if (newi != -1) i = newi-1;
		} else if (newi == -11) { //divisione per 0
			printf("ERRORE divisione per 0");
			return -1;
		}
	}
	if (output == 0) printf("END\nFine esecuzione\n");
	
	printRegisters(registers);
	free(registers);
	free(tags);
	
	return 0;
}
