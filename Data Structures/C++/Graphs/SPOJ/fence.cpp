#include<iostream>
#include <iomanip>
using namespace std;
#define PI 3.14159
int main() {
  int l;
  double ans;
  while(l != 0) {
    ans = (l*l)/(PI * 2);
    cout << fixed;
    cout << setprecision(2);
    cout << ans;
    cin >> l;
  }
  return 0;
}
