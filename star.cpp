#include <iostream>
#include <string>

using namespace std;

void print_repeat(int n, char c);
void print_head(int n);
void print_line(int n);
void print_body(int n);
void print_leg(int n);

int main(int argc, char* argv[]) {
  int n;

  // Checking parameters
  try {
    n = stoi(argv[1]);
  }
  catch (exception const & e){
    cerr << "Usage: ./star" << endl;
    return -1;
  }

  if (n < 0) {
    cerr << "Usage: ./star" << endl;
    return -1;
  }
  // Handling special cases

  if (n == 0)
    return 0;

  else if (n == 1) { // n == 1 is considered as a special case, because the example output of n == 1 given in the description does not follow the same pattern as when n > 1.
    printf("   *\n*** ***\n *   *\n*** ***\n   *\n");
    return 0;
  }

  // Normal outputs
  print_head(n);
  print_line(n);
  print_body(n);
  print_line(n);
  print_leg(n);
  return 0;
}

void print_repeat(int n, char c) {
  for (int i = 0; i < n; i++)
    printf("%c", c);
}


void print_head(int n) {
  // Printing the head
  print_repeat(n * 3 - 1, ' ');
  printf("*\n");
  for (int i = 1; i < n; i++) {
    print_repeat(n * 3 - i - 1, ' ');
    printf("*");
    print_repeat(i * 2 - 1, ' ');
    printf("*\n");
  }
}

void print_line(int n) {
  print_repeat(2 * n + 1 , '*');
  print_repeat(2 * n - 3 , ' ');
  print_repeat(2 * n + 1, '*');
  printf("\n");
}

void print_body(int n) {
  // Print the upper body
  for (int i = 0; i < n; i++) {
    print_repeat(i + 1, ' ');
    printf("*");
    print_repeat(n * 6 - 2 * (i + 2) - 1, ' ');
    printf("*\n");
  }

  // Print the lower body, basically it's just reversing the code on top...
  for (int i = n - 2; i >= 0; i--) {
    print_repeat(i + 1, ' ');
    printf("*");
    print_repeat(n * 6 - 2 * (i + 2) - 1, ' ');
    printf("*\n");
  }
}

void print_leg(int n) {
  // Printing the leg, just reversing print_head()
  for (int i = n - 1; i > 0; i--) {
    print_repeat(n * 3 - i - 1, ' ');
    printf("*");
    print_repeat(i * 2 - 1, ' ');
    printf("*\n");
  }

  print_repeat(n * 3 - 1, ' ');
  printf("*\n");
}
