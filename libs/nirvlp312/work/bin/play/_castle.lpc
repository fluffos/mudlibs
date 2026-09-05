#include <ansi.h>

status cmd_castle(string str) {
  object me, c, ec;
  int    cost;
  string castle;
  
  if((int)(me=this_player())->query_level() < 10) {
    write("You are too low of a level to use this command.\n"+
          "Explore a bit first.\n");
    return 1;
  }
  else
    cost=5;
  if((int)me->query_level() > 19) cost = 0;
  /** Removed by Gnar 
  me->spell_block();
  if((int)me->query_spell_block())
    return (write("You are unable to do that.\n"), 1);
  **********/
  if(!str)
    return (write("Usage: 'castle <creator>'\n\
Visit the old man in the adventurer's guild for a list.\n"), 1);
  if(creator(environment(this_player()))) {
    write("You cannot use this spell in a Wizard's realm.\n");
    if((int)this_player()->query_level() < 21)
    return 1;
    else write("You are a wizard...\n");
  }
  str = lower_case(str);
  if(file_size("/players/"+str) != -2) {
    write(capitalize(str)+" is not a wizard.\n");
    return 1;
  }
  if(str == "mizan")
    castle = "/players/mizan/ent";
  else
    castle = "/players/"+str+"/castle";
  if(!(c=find_object(castle)) || !(ec=environment(c)) ||
          creator(ec))
  {
    write(capitalize(str)+"'s castle is not open.\n");
    return 1;
  }
  
  if((int)this_player()->query_sp() < cost)
    return (write("You don't have enough spell points to cast this.\n"), 1);
  this_player()->add_spell_point(-cost);
  write("You cast the spell of "+HIG+"Castle"+NORM+"...\n");
  say((string)this_player()->query_name() + " casts the spell of " +
   HIC+"Castle"+NORM+"...\n");
  this_player()->move_player("X#"+object_name(environment(castle)));
  write("You are outside the realm of "+HIG+capitalize(str)+NORM+".\n");
  return 1;
}
