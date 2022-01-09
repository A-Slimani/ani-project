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

	// stores the current directories into a vector 
	while(!dir_list.empty()){
		
		// ignores dot files
		bool ignore_matrix = strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0;

		// adds files onto the vector list 
		if (ignore_matrix) dir_list.push_back(entity); 

		// continues the while loop
		entity = readdir(dir);
	}

	for(int i = 0; i < dir_list.size(); i++){
		printf("%s \n",dir_list[i]->d_name);
	}

	closedir(dir);
}

int main(int argc, char* argv[]){
	listFiles("/home/aboud/anime/");
	return 0;
}
