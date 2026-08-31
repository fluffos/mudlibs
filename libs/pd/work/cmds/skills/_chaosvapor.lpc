#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

#define FAIL(s) return notify_fail(s);
#define COL "%^BOLD%^%^BLACK%^"
#define RES "%^RESET%^"

inherit DAEMON;

int spell() {
  object tp=this_player();
  if (tp->query_subclass() == "black" &&
      tp->query_skill("magic attack") >= 30*5 &&
      tp->query_skill("wizardry") >= 30*5 &&
      tp->query_skill("conjuring") >= 30*3)
        return 1;
  return 0;
}

string type() { return "attack"; }

int ok_cast(object tp) {
  if (environment(tp)->query_property("no magic") ||
      environment(tp)->query_property("no attack"))
    FAIL("You cannot do that here.\n");

  return 1;
}

int cmd_chaosvapor(string str) {
  object tp=this_player();
  object env=environment(tp);
  object *tgts;

  int s, rank;

  if (!spell()) return 0;

  if (tp->query_busy()) return notify_fail("You are busy.");

  if (!ok_cast(tp)) return 0;
  
  tp->set_paralyzed(1, "You are concentrating on your spell.");
  tp->add_mp(-45);

  if (tp->query_level() >= 50) rank=4;
  else rank=3;

  tgts=filter(all_inventory(env), (: $1->is_living() :) )-({tp});
  s=sizeof(tgts);

  message("magic",COL+"Dark chaotic mists form around you and "
                  "spray in all directions!"+RES,tp);
  message("magic",COL+"Dark chaotic mists form around "+tp->query_cap_name()+
                  " and spray in all directions!"+RES, env, tp);

  foreach (object tgt in tgts) {
    int dmg, cost;

    if (--s > 0)
      if (random(100) < 25)
        continue;
  
    if (!tp->kill_ob(tgt)) {
      message("info","You cannot attack "+tgt->query_cap_name()+".",tp);
      continue;
    }

    dmg = BALANCE3_D->get_damage(tp, tgt, rank,
            ({"magic attack", "magic attack", "wizardry"}),
            ({"intelligence", "intelligence", "wisdom"}),
            ({"wizardry"}) );

    dmg=dmg*6/5;

    cost = BALANCE3_D->get_cost(dmg, rank, "mp") * 70 / 100;
    
    if (tp->query_mp() < cost) {
      message("info","You run out of magical energy.",tp);
      return 1;
    }

    message("magic", COL+"Chaos vapors shoot into you, attacking "
                     "your vital essences!"+RES, tgt);
    message("magic", COL+"Chaos vapors shoot into "+tgt->query_cap_name()+
                     ", attacking "+tgt->query_possessive()+
                     " vital essences!"+RES, env, tgt);

    tp->add_mp(-cost);
    tgt->do_damage("random", dmg, DAMAGE_MAGIC, DAMAGE_BYPASS_ARMOUR | DAMAGE_BYPASS_STRENGTHS, tp);
  }
  
  return 1;
}

void help() {
  message("help","\n"
    "Syntax: <chaosvapor>\n"
    "A very evil and chaotic spell, the black dragon can create "
    "mists of pure chaos that attack the life essences of various "
    "living things in the area. They are hard to fully control, "
    "but there is no defense against them.",
    this_player());
}

