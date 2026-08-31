#include <daemons.h>
#include <std.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;

int abil();

string type() { return "attack"; }

int cmd_gnash(string str) {
  object tp, ob;
  int i, which, skip, attack;
  object *inv;
  string what;

  if (!abil()) {
    return 0;
  }

  tp = this_player();

  if(tp->query_ghost())
    return notify_fail("You emit a ghostly moan.\n");

  if (tp->query_busy())
    return notify_fail("You are too busy to do that.\n");

  if(environment(tp)->query_property("no attack"))
    return notify_fail("Some strange force prevents your attack.\n");

  if(tp->query_sp() < 20) 
    return notify_fail("You are too tired!\n");

  if (str) ob = present(str, environment(tp));
  else ob = tp->query_current_attacker();

  if (!ob) return notify_fail("Gnash who?");

  if(!living(ob)) {
    notify_fail(ob->query_cap_name()+" is not a living thing!\n");
    return 0;
  }

  if(ob==tp)
    return notify_fail("Bite yourself?\n");

  if(ob->is_player() && !interactive(ob))
    return notify_fail("You cannot attack link-dead players.\n");

  if(environment(tp)->query_property("no attack"))
    return notify_fail("Some strange force prevents your attack!\n");

  attack = BALANCE3_D->get_damage( tp, ob, 4, ({ "attack", "melee", "attack" }),
   ({ "dexterity", "strength" }), ({"dexterity", "strength"}) );

  //	attack = attack * 1.3;

  if(!this_player()->kill_ob(ob)) {
    write(ob->query_cap_name()+" can't be attacked by you yet.");
    return 1;
  }

  write("%^BOLD%^%^RED%^You gnash at " +ob->query_cap_name()+ " with your teeth!%^RESET%^");

  message("room","%^RED%^%^BOLD%^"+tp->query_cap_name()+
   " gnashes at "
   +ob->query_cap_name()+
   " with their theeth!%^RESET%^", environment(tp), ({tp,ob}));            

  message("ob", "%^RED%^%^BOLD%^"+tp->query_cap_name()+ " gnashes at you with "
   +tp->query_possessive()+
   " teeth!%^RESET%^",ob);

  ob->do_damage("target", attack, DAMAGE_PHYSICAL | DAMAGE_PIERCE, 0, tp);

  tp->add_skill_points("attack", attack/20 + 2);
  tp->add_skill_points("melee", attack/20 + 2);

  tp->add_sp(-BALANCE3_D->get_cost(attack, 4, "sp"));

  tp->set_disable();

  return 1;
}
void help() {
  write("Syntax: <gnash [(living)]>\n"
   "A wolf can bite an attacker with thier "
   "sharp teeth, causing great damage.\n");
}
int abil() {
  object tp;
  tp = this_player();
  if (!tp) return 0;
  if(tp->query("wolf")) return 1;

  return 0;
}

