#include <cstdint>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <inttypes.h>
#include <vector>

using namespace std;

/*
    NOTES / TODO
    - Save the struct in an array?
    -  
*/

void listFiles(const char* dirname){
	// opens directory
	DIR* dir = opendir(dirname); 

	if (dir == NULL){
		printf("empty.\n");
	}

	// assigns the dir structure and reads it
	struct dirent* entity;
	entity = readdir(dir);

	vector<struct dirent*> dir_list; 

	// ingores dot files
	// bool ignore_matrix = strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0;

	// stores the current directories into a vector 
	while(entity != NULL){

		bool ignore_matrix = strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0;
		// adds files onto the vector list 
		if (ignore_matrix) dir_list.push_back(entity); 

		// continues the while loop
		entity = readdir(dir);
	}

	// TODO : Sort folder based on type and name(alphabetical order)

	closedir(dir);
}

int main(int argc, char* argv[]){
	listFiles(".");
	return 0;
}
