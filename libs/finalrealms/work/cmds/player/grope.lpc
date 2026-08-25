// Grope (around in the dark)
// For blind players to find their way.
// Quark, April 97

#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;
void setup()
{
   position = 0;
}
string query_usage()
{
   return "grope (no parameter)";
}
string query_short_help()
{
   return "Lets you feel around the area for an exit.";
}
/*
protected int cmd(string arg, object me)
*/
int cmd(string arg, object me)
{
mixed *exits, exit;
object *contents;
int i,j;

i = random(10);

if(!me->query_property("BLIND")) return 0;

 if(me->query_property("JUST_SEARCHED"))
 {
   notify_fail("You must wait a while to regain your balance "
               "before trying to grope again.\n");
   return 0;
 } 
 me->add_timed_property("JUST_SEARCHED",1,1);

 if(i<3)
   {
    contents = all_inventory(environment(me)); 
    j = random(sizeof(contents));
    if(interactive(contents[j]))
     {
       tell_object(me, "You bump into "+
        contents[j]->query_cap_name()+"!\n");
       tell_object(contents[j],me->query_cap_name()+" bumps "
        "into you.\n");
       tell_object(environment(me),me->query_cap_name()+" bumps "
        "into "+contents[j]->query_cap_name()+".\n",({ me, contents[j]}));
      }
     else
      if(contents[j]->query_npc())
       {
        tell_object(me, "Oh no, you seem to have stepped on a "
          "nearby "+contents[j]->query_cap_name()+"!\n");
        tell_object(environment(me),me->query_cap_name()+" steps on "
         "a "+contents[j]->query_cap_name()+"!\n",({ me, }));
        contents[j]->attack_ob(me);
       }
     else
      {
       tell_object(me,"You trip over a "+contents[j]->query_cap_name()+
          ".\n");
       tell_object(environment(me),me->query_cap_name()+" trips over "
          "a nearby "+contents[j]->query_cap_name()+".\n");
       }      
    return 1;
   }
  else
   {
    exits = environment(me)->query_dest_dir();  
    if(sizeof(exits))
     {
      exit = exits[(random(sizeof(exits)/2))*2];
      tell_object(me, "You grope around and find an exit to "
       "the "+exit+".\n");
      return 1;
     }
    }
  notify_fail("You cannot find anything.\n");
  return 0;
}
