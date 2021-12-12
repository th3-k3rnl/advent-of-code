#include "io.h"

#define DIM 5



vector<int> get_bingo_draw() {
  
}


bool check_for_bingo() {}


void get_a_grid() {}


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
