#include <daemons.h>
#include <std.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;

int abil();

string type() { return "attack"; }

int cmd_crush(string str) {
  object tp, ob;
  int i, which, skip, attack;
  object *inv;
  string what;

  if (!abil())
    return 0;

  tp = this_player();

  if(tp->query_ghost())
    return notify_fail("You emit a ghostly moan.\n");

  if (tp->query_busy())
    return notify_fail("You are too busy to grab your prey!\n");

  if(environment(tp)->query_property("no attack"))
    return notify_fail("Some strange force prevents your attack.\n");

  if(tp->query_casting()) return notify_fail("You are casting a spell!");

  if(tp->query_sp() < 20) 
    return notify_fail("You are too tired!\n");

  if (str) ob = present(str, environment(tp));
  else ob = tp->query_current_attacker();

  if (!ob) return notify_fail("Crush who?");

  if(!living(ob)) {
    notify_fail(ob->query_cap_name()+" is not a living thing!\n");
    return 0;
  }

  if(ob==tp)
    return notify_fail("Crush yourself?\n");

  if(ob->is_player() && !interactive(ob))
    return notify_fail("You cannot attack link-dead players.\n");

  if(environment(tp)->query_property("no attack"))
    return notify_fail("Some strange force prevents your attack!\n");

  attack = BALANCE3_D->get_damage( tp, ob, 4, ({ "melee", "attack", "attack" }),
   ({ "dexterity", "strength", "strength" }), ({"dexterity", "strength"}) );

  attack = attack * 125/100;

  if(!this_player()->kill_ob(ob))
    return notify_fail(ob->query_cap_name()+" can't be attacked by you yet.\n");

  write("%^BOLD%^You grab " +ob->query_cap_name()+ " and %^RED%^c%^RESET%^%^RED%^r%^BOLD%^u%^RESET%^%^RED%^s%^BOLD%^h%^WHITE%^ "
   +ob->query_objective()+" with your arms!%^RESET%^");

  message("room","%^BOLD%^"+tp->query_cap_name()+
   " grabs "
   +ob->query_cap_name()+
   " and %^RED%^c%^RESET%^%^RED%^r%^BOLD%^u%^RESET%^%^RED%^s%^BOLD%^h%^RESET%^%^RED%^e%^BOLD%^s%^WHITE%^ "
   +ob->query_objective()+
   " with "
   +tp->query_possessive()+
   " arms!%^RESET%^", environment(tp), ({tp,ob}));            

  message("ob", "%^BOLD%^"+tp->query_cap_name()+ " grabs you and %^RED%^c%^RESET%^%^RED%^r%^BOLD%^u%^RESET%^%^RED%^s%^BOLD%^h%^RESET%^%^RED%^e%^BOLD%^s%^WHITE%^ you with "
   +tp->query_possessive()+
   " arms!%^RESET%^",ob);

  ob->do_damage("random", attack, tp->query_unarmed_damage_type(), tp->query_unarmed_damage_flags(), tp);

  tp->add_skill_points("attack", attack/20 + 2);
  tp->add_skill_points("melee", attack/20 + 2);

  tp->add_sp(-BALANCE3_D->get_cost(attack, 4, "sp") * 110 / 100);

  tp->set_disable();

  return 1;
}
void help() {
  write("Syntax: <crush [(living)]>\n"
   "A bear can crush its prey between its powerful "
   "arms, causing great pain and damage to the prey.\n");
}
int abil() {
  object tp;
  tp = this_player();
  if (!tp) return 0;
  if(tp->query_level() < 65) return 0;
  if(!tp->query("bear")) return 0;

  return 1;
}

