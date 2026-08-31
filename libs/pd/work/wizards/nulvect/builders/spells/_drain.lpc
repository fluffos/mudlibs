#include <std.h>
#define FAIL(s) return notify_fail(s);
#define COL "%^RED%^"
#define RES "%^RESET%^"

inherit DAEMON;

int spell() {
  object tp=this_player();
  if (tp->query_subclass() == "kataan" &&
      tp->query_skill("faith") >= 18*5)
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
    FAIL("How foolish.\n");

  if (!tp->kill_ob(tgt))
    FAIL("That cannot be attacked by you yet.\n");

  return 1;
}

int cmd_drain(string str) {
  object tp=this_player();
  object tgt;

  int wis, faith;
  int twis;
  int cost, dmg;

  if (!spell()) return 0;

  if (tp->query_disable()) return 1;

  if (!str) tgt=tp->query_current_attacker();
  else tgt=present(str,environment(tp));

  if (!ok_cast(tp,tgt)) return 0;
  
  wis=tp->query_stats("wisdom");
  faith=tp->query_skill("faith");
  
  twis=tgt->query_stats("wisdom");

  dmg=wis*2+faith/3+random(tp->query_level()/3);
  dmg-=twis/4;
  cost=dmg/6;
  
  if (tp->query_mp() < cost)
    FAIL("Too low on magic.\n");

  tp->set_disable(1);
  tp->add_mp(-cost);

  message("magic",COL+"You reach a hand out towards "+tgt->query_cap_name()+
                  " and drain some energy from "+tgt->query_objective()+"!"+RES,tp);
  message("magic",COL+tp->query_cap_name()+" reaches a hand out towards you "
                  "and drains some of your energy!"+RES,tgt);
  message("magic",COL+tp->query_cap_name()+" reaches a hand out towards "+tgt->query_cap_name()+
                  " and drains some energy from "+tgt->query_objective()+"!"+RES,
                  environment(tp),({tp,tgt}));

  tp->add_sp(dmg);
  tgt->add_sp(-dmg);
  tp->add_alignment(-3);

  return 1;
}

void help() {
  message("help","\n"
    "Syntax: <drain [living]>\n"
    "This evil spell sucks the stamina out of an opponent and gives it to the caster.",
    this_player());
}

