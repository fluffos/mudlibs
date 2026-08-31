#include <std.h>
#define FAIL(s) return notify_fail(s);

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp->query_subclass() == "kataan")
    return 1;
  return 0;
}

int is_proj(object *blah) { return (blah->query_type() == "projectile" ? 1 : 0); }

int ok_cast(object tp, object tgt) {

  if (tp->query_rest_type())
    FAIL("You must be standing to do that.\n");
  
  if (environment(tp)->query_property("no attack"))
    FAIL("You cannot do that here.\n");

  if (!tgt)
    FAIL("You don't see that here.\n");

  if (!living(tgt))
    FAIL("That is not alive.\n");

  if (tp == tgt)
    FAIL("How foolish.\n");

  if (sizeof(filter(tp->query_wielded(),"is_proj",this_object())) != sizeof(tp->query_wielded()))
    FAIL("You cannot perform this attack properly with anything but a spear.\n");
  
  if (!tp->kill_ob(tgt))
    FAIL("That cannot be attacked by you yet.\n");

  return 1;
}

int cmd_pierce(string str) {
  object tp=this_player();
  object tgt;

  int strong, dex, att, proj;
  int tdex, tdef;
  int cost, dmg;

  if (!abil()) return 0;

  if (tp->query_disable()) return 1;

  if (!str) tgt=tp->query_current_attacker();
  else tgt=present(str,environment(tp));

  if (!ok_cast(tp,tgt)) return 0;
  
  strong=tp->query_stats("strength");
  dex=tp->query_stats("dexterity");
  att=tp->query_skill("attack");
  proj=tp->query_skill("projectile");
  
  tdex=tgt->query_stats("dexterity");
  tdef=tgt->query_skill("defense");

  dmg=strong*3+att*4/3+random(tp->query_level()+10);
  cost=dmg/9;
  
  if (tp->query_sp() < cost)
    FAIL("You are too tired.\n");

  tp->set_disable(1);
  tp->add_sp(-cost);

  if (tdex/2+tdef/2 > dex+proj) {
    message("combat","%^BOLD%^%^BLACK%^You try to pierce "+tgt->query_cap_name()+
                     " with your spear, but miss.%^RESET%^",tp);
    message("combat","%^BOLD%^%^BLACK%^"+tp->query_cap_name()+" tries to pierce "+tgt->query_cap_name()+
                     " with "+tp->query_possessive()+" spear, but misses.%^RESET%^",environment(tp),({tp,tgt}));
    message("combat","%^BOLD%^%^BLACK%^"+tp->query_cap_name()+" tries to pierce you"
                     " with "+tp->query_possessive()+" spear, but misses.%^RESET%^",tgt);
  }
  else {
    message("combat","%^BOLD%^%^BLACK%^You thrust your spear at "+
                     tgt->query_cap_name()+" and pierce "+tgt->query_possessive()+" flesh!%^RESET%^",tp);
    message("combat","%^BOLD%^%^BLACK%^"+tp->query_cap_name()+" thrusts "+tp->query_possessive()+" spear at "+
                     tgt->query_cap_name()+" and pierces "+tgt->query_possessive()+" flesh!%^RESET%^",
                     environment(tp),({tp,tgt}));
    message("combat","%^BOLD%^%^BLACK%^"+tp->query_cap_name()+" thrusts "+tp->query_possessive()+" spear at "+
                     "you and pierces your flesh!%^RESET%^", tgt);
    tgt->do_damage(tgt->return_target_limb(),dmg);
  }
  
  return 1;
}

void help() {
  message("help","\n"
    "Syntax: <pierce [living]>\n"
    "A basic thrusting attack with a spear, this is the kataan's first step down the path of spear mastery.",
    this_player());
}

