//     A fighter physical ability for use with blunt weapons
//     Written by Asmodeus for Primal Darkness
 
#include <std.h>
inherit DAEMON;
int abil();
 
int cmd_maul (string str) {
   
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
        if((string)weapons[i]->query_type() != "blunt") continue;
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
      write("You are unable to maul at this time.");
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
    if (ob->query_stats("dexterity")+ob->query_skill("defense")/3  >
this_player()->query_stats("dexterity")+random(50)+this_player()->query_skill("attack"))

      {
       write("You swing and miss!\n");
       tell_room(environment(this_player()), this_player()->query_cap_name()+
"fails in an attempt to maul "+ob->query_cap_name()+"!\n", ({ ob, this_player() }));
       return 1;
      }
      write("You MAUL "+ob->query_cap_name()+" with a heavy blow!");
      attack = this_player()->query_skill("attack")/3 + this_player()->query_skill("blunt")/3;
      attack += this_player()->query_stats("strength")/2;
      attack -= ob->query_stats("dexterity")/2;
      attack -= ob->query_skill("defense")/3;
    if (attack < 35) return notify_fail("You swing and miss!\n");
      tell_room(environment(this_player()), this_player()->query_cap_name()+
     " MAULS "+(string)ob->query_cap_name() + " with a heavy blow!", ({ob, this_player()}));
      tell_object(ob, this_player()->query_cap_name()+" MAULS you with a heavy blow!");
      total = random(this_player()->query_level()*2) + (attack);
if ((total) > ob->query_skill("defense")*3 + random(300)) {
     write(ob->query_cap_name()+" has been temporarily immobilized!\n");
   tell_room(environment(this_player()), ob->query_cap_name()+" has been temporarily immobilized!\n", ({ob, this_player()}));
      tell_object(ob, "You are unable to focus after the crushing blow!");
    ob->set_paralyzed(random(3)+1);
}
      this_player()->add_skill_points("attack", total/60);
      this_player()->add_skill_points("blunt", total/80);
      this_player()->add_sp(-((total)/7));
      ob->damage(total + random(this_player()->query_level()/2));
      return 1;
   }

void help() {
   write("Syntax: <maul [(living)]>\n\n"
      "A powerful fighter attack used with blunt weapons.  If the hit is strong enough, this attack will temporarily immobilize your target.");
}

int abil() {
   object r;
   r = this_player();
   if (!r) return 0;
if (r && r->query_class() == "fighter" && r->query_level() >= 15) return 1;
}
