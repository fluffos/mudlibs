#include <daemons.h>
#include <std.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;

int abil();

string type() { return "attack"; }

int cmd_pincer(string str) {
  object tp, ob;
  int i, which, skip, attack, cost;
  object *inv, *wield, *knives;
  string what;    
  knives = ({});

  if (!abil())
    return 0;

  tp = this_player();

  if(tp->query_ghost())
    return notify_fail("You emit a ghostly moan.\n");

  if (tp->query_disable())
    return notify_fail("You are too busy to perform that move!\n");

  if(environment(tp)->query_property("no attack"))
    return notify_fail("Some strange force prevents your attack.\n");

  if(tp->query_casting()) return notify_fail("You are casting a spell!");

  if(tp->query_sp() < 30) 
    return notify_fail("You are too tired!\n");

  if (str) ob = present(str, environment(tp));
  else ob = tp->query_current_attacker();

  if (!ob) return notify_fail("Attack who?");

  if(!living(ob)) {
    notify_fail(ob->query_cap_name()+" is not a living thing!\n");
    return 0;
  }

  if(ob==tp)
    return notify_fail("Pincer yourself with daggers?\n");

  if(ob->is_player() && !interactive(ob))
    return notify_fail("You cannot attack link-dead players.\n");

  if(environment(tp)->query_property("no attack"))
    return notify_fail("Some strange force prevents your attack!\n");

  if(!this_player()->kill_ob(ob))
    return notify_fail(ob->query_cap_name()+" can't be attacked by you yet.\n");

  wield = tp->query_wielded();

  if(!wield)
    return notify_fail("You need a weapon to do this move with!\n");

  i = sizeof(wield);
  while (i--) {
    if(wield[i]->query_type() == "knife")
      knives  += ({ wield[i] });
  }
  if(sizeof(knives) < 2)    	
    return notify_fail("You need two knives to use this move!\n");

  /*
  attack = BALANCE2_D->get_Pdamage( tp, ob, 2, 
   ({ "knife", "perception", "double wielding", "attack" }),
   ({ "dexterity", "dexterity", "strength" }), 
   ({ "dexterity" }) );

  attack = attack * 1.3;

  if(attack < 10) attack = 15 +random(5);
  */

  attack = BALANCE3_D->get_damage(tp, ob, 4,
    ({ "knife", "perception", "double wielding", "attack" }),
    ({ "dexterity", "dexterity", "strength" }),
    ({ "dexterity" }) );
  attack = attack * 108 / 100;

  attack = attack + (knives[0]->query_wc()*3/2) + (knives[1]->query_wc()*3/2);

  cost = BALANCE3_D->get_cost(attack, 4, "sp") * 105 / 100;

  if (tp->query_sp() < cost)
    return notify_fail("You are too tired.");

  write("%^BOLD%^You %^BLACK%^t%^RESET%^%^BLUE%^r%^BOLD%^%^BLACK%^a%^RESET%^%^BLUE%^p%^BOLD%^%^WHITE%^ "
   +ob->query_cap_name()+
   " between your %^BLACK%^d%^RESET%^a%^BOLD%^%^BLACK%^g%^RESET%^g%^BOLD%^%^BLACK%^e%^RESET%^r%^BOLD%^%^BLACK%^s%^WHITE%^ and %^RED%^th%^RESET%^%^RED%^ru%^BOLD%^st%^WHITE%^ them into "
   +ob->query_objective()+
   "!"
  );

  message("room", "%^BOLD%^"
   +tp->query_cap_name()+
   " %^BLACK%^t%^RESET%^%^BLUE%^r%^BOLD%^%^BLACK%^a%^RESET%^%^BLUE%^p%^BOLD%^%^BLACK%^s%^WHITE%^ "
   +ob->query_cap_name()+
   " between "
   +tp->query_possessive()+
   " %^BLACK%^d%^RESET%^a%^BOLD%^%^BLACK%^g%^RESET%^g%^BOLD%^%^BLACK%^e%^RESET%^r%^BOLD%^%^BLACK%^s%^WHITE%^, then %^RED%^th%^RESET%^%^RED%^rus%^BOLD%^ts%^WHITE%^ them into "
   +ob->query_objective()+
   "!"
   , environment(tp), ({tp,ob}));

  message("target", "%^BOLD%^"
   +tp->query_cap_name()+
   " %^BLACK%^t%^RESET%^%^BLUE%^r%^BOLD%^%^BLACK%^a%^RESET%^%^BLUE%^p%^BOLD%^%^BLACK%^s%^WHITE%^ you between "
   +tp->query_possessive()+
   " %^BLACK%^d%^RESET%^a%^BOLD%^%^BLACK%^g%^RESET%^g%^BOLD%^%^BLACK%^e%^RESET%^r%^BOLD%^%^BLACK%^s%^WHITE%^, then %^RED%^th%^RESET%^%^RED%^rus%^BOLD%^ts%^WHITE%^ them into you!"
   ,ob);

  ob->do_damage("target", attack, DAMAGE_PHYSICAL | DAMAGE_PIERCE, 0, tp);

  tp->add_skill_points("attack", attack/20 + 2);
  tp->add_skill_points("knife", attack/20 + 2);
  tp->add_skill_points("perception", attack/20 + 2);
  tp->add_skill_points("double wielding", attack/20 + 2);

  tp->add_sp(-cost);

  tp->set_disable();

  return 1;
}
void help() {
  write("Syntax: <pincer [(living)]>\n"
   "Those skilled in knives can use their skill to "
   "trap their target between their knives.\n");
}
int abil() {
  object tp;
  tp = this_player();
  if (!tp) return 0;
  if (tp->query_subclass() != "scout") return 0;
  if (tp->query_skill("double wielding") < 360) return 0;
  if (tp->query_skill("knife") < 360) return 0;
  if (tp->query_skill("perception") < 360) return 0;
  return 1;
}

