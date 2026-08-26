/*
 * returns array "a" minus "n" elements from "ind".
 */
mixed *delete(mixed *a, int ind, int n) {
  if (!pointerp(a) || ind < 0 || ind >= sizeof(a)) return a;
  if (sizeof(a)-n <= 0) return ({ });
  if (ind == 0)
    return a[n..sizeof(a)-n];
  if (ind == sizeof(a)-n)
    return a[0..ind-n];
  return a[0..ind-1] + a[ind+n..sizeof(a)-n];
}
