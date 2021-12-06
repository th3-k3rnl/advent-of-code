#include <io.h>

int main(int argc, char** argv) {
  if (argc < 2) {
    cout << "Path to input file required.\n";
    return EXIT_FAILURE;
  }  

  vector<int> inputs = read_file(argv[1]);
  int num_inputs = inputs.size();

  if (num_inputs == 0)
    return EXIT_FAILURE;

  return 0;
}
