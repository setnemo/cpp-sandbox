#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream input("input.txt");
  ofstream output("output.txt");
  if (input && output) {
    string line;
    while (getline(input, line)) {
      output << line << endl;
    }
  }
  return 0;
}
