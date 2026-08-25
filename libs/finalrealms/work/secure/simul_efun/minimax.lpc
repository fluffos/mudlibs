
// by Dank Mar 11 93.  max may be a reserved word, so maxi is safer
int maxi(int *arry) {
  int i, j;
  if (!sizeof(arry)) {
    notify_fail("Array must contain one or more ints.\n");
    return 0;
  }
  j = arry[0];
  for (i=1; i<sizeof(arry); i++)
    if (arry[i] > j)
      j = arry[i];
  return j;
}

int mini(int *arry) {
  int i, j;
  if (!sizeof(arry)) {
    notify_fail("Array must contain one or more ints.\n");
    return 0;
  }
  j = arry[0];
  for (i=1; i<sizeof(arry); i++)
    if (arry[i] < j)
      j = arry[i];
  return j;
}
