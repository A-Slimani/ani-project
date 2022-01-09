#include <iostream>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

using namespace std;

int main(int argc, char* argv[]){
	DIR* dir = opendir("C:\\Users");

	if (dir == NULL){
		cout << "empty." << endl;
	}

	struct dirent* entity;
	entity = readdir(dir);

	while(entity != NULL){
		cout << entity -> d_name << endl;
	}

	closedir(dir);

	return 0;
}