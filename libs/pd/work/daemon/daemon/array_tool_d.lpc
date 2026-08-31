// This is the array toolbox

#include <std.h>
#define IS_IN(el,array) (member_array(el,array) != -1)

inherit DAEMON;

void create()
{
  ::create();
}

mixed *random_elements(mixed *a, int number)
{
  int rnd = random(sizeof(a));
  if(!number || number > sizeof(a)) return ({ });
  return ({ a[rnd] }) +
    this_object()->random_elements(a[0..rnd-1] + a[rnd+1..sizeof(a)], --number);
}

int is_in(mixed el, mixed *a) { return IS_IN(el, a); }

int same_array(mixed *a, mixed *b)
{
  int n = sizeof(b);
  if (n != sizeof(a)) return 0;
  return (sizeof(filter_array(a,"is_in",this_object(),b)) == n);
}

mixed *unique_elements(mixed *a)
{
  mixed *b = ({});
  int i, n = sizeof(a);
  for (;i < n; ++i)
    if (!IS_IN(a[i],b))
      b += ({a[i]});
  return b;
}

mixed *union_array(mixed *a, mixed *b)
{
  return unique_elements(a+b);
}

mixed *intersect_array(mixed *a, mixed *b)
{
  mixed *c = ({});
  int i, n = sizeof(a);
  for (;i < n; ++i)
    if(IS_IN(a[i],b))
      c += ({a[i]});
  return c;
}
