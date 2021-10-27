/*
 * ---------------------------------
 * Student Name: Daniel Fischer
 * Student ID: 200800490
 * Student Email: fisc0490@mylaurier.ca
 * ---------------------------------
 */
// hey i remembered my credentials this time
#include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <math.h>
# include <stdlib.h>
# include "A4.h"

//-------------------------Task 1 ----------------------------

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

//-------------------------Task 2 ----------------------------

void format_str(const char *inStr, char *outStr) {
	int size = strlen(inStr);
	//1. String Length
	printf("String Length = %d\n", size);
	//2. Middle Caps
	strcpy(outStr,inStr);
	for(int i = 1; i < size-1; i ++){ // iterates through every char in outStr except for the first and last
		outStr[i] = toupper(outStr[i]);
	}
	printf("After middle caps = %s\n", outStr);
	//3. Split
	int pos = size / 2;
	for(int i = size; i >= pos; i--)
		outStr[i + 1] = outStr[i];
	outStr[pos] = ' ';
	printf("After split = %s\n", outStr);
	//4. Reverse Left Side
		char temp[strlen(outStr)];
		int half;
		for(int i = 0; i < strlen(outStr); i++ ){
			if(strcmp(&outStr[i], " ") == 0)
				half++;
		}
		strncat(temp,outStr, half);
		strrev(temp);
		strcpy(outStr,temp);
	printf("After First half reverse = %s\n", outStr);
	return;
}

//-------------------------Task 3 ----------------------------

int* get_multiples_array1(int *multiples, const int size) {
	//your solution here
	return NULL;
}

void print_multiples1(int *array, const int size) {
	//your solution here
	return;
}

//-------------------------Task 4 ----------------------------
int** get_multiples_array2(int *multiples, const int size) {
	//your solution here
	return NULL;
}

void print_multiples2(int **array, const int size) {
	//your solution here
	return;
}
