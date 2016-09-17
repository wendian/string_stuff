#include <stdio.h>
#include <stdlib.h>
//Prints a two dimensional boolean array of two strings,
//1 if the letters match, 2 if they do not
//Takes 1 or two strings separated by a space
//If there is only one string, it is compared to itself

int main(int argc, char ** argv){
	if (argc == 1) return 0;
	char * c = argv[1];
	//get the lengths of the strings
	int n1 = 0;
	int n2 = 0;
	while (*c){
		n1++;
		c++;
	}
	if (argc >= 3){
		c = argv[2];
		while (*c){
			n2++;
			c++;
		}
	}
	else n2 = n1;
	//create boolean array, use calloc to initialize all zeros
	int ** intersects = (int **) calloc(n1 * n2, sizeof(int));
	c = argv[1];
	char * c2;
	if (argc == 2) c2 = argv[1];
	else c2 = argv[2];
	int i, j;
	for (i = 0; i < n1; i++){
		for (j = 0; j < n2; j++){
			if (c[i] == c2[j]) intersects[i + j * 10] = (int *) 1;
		}
	}
	//print everything
	printf("  ");
	while (*c2){
	    printf("%c ", *c2);
		c2++;
	}
	for (i = 0; i < n1; i++){
		printf("\n%c ", c[i]);
		for (j = 0; j < n2; j++){
			printf("%d ", intersects[i + j * 10]);
		}
	}
	printf("\n");
	free(intersects);
	return 0;
}