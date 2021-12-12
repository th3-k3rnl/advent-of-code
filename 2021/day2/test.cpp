#include "io.h"

using namespace std;

int main(int argc, char** argv) {
	string input;
	//  map<string, int> inputs;

	if (argc < 2) {
		cout << "Path to input file required.\n";
		return EXIT_FAILURE;
	}

	input = argv[1];

	read_file_string(input);
	//  int num_inputs = inputs.size();

	//  if (num_inputs == 0)
	//    return EXIT_FAILURE;

	//  for (const auto& input : inputs)
	//  for (auto input : inputs)
	//    cout << dir << " | " << mag << "\n";
	//    cout << input << "\n";

	return 0;
}
