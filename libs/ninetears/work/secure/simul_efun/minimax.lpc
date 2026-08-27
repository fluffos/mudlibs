
// by Dank Mar 11 93.  max may be a reserved word, so maxi is safer
int maxi(int *arra) {
  int i, j;
  if (!sizeof(arra)) {
    notify_fail("Array must contain one or more ints.\n");
    return 0;
  }
  j = arra[0];
  for (i=1; i<sizeof(arra); i++)
    if (arra[i] > j)
      j = arra[i];
  return j;
}

int mini(int *arra) {
  int i, j;
  if (!sizeof(arra)) {
    notify_fail("Array must contain one or more ints.\n");
    return 0;
  }
  j = arra[0];
  for (i=1; i<sizeof(arra); i++)
    if (arra[i] < j)
      j = arra[i];
  return j;
}
