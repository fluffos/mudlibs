//   a dungeonware.net production
//   26-Dec-00


#include <std.h>
inherit DAEMON;
int spell();

int cmd_fizgig (string str) {
    int mag, points, final, ran, temps;
    object ob;

   if (!spell()) {
     write("Your magic is not quite strong enough.");
     return 1;
   }
    this_player()->set_magic_round();
   if(!str) {
      ob = (object)this_object()->query_current_attacker();
      if(!ob) {
         notify_fail("Fizgig what?\n");
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
    if((mag = (int)this_player()->query_skill("illusion")) < 50) {
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
   if(!ob->kill_ob(this_player(),0)) return 1;
   if(ob->query_property("no magic")) {
     notify_fail(sprintf("%s is immune to your magic!\n",
		 ob->query_cap_name()));
     return 0;
   }
   if(environment(this_player())->query_property("no attack")) {
      notify_fail("A magic force prevents you from casting your spell.\n");
      return 0;
   }
   write("%^BLUE%^%^BOLD%^You send a ball of illusion fire "
	 "at your opponent!\n%^RESET%^You feel drained, and cannot move.");
    points = ((int)this_player()->query_mp())*2/3;
    points += mag - ((int)ob->query_stats("intelligence"))*5;
    if(points < 0) points = 1;
    temps = random(200-mag)/10;
    if(temps <7) temps =7;
    this_player()->set_paralyzed(temps/2);
    this_player()->add_skill_points("illusion", temps);
    this_player()->add_mp(-((int)this_player()->query_mp()));
    if(!(ran = random(4))) write("Your magic powers fail!");
    final = (points * ran)*3/4;
    this_player()->set_casting(final);
   tell_room(environment(this_player()), "%^RED%^%^BOLD%^"+
	     this_player()->query_cap_name()+" launches a large ball of "
	     "fire at "+(string)ob->query_cap_name()+"!",
	     ({ ob, this_player()}));
   tell_object(ob, "%^BLUE%^%^RED%^"+this_player()->query_cap_name()+
	       " launches a large ball of fire at you!");
   return 1;
}

void help() {
   write("Syntax: <fizgig [(living)]>\n\n"
      "Creates an illusion of a large ball of fire and launches it at the target. "
      "The illusion is real to the target thus causing damage.\n");
}

int spell() {
   object tp;
   tp = this_player();
   if (!tp) return 0;
   if (tp->query_class() != "mage") return 0;
   if (tp->query_skill("illusion") < 50) return 0;
   if (tp->query_level() < 10) return 0;
   if (tp->query_subclass() != "illusionist") return 0;
   return 1;
}

