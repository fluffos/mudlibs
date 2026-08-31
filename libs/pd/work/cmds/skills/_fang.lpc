#include <daemons.h>
#include <std.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;

int abil();

string type() { return "attack"; }

int cmd_fang(string str) {
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
    return notify_fail("You are too busy to get the drop on your opponent!\n");

  if(environment(tp)->query_property("no attack"))
    return notify_fail("Some strange force prevents your attack.\n");

  if(tp->query_casting()) return notify_fail("You are casting a spell!");

  if(tp->query_sp() < 30) 
    return notify_fail("You are too tired!\n");

  if (str) ob = present(str, environment(tp));
  else ob = tp->query_current_attacker();

  if (!ob) return notify_fail("Drop on whom?");

  if(!living(ob)) {
    notify_fail(ob->query_cap_name()+" is not a living thing!\n");
    return 0;
  }

  if(ob==tp)
    return notify_fail("Get the drop on yourself?\n");

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

  attack = attack * 1.1;

  if(attack < 10) attack = 15 +random(5);
  */

  attack = BALANCE3_D->get_damage(tp, ob, 3,
    ({ "knife", "perception", "double wielding", "attack" }),
    ({ "dexterity", "dexterity", "strength" }),
    ({ "dexterity" }) );

  attack = attack + (knives[0]->query_wc()*3/2) + (knives[1]->query_wc()*3/2);

  cost = BALANCE3_D->get_cost(attack, 3, "sp") * 110 / 100;

  if (tp->query_sp() < cost)
    return notify_fail("You are too tired.");

  write("%^BOLD%^You %^GREEN%^s%^RESET%^%^GREEN%^p%^BOLD%^r%^RESET%^%^GREEN%^i%^BOLD%^n%^RESET%^%^GREEN%^g%^BOLD%^%^WHITE%^ into the %^BLUE%^a%^CYAN%^i%^BLUE%^r%^WHITE%^, with your daggers pointed to the %^BLUE%^s%^WHITE%^k%^BLUE%^y%^WHITE%^!%^RESET%^");
  write("%^BOLD%^You %^BLACK%^s%^WHITE%^p%^BLACK%^i%^WHITE%^n around in mid-%^CYAN%^a%^WHITE%^i%^CYAN%^r%^WHITE%^, point your daggers at "
   +ob->query_cap_name()+
   " and %^RED%^fall%^WHITE%^ at them!");
  write("%^BOLD%^You land on "
   +ob->query_cap_name()+
   " %^RED%^f%^RESET%^%^RED%^o%^BOLD%^r%^RESET%^%^RED%^c%^BOLD%^i%^RESET%^%^RED%^n%^BOLD%^g%^WHITE%^ your daggers into "
   +ob->query_objective()+
   "!");

  message("room", "%^BOLD%^" +tp->query_cap_name()+
   " %^GREEN%^s%^RESET%^%^GREEN%^p%^BOLD%^r%^RESET%^%^GREEN%^i%^BOLD%^n%^RESET%^%^GREEN%^g%^BOLD%^s%^WHITE%^ into the %^BLUE%^a%^CYAN%^i%^BLUE%^r%^WHITE%^, "
   "%^BLACK%^s%^WHITE%^p%^BLACK%^i%^WHITE%^n%^BLACK%^s%^WHITE%^ around, "
   "and %^RED%^lands%^WHITE%^ on "
   +ob->query_cap_name()+
   ", %^RED%^s%^RESET%^%^RED%^i%^BOLD%^n%^RESET%^%^RED%^k%^BOLD%^i%^RESET%^%^RED%^n%^BOLD%^g%^WHITE%^ "
   +tp->query_possessive()+
   " daggers deep into "
   +ob->query_objective()+
   "!", environment(tp), ({tp,ob}));

  message("target", "%^BOLD%^"
   +tp->query_cap_name()+
   " %^GREEN%^s%^RESET%^%^GREEN%^p%^BOLD%^r%^RESET%^%^GREEN%^i%^BOLD%^n%^RESET%^%^GREEN%^g%^BOLD%^s%^WHITE%^ into the %^BLUE%^a%^CYAN%^i%^BLUE%^r%^WHITE%^, "
   "%^BLACK%^s%^WHITE%^p%^BLACK%^i%^WHITE%^n%^BLACK%^s%^WHITE%^ around, "
   "and %^RED%^lands%^WHITE%^ on you!\n"
   "%^RED%^S%^RESET%^%^RED%^i%^BOLD%^n%^RESET%^%^RED%^k%^BOLD%^i%^RESET%^%^RED%^n%^BOLD%^g%^WHITE%^ "
   +tp->query_possessive()+
   " daggers into you!"
   , ob);

  ob->do_damage("random", attack, DAMAGE_PHYSICAL | DAMAGE_PIERCE, 0, tp);

  tp->add_skill_points("attack", attack/20 + 2);
  tp->add_skill_points("knife", attack/20 + 2);
  tp->add_skill_points("perception", attack/20 + 2);
  tp->add_skill_points("double wielding", attack/20 + 2);

  tp->add_sp(-cost);

  tp->set_disable();

  return 1;
}
void help() {
  write("Syntax: <fang [(living)]>\n"
   "Those skilled with knives, and aware of their surroundings can leap "
   "into the air, and use the force of the fall to push the knives into "
   "the target.\n");
}
int abil() {
  object tp;
  tp = this_player();
  if (!tp) return 0;
  if (tp->query_subclass() != "scout") return 0;
  if (tp->query_skill("double wielding") < 192) return 0;
  if (tp->query_skill("knife") < 192) return 0;
  if (tp->query_skill("perception") < 192) return 0;
  return 1;
}

