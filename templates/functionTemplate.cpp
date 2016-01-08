#include <iostream> //for cout

using std::cout;

//Requires T to implement + operator
template<class T>
T add(T a, T b) {
   return a + b;
}

int main(int argc, char** argv) {
   int a = 3, b = 4;
   cout << "add(3,4): " << add(a,b) << "\n";
   return 0;
}
