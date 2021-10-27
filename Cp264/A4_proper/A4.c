/*
 * ---------------------------------
 * Student Name:Daniel Fischer
 * Student ID: 200800490
 * Student Email:fisc0490@mylaurier.ca
 * ---------------------------------
 */

#include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <math.h>
# include <stdlib.h>
# include "A4.h"

//-------------------------Task 1 ----------------------------
void update_array(int** array, const int size, int multiplier){
	if(multiplier <= 0){
		printf("Error (update_array): invalid multiplier");
		return;
	}
		*array = (int*)realloc(*array,sizeof(int) * (size * multiplier));
		int originalArray[size];
		int i, j;
		// Let's save the original array first
		for (i=0; i<size; i++)
			originalArray[i] = (*array)[i];

		int newIndex = 0;

		// Loop through the original size
		for (i=0; i<size; i++)
		{
			// Loop through the multiplier since the numbers will be repeated here
			for (j=0; j<multiplier; j++)
			{
				// Save the original array value repeated on the multiplier
				(*array)[newIndex] = originalArray[i];
				// Increment the new index every loop to the array
				newIndex++;
			}
		}
	return;
}

//-------------------------Task 2 ----------------------------
void format_city(char *city) {
	char *e = strchr(city, ' '); // obtain a pointer to the space, if none exists, returns null
	int ind = (e - city), size = strlen(city); // ind gets index by subtracting the two pointers
	if(!e)
		city[0] = toupper(city[0]);// case 1: there is no space in the name
	else{
		city[0] = toupper(city[0]);
		city[ind+1] = toupper(city[ind+1]);//add one to the index since ind is the location of the space
		for(int i = ind; i < size; i ++) // removes the space using similar method to remove in R5
				city[i] = city[i + 1];
	}
	return;
}

void format_cities(char city_array[][MAX], const int size) {
	if(size >= MAX || size < 1){
		printf("Error(format_cities): invalid size\n"); // error handling for invalid sizes
		return;
	}
	if(!city_array){
		printf("Error(format_cities): array is NULL\n"); // error handling for null array
		return;
	}
	for(int i = 0; i < size; i++) //for each city in array, run format city.
		format_city(city_array[i]);
	return;
}

//-------------------------Task 3 ----------------------------

void format_str(const char *inStr, char *outStr) {
	int size = strlen(inStr);
	int i; int j;
	//1. String Length
	printf("String Length = %d\n", size);
	//2. Middle Caps
	strcpy(outStr,inStr);
	for(int i = 1; i < size-1; i ++){ // iterates through every char in outStr except for the first and last
		outStr[i] = toupper(outStr[i]);
	}
	printf("After middle caps = %s\n", outStr);
	//3. Split
	int pos = size / 2; // sets the position of the space character
	for(int i = size; i >= pos; i--)
		outStr[i + 1] = outStr[i];
	outStr[pos] = ' ';
	printf("After split = %s\n", outStr);
	//4. Reverse Left Side
	   i = 0;
	   j = (size / 2) - 1; // j is set to the character before the space
	   while(i<j){
	       char temp = outStr[i];
	       outStr[i] = outStr[j];
	       outStr[j] = temp;
	       i++;
	       j--;
	   }
	printf("After First half reverse = %s\n", outStr);
	//5. Reverse Right Side
	i = (size / 2) + 1; // i is set to the character after the space
	j = size;
	while(i < j){
		char temp = outStr[i];
		outStr[i] = outStr[j];
		outStr[j] = temp;
		i++;
		j--;
	}
	printf("After Second half reverse = %s\n",outStr);
	return;
}

//-------------------------Task 4 ----------------------------

int* get_multiples_array1(int *multiples, const int size) {
	 int i,j,num;
	 int *array;
	 if(multiples == NULL){
		 printf("Error(get_multiples_array1): invalid array\n");
		 return NULL;
	 }
	 if(size <= 0){
		 printf("Error(get_multiples_array1): invalid size\n");
		 return NULL;
	 }
	   array=(int *)calloc(NUM * size,sizeof(int));
	   for(i = 0; i < size;i++){
	       for(j = 1; j <= NUM; j++){
	           num = multiples[i]*j;
	           if(num < 1000)
	               *(array + (i * NUM) + j - 1) = num;
	           else
	               break;
	       }
	   }
	   return array; // return array pointer
	}
	void print_multiples1(int *array, const int size) {
	    int i, c = 0;
	   if(array == NULL){
		   printf("Error(print_multiples1): invalid array\n");
		   return;
	   }
	   if(size <= 0){
		   printf("Error(print_multiples1): invalid size\n");
		   return;
	   }
	    for(i = 0; i < size * NUM; i++) {
	        printf("%3d   ",array[i]);
	        c++;
	        if(c % NUM == 0){
	            printf("\n");
	            c = 0;
	        }
	    }
	    free(array);
	    return;
	}

//-------------------------Task 5 ----------------------------
int** get_multiples_array2(int *multiples, const int size) {
	int **array;
	int i,j,num;
	array = (int **)calloc(NUM * size,sizeof(int));
	for(i = 0; i < size;i++){
		       for(j = 1; j <= NUM; j++){
		           num = multiples[i]*j;
		           if(num < 1000)
		              **(array + (i * NUM) + j - 1) = num;
		           else
		               break;
		       }
		   }
	return array;
}

void print_multiples2(int **array, const int size) {
	   int i, c = 0;
		   if(array == NULL){
			   printf("Error(print_multiples1): invalid array\n");
			   return;
		   }
		   if(size <= 0){
			   printf("Error(print_multiples1): invalid size\n");
			   return;
		   }
		    for(i = 0; i < size * NUM; i++) {
		        printf("%3d   ",*array[i]);
		        c++;
		        if(c % NUM == 0){
		            printf("\n");
		            c = 0;
		        }
		    }

	return;
}
