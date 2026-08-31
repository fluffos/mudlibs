//   /bin/user/_blast.c
//   from the Nightmare mudlib
//   A very powerful destruction spell
//   Created by Forlock on some strange date system that Descartes loves.
//   930417 17 april 1993 stardate 46835.9 170493
#include <std.h>
inherit DAEMON;
int spell();
int cmd_energybolt (string str) {
    int mag, points, final, ran, temps;
    object ob;
   if (!spell()) {
     write("What?\n");
     return 1;
   }
    this_player()->set_magic_round();
   if(!str) {
      ob = (object)this_object()->query_current_attacker();
      if(!ob) {
         notify_fail("Energybolt what?\n");
         return 0;
      }
   }
   else ob = present(str, environment(this_player()));
   if(!ob) ob = parse_objects(environment(this_player()), str);
    if(!ob || !living(ob)) {
        notify_fail("No "+str+" here.\n");
        return 0;
   }
   if (ob==this_player())
     {
      notify_fail("Ouch that would hurt.\n");
      return 0;
     }
   if(environment(this_player())->query_property("no magic")) {
      notify_fail("A magic force prevents your spell.\n");
      return 0;
   }
    if((mag = (int)this_player()->query_skill("wizardry")) < 175) {
      notify_fail("You are not skilled enough for this spell.\n");
      return 0;
   }
    if((points = (int)this_player()->query_mp()) <50) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
   if(this_player()->query_ghost()) {
      notify_fail("Your voice is hollow.\n");
      return 0;
   }
   if(this_player()->query_casting()) return 1;
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   if(ob->query_property("no magic")) {
     notify_fail(sprintf("%s is immune to your magic!\n",
                 ob->query_cap_name()));
     return 0;
   }
   if(environment(this_player())->query_property("no attack")) {
      notify_fail("A magic force prevents you from casting your spell.\n");
      return 0;
   }
   write("%^RED%^%^BOLD%^You summon up the forces of your life and send a hyperbolt of energy at your opponent!\n%^RESET%^You feel drained, and cannot move.");
    points = ((int)this_player()->query_mp());
    points += mag - ((int)ob->query_skill("magic defense"))*2;
    if(points < 0) points = 1;
    temps = random(mag)/20;
    if(temps < 2) temps = 2;
    if(temps > 5) temps = 5;
    this_player()->set_paralyzed(temps);
    this_player()->add_skill_points("wizardry", temps/5);
    this_player()->add_mp(-((int)this_player()->query_mp()/2));
    if(!(ran = random(4))) write("Your magic powers fail!");
    final = (points * ran);
    this_player()->set_casting(final);
   tell_room(environment(this_player()), "%^RED%^%^BOLD%^"+this_player()->query_cap_name()+" sends a hyperbolt of energy at "+(string)ob->query_cap_name()+"!",
             ({ ob, this_player()}));
   tell_object(ob, "%^RED%^%^BOLD%^"+this_player()->query_cap_name()+" sends a hyperbolt of energy at you.");
   return 1;
}
void help() {
   write("Syntax: <energybolt [(living)]>\n\n"
      "Focuses the collective energy of the universe and sends "
      "a hyper charged bolt of energy at the living object named. "
      " Doing this takes a great deal of energy, and will leave "
      "you temporarily immobile until the affects ware off.  This "
      "spell takes half of your magic points to cast.\n");
}
int spell() {
   object tp;
   tp = this_player();
   if (!tp) return 0;
   if (tp->query_class() != "mage") return 0;
   if (tp->query_skill("magic attack") < 175) return 0;
   if (tp->query_level() < 35) return 0;
   if (tp->query_subclass() != "wizard") return 0;
   return 1;
}
