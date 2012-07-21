#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

// Takes a line and replaces any spaces with tabs unless
// those spaces are in a double-quoted or bracketed context.
int main() {
  string line;
  cin.sync_with_stdio(false);
  while (std::getline(cin, line)) {
    const char* head = line.c_str();
    short quotes = 0;
    short brackets = 0;
    while (*head) {
      if (*head == '"' && *(head-1) != '\\')
        quotes ^= 1;
      if (*head == '[' && !quotes)
        brackets ^= 1;
      if (*head == ']' && brackets)
        brackets ^= 1;
      if (*head == ' ' && !quotes && !brackets)
        cout << '\t';
      else
        cout << *head;
      ++head;
    }
    cout << endl;
  }
  return 0;
}
