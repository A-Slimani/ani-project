#include <iostream>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

using namespace std;

/*
	NOTES / TODO
	- Figure out how to crawl through each directory (somewhat done)
	- Figure out how to detect file types (done I think)
	- Get the files in order
*/

void listFiles(const char* dirname){
	// opens directory
	DIR* dir = opendir(dirname); 

	if (dir == NULL){
		printf("empty.\n");
	}

	printf("----------------- \n");
	printf("Reading files in: %s\n", dirname);
	printf("----------------- \n");

	// assigns the dir structure and reads it
	struct dirent* entity;
	entity = readdir(dir);

	while(entity != NULL){

		// ignores dot files 
		bool ignore_matrix = strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0;

		// prints files that are not dot files	
		if (ignore_matrix) printf("%d %s\n", entity->d_type ,entity->d_name);

		// if it comes across a file directory it will run the function recursively
		if(entity->d_type == DT_DIR && ignore_matrix){
			// path name
			char path[100] = { 0 };

			// adds the directory name with the current path
			strcat(path, dirname);
			strcat(path, "/");
			strcat(path, entity->d_name);

			// runs the function recursively
			listFiles(path);
		}

		entity = readdir(dir);
	}
	closedir(dir);
}

int main(int argc, char* argv[]){
	listFiles("/home/aboud/anime/");
	return 0;
}
