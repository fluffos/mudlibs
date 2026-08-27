//Basic wear command.  Orig by Casper 10/13/95
// 04/23/96  Made changes w.r.t. armour::query_worn() returning 0 for not worn.

#include <object_types.h>
#include <command.h>
 
int main(string str)
{
  object armour,tp;
  int i;
 
  if(!str)
    return notify_fail("Wear what?\n");
  if(!(armour = present(str,tp = this_player())))
    return notify_fail("You have no "+str+".\n");
  if(!(tp == environment(armour)))
    return notify_fail("You have no "+str+".\n");
  if(!(armour->query_object_class() & OBJECT_ARMOUR))
    return notify_fail(armour->short()+" is not something to can wear.\n");
  if(armour->query_worn())
    return notify_fail("You are allready wearing "+armour->short()+".\n");
  i = member_array(armour->query_type(),tp->query_armour_types());
  if (i == -1)
    return notify_fail("You have no place to wear "+armour->short()+".\n");
  return tp->do_wear(armour, 1);
}
