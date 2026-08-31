#include <std.h>
#include <daemons.h>
inherit DAEMON;
#define WT    "%^RESET%^%^BOLD%^"
#define BL    "%^BLUE%^"
#define BK    "%^BLACK%^"
#define RD    "%^RED%^"

int abil();
void finish_him(object *stuff);

int cmd_dragonfury(string str) {
   object ob, tp, env, *blah;
   tp = this_player();
   env = environment(tp);

   if (str)
      return notify_fail("Syntax: <dragonfury>\n");

   ob = tp->query_current_attacker();

   if (!abil())
      return 0;

   if (tp->query_class() != "dragon")
      return 0;

   if (!ob) {
      notify_fail("You are not in combat.\n");
      return 0;
   }

   if (tp->query_level() < 12)
      return notify_fail("You cannot do that here.\n");

   if (env->query_property("no attack") || env->query_property("no magic"))
      return notify_fail("Greater powers prevent your malice.\n");

   if (!living(ob))
      return notify_fail("You cannot call fury upon an inanimate object!\n");

   if (tp->query_disable())
      return notify_fail("You are busy.\n");

   if (ob == tp)
      return notify_fail("And give up your own life??\n");

   if (tp->query_sp() < 50) 
      return notify_fail("You are too tired.\n");

   tp->set_disable();
   tp->set_magic_round(2);
   tp->paralyze(3, "You dare not break your concentration!");
   write("%^RESET%^%^BOLD%^%^B_BLUE%^You ask the dragons of long ago to come to your aid...");
   blah = ({ tp , ob });
   call_out("finish_him", 3, blah);
   return 1;
}

void finish_him(object *stuff) {
   object ob, tp;
   int dmg;

   tp = stuff[0];
   ob = stuff[1];

   if(!ob)
     return;

   if(environment(ob) != environment(tp)) {
     write("Your prey has evaded you!");
     return;
   }

   tp->set_disable();

    if(!this_player()->kill_ob(ob)) {
       return;
    }

   dmg = tp->query_skill("attack")/2 + tp->query_skill("flying") + tp->query_skill("claw");
   dmg += tp->query_skill("breath") + tp->query_skill("tail");
   dmg -= ob->query_stats("constitution") + ob->query_stats("dexterity");
   dmg -= ob->query_skill("defense");
   dmg *= 3/2;
   if (dmg < 40) {
      write("You call goes unheeded.");
      return;
   }
   message("info","The power of "WT"a"BL"l"BK"l"RD" t"WT"h"BL"e"BK" d"RD"r"WT"a"BL"g"BK"o"RD"n"WT"s%^RESET%^ falls upon "+ob->query_cap_name()+" and blasts "
      +ob->query_objective()+" completely!", tp);
   tell_object(ob, "The power of "WT"a"BL"l"BK"l"RD" t"WT"h"BL"e"BK" d"RD"r"WT"a"BL"g"BK"o"RD"n"WT"s%^RESET%^ combines and blasts you completely!");
   message("info", "The power of "WT"a"BL"l"BK"l"RD" t"WT"h"BL"e"BK" d"RD"r"WT"a"BL"g"BK"o"RD"n"WT"s%^RESET%^ falls upon "+ob->query_cap_name()+" and blasts "
      +ob->query_objective()+" completely!",environment(tp),({ ob, tp }));
   tp->add_sp(- dmg/7);
   ob->damage(dmg + random(this_player()->query_level()));
   return;
}

void help() {
write("
Syntax: <dragonfury>\n
The highest of dragons are able to call upon their
ancestors, who may come to their aid.  The combination
of all the dragon elders is enough to destroy the
most powerful of enemies.
");
}

int abil() {
   object o;
   o = this_player();
   if (o && o->query_level() >= 50)
   if (o->query_class() == "dragon")
     return 1;
}
