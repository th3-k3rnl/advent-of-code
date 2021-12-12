#include <bits/stdc++.h>

#define NUM_BITS 5

using namespace std;

typedef vector<pair<string, int>> Instruction;

vector<int> read_file_int(string file_path);

Instruction read_file_string(string file_path);

vector<bitset<NUM_BITS>> read_file_bits(string file_path);


// template <typename T>
// class IO {
// 	char* file_path;

// 	public:
// 	IO(char* fp) : file_path(fp);

// 	~IO();

// 	T read_file();
// };
