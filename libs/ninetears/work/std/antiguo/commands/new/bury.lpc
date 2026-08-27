/* Cleaning up.
 * Wonderflug, 96.
 */

int bury(string str,object x)
{
  object me;
  object *target;
  int counter,i;
 
  if(x) 
    me = x;
  else
    me = this_player();

  if (!str || str == "") 
    str = "corpse";

  if(me->query_dead())
  {
    tell_object(me,"You, a disembodied ghost, expect to bury your own "
      "corpse ?.\nCyric pats you on the head and tells you: Nice try.\n ");
    return 1;
  }

  target = all_inventory(environment(me));

  counter = 0;
  for (i=0;i<sizeof(target);i++)
    if( target[i]->query_corpse() )
    {
      target[i]->dest_me(); // Allow them to clean up themselves.
      counter++;
    }

  if (counter)
    tell_object(me,"You bury the corpse"+(counter == 1?"":"s")+
      " deep within the earth.\n");
  else
    tell_object(me,"You can't find the corpse!\n");

  return 1;
}

string help()
{
  return
    "\nSyntax: bury\n\n"
    "This command buries all the corpses in the room.  Anything in the "
    "corpses gets buried with them.\n\n";
}
