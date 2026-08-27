//Basic unwield command.  Orig by Casper 10/12/95
 
#include <object_types.h>
#include <weapon_types.h>
#include <command.h>
 
int main(string str)
{
  object weapon,tp;
  if(!str)
    return notify_fail("Unwield what?\n");
  if (!(weapon = present(str,(tp=this_player()))))
    return notify_fail("You don't have a "+str+".\n");
  if(environment(weapon)!=tp)
    return notify_fail("You don't have a "+str+".\n");
  if(!(weapon->query_object_class() & OBJECT_WEAPON))
    return notify_fail("you are not using "+weapon->short()+".\n");
  if(!weapon->query_wielded())
    return notify_fail("You are not using a "+str+".\n");
  return tp->do_unwield(weapon,1);
}
