#include <daemons.h>
inherit DAEMON;
int abil();
int cmd_headbutt(string str)
{
 int a;
 object ob;
   if (!abil()) {
      write("What?\n");
      return 1;
   }
 if ((!str || str=="") && !this_player()->query_current_attacker())
   {
    write("Headbutt whom?");
    return 1;
  }
   if (environment(this_player())->query_property("no attack"))
     {
      write("Greater powers prevent your malice.");
      return 1;
     }
   if (this_player()->query_level() < 8)
      return notify_fail("You cannot do this.\n");
  if (this_player()->query_current_attacker()) 
    ob = this_player()->query_current_attacker();
   else {
     ob = present(str, environment(this_player()));
     if (!ob)
       {
        write("You dont see that.");
        return 1;
       }
     if (ob==this_player())
      {
       write("Not the very easy to do, but I have faith in you...");
       return 1;
      }
    }
 if (this_player()->query_sp() < 30) 
   {
    write("You are too tired.");
    return 1;
   }
 a = this_player()->query_skill("melee")/2 + this_player()->query_stats("strength");
 a -= ob->query_skill("defense")/3 + ob->query_stats("constitution")/2;
   if(this_player()->query_casting()) return 1;
   if(this_player()->query_disable()) return 1;
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
    this_player()->set_disable();  
    if (a < 0)
      {
        write("You miss your headbutt!");
        say( this_player()->query_cap_name()+" misses "
           +possessive(this_player())+" headbutt!");
        return 1;
   }
    
    write("You grab "+ob->query_cap_name()+" by the shoulders and headbutt "+ob->query_objective()+".");
    message("info", this_player()->query_cap_name()+" headbutts "+ob->query_cap_name()+".", environment(this_player()), ({ this_player(), ob }));        
    message("info", this_player()->query_cap_name()+" grabs you "
       "by the shoulders and headbutts you!", ob);
  ob->set_target_limb(lower_case("head"));
  ob->damage(random(a*3/2));
                                 
  this_player()->add_sp(-(a/7));   
 return 1;
}
int abil() {
   object o;
   o = this_player();
   if (o && o->query_class() == "fighter")
   if (o->query_level() >= 8)
   return 1;
}
void help() {
write("Syntax: <headbutt [living]>\n"
      "A fighter may grab there opponent and using there head hit them.");
}
