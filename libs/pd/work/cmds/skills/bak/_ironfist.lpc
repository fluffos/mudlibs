// a dungeonware.net production
// 8/20/2002 based on _jab.c
 
#include <daemons.h>
#include <std.h> 
inherit DAEMON;
int abil(); 
string type() { return "attack"; }
int cmd_ironfist (string str) {
   int attack, total;
   object ob;
   if (!abil()) {
      return 0;
   }
    if(!str)
      ob = (object)this_player()->query_current_attacker();
    else {
       ob = present(str, environment(this_player()));
       if(!ob) ob = parse_objects(environment(this_player()), str);
    }
   if(!ob || !living(ob)) {
        notify_fail("That is not here.\n");
      return 0;
   }
   if(ob == this_player())
      return notify_fail("Why would you want to do a thing like that?\n");
   if(this_player()->query_ghost()) {
      notify_fail("You're a ghost.\n");
      return 0;
   }
   if (this_player()->query_busy())
     {
      write("You are off balance.");
      return 1;
     }
   if(this_player()->query_ghost())
     return notify_fail("You have no body to punch with.\n");
   if(this_player()->query_casting()) return 1;
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   if(environment(this_player())->query_property("no attack")) {
      notify_fail("You cannot do that here.\n");
      return 0;
   }
    if((int)this_player()->query_sp() < 10) {
        notify_fail("You are too tired.\n");
        return 0;
    }
    this_player()->set_disable();
    if (ob->query_stats("constitution")+ob->query_skill("defense")/2 > this_player()->query_skill("melee")+30+this_player()->query_skill("attack"))
      {
       write("You miss your opponent.");
       tell_room(environment(this_player()), this_player()->query_cap_name()+ " misses an iron fisted strike against "+(string)ob->query_cap_name()+".", ({ ob, this_player() }));
       return 1;
      }
    
      write("You slam a fist of iron into "+ob->query_cap_name()+"!\n");
      attack = BALANCE_D->get_damage( this_player(), ob, 1, ({ "attack", "attack", "melee" }),
                                   ({ "strength" }) );
      tell_room(environment(this_player()), this_player()->query_cap_name()+ " strikes "+(string)ob->query_cap_name()+" with a fist of iron!\n", ({ob, this_player()}));
      tell_object(ob, this_player()->query_cap_name()+" strikes you with an iron fist!\n");
      total = (attack);
      this_player()->add_skill_points("attack", total/30);
      this_player()->add_sp(-total/7);
      ob->damage(total);
      return 1;
   }
void help() {
   write("Syntax: <ironfist [(living)]>\n\n"
         "Monks concentrate their chi into their fist causing "
         "it to harden like iron and strike at their target.");
}
int abil() {
   if (this_player()->query_subclass() != "monk") return 0;
   return 1;
}
