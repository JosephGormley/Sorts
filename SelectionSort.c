/* Author: Joseph Gormley - Date: 12/22/17 */

#define LIST_SIZE 15

#include <stdio.h>
#include <string.h>

// Number of comparisons Selection Sort took to sort this list. 
int numberOfComparisons = 0;

// Function declarations.
void sort(char ** list);
void printList(char ** list);

// Driver function. 
int main(){
	
	// List of 15 strings randomly selected. https://www.randomlists.com
	// Note: This same list will be used in all of my sorts as an example. 
	char * list[LIST_SIZE] = {"mind", "duck", "slow", "precious", "joke",
				  "sign", "ask", "special", "silky", "ruthless",
				  "rainy", "delirious", "scare", "van", "join"};
	
	// Print list, sort list, print list again. 
	printList(list);
	sort(list);
	printList(list);

	return 0;
}

// SReqrqr
void sort(char ** list){

	char * wordToSwap = list[0];

	// Find element that belongs in properIndex's location. 
	int properIndex;
	for(properIndex = 0; properIndex < LIST_SIZE - 1; properIndex++){

		// Find smallest element 
		int i;
		for(i = properIndex; i < LIST_SIZE - 1; i++){
			numberOfComparisons++;
			// Is wordToSwap smaller than list[i]?
			if(strcmp(wordToSwap, list[i]) < 0){
				wordToSwap = list[i];
			} 
		}

		list[properIndex] = wordToSwap;

	}

	return;
}

/* Prints out a given list of elements */
void printList(char ** list){

	printf("LIST:\n");

	// Iterate list of elements. 
	int i;
	for(i = 0; i < LIST_SIZE; i++){
		printf("%s\n", list[i]);
	}

	printf("\n");

	return;
}