/* LeetCode 264 - Ugly Number II */
/* by jennygaz */
int values[2000] {};

int nthUglyNumber(int n) {
  values[0] = 1;
  int prev_pow2 {0}, prev_pow3 {0}, prev_pow5 {0};
  for( int i = 1; i < n; ++ i ) {
    int pow2 = values[prev_pow2] * 2;
    int pow3 = values[prev_pow3] * 3;
    int pow5 = values[prev_pow5] * 5;
    values[i] = min( pow2, min( pow3, pow5 ) );
    if( values[i] == pow2 ) ++ prev_pow2;
    if( values[i] == pow3 ) ++ prev_pow3;
    if( values[i] == pow5 ) ++ prev_pow5;
  }
  return values[n - 1];
}
