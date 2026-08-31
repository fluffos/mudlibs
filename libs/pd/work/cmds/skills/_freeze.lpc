//      _tremble.c
//      Mage ability
//      written by Daboura, based on missile

#include <daemons.h>
#include <std.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;

int spell();
string type() { return "attack"; }
int cmd_freeze(string str) {
  object tp, ob;
  int i, which, skip, attack;
  object *inv;
  string what;

  if (!spell()) {
    return 0;
  }

  tp = this_player();

  if(tp->query_ghost()) {
    notify_fail("You emit a ghostly moan.\n");
    return 0;
  }

  if (tp->query_busy())
    return notify_fail("You are too busy to cast this spell.\n");

  if(environment(tp)->query_property("no magic")
   || environment(tp)->query_property("no attack")) {
    notify_fail("Something seems to be blocking your concentration.\n");
    return 0;
  }

  if(tp->query_casting()) return notify_fail("You are already casting a spell!");

  if((int)tp->query_mp() < 10) {
    notify_fail("Too low on magic power.\n");
    return 0;
  }

  if (str) ob = present(str, environment(tp));
  else ob = tp->query_current_attacker();

  if (!ob) return notify_fail("Freeze who?");

  if(!living(ob)) {
    notify_fail(ob->query_cap_name()+" is not a living thing!\n");
    return 0;
  }

  if(ob==tp) {
    notify_fail("You shiver from the cold.\n");
    return 0;
  }
  if(ob->is_player() && !interactive(ob)) {
    notify_fail("You cannot attack link-dead players.\n");
    return 0;
  }
  if(ob->query_property("no magic")) {
    notify_fail(sprintf("%s is immune to such magic.\n",
      ob->query_cap_name()));
    return 0;
  }
  attack = BALANCE3_D->get_damage( tp, ob, 1, ({ "magic attack", "nature" }),
   ({ "wisdom" }) );

  attack = attack * 80 / 100;

  if(attack < 10) attack = 15 +random(5);
  if(attack > 150) attack = 150 + tp->query_level();

  if(!this_player()->kill_ob(ob)) {
    write(ob->query_cap_name()+" can't be attacked by you yet.");
    return 1;
  }

  write("%^BOLD%^%^CYAN%^You call upon %^GREEN%^%^BOLD%^M%^RESET%^%^GREEN%^o%^BOLD%^t%^RESET%^%^GREEN%^h%^BOLD%^e%^RESET%^%^GREEN%^r %^BOLD%^N%^RESET%^%^GREEN%^a%^BOLD%^t%^RESET%^%^GREEN%^u%^BOLD%^r%^RESET%^%^GREEN%^e %^BOLD%^%^CYAN%^to freeze the air around "
   +ob->query_cap_name()+ "!%^RESET%^"); 
  write("%^BOLD%^%^CYAN%^The air around " +ob->query_cap_name()+ " %^RESET%^%^CYAN%^f%^BOLD%^r%^RESET%^%^CYAN%^e%^BOLD%^e%^RESET%^%^CYAN%^z%^BOLD%^e%^RESET%^%^CYAN%^s%^BOLD%^!%^RESET%^");

  message("room","%^BOLD%^%^CYAN%^"+tp->query_cap_name()+
   " force the air around "
   +ob->query_cap_name()+" to %^RESET%^%^CYAN%^f%^BOLD%^r%^RESET%^%^CYAN%^e%^BOLD%^e%^RESET%^%^CYAN%^z%^BOLD%^e!%^RESET%^", environment(tp), ({tp,ob}));            

  message("ob", "%^BOLD%^%^CYAN%^"+tp->query_cap_name()+ 
   " forces the air around you to %^RESET%^%^CYAN%^f%^BOLD%^r%^RESET%^%^CYAN%^e%^BOLD%^e%^RESET%^%^CYAN%^z%^BOLD%^e!"
   ,ob);

  if(tp->query_skill("nature") > ob->query_skill("magic defense"))
  {
    if(tp->query_stats("wisdom") > 3*(ob->query_stats("wisdom"))/2)
    {
      if(random(3) < 2 && !ob->query_paralyzed()) 
	ob->set_paralyzed(2+random(3), "The air is frozen around you!");
    }
  }

  tp->add_skill_points("magic attack", attack/20 + 2);
  tp->add_skill_points("nature", attack/20 + 2);

  tp->add_mp(-BALANCE3_D->get_cost(attack, 1, "mp"));

  tp->set_magic_round();

  ob->do_damage("all", attack, DAMAGE_FAITH | DAMAGE_ICE, DAMAGE_NO_SEVER, tp);

  return 1;
}
void help() {
  write("Syntax: <freeze [(living)]>\n"
   "A druid can call upon Mother Nature "
   "to freeze the air around a target.\n");
}
int spell() {
  object tp;
  tp = this_player();
  if (!tp) return 0;
  if (tp->query_subclass() != "druid") return 0;
  if (tp->query_level() < 4) return 0;


  return 1;
}

