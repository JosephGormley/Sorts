/* Author: Joseph Gormley - Date: 12/22/17 */

#define MAX_WORD_LENGTH 15

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Number of comparisons used to sort this list. 
int numberOfComparisons;
int listSize; 
// Function declarations.
void sort(char * list);
void printList(char * list);

// Driver function. 
// Lists built by https://www.randomlists.com/random-words
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

	char buffer[MAX_WORD_LENGTH + 1]; // Used to read in file.
	if((fgets(buffer, sizeof(buffer), fd)) == NULL){
		fprintf(stderr, "Error with file format\n");
		return -1;
	}

	// No errors in arguements or file format at this point.
	// Initialize globals. 
	listSize = atoi(buffer);
	numberOfComparisons = 0;

	// Read in list of words from given file. 
	// Note: One word per line, terminating char is appended w/ fgets.
	int i = 0; // Used to traverse list of words. 
	char * list = (char *)malloc(listSize * (MAX_WORD_LENGTH + 1));
	while(fgets(buffer, sizeof(buffer), fd) != NULL){ 
		strcpy((list + (i * MAX_WORD_LENGTH)), buffer);
		i++;
	}

	// Print list.
	printf("Unsorted list\n"); // For presentation. 
	printf("-------------\n"); // For presentation. 
	printList(list);           // For presentation. 
	printf("\n");              // For presentation. 

	// Sort List.
	sort(list);

	// Print sorted list. 
	printf("Sorted list\n");   // For presentation. 
	printf("-----------\n");   // For presentation. 
	printList(list);           // For presentation. 
	printf("\n");              // For presentation. 
	printf("Comparisons: %d\n\n", numberOfComparisons);

	// Completed successfully. 
	return 0;
}

// This function sorts a list of strings with selection sort. 
void sort(char * list){

	int maxWordSize = MAX_WORD_LENGTH; 
	// Variables below are used to swap words. 
	int indexToSwap = -1; 
	char * tmp = (char *)malloc(maxWordSize + 1); 
	char * wordToSwap = NULL;

	// Index of the nth word sorted word. 
	int properIndex;
	for(properIndex = 0; properIndex  < listSize; properIndex++){		
		wordToSwap = list + (properIndex * maxWordSize);
		// Find string that belongs in properIndex's location. 
		int i;
		for(i = properIndex + 1; i < listSize; i++){
			numberOfComparisons++;
			// Is wordToSwap smaller than list[i]?
			if(strcmp(wordToSwap, list + (i * maxWordSize)) >= 0){
				wordToSwap = list + (i * maxWordSize);
				indexToSwap = i; 
			} 
		}

		// If addresses overlap, behavior is undefined. Here's how we avoid that. 
		if(strcmp(list + (properIndex * maxWordSize), wordToSwap) != 0){
			// Swap words. 
			strcpy(tmp, list + (properIndex * maxWordSize));
			strcpy(list + (properIndex * maxWordSize), wordToSwap);
			strcpy(list + (indexToSwap * maxWordSize), tmp);	
		}
	}

	return;
}

/* Prints out a given list of strings */
void printList(char * list){

	// Iterate list of strings. 
	int i;
	for(i = 0; i < listSize; i++){
		printf("%s", list + (i * MAX_WORD_LENGTH));
	}

	return;
}
