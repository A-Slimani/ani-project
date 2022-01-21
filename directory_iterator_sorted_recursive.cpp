#include <boost/filesystem.hpp>
#include <boost/filesystem/operations.hpp>
#include <iostream>

using std::cout;
using std::endl;
using namespace boost::filesystem;

void get_files(path p) {

  if (is_directory(p)) {
    cout << p << " is a directory containing: (in alphabetical order) " << endl;

    std::vector<path> v;

    for (auto &&x : directory_iterator(p))
      v.push_back(x.path());

    std::sort(v.begin(), v.end());

    for (auto &&x : v)
      cout << "   " << x.filename() << endl;
  } else
    cout << p << " exists, but is not a regular file or directory. " << endl;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cout << "provide a path" << endl;
    return 1;
  }

  path p(argv[1]);

  try {
    if (exists(p)) {
      if (is_regular_file(p))
        cout << p << " size is " << file_size(p) << endl;

      // wanna put the recursive function here
      // get_files() <-- recursive function

    } else
      cout << p << " does not exist" << endl;

  } catch (const filesystem_error &ex) {
    cout << ex.what() << endl;
  }

  return 0;
}