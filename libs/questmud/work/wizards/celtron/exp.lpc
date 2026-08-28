/* reduces total with percent, returns new total */
string reduce_by_percent(string total, int percent) {
  int last, l;
  if(percent >= 100) return 0;
  l = strlen(total);
  if(l < 7) {
    last = to_int(total);
    last -= last /100 * percent;
    total = to_string(last);
    return total;
  }
  /* hard case. only 5 first numbers matter */

  last = to_int(total[0..4]);
  last -= last * percent / 100;
  total = to_string(last)+total[5..l];
  return total;
}
