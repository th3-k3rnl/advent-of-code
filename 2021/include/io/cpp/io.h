#include <bits/stdc++.h>

#define NUM_BITS 12

using namespace std;

typedef vector<pair<string, int>> Instruction;

vector<int> read_file_int(string file_path);

Instruction read_file_string(string file_path);

vector<bitset<NUM_BITS>> read_file_bits(string file_path);
