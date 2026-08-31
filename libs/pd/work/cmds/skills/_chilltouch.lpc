#include <std.h>
#include <daemons.h>
inherit DAEMON;

int spell();

string type() { return "attack"; }

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
      return notify_fail("What?\n");



   if (env->query_property("no attack") || env->query_property("no magic"))
      return notify_fail("Greater powers prevent your malice.\n");


   if (!living(ob))
    return notify_fail("Syntax: <Chilltouch may only be cast upon the
living.\n");

   if (ob == tp)
      return notify_fail("That is not possible.\n");

   if (tp->query_mp() < 95) 
      return notify_fail("Your spell fails, due to lack of magic.\n");

    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   dmg = tp->query_skill("magic attack")*3/2;
   dmg += tp->query_stats("intelligence");
   dmg += tp->query_stats("wisdom");
   dmg -= ob->query_skill("magic defense")/2;
   dmg -= ob->query_stats("wisdom");
  if (dmg < 30) {
     write("%^BOLD%^CYAN%^Your spell fails!%^RESET%^");
      tell_room(env, "%^BOLD%^CYAN%^"+tp->query_cap_name()+"'s spell fails.%^RESET%^", ({ tp }));
      return 1;
   }

write("%^BOLD%^CYAN%^The freezing death of %^WHITE%^c%^CYAN%^hi%^WHITE%^ll%^CYAN%^tou%^WHITE%^c%^CYAN%^h burns your victim!%^RESET%^");
if (tp->query_skill("magic attack") < (tp->query_level()*6)) {
write("%^BLUE%^"+ob->query_cap_name()+"'s energy empowers you.");
tp->add_skill_bonus("magic attack", ma , tp->query_level()*3);
}  
tell_room(env, "%^BOLD%^CYAN%^"+tp->query_cap_name()+" freezes the soul of %^BOLD%^CYAN%^"+ob->query_cap_name()+" with a %^WHITE%^c%^CYAN%^hi%^WHITE%^ll%^CYAN%^tou%^WHITE%^c%^CYAN%^h! %^RESET%^", ({ tp, ob }));
tell_room(env, "%^BOLD%^CYAN%^"+ob->query_cap_name()+" trembles in pain from the life draining energy of "+tp->query_cap_name()+"!%^RESET%^", ({ ob, tp }));
tell_object(ob, "%^BOLD%^CYAN%^"+tp->query_cap_name()+" freezes your soul with a %^WHITE%^c%^CYAN%^hi%^WHITE%^ll%^CYAN%^tou%^WHITE%^c%^CYAN%^h! %^RESET%^");
tell_object(ob, "%^BOLD%^CYAN%^"+tp->query_cap_name()+"'s life draining power sends terrible waves of pain through your body!");

   ob->add_hp(-(dmg/2));
   tp->set_casting(dmg + random(tp->query_level()/2));
   tp->set_disable();
   tp->add_mp(-dmg/7);
   return 1;
}

void help() {
write("
Syntax: <chilltouch [living target]>
A spell used by by liches to feed upon the life energy of the living. 
The victim suffers great pain as the lich grows in power from the lifeforce.
See also: lich
");
}

int spell() {
   object o;
   o = this_player();
   if (o->query_level() < 1) return 0;
   if (o->query_race() == "lich")
      return 1;
}


