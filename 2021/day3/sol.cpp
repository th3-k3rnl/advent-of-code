#include "io.h"


bitset<NUM_BITS> get_most_common_bits(vector<bitset<NUM_BITS>> lines) {
  int num_lines = lines.size();
  int sum[NUM_BITS] = {};
  bitset<NUM_BITS> bitmask = {};

  for (int line = 0; line < num_lines; ++line) {
    for (int bit = 0; bit < NUM_BITS; ++bit) {
      sum[bit] += (int) lines.at(line)[bit];
    }
  }

  for (int bit = 0; bit < NUM_BITS; ++bit) {
    bitmask[bit] = sum[bit] <= num_lines / 2 ? 0 : 1;
  }
  return bitmask;
}


unsigned long get_power_consumption(vector<bitset<NUM_BITS>> lines) {
  bitset<NUM_BITS> gamma_rate = get_most_common_bits(lines);
  bitset<NUM_BITS> epsilon = ~gamma_rate;

  return gamma_rate.to_ulong() * epsilon.to_ulong();
}

unsigned long get_life_support_rating(vector<bitset<NUM_BITS>> lines) {
  bitset<NUM_BITS> o2_gen_rate;
  bitset<NUM_BITS> co2_scrub_rate;
  
  return o2_gen_rate.to_ulong() * co2_scrub_rate.to_ulong();
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

  //  for (auto line : lines)
  //    cout << line << '\n';

  power_consumption = get_power_consumption(lines);
  cout << power_consumption << '\n';

  return EXIT_SUCCESS;
}
