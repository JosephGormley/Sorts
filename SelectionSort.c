/* Author: Joseph Gormley - Date: 12/22/17 */

#define LIST_SIZE 15

#include <stdio.h>
#include <string.h>

// Number of comparisons used to sort this list. 
int numberOfComparisons = 0;

// Function declarations.
void sort(char ** list);
void printList(char ** list);

// Driver function. 
// Lists built by https://www.randomlists.com
int main(int argc, char * argv[]){

	// Error handling.
	if(argc != 2){
		fprintf(stderr, "Interface: ./SelectionSort <list_to_sort>\n");
		return -1; 
	}

	FILE * fd;
	if((fd = fopen(argv[1], "r")) == NULL){
		fprintf(stderr, "Error opening file: %s\n", argv[1]);
		return -1;
	}

	char * list[15];
	//TODO @ME: Read file by line and add words to list. 







	// Print list.
	printf("Unsorted list\n");
	printf("-------------\n"); 
	printList(list);

	// Sort List.
	sort(list);

	// Print list again. 
	printf("Sorted list\n");
	printf("-----------\n"); // For presentation. 
	printList(list);
	printf("Comparisons: %d\n\n", numberOfComparisons);

	// Completed successfully. 
	return 0;
}

// This function sorts a list of strings with selection sort. 
void sort(char ** list){

	int indexToSwap = -1; // This variable is used to swap the words. 
	char * tmp = NULL; // This variable is used to swap the words. 
	char * wordToSwap = list[0];

	// Find string that belongs in properIndex's location. 
	int properIndex;
	for(properIndex = 0; properIndex  < LIST_SIZE; properIndex++){
		
		wordToSwap = list[properIndex];

		// Find smallest string 
		int i;
		for(i = properIndex + 1; i < LIST_SIZE; i++){
			numberOfComparisons++;
			// Is wordToSwap smaller than list[i]?
			if(strcmp(wordToSwap, list[i]) >= 0){
				wordToSwap = list[i];
				indexToSwap = i; 
			} 
		}

		// Swap words. 
		tmp = list[properIndex];
		list[properIndex] = wordToSwap;
		list[indexToSwap] = tmp;
		
	}

	return;
}

/* Prints out a given list of strings */
void printList(char ** list){


	// Iterate list of strings. 
	int i;
	for(i = 0; i < LIST_SIZE; i++){
		printf("%s\n", list[i]);
	}

	printf("\n");

	return;
}
