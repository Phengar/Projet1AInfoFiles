#include <stdio.h>

void simulate() {
	printf("Launching simulation...\n");
}

void do_nothing() {

}

// Displays the user interfaces
void disp_menu() {
	printf("======== Checkout line simulator ========\n");
	printf(" 1. Simulate\n");
	printf(" 2. \n");
	printf(" 0. Quit\n");
	printf("=========================================\n");
	printf(">> ");
}

void menu() {
	int i = -1;
	while(i != 0) { // Type 0 in menu to stop the program
		disp_menu();
		scanf("%d", &i);
		switch(i) {
			case 1:
				simulate();
			break;
			case 2:
				do_nothing();
			break;
		}
		printf("\n");
	}
	printf("by DAVAL Quentin - HUBINET Benjamin - ISMIN 1A - EI21\n");
}

int main() {
	menu();
	return 0;
}