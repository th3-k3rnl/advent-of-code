#include "io.h"


unsigned long get_power_consumption(vector<bitset<NUM_BITS>> lines) {
  bitset<NUM_BITS> gamma_rate;
  bitset<NUM_BITS> epsilon;
  int num_lines = lines.size();
  int sum[NUM_BITS] = {};

  for (int line = 0; line < num_lines; ++line) {
    for (int bit = 0; bit < NUM_BITS; ++bit) {
      sum[bit] += (int) lines.at(line)[bit];
    }
  }

  for (int bit = 0; bit < NUM_BITS; ++bit) {
    if (sum[bit] <= num_lines / 2) {
      gamma_rate[bit] = 0;
      epsilon[bit] = 1;
    } else {
      gamma_rate[bit] = 1;
      epsilon[bit] = 0;
    }
  }

  return gamma_rate.to_ulong() * epsilon.to_ulong();
}


int main(int argc, char** argv) {
  vector<bitset<NUM_BITS>> lines;
  string file_path;
  unsigned long power_consumption = 0;

  if (argc < 2) {
    cout << "Path to input file required.\n";
    return EXIT_FAILURE;
  }

  file_path = argv[1];
  lines = read_file_bits(file_path);
  
  if (lines.size() == 0) {
    cout << "Failed to return the contents of the input file.\n";
    return EXIT_FAILURE;
  }

  for (auto line : lines)
    cout << line << '\n';

  power_consumption = get_power_consumption(lines);
  cout << power_consumption << '\n';

  return EXIT_SUCCESS;
}
