//      _vinegrasp.c
//      Mage ability
//      written by Daboura, based on missile

#include <daemons.h>
#include <std.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;

int spell();
string type() { return "attack"; }
int cmd_vinegrasp(string str) {
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

  if((int)tp->query_mp() < 20) {
    notify_fail("Too low on magic power.\n");
    return 0;
  }

  if (str) ob = present(str, environment(tp));
  else ob = tp->query_current_attacker();

  if (!ob) return notify_fail("Grasp who?");

  if(!living(ob)) {
    notify_fail(ob->query_cap_name()+" is not a living thing!\n");
    return 0;
  }

  if(ob==tp) {
    notify_fail("You summon some vines, but they seem confused.\n");
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
  attack = BALANCE3_D->get_damage( tp, ob, 1, ({ "magic attack", "nature", "conjuring", "magic attack", "nature" }),
   ({ "wisdom" }) );

  attack = attack * 90 / 100;

  if(attack < 1) attack = 1;
  if(attack > 260) attack = 260 + tp->query_level();

  if(!this_player()->kill_ob(ob)) {
    write(ob->query_cap_name()+" can't be attacked by you yet.");
    return 1;
  }

  write("%^GREEN%^You summon forth %^BOLD%^vi%^RESET%^%^GREEN%^n%^BOLD%^es%^RESET%^%^GREEN%^ from the ground and have them %^BOLD%^%^RED%^entangle%^RESET%^%^GREEN%^ " 
   +ob->query_cap_name()+"!");

  message("room", "%^GREEN%^"+tp->query_cap_name()+
   " summons large %^BOLD%^vi%^RESET%^%^GREEN%^n%^BOLD%^es%^RESET%^%^GREEN%^ from the ground, and commands them to %^BOLD%^%^RED%^entangle%^RESET%^%^GREEN%^ "
   +ob->query_cap_name()+"!"
   , environment(tp), ({tp,ob}));            

  message("ob", "%^GREEN%^"+tp->query_cap_name()+
   " calls forth several large %^BOLD%^vi%^RESET%^%^GREEN%^n%^BOLD%^es%^RESET%^%^GREEN%^ from the ground, and %^BOLD%^%^RED%^entangles%^RESET%^%^GREEN%^ you in them!"
   ,ob);

  if(!ob->query_paralyzed())
  {
    if(random(10) == 0)
    {
      ob->set_paralyzed(2+random(3), "You are entangled in vines!");		
    }
    else if(tp->query_skill("nature") > ob->query_skill("magic defense"))
    {
      if(tp->query_stats("wisdom") > 3*(ob->query_stats("wisdom"))/2)
      {
	if(random(3) < 2 && !ob->query_paralyzed()) 
	  ob->set_paralyzed(2+random(3), "You are entangled in vines!");
      }
    }
  }

  tp->add_skill_points("magic attack", attack/20 + 2);
  tp->add_skill_points("nature", attack/20 + 2);
  tp->add_skill_points("conjuring", attack/20 + 1);

  tp->add_mp(-BALANCE3_D->get_cost(attack, 1, "mp"));

  tp->set_magic_round();

  ob->do_damage("random", attack, DAMAGE_PHYSICAL | DAMAGE_IMPACT, DAMAGE_NO_SEVER, tp);

  return 1;
}
void help() {
  write("Syntax: <vinegrasp [(living)]>\n"
   "The druid will summon forth large vines to entangle "
   "the target, in some cases, the vines may prevent the "
   "target from moving.\n");
}
int spell() {
  object tp;
  tp = this_player();
  if (!tp) return 0;
  if (tp->query_subclass() != "druid") return 0;
  if(tp->query_skill("nature") < 72) return 0;
  if(tp->query_skill("conjuring") < 36) return 0;   

  return 1;
}

