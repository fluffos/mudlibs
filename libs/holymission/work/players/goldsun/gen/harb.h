/* function returns 1 if a player is in this room, else returns 0
   use only in rooms
*/

int query_traveler_in_harbour(){ 
 object all;

  all=first_inventory(this_object());
  while(all)
  {
   if (living(all) && !all->query_npc()) return 1;
   all=next_inventory(all);
  }
  return 0;
}

