#include <iostream> //for cout

using std::cout;

void incrVar(int *pointerToVal) {
   //*pointerToVal to set value pointerToVal is pointing to
   *pointerToVal = *pointerToVal + 1;
}

int main(int argc, char** argv) {
   int i = 10;
   cout << "i before incrVal(&i): " << i << "\n";
   incrVar(&i);
   cout << "i after incrVal(&i): " << i << "\n";
}