/*
 * ---------------------------------
 * Student Name:Daniel Fischer
 * Student ID: 200800490
 * Student Email: fisc0490@mylaurier.ca
 * ---------------------------------
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void count_letters(const char *filename, int counters[26]);
void write_results(const char *filename, int counters[26]);
void append_sum(const char *filename, int counters[26]);
const char ALPHABET[] = "abcdefghijklmnopqrstuvwxyz";
int main() {
	setbuf(stdout, NULL);

	char filename[20] = "text1.txt";
	int counters[26] = { 0 };

	count_letters(filename, counters);

	filename[4] = '2';
	write_results(filename, counters);

	append_sum(filename, counters);

	printf("Check text2.txt for output\n");

	return 0;
}
void count_letters(const char *filename, int counters[26]) {
    FILE* in_file = fopen(filename, "r"); // open file for reading
    if(in_file == NULL){
    	printf("Error(count_letters): Could not open file %s\n",filename);
        return;
    }
    char line[999];//arbitrary max line length
    while(fgets(line, sizeof(line),in_file)){ //keep reading lines until there's nothing left to read
    	for(int pos = 0; pos < strlen(line); pos++){//iterate through each character in line...
        	if(isalpha(line[pos])){//skip checking and increment position if current char is not alphabetical
            	for(int i = 0; i < strlen(ALPHABET); i++){//...for each character in the alphabet
                	if(tolower(line[pos]) == ALPHABET[i])//upper case and lower case are counted as same
                		counters[i]++;// increment the current element in counters for each match in the line
                }
            }
        }
    }
    fclose(in_file);
    return;
}
void write_results(const char *filename, int counters[26]) {
	FILE* out_file = fopen(filename, "w");//open file for writing
	if(out_file == NULL){
			printf("Error(write_results): Could not open file %s\n",filename);
			return;
	}
	for(int i = 0; i < strlen(ALPHABET); i++)
		fprintf(out_file, "count(%c) = %d\n", ALPHABET[i], counters[i]);//print each letter and its occurrence
	fclose(out_file);
	return;
}

void append_sum(const char *filename, int counters[26]) {
	FILE* out_file = fopen(filename, "r+"); // open file for reading & writing
	if(out_file == NULL){
		printf("Error(append_sum): Could not open file %s\n",filename);
		return;
	}
	int sum = 0;
	fseek(out_file, 0, SEEK_END); // get to the end of the file
	for(int i = 0; i < strlen(ALPHABET); i++)
		sum += counters[i]; // add up each number in counters
	fprintf(out_file, "Total = %d", sum); // print the total at the end of the file
	return;
}

