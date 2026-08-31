#include <daemons.h>
#include <std.h>
inherit DAEMON;
int abil();

string type() { return "attack"; }
 
int cmd_circle (string str) {
   
  int attack, total, ds;
   int i, tmp;
   object ob, *weapons;

   if (!abil()) {
      return 0;
   }
    weapons = (object *)this_player()->query_wielded();
    ds = 0;
    for(i=0, tmp = sizeof(weapons); i<tmp; i++) {
        if((string)weapons[i]->query_type() != "knife") continue;
        ds = 1;
    }
    if(!ds) {
      return notify_fail("You need a knife or dagger to circle with!\n");
    }
    if(!str) {
      ob = (object)this_player()->query_current_attacker();
    }
    else {
       ob = present(str, environment(this_player()));
       if(!ob) ob = parse_objects(environment(this_player()), str);
    }
   if(!ob || !living(ob)) {
        notify_fail("You do not see that here.\n");
      return 0;
   }
   if (ob==this_player())
     return notify_fail("You cannot do that.\n");
   if(this_player()->query_ghost()) {
      notify_fail("Planning on dying again?\n");
      return 0;
   }
   if (this_player()->query_disable())
     {
      write("You are not balanced enough to circle.");
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
   if(this_player()->query_ghost()) {
      return notify_fail("You can't hurt anyone in that form.\n");
   }
    if((int)this_player()->query_sp() < 150) {
        notify_fail("You are too tired.\n");
        return 0;
    }
    this_player()->set_disable();
    if (ob->query_stats("dexterity")+ob->query_skill("defense")/3  > this_player()->query_stats("dexterity")+30+this_player()->query_skill("attack"))
      {
       write("You circle around your opponent, thrusting your dagger right next to them !");
       tell_room(environment(this_player()), this_player()->query_cap_name()+" misses their chance of circling!", ({ ob, this_player() }));
       return 1;
      }
      write("%^YELLOW%^You Circle around "+ob->query_cap_name()+" thrusting your knife into their back!%^RED%^\n");
      attack = BALANCE_D->get_damage( this_player(), ob, 4, ({ "attack","murder","murder","agility","knife" }),
                    ({ "strength", "dexterity", "dexterity" }), ({"dexterity", "strength"}) );

    if (attack < 25) return notify_fail("You miss.\n");
    if(this_player()->query_arena())
      if(!present(ob->query_name(), environment(this_player())))
        return 1; 
    total = attack;
      tell_room(environment(this_player()), this_player()->query_cap_name()+ " circles around "+(string)ob->query_cap_name() + "\n", ({ob, this_player()}));
      tell_object(ob, this_player()->query_cap_name()+" circles around you thrusting "+this_player()->query_possessive()+" knife into your back!\n");
      this_player()->add_skill_points("attack", attack/20);
      this_player()->add_skill_points("knife", attack/20);
      this_player()->add_sp(-total/10);
      ob->damage(total);
      return 1;
   }

void help() {
   write("Syntax: <circle [(living)]>\n\n"
      "This command allow's rogues to circle behind there opponents, landing a vital blow.");
}

int abil() {
   object r;
   r = this_player();
   if (!r) return 0;
   if (r->query_class() != "rogue") return 0;
   if (r->query_level() < 50) return 0;
   if (r->query_subclass() == "scout") return 0;
   if (r->query_subclass() == "thug") return 0;
   return 1;
}
