#include <boost/filesystem.hpp>
#include <boost/filesystem/operations.hpp>
#include <iostream>

using namespace std;
using namespace boost::filesystem;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cout << "Usage: tut2 path\n";
    return 1;
  }

  path p(argv[1]); // avoid repeated path construction below

  // doest path p actually exists?
  if (exists(p)) {
    // is path p a regular file?
    if (is_regular_file(p))
      cout << p << " size is " << file_size(p) << endl;

    // is path p a directory?
    else if (is_directory(p))
      cout << p << " is a directory" << endl;

    else
      cout << p << " exists, but is not a regular file or directory" << endl;
  } else
    cout << p << " does not exists" << endl;

  return 0;
}