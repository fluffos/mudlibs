#include <daemons.h>
#include <std.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;

int abil();

string type() { return "attack"; }

int cmd_claw(string str) {
  object tp, ob;
  int i, which, skip, attack;
  object *inv;
  string what;
  int rank;
  string *skills;

  if (!abil()) {
    return 0;
  }

  tp = this_player();

  if(tp->query_ghost())
    return notify_fail("You emit a ghostly moan.\n");

  if (tp->query_busy())
    return notify_fail("You are too busy to claw.\n");

  if(environment(tp)->query_property("no attack"))
    return notify_fail("Some strange force prevents your attack.\n");

  if(tp->query_casting()) return notify_fail("You are casting a spell!");

  if(tp->query_sp() < 20) 
    return notify_fail("You are too tired!\n");

  if(!str) {
    ob = (object)tp->query_current_attacker();
    if(!ob) {
      return notify_fail("Claw who?\n");
    }
  }
  else {
    ob = present(str, environment(tp));
    if(!ob) {
      sscanf(str, "%s %d", what, which);
      inv = all_inventory(environment(tp));
      for(i=0, skip = 0; i<sizeof(inv) && !ob; i++) {
	if(inv[i]->id(what)) {
	  skip++;
	  if(skip == which) ob = inv[i];
	}
      }
      if(!ob) {
	notify_fail("No "+str+" here!\n");
	return 0;
      }
    }
  }

  if(!living(ob)) {
    notify_fail(ob->query_cap_name()+" is not a living thing!\n");
    return 0;
  }

  if(ob==tp)
    return notify_fail("Claw yourself?\n");

  if(ob->is_player() && !interactive(ob))
    return notify_fail("You cannot attack link-dead players.\n");

  if(environment(tp)->query_property("no attack"))
    return notify_fail("Some force prevents your violence.\n");

  if (tp->query_level() >= 50) rank=4;
  else if (tp->query_level() >= 30) rank=3;
  else if (tp->query_level() >= 15) rank=2;
  else rank=1;

  skills = ({ "melee", "melee", "attack" });
  if (tp->query_class() == "vampire") skills += ({ "ferocity" });

  attack = BALANCE3_D->get_damage( tp, ob, rank, skills,
   ({ "dexterity", "strength" }), ({"dexterity", "strength"}) );


  //	attack = attack * 1.3;

  if(!this_player()->kill_ob(ob)) {
    write(ob->query_cap_name()+" can't be attacked by you yet.");
    return 1;
  }

  write("%^BOLD%^%^RED%^You slash at " +ob->query_cap_name()+ " with your claws!%^RESET%^");

  message("room","%^RED%^%^BOLD%^"+tp->query_cap_name()+
   " slashes at "
   +ob->query_cap_name()+
   " with "+tp->query_possessive()+" claws!%^RESET%^", environment(tp), ({tp,ob}));            

  message("ob", "%^RED%^%^BOLD%^"+tp->query_cap_name()+ " slashes at you with "
   +tp->query_possessive()+
   " claws!%^RESET%^",ob);

  ob->do_damage("target", attack, DAMAGE_PHYSICAL | DAMAGE_SLASH | DAMAGE_PIERCE, 0, tp);

  tp->add_skill_points("attack", attack/20 + 2);
  tp->add_skill_points("melee", attack/20 + 2);

  tp->add_sp(-(BALANCE3_D->get_cost(attack, rank, "sp")));

  tp->set_disable();

  return 1;
}
void help() {
  write("Syntax: <claw [(living)]>\n"
   "A monster with powerful enough claws can "
   "use them to cause massive damage to their meal.\n");
}
int abil() {
  object tp;
  tp = this_player();
  if (!tp) return 0;
  if (tp->query_class() == "animal") return 1;
  if (tp->query_property("claw")) return 1;
  if(tp->query_class() == "dragon") return 1;
  if(tp->query("bear")) return 1;
  if(tp->query("lion")) return 1;

  if (tp->query_class() == "vampire" &&
   tp->query_level() >= 5) return 1;

  return 0;
}

