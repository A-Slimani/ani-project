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

  // stores the current directories into a vector
  while (entity != NULL) {

    bool ignore_matrix =
        strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0;

    // adds files onto the vector list
    if (ignore_matrix)
      dir_list.push_back(entity);

    cout << "current dir: " << entity->d_name << endl;

    if (entity->d_type == DT_DIR && ignore_matrix) {
      // path name
      char path[100] = {0};

      // adds the directory name with the current path
      strcat(path, dirname);
      strcat(path, "/");
      strcat(path, entity->d_name);

      // runs the function recursively
      list_files(path);
    }

    // continues the while loop
    entity = readdir(dir);
  }

  // TODO : Sort folder based on type and name(alphabetical order)
  // sort(dir_list.begin(), dir_list.end());

  // Prints the sorted list
  // for (struct dirent *x : dir_list) {
  //   cout << x->d_name << endl;
  // }

  closedir(dir);
}

int main(int argc, char *argv[]) {
  list_files("/home/aboud/anime");
  return 0;
}
