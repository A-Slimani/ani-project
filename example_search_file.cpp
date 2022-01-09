#include <iostream>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

using namespace std;

/*
	NOTES / TODO
	- Figure out how to crawl through each directory (somewhat done)
	- Figure out how to detect file types (done I think)
	- 
*/

void listFiles(const char* dirname){
	DIR* dir = opendir(dirname);

	if (dir == NULL){
		printf("empty.\n");
	}

	printf("----------------- \n");
	printf("Reading files in: %s\n", dirname);
	printf("----------------- \n");

	struct dirent* entity;
	entity = readdir(dir);

	while(entity != NULL){

		// ignores dot files 
		bool ignore_matrix = strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0;

		// prints files that are not dot files	
		if (ignore_matrix) printf("%d %s\n", entity->d_type ,entity->d_name);

		if(entity->d_type == DT_DIR && ignore_matrix){
			char path[100] = { 0 };

			strcat(path, dirname);
			strcat(path, "/");
			strcat(path, entity->d_name);

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
