#include <std.h>
#include <daemons.h>
inherit DAEMON;

int spell();

int cmd_chilltouch(string str) {
   int dmg, ma;
   object ob, tp, env;
   tp = this_player();
ma = 1;
   env = environment(tp);
    if (!str) ob = tp->query_current_attacker();
   else ob = present(str, env);

   if (!ob) {
      notify_fail("You do not see "+str+" here.\n");
      return 0;
   }

if (tp->query_casting()) return 1;
   if (tp->query_race() != "lich")
      return notify_fail("Only a lich may cast chilltouch.\n");



   if (env->query_property("no attack") || env->query_property("no magic"))
      return notify_fail("Greater powers prevent your malice.\n");


   if (!living(ob))
    return notify_fail("Syntax: <Chilltouch may only be cast upon the living.\n");

   if (ob == tp)
      return notify_fail("That is not possible.\n");

   if (tp->query_mp() < 95) 
      return notify_fail("Your spell fails, due to lack of magic.\n");
// Don't fuck with the dmg
   tp->kill_ob(ob);
/*  dmg = tp->query_skill("magic attack")*2 + random(tp->query_stats("intelligence"))*2;
    dmg += tp->query_stats("wisdom")*2 + random(50);
    dmg -= ob->query_stats("constitution")*3 + ob->query_stats("wisdom")*3+ random(350);
*/
   dmg = tp->query_skill("magic attack")*3/2 + tp->query_stats("intelligence");
   dmg += random(tp->query_stats("wisdom")) + (random(tp->query_level()));
   dmg -= ob->query_stats("constitution")/2 + ob->query_stats("wisdom");
   dmg *= 2;
   if (dmg < 10) {
      write("%^BOLD%^WHITE%^Your spell fails!");
      tell_room(env, "%^BOLD%^WHITE%^"+tp->query_cap_name()+"'s spell fails.", ({ tp }));
      return 1;
   }
   tell_room(env, "%^BOLD%^%^WHITE%^"+tp->query_cap_name()+" freezes the soul of "+ob->query_cap_name()+" with a %^CYAN%^c%^WHITE%^hi%^CYAN%^ll%^WHITE%^tou%^CYAN%^c%^WHITE%^h!%^RESET%^", ({ tp }));

   write("%^BOLD%^%^WHITE%^You feed on the soul of "+ob->query_cap_name()+" with a %^CYAN%^c%^WHITE%^hi%^CYAN%^ll%^WHITE%^tou%^CYAN%^c%^WHITE%^h.%^RESET%^");
tell_room(env, "%^BOLD%^CYAN%^"+ob->query_cap_name()+" trembles in pain from the life draining energy of "+tp->query_cap_name()+"!%^RESET%^", ({ ob, tp }));

  tell_object(ob, "%^BOLD%^CYAN%^"+ob->query_cap_name()+"'s life draining energy sends terrible waves of pain through your body!");
if (tp->query_skill("magic attack") < tp->query_level()*6) {
  write("%^BOLD%^CYAN%^You feel your power grow!%^RESET%^");
   tp->add_skill_bonus("magic attack", ma);
return 0;
}
if (tp->query_skill("magic attack") >= tp->query_level()*6) {
   write("%^BOLD%^CYAN%^You cause great damage but are unable to hold any more energy!%^RESET%^");
return 0;
}
   tp->add_mp(150 + random(this_player()->query_level()));
   tp->set_casting(dmg + random(tp->query_level()));
   return 1;
}

void help() {
write("
Syntax: <chilltouch [living target]>
A spell used by by liches to feed upon the souls of the living. 
The victim suffers great pain as the lich grows in power from the life energy.
See also: lich
");
}

int spell() {
   object o;
   o = this_player();
   if (o)
  if (o->query_race() == "lich")
      return 1;
}

