//     based oon /bin/user/_stab.c
//     A rogue/fighter physical attack
//     asmodeus
 
#include <std.h>
inherit DAEMON;
int abil();
 
int cmd_impale (string str) {
   
   int attack, total, ds;
   int i, tmp;
   object ob, *weapons;

   if (!abil()) {
      write("What?\n");
      return 1;
   }
    weapons = (object *)this_player()->query_wielded();
    ds = 0;
    for(i=0, tmp = sizeof(weapons); i<tmp; i++) {
        if((string)weapons[i]->query_type() != "projectile") continue;
        ds = 1;
    }
    if(!ds) {
      return notify_fail("You are not equipped with a suitable weapon.\n");
    }
    if(!str)
      ob = (object)this_player()->query_current_attacker();
    else {
       ob = present(str, environment(this_player()));
       if(!ob) ob = parse_objects(environment(this_player()), str);
    }
   if(!ob || !living(ob)) {
        notify_fail("You do not see that here.\n");
      return 0;
   }
   if (ob==this_player())
    return notify_fail("That isn't recommended.\n");
   if(this_player()->query_ghost()) {
      notify_fail("Planning on dying again?\n");
      return 0;
   }
   if (this_player()->query_disable())
     {
      write("You are unable to impale at this time.");
      return 1;
     }
 
   
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   if(environment(this_player())->query_property("no attack")) {
      notify_fail("Greater powers prevent your malice.\n");
      return 0;
   }
    if((int)this_player()->query_sp() < 40) {
        notify_fail("You are too tired.\n");
        return 0;
    }
    this_player()->set_disable();
    if (ob->query_stats("dexterity")+ob->query_skill("defense")/3  > this_player()->query_stats("dexterity")+30+this_player()->query_skill("attack"))
      {
       write("You fail to impale your victim!");
       tell_room(environment(this_player()), this_player()->query_cap_name()+ "misses with an attempt to impale!", ({ ob, this_player() }));
       return 1;
      }
      write("You thrust and impale "+ob->query_cap_name()+" with a deep wound!\n");
      attack = this_player()->query_skill("attack")/2;
      attack += this_player()->query_stats("strength");
      attack -= ob->query_stats("dexterity")/2;
      attack -= ob->query_skill("defense")/3;
    if (attack < 10) return notify_fail("You miss.\n");
      tell_room(environment(this_player()), this_player()->query_cap_name()+
      " impales "+(string)ob->query_cap_name() + "!\n", ({ob, this_player()}));
      tell_object(ob, this_player()->query_cap_name()+" impales you!\n");
      total = random(this_player()->query_level())/2 + (attack);
      this_player()->add_skill_points("attack", total/40);
      this_player()->add_skill_points("projectile", total/40);
      this_player()->add_sp(-total/7);
      ob->add_hp(-total);
      return 1;
   }

void help() {
   write("Syntax: <impale [(living)]>\n\n"
      "A thrusting attack used with a spear, pike or other similar projectile.");
}

int abil() {
   object r;
   r = this_player();
   if (!r) return 0;
if (r->query_subclass() == "kataan"  && r->query_level() >= 13) return 1;
if (r->query_subclass() == "warrior" && r->query_level() >= 10) return 1;
}


