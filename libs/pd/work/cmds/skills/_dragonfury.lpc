#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;
#define WT    "%^RESET%^%^BOLD%^"
#define BL    "%^BLUE%^"
#define BK    "%^BLACK%^"
#define RD    "%^RED%^"

int abil();
string type() { return "attack"; }
void finish_him(object *stuff);

int cmd_dragonfury(string str) {
   object ob, tp, env, *blah;
   tp = this_player();
   env = environment(tp);

   if (!abil())
      return 0;

    if (!str || str == "")
      ob=tp->query_current_attacker();
    else
      ob=present(str, env);

   if (tp->query_class() != "dragon")
      return 0;

   if (!ob) {
      notify_fail("Call dragonfury upon who?\n");
      return 0;
   }

   if (tp->query_level() < 12)
      return notify_fail("You cannot do that here.\n");

   if (env->query_property("no attack") || env->query_property("no magic"))
      return notify_fail("Greater powers prevent your malice.\n");

   if (!living(ob))
      return notify_fail("You cannot call fury upon an inanimate object!\n");

   if (tp->query_ghost())
      return notify_fail("You cannot do that in your incorporeal form.\n");

   if (tp->query_busy())
      return notify_fail("You are busy.\n");

   if (ob == tp)
      return notify_fail("And give up your own life??\n");

   if (tp->query_sp() < 50) 
      return notify_fail("You are too tired.\n");

  if (!(tp->kill_ob(ob))) return notify_fail("You cannot attack that.\n");

   tp->set_magic_round();
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

   if(!tp || !ob)
     return;

   if(environment(ob) != environment(tp)) {
     write("Your prey has evaded you!");
     return;
   }

   tp->set_magic_round();

    if(!tp->kill_ob(ob)) {
       return;
    }

   dmg = BALANCE3_D->get_damage( tp, ob, 4, ({ "tail", "flying", "breath", "claw" }),
      ({ "wisdom", "intelligence", "strength", "dexterity" }),
      ({ "breath", "claw", "tail", "attack" })
    );
   dmg = dmg*3;
   if (dmg < 40) {
      write("Your call goes unheeded.");
      return;
   }
   message("info","The power of "WT"a"BL"l"BK"l"RD" t"WT"h"BL"e"BK" d"RD"r"WT"a"BL"g"BK"o"RD"n"WT"s%^RESET%^ falls upon "+ob->query_cap_name()+" and blasts "
      +ob->query_objective()+" completely!", tp);
   tell_object(ob, "The power of "WT"a"BL"l"BK"l"RD" t"WT"h"BL"e"BK" d"RD"r"WT"a"BL"g"BK"o"RD"n"WT"s%^RESET%^ combines and blasts you completely!");
   message("info", "The power of "WT"a"BL"l"BK"l"RD" t"WT"h"BL"e"BK" d"RD"r"WT"a"BL"g"BK"o"RD"n"WT"s%^RESET%^ falls upon "+ob->query_cap_name()+" and blasts "
      +ob->query_objective()+" completely!",environment(tp),({ ob, tp }));
   tp->add_sp(-(BALANCE3_D->get_cost(dmg, 4, "sp")));
   ob->do_damage("all", dmg/4, DAMAGE_MAGIC, DAMAGE_NO_HP, tp);
   ob->do_damage("random", dmg/2, DAMAGE_MAGIC, DAMAGE_NO_HP, tp);
   ob->do_damage("none", dmg, DAMAGE_MAGIC, DAMAGE_HP_ONLY, tp);
   return;
}

void help() {
write("
Syntax: <dragonfury [living]>\n
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
