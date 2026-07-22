// rand.h
#ifndef __RAND__
#define __RAND__

int sum(int n,int base,int d)
{
  return (n*(2*base+(n-1)*d)/2);
}

int NewRandom(int n,int base,int d)
{ 
  int i = 1;
  int randnum = random(sum(n,base,d));

  if (sum(6,base,d) < randnum)
   {
    i = 7;
    while (sum(i,base,d) < randnum)
          i++;
    }
  else {
    while (sum(i,base,d) < randnum)
        i++;
   } 
  return (i-1);
}

#endif
