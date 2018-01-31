/* Author: Joseph Gormley - Date: 01/26/17 */

// Including null byte. 
#define MAX_WORD_LENGTH 15

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Number of comparisons used to sort this list. 
int numberOfComparisons;
int listSize; 
// Function declarations.
void sort(char * list, int left, int right);
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
	sort(list, 0, listSize - 1);

	// Print sorted list. 
	printf("\nSorted list\n"); // For presentation. 
	printf("-----------\n");   // For presentation. 
	printList(list);           // For presentation. 
	printf("\n");              // For presentation. 
	printf("Comparisons: %d\n", numberOfComparisons);

	// Completed successfully. 
	return 0;
}

// This function sorts a list of strings with mergesort. 
void sort(char * list, int left, int right){

	// Base Case
	if(left >= right){
		return;
	}

	int maxWordSize = MAX_WORD_LENGTH;
	int middle = (left + right)/2;

	// Break list down. 
	sort(list, left, middle);
	sort(list, middle + 1, right);

	// Create temp arrays to store both sides.
	// MergeSort is NOT an in-place sort. 
	int i;
	char * leftList = (char *)malloc((middle - left + 1) * (maxWordSize +1));
	char * rightList = (char *)malloc((right - middle) * (maxWordSize +1));
	// Copy left list.
	//printf("%d %d\n", left, right);
	for(i = 0; i < middle - left + 1; i++){
		//strcpy(leftList + (i * maxWordSize), list + ((left + i) * maxWordSize));
		printf("%s", leftList + (i * maxWordSize));
	}
	//printf("\n");
	// Copy right list. 
	for(i = 0; i < right - middle; i++){
		strcpy(rightList + (i * maxWordSize), list + ((middle + 1 + i) * maxWordSize));
		//printf("%s", rightList + (i * maxWordSize));
	}

	//printf("\n\n\n\n");



	// Rebuild list
	while(){
		if(strcmp(list + (left * maxWordSize), list + ((middle + 1) * maxWordSize)) > 0){
			// Swap strings




			left++;
		}else{
			// Strings are in correct place
			left++;
		}
	}

	free(leftList);
	free(rightList);

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
