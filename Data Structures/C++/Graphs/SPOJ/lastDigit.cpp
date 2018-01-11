#include <iostream>
using namespace std;
int lastDigitPow(int a, int b) {
  int res = 1;
  for(int i = 0; i < b; i++) {
    res *= a;
  }
  return res % 10;
}
int main() {
  int t, a, b;
  cin >> t;
  while(t--) {
  	cin >> a >> b;
  	if(a == 0 && b == 0)
      cout << "1" << endl;
    else if(b == 0)
      cout << "1" << endl;
    else if(a == 0)
      cout << "0" << endl;
    else {
      b = (b % 4 == 0) ? 4 : b % 4;
      cout << lastDigitPow(a, b) << endl;
    }
  }
  return 0;
}
