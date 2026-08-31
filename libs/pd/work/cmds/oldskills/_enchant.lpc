#include <std.h>
#include <daemons.h>
inherit DAEMON;

int spell();

int cmd_enchant(string str) {
   object ob, tp;
   tp = this_player();
   ob = present(str, tp);

   if (!ob) {
      ob = present(str, environment(tp));
      if (!ob) return notify_fail("You do not see that here.\n");
   }

   if (tp->query_subclass() != "sorceror" && tp->query_subclass() != "wizard"
        && tp->query_subclass() != "black")
      return notify_fail("What?\n");

   if (tp->query_level() < 14) 
      return notify_fail("You are not experienced enough to do this.\n");

   if (tp->query_mp() < 38)
      return notify_fail("Your spell fails, due to lack of magic.\n");

   if (ob->is_living())
      return notify_fail("You cannot enchant that.\n");

   if (tp->query_skill("conjuring") < 56)
      return notify_fail("Your powers of conjuring are not strong enough.\n");

   if (ob->query_enchanted())
      return notify_fail("It has already been enchanted.\n");

   if (ob->is_weapon()) {
      ob->set_wc(ob->query_wc() + random(5));
      ob->set_enchanted(1);
      write(ob->query_name()+" looks more deadly.");
   }
   if (ob->is_armour()) {
      ob->set_ac(ob->query_ac() + random(5));
      ob->set_enchanted(1);
      write(ob->query_name()+" looks tougher.");
   }
   if (ob->is_object()) {
      ob->set_value(ob->query_value() + ob->query_value()/4);
      ob->set_enchanted(1);
      if (ob->query_value() > 60)
         write(ob->query_name()+" looks much more valuable.");
   }
   tell_room(environment(tp), tp->query_cap_name()+" magically enchants "+
      ob->query_short()+".", ({ tp }));
   return 1;
}

void help() {
write("
Syntax: <enchant [object]>
This wizard and sorceror spell allows the caster to make the object
enchanted simply better at whatever it did originally.
");
}

int spell() {
   object o;
   o = this_player();
   if (o)
     if (o->query_subclass() == "wizard" || o->query_subclass() == "sorceror" || o->query_subclass() == "black")
      if (o->query_level() >= 14 && o->query_skill("conjuring") >= 56)
          return 1;
}
