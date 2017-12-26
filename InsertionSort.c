/* Author: Joseph Gormley - Date: 12/25/17 */

#define LIST_SIZE 15

#include <stdio.h>
#include <string.h>

// Number of comparisons used to sort this list. 
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

	// Print list
	printf("Unsorted list\n");
	printf("-------------\n"); 
	printList(list);

	// Sort List
	sort(list);

	// Print list again. 
	printf("Sorted list\n");
	printf("-----------\n");
	printList(list);
	printf("Comparisons: %d\n\n", numberOfComparisons);

	return 0;
}

// This function sorts a list of strings with insertion sort. 
void sort(char ** list){

	return;
}