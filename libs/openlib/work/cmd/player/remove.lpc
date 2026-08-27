#include <object_types.h>
#include <command.h>
 
int main(string str)
{
  object tp,armour;
 
  if(!str)
    return notify_fail("Remove what?\n");
  if(!(armour = present(str,(tp = this_player()))))
    return notify_fail("You have no "+str+".\n");
  if(tp != environment(armour))
    return notify_fail("You have no "+str+".\n");
  if(!(armour->query_object_class() & OBJECT_ARMOUR))
    return notify_fail("You are not wearing "+armour->short()+".\n");
  if(!armour->query_where_worn())
    return notify_fail("You are not wearing "+armour->short()+".\n");
  tp->do_remove(armour);
  return 1;
}
