
#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

#define COL "%^BOLD%^%^YELLOW%^"
#define COL2 "%^BOLD%^%^WHITE%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s+"\n");

#define ANGEL_ALIGN 1000

int spell() {
  object tp=this_player();
  if (tp && tp->query_race() == "archangel" && tp->query_level() >= 25)
    return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <levin [whom]>\n\n"
    "Archangels can summon a bolt of heavenly energy to strike an opponent.\n"
    "The angel's holiness and strength of will are very important, "
    "as well as the alignment of the target.",
    this_player() );
}

int can_cast(object tp, object tgt) {
  
  if (!tp) return 0;

  if (tp->query_alignment() < ANGEL_ALIGN)
    FAIL("You are not holy enough to call down levin!");
  
  if (environment(tp)->query_property("no attack"))
    FAIL("You cannot attack here.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You are not corporeal enough to call down levin.");

  if (!tgt)
    FAIL("Call levin upon whom?");

  if (!living(tgt))
    FAIL("That is not a living thing.");

  if (tgt == tp || tgt->query_race() == "archangel")
    FAIL("The heavens will not attack one of their own!");

  if (!tp->kill_ob(tgt))
    FAIL("You can't attack "+tgt->query_cap_name()+".");
  
  return 1;
}

int cmd_levin(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  int dmg, cost, rank;
  int align, tgtalign, level;
  int mult;

  if (!spell()) return 0;

  if (str)
    tgt=present(str, env);
  else
    tgt=tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  level=tp->query_level();
  align=tp->query_alignment();
  tgtalign=tgt->query_alignment();
  
  if (level >= 45) rank=4;
  else if (level >= 35) rank=3;
  else rank=2;

  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    ({"none"}),
    ({"wisdom", "wisdom", "wisdom", "intelligence"})
  );

  mult = 100;

  // +1% damage for every 50 alignment below -200 of the target, max +26%
  if (tgtalign <= -200)
    mult += (-200-tgtalign)/50;
  // -1% damage for every 50 alignment over -200
  else
    mult += (-200-tgtalign)/50;

  // +1% every 7 levels
  mult += (level-25)/7;
  
  dmg = dmg * mult / 100;
  
  cost = BALANCE3_D->get_cost(dmg, rank, "mp");

  if (tp->query_mp() < cost)
    FAIL("You need more magic.");

  if (tgtalign >= 1400 || tgtalign > align ||
      tgt->query_stats("wisdom") > tp->query_stats("wisdom")+random(15)) {
        message("magic", "You call down a bolt of levin upon "+
                         tgt->query_cap_name()+", but it deflects off of "+
                         tgt->query_objective()+"!", tp);
        message("magic", tp->query_cap_name()+" calls down a bolt of levin upon "
                         "you, but it deflects off!", tgt);
        message("magic", tp->query_cap_name()+" calls down a bolt of levin upon "+
                         tgt->query_cap_name()+", but it deflects off!", env, ({tp, tgt}) );
  }
  else {
    message("magic", COL+"You call down a "+COL2+"bolt"+COL+" of "+COL2+
                     "holy levin"+COL+" upon "+tgt->query_cap_name()+"!"+RES, tp);
    message("magic", COL+tp->query_cap_name()+" calls down a "+COL2+"bolt"+COL+
                     " of "+COL2+"holy levin"+COL+" upon you!"+RES, tgt);
    message("magic", COL+tp->query_cap_name()+" calls down a "+COL2+"bolt"+COL+
                     " of "+COL2+"holy levin"+COL+" upon "+
                     tgt->query_cap_name()+"!"+RES, env, ({tp,tgt}) );
    tgt->do_damage("random", dmg, DAMAGE_FAITH | DAMAGE_HOLY, 0, tp);
  }

  tp->add_mp(-(cost+random(cost/6)));
  tp->set_magic_round(1);

  return 1;
}

