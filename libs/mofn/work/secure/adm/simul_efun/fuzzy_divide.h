int fuzzy_divide(int n, int d) {
  if(d < 0) {
    d *= -1;
    n *= -1;
  }
  if(n > 0)
    if(random(d) < n)
      return( (n/d) + 1);
    else
      return( (n/d) );

  if(random(d) > -n)
    return( (n/d) + 1 );
  else
    return( (n/d) );
}
