#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>
#define FAIL(s) return notify_fail(s);
#define COL ""
#define RES ""

inherit DAEMON;

int spell() {
  object tp=this_player();
  if (tp->query_subclass() == "blue" &&
      tp->query_skill("tail") >= 40*2 &&
      tp->query_skill("faith") >= 40*6 &&
      tp->query_skill("conjuring") >= 40*3)
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

int cmd_tailspin(string str) {
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

  message("magic",COL+"%^BOLD%^%^BLUE%^You spin your quickly tail in a circle, creating shards of ice!"+RES,tp);
  message("magic",COL+"Shards of ice shoot from "+tp->query_cap_name()+
                  "'s tail as it spins with great speed!"+RES, env, tp);

  foreach (object tgt in tgts) {
    int dmg, cost;

    if (--s > 0)
      if (random(100) < 15)
        continue;
  
    if (!tp->kill_ob(tgt)) {
      message("info","You cannot attack "+tgt->query_cap_name()+".",tp);
      continue;
    }

    dmg = BALANCE3_D->get_damage(tp, tgt, rank,
            ({"tail", "conjuring", "faith"}),
            ({"intelligence", "intelligence", "wisdom"}),
            ({"faith"}) );

    dmg=dmg*5/4;

    cost = BALANCE3_D->get_cost(dmg, rank, "mp") * 60 / 100;
    
    if (tp->query_mp() < cost) {
      message("info","You run out of magical energy.",tp);
      return 1;
    }

    message("magic", COL+"%^BOLD%^%^BLUE%^Shards of ice deeply pierce your "
                     "body!"+RES, tgt);
    message("magic", COL+"Shards of ice fly into "+tgt->query_cap_name()+
                     ", piercing "+tgt->query_possessive()+
                     " skin!"+RES, env, tgt);

    tp->add_mp(-cost);
    tgt->do_damage("random", dmg, DAMAGE_MAGIC, DAMAGE_BYPASS_ARMOUR |
DAMAGE_BYPASS_STRENGTHS, tp);
  }
  
  return 1;
}

void help() {
  message("help","\n"
    "Syntax: <tailspin>\n"
    "This is a crappy copied spell.",
    this_player());
}
