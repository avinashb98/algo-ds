#include <iostream>
using namespace std;

int main() {
  long long t, f, l, s, n, d, a;
  cin >> t;
  while(t--) {
    cin >> f >> l >> s;
    n = (s * 2)/(f + l);
    cout << n << endl;
    d = (l - f)/(n - 5);
    a = f - 2 * d;
    cout << a;
    for(long long i = 0; i < n - 1; i++){
      a += d;
      cout << " "<< a;
    }
    cout << endl;
  }
  return 0;
}
