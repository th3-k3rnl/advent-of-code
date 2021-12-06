#include "io.h"

vector<string> tokenize(string s, string del = " ")
{
  int start = 0;
  int end = s.find(del);
  vector<string> parts;

  while (end != -1) {
    parts.push_back(s.substr(start, end - start));

    start = end + del.size();
    end = s.find(del, start);
  }
    
  parts.push_back(s.substr(start, end - start));
  return parts;
}


vector<int> read_file_int(string file_path) {
  int num;
  vector<int> nums;

  ifstream input(file_path);

  if (!input)
    cout << "Something went wrong opening file." << "\n";

  while(input >> num) {
    nums.push_back(num);
  }
  return nums;
}


Instruction read_file_string(string file_path) {
  string line;
  Instruction instructions;

  ifstream input(file_path);

  if (!input)
    cout << "Something went wrong opening file." << "\n";

  while(getline(input, line)) {
    vector<string> parts = tokenize(line);
    instructions.push_back( pair<string, int>(parts.at(0), stoi(parts.at(1))) );
  }

  return instructions;
}

vector<bitset<NUM_BITS>> read_file_bits(string file_path) {
  string line;
  vector<bitset<NUM_BITS>> lines;
  ifstream input(file_path);

  if (!input)
    cout << "Something went wrong opening file." << "\n";

  while(input >> line)
    lines.push_back(bitset<NUM_BITS>(string(line)));

  return lines;
}
