status matching_arrays(mixed *c, mixed *d)
{
  int   sc;

  sc = sizeof(c);

  if(sc != sizeof(d))
    return 0;

  while(sc--)
    if(c[sc] != d[sc])
      return 0;

  return 1;
}
