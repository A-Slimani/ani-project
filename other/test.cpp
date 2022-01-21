#include <algorithm>
#include <cstdint>
#include <dirent.h>
#include <inttypes.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

/*
    NOTES / TODO
    - Save the struct in an array?
    -
*/

void list_files(const char *dirname) {
  // opens directory
  DIR *dir = opendir(dirname);

  if (dir == NULL) {
    printf("empty.\n");
  }

  // assigns the dir structure and reads it
  struct dirent *entity;
  entity = readdir(dir);

  vector<struct dirent *> dir_list;

  while (entity != NULL) {
    bool ignore_matrix =
        strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0;

    if (ignore_matrix)
      dir_list.push_back(entity);

    entity = readdir(dir);
  }

  closedir(dir);
}

int main() {
  list_files("/home/aboud/anime");
  return 0;
}