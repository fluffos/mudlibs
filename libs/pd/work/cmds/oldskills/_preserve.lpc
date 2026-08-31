#include <std.h>
#include <daemons.h>
inherit DAEMON;

int spell();

int cmd_preserve(string str) {
   object ob, tp, env;
   if(!str) return notify_fail("What?\n");
   tp = this_player();
   env = environment(tp);
   ob = present(str, env);

   if (!ob)
      return notify_fail("You do not see that here.\n");

   if (tp->query_subclass() != "kataan" && tp->query_subclass() != "necromancer")
      return notify_fail("What?\n");

   if (tp->query_level() < 12) 
      return notify_fail("You are not experienced enough to do this.\n");

   if (!ob->query_corpse() && !ob->is_limb())
      return notify_fail("That is not a corpse or a limb.\n");

   if (tp->query_mp() < 20)
      return notify_fail("Your spell fails, due to lack of magic.\n");

/*   if (random(tp->query_skill("necromancy")) < random(50))
      return notify_fail("%^GREEN%^Your spell fails!\n");*/

   ob->preserve_me();
   write("%^GREEN%^You preserve "+ob->query_short()+".%^RESET%^");
   tell_room(environment(tp), "%^GREEN%^"+tp->query_cap_name()+" preserves "+
      ob->query_short()+".%^RESET%^", ({ tp }));
   ob->set_long(" %^GREEN%^(preserved)%^RESET%^ ");
   tp->add_mp(-random(15));
   return 1;
}

void help() {
write("
Syntax: <preserve [corpse/limb]>
This necromancer and kataan spell preserves a corpse or body part from
decaying completely.
See also: devour, offer, sacrifice, bury
");
}

int spell() {
   object o;
   o = this_player();
   if (o)
     if (o->query_subclass() == "kataan" || o->query_subclass() == "necromancer")
      if (o->query_level() >= 12)
          return 1;
}
