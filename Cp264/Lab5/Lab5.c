/*
 * ---------------------------------
 * Student Name:daniel fischer
 * Student ID:200800490
 * Student Email:fisc0490@mylaurier.ca
 * ---------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
char* encrypt(char *plaintext, int key) {
	int i = 0, size = sizeof(plaintext);
	char *ciphertext = (char *)malloc(size + 1);
	strcpy(ciphertext,plaintext);
	while(plaintext[i] != '\0'){
		if(isalpha(plaintext[i])){
			ciphertext[i] += key;
			if((ciphertext[i] >=65 && ciphertext[i]<=90) || (ciphertext[i]>=97 && ciphertext[i] <= 122)){}
			else
				ciphertext[i] -= 26;

		}
		i++;
	}
	ciphertext[i] = '\0';
	return ciphertext;
}

char* decrypt(char *ciphertext, int key) {
	int i = 0,size = sizeof(ciphertext);
	char *plaintext = (char *)malloc(size + 1);
	strcpy(plaintext,ciphertext);
	while(ciphertext[i]!=''){
		if(isalpha(ciphertext[i])){
			plaintext[i] -= key;
			if((plaintext[i] >=65 && plaintext[i]<=90) || (plaintext[i]>=97 && plaintext[i] <= 122)){}
			else
				plaintext[i] += 26;
	}
		i++;
	}
	plaintext[i] = '\0';
	return plaintext;
}
