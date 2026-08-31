#include <std.h>
#define FAIL(s) return notify_fail(s);
#define COL "%^BOLD%^%^CYAN%^"
#define RES "%^RESET%^"

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp->query_subclass() == "blue" &&
      tp->query_skill("faith") >= 14*5 &&
      tp->query_skill("claw") >= 14*4)
    return 1;
  return 0;
}

int ok_cast(object tp, object tgt) {
  if (environment(tp)->query_property("no magic") ||
      environment(tp)->query_property("no attack"))
    FAIL("You cannot do that here.\n");

  if (!tgt)
    FAIL("You don't see that here.\n");

  if (!living(tgt))
    FAIL("That is not alive.\n");

  if (tp == tgt)
    FAIL("Thwack.\n");

  if (!tp->kill_ob(tgt))
    FAIL("That cannot be attacked by you yet.\n");

  return 1;
}

int cmd_iceclaw(string str) {
  object tp=this_player();
  object tgt;

  int intel, strong, dex, faith, claw;
  int tdex, tdef;
  int cost, dmg;

  string limb;

  if (!abil()) return 0;

  if (tp->query_disable()) return 1;

  if (!str) tgt=tp->query_current_attacker();
  else tgt=present(str,environment(tp));

  if (!ok_cast(tp,tgt)) return 0;
  
  intel=tp->query_stats("intelligence");
  dex=tp->query_stats("dexterity");
  strong=tp->query_stats("strength");
  faith=tp->query_skill("faith");
  claw=tp->query_skill("claw");
  
  tdex=tgt->query_stats("dexterity");
  tdef=tgt->query_skill("defense");
  
  dmg=intel+strong+dex+faith*2/3+claw;
  dmg-=tdex/2+tdef/3;
  cost=dmg/10+random(tp->query_level()/4);
  
  if (tp->query_sp() < cost)
    FAIL("You are too tired.\n");
  if (tp->query_mp() < cost/3)
    FAIL("Your magic is too low.\n");
  
  tp->set_disable(1);
  tp->add_sp(-cost);
  tp->add_mp(-(cost/3));

  limb=tgt->return_target_limb();
  
  message("magic",COL+"You swing a claw at "+tgt->query_cap_name()+".\n"
                      "Sharp icicles jut from your claw and %^BOLD%^%^RED%^dig "+COL+
                      "into "+tgt->query_possessive()+" "+limb+"!"+RES,tp);
  message("magic",COL+tp->query_cap_name()+" swings a claw at you.\n"
                  "Sharp icicles suddenly jut out and %^BOLD%^%^RED%^dig "+COL+
                  "into your "+limb+"!"+RES,tgt);
  message("magic",COL+tp->query_cap_name()+" swings a claw at "+tgt->query_cap_name()+
                  " and sharp icicles %^BOLD%^%^RED%^dig "+COL+"into "+
                  tgt->query_possessive()+" "+limb+"!"+RES, environment(tp),({tp,tgt}));

  tgt->do_damage(limb,dmg);
  
  return 1;
}

void help() {
  message("help","\n"
    "Syntax: <iceclaw [living]>\n"
    "A blue dragon can form deadly icicles on his claws in mid-swing, "
    "extending his reach and causing even more damage.",
    this_player());
}

