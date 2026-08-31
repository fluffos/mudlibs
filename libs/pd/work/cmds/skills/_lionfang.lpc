#include <daemons.h>
#include <std.h>
#include <damage.h>
#include <damage_types.h>
inherit DAEMON;

int abil();

string type() { return "attack"; }

int cmd_lionfang(string str) {
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
    return notify_fail("Stab yourself with daggers?\n");

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

  attack = attack * 1.2;

  if(attack < 10) attack = 15 +random(5);
  */

  attack = BALANCE3_D->get_damage(tp, ob, 4,
    ({ "knife", "perception", "double wielding", "attack" }),
    ({ "dexterity", "dexterity", "strength" }),
    ({ "dexterity" }) );

  attack = attack + (knives[0]->query_wc()*3/2) + (knives[1]->query_wc()*3/2);

  cost = BALANCE3_D->get_cost(attack, 4, "sp");

  if (tp->query_sp() < cost)
    return notify_fail("You are too tired.");

  write("%^BOLD%^You %^CYAN%^sw%^BLACK%^i%^CYAN%^ng%^WHITE%^ your daggers at "
   +ob->query_cap_name()+
   "!\n"
   "Your daggers %^YELLOW%^p%^MAGENTA%^i%^YELLOW%^e%^MAGENTA%^r%^YELLOW%^c%^MAGENTA%^e%^WHITE%^ "
   +ob->query_objective()+
   " causing %^RED%^b%^RESET%^%^RED%^l%^BOLD%^o%^RESET%^%^RED%^o%^BOLD%^d%^WHITE%^ to spill onto the %^GREEN%^g%^RESET%^%^GREEN%^r%^BOLD%^o%^RESET%^%^GREEN%^u%^BOLD%^n%^RESET%^%^GREEN%^d%^BOLD%^%^WHITE%^!");

  message("room", "%^BOLD%^"
   +tp->query_cap_name()+
   " %^CYAN%^sw%^BLACK%^in%^CYAN%^gs%^WHITE%^ "
   +tp->query_possessive()+
   " daggers at "
   +ob->query_cap_name()+
   "!\n"
   +tp->query_cap_name()+    
   " %^YELLOW%^p%^MAGENTA%^i%^YELLOW%^e%^MAGENTA%^r%^YELLOW%^c%^MAGENTA%^e%^YELLOW%^s%^WHITE%^ "
   +ob->query_cap_name()+
   " causing %^RED%^b%^RESET%^%^RED%^l%^BOLD%^o%^RESET%^%^RED%^o%^BOLD%^d%^WHITE%^ to spill onto the %^GREEN%^g%^RESET%^%^GREEN%^r%^BOLD%^o%^RESET%^%^GREEN%^u%^BOLD%^n%^RESET%^%^GREEN%^d%^BOLD%^%^WHITE%^!"
   , environment(tp), ({tp,ob}));

  message("target", "%^BOLD%^"
   +tp->query_cap_name()+
   " %^CYAN%^sw%^BLACK%^in%^CYAN%^gs%^WHITE%^ "
   +tp->query_possessive()+
   " daggers at you!\n"
   +tp->query_cap_name()+
   " %^YELLOW%^p%^MAGENTA%^i%^YELLOW%^e%^MAGENTA%^r%^YELLOW%^c%^MAGENTA%^e%^YELLOW%^s%^WHITE%^ you,"
   " causing %^RED%^b%^RESET%^%^RED%^l%^BOLD%^o%^RESET%^%^RED%^o%^BOLD%^d%^WHITE%^ to spill onto the %^GREEN%^g%^RESET%^%^GREEN%^r%^BOLD%^o%^RESET%^%^GREEN%^u%^BOLD%^n%^RESET%^%^GREEN%^d%^BOLD%^%^WHITE%^!"
   ,ob);

  ob->do_damage("target", attack, DAMAGE_PHYSICAL | DAMAGE_PIERCE | DAMAGE_SLASH, 0, tp);

  tp->add_skill_points("attack", attack/20 + 2);
  tp->add_skill_points("knife", attack/20 + 2);
  tp->add_skill_points("perception", attack/20 + 2);
  tp->add_skill_points("double wielding", attack/20 + 2);

  tp->add_sp(-cost);

  tp->set_disable();

  return 1;
}
void help() {
  write("Syntax: <lionfang [(living)]>\n"
   "Those skilled with knives, and aware of their surroundings, can "
   "pierce the sides of their target in the vital areas, causing "
   "large amounts of blood loss.\n");
}
int abil() {
  object tp;
  tp = this_player();
  if (!tp) return 0;
  if (tp->query_subclass() != "scout") return 0;
  if (tp->query_skill("double wielding") < 270) return 0;
  if (tp->query_skill("knife") < 270) return 0;
  if (tp->query_skill("perception") < 270) return 0;
  return 1;
}

