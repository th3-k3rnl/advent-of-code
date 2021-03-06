#include "io.h"

using namespace std;

void part1(vector<int> inputs, int num_inputs) {
	int num_increases = 0;

	for (int idx = 1; idx < num_inputs; ++idx) {
		if (inputs.at(idx) > inputs.at(idx - 1))
			++num_increases;
	}
	cout << "PART 1" << "\n";
	cout << "number of increases = " << num_increases << "\n";
}

void part2(vector<int> inputs, int num_inputs) {
	int sliding_window = 0;
	int num_increases = 0;

	for(int idx = 3; idx < num_inputs; ++idx) {
		int new_sliding_window = inputs.at(idx - 2) +
			inputs.at(idx - 1) +
			inputs.at(idx);

		if (new_sliding_window > sliding_window)
			++num_increases;

		sliding_window = new_sliding_window;
	}
	cout << "PART 2" << "\n";
	cout << "number of increases = " << num_increases << "\n";
}

int main(int argc, char** argv) {
	if (argc < 2) {
		cout << "Path to input file required.\n";
		return EXIT_FAILURE;
	}  

	vector<int> inputs = read_file_int(argv[1]);
	int num_inputs = inputs.size();

	if (num_inputs == 0)
		return EXIT_FAILURE;

	part1(inputs, num_inputs);
	part2(inputs, num_inputs);

	return EXIT_SUCCESS;
}
