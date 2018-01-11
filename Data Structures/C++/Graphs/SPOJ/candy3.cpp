#include <iostream>
using namespace std;

int main() {
  int t, s, r, x, temp;
  cin >> t;
  while(t--) {
    cin >> s;
    temp = s;
    r = 0;
    while(temp--) {
      cin >> x;
      r = (r + x % s) % s;
    }
    if(!r) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
