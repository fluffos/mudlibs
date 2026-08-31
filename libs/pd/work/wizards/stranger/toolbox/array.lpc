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
