function fibo(n) {
  function fiboUp(a, b, i) {
    if(i == n) return a+b;
    else return fiboUp(b, a+b, i+1);
  }

  if(n < 2) return n;
  else return fiboUp(0, 1, 2);
}


console.log(fibo(6));
