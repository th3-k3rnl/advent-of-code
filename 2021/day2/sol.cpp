#include <io.h>

struct State {
  int depth = 0; // The number of units below the water level
  int disp  = 0; // Displacement in the forward direction
  int aim   = 0; // The magnitude of the aimed position of the submarine
};


State* part1(Instruction instructions) {
  State* state = new State();

  for (auto it=instructions.begin(); it!=instructions.end(); ++it) {
    if(it->first == "forward")
      state->disp += it->second;
    if(it->first == "down")
      state->depth += it->second;
    if(it->first == "up")
      state->depth -= it->second;
  }

  return state;
}


State* part2(Instruction instructions) {
  State* state = new State();

  for (auto it=instructions.begin(); it!=instructions.end(); ++it) {
    if(it->first == "forward") {
      state->disp += it->second;
      state->depth += state->aim * it->second;
    }
    if(it->first == "down")
      state->aim += it->second;
    if(it->first == "up")
      state->aim -= it->second;
  }

  return state;  
}


int main(int argc, char** argv) {
  string input;
  Instruction instructions;
  int product = 0;
  State* state1;
  State* state2;

  if (argc < 2) {
    cout << "Path to input file required.\n";
    return EXIT_FAILURE;
  }

  input = argv[1];

  instructions = read_file_string(input);

  if (instructions.size() == 0)
    return EXIT_FAILURE;

  // Part 1
  state1 = part1(instructions);
  product = state1->depth * state1->disp;
  cout << product << '\n';

  // Part 2
  state2 = part2(instructions);
  cout << state2->depth << " " << state2->disp << '\n';
  product = state2->depth * state2->disp;
  cout << product << '\n';

  return 0;
}
