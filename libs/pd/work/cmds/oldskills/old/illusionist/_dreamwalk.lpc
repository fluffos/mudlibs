//coded by asmodeus for primal darkness illusionists
//00.09.24

#include <std.h>
inherit DAEMON;
int spell();

int cmd_dreamwalk (string str) {
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
         notify_fail("Cast dreamwalk upon whom?\n");
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
      notify_fail("You're going to scare yourself?\n");
      return 0;
     }
   if(environment(this_player())->query_property("no magic")) {
      notify_fail("A magic force prevents your spell.\n");
      return 0;
   }
    if((mag = (int)this_player()->query_skill("conjuring")) < 30) {
      notify_fail("You are not skilled enough for this spell.\n");
      return 0;
   }
    if((points = (int)this_player()->query_mp()) <100) {
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
   write("BOLD%^BLUE%^You close your eyes and search your victim's mind for hidden fears!\n%^RESET%^BLUE%^Swirling images of pain and suffering begin to surface...");
    points = (int)this_player()->query_mp();
    points += mag - ((int)ob->query_stats("wisdom"))*5;
    if(points < 0) points = 1;
    temps = random(200-mag)/10;
    if(temps <4) temps =4;
    this_player()->set_paralyzed(temps);
    ob->set_paralyzed(temps);
    this_player()->add_skill_points("conjuring", temps);
    this_player()->add_mp(-((int)this_player()->query_max_mp()));
    if(!(ran = random(4))) write("Your magic powers fail!");
    final = points * ran;
    this_player()->set_casting(final);
   tell_room(environment(this_player()), "%^BOLD%^BLUE%^"+ob->query_cap_name()+" seems paralyzed with fear and unable to fight!",
          ({ ob, this_player()}));
   tell_object(ob, "%^BOLD%^BLUE%^You find yourself in combat with the horrors of your past!\n%^BLUE%^The pain feels so real!");
   return 1;
}

void help() {
   write("Syntax: <dreamwalk [(living)]>\n\n"
      "An illusionist spell that summons the victims darkest fears and calls these fears to battle.  The illusion causes no damage itself but the victim is unable to distinguish between the illusion and reality and hence suffers the pain.\n");
}

int spell() {
   object tp;
   tp = this_player();
   if (!tp) return 0;
   if (tp->query_class() != "mage") return 0;
   if (tp->query_level() < 10) return 0;
   if (tp->query_skill("conjuring") < 30) return 0;
   if (tp->query_subclass() != "illusionist") return 0;
   return 1;
}

