/* Author: Joseph Gormley - Date: 12/25/17 */

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
	printf("\nSorted list\n"); // For presentation. 
	printf("-----------\n");   // For presentation. 
	printList(list);           // For presentation. 
	printf("\n");              // For presentation. 
	printf("Comparisons: %d\n", numberOfComparisons);

	// Completed successfully. 
	return 0;
}

// This function sorts a list of strings with insertion sort. 
void sort(char * list){

	int maxWordSize = MAX_WORD_LENGTH;
	// Variables below are used to swap / compare words. 
	char * tmp = (char *)malloc(maxWordSize + 1); 
	char * wordToSort;
	char * wordToCompare;

	// Iterate list, start at 2nd word (insertion sort).
	char * startUnsortedList;
	for(startUnsortedList = list + (1 * maxWordSize); startUnsortedList <= list + ((listSize - 1) * maxWordSize); startUnsortedList += maxWordSize){
		// Compare the word to sort with the word before it.
		// Continue until word is sorted.  
		wordToSort = startUnsortedList;
		wordToCompare = wordToSort - maxWordSize;
		while(wordToCompare >= list){
			numberOfComparisons++;
			if(strcmp(wordToSort, wordToCompare) < 0){
				strcpy(tmp, wordToCompare);
			 	strcpy(wordToCompare, wordToSort);
			 	strcpy(wordToSort, tmp);
			 	// wordToSort was swapped left, so must move pointers left. 
			 	wordToSort -= maxWordSize; 
			 	wordToCompare -= maxWordSize;
			}else{
				// wordToSort is sorted. 
				break;
			}
		}
	}

	// Free allocated memory
	free(tmp);
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
