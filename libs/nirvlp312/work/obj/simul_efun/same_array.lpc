status same_array(mixed *a, mixed *b)
{
  int x, y;
  if((y = sizeof(a)) != sizeof(b))
    return 0;
  while(y--)
  {
#ifndef __LDMUD__ /* Rumplemintz */
    if((x=member_array(a[y], b)) > -1)
#else
    if ((x = member(b, a[y])) > -1)
#endif
      b -= ({ b[x] });
    else
      return 0;
  }
  return 1;
}

status same_exact_array(mixed *a, mixed *b)
{
  int x, y;
  if((y = sizeof(a)) != sizeof(b))
    return 0;
  for(x=0;x<y;x++)
    if(a[x]==b[x])
      continue;
    else
      return 0;
  return 1;
}
