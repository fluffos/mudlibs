//Wield command.  Orig by Casper
 
#include <object_types.h>
#include <weapon_types.h>
#include <command.h>
 
int main(string str)
{
  object weapon,tp;
  int free_hands,hands_used = 0,max_hands,hands_needed,i,j = 0;
  mixed *weapon_info, *this_weapon_info;
  if(!str)
  {
    notify_fail("Wield what?\n");
    return 0;
  }
  if(!(weapon = present(str,(tp = this_player()))))
  {
    notify_fail("You don't have a "+str+".\n");
    return 0;
  }
  if(environment(weapon)!=tp)
  {
    notify_fail("You don't have a "+str+".\n");
    return 0;
  }
 
  if(!(weapon->query_object_class() & OBJECT_WEAPON))
  {
    notify_fail(weapon->short()+" is not something to can wield.\n");
    return 0;
  }
  if(weapon->query_wielded())
  {
    notify_fail("You are already using a "+str+".\n");
    return 0;
  }
  free_hands = tp->query_free_hands();
  max_hands = tp->query_hands();
  hands_needed = weapon->query_hands();
  if (hands_needed == 1)
  {
    for(i = 0, j = 1; i < max_hands && !hands_used; j *=2, i++)
    {
      if(!(free_hands & j))
      {
        hands_used = j;
      }
    }
  }
  else
  {
    for(i = 0, j = 1; i < max_hands && !hands_used; j *=4, i +=2)
    {
      if((!free_hands & j) && (!free_hands & (j * 2)))
      {
        hands_used = j * 3;
      }
    }
  }
  if(!hands_used)
  {
    notify_fail("You haven't the free hands for a "+str+".\n");
    return 0;
  }
  return tp->do_wield(weapon, hands_used, 1);
}
