#include <daemons.h>
inherit DAEMON;
int abil();
int cmd_shimmer(string str)
{
 int a;
  string target_thing;
 object ob;
   if (!abil())
      return notify_fail("What?\n");
 if ((!str || str=="") && !this_player()->query_current_attacker())
   {
    write("Shimmer what?");
    return 1;
  }
   if (environment(this_player())->query_property("no attack"))
     {
      write("Greater powers prevent your malice.");
      return 1;
     }
   if(this_player()->query_wielded() == ({ })) {
        notify_fail("You need a weapon with which to shimmer.\n");
        return 0;
    }
   
  if (this_player()->query_current_attacker()) 
    ob = this_player()->query_current_attacker();
   else {
     ob = present(str, environment(this_player()));
     if (!ob)
       {
        write("You do not see that here.");
        return 1;
       }
     if (ob==this_player())
       return notify_fail("Three words: Seek professional help..\n");
    }
a =  this_player()->query_skill("attack")/2 +
        this_player()->query_skill("faith")/2 +
        this_player()->query_stats("strength") +
        this_player()->query_stats("dexterity")/2 +
       random(this_player()->query_level());
   a -= ob->query_skill("defense")*2/3 +
        ob->query_stats("dexterity")*2/3 +
        ob->query_stats("constitution");
 if (this_player()->query_sp() < 50) 
   {
    write("You are exhausted.");
    return 1;
   }
   if(this_player()->query_disable()) return 1;
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   this_player()->set_disable();
    if (a < 10)
      {
        write("Your opponent does not fall for your attack.");
        return 1;
   }
    write("Your body shimmers, and when "+ob->query_cap_name()+" leasts "
     "expects it, you strike "+ob->query_objective()+"!");
    say(this_player()->query_cap_name()+"'s body shimmers and changes, confusing you..", this_player());
    message("info", this_player()->query_cap_name()+" strikes at you!", ob);
  ob->damage(a);
  ob->check_on_limb(target_thing);
  this_player()->add_sp(-a/7);
 return 1;
}
int abil() {
   object o;
   o = this_player();
   if (o && o->query_class() == "fighter")
   if (o->query_level() >= 9 && o->query_subclass() == "antipaladin")
   return 1;
}
void help() {
 write(@ENDTEXT
Syntax: <shimmer [enemy]>
This strange antipaladin attack makes the antipaladin's body shimmer so it
is hard to trace, and then the antipaladin strikes when their opponent
cannot see where they are.
ENDTEXT);
}
