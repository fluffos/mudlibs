
#include <std.h>
#include <daemons.h>
#include <rest.h>
#include <damage_types.h>
#include <damage.h>

#define FAIL(s) return notify_fail(s+"\n")

#define RES "%^RESET%^"
#define COL RES+"%^WHITE%^"
#define COL2 "%^CYAN%^"
#define COLC RES+"%^B_RED%^"

int abil() {
  object tp = this_player();
  if (tp->query_subclass() == "monk" &&
      tp->query_skill("melee") >= 20*6 &&
      tp->query_skill("attack") >= 20*5)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <surgingblow [who]>\n\n"
    "This powerful attack can cause major damage to an enemy, "
    "and even knock them out if done at the proper time.",
    this_player() );
}

int can_cast(object tp, object tgt) {

  string *limbs;

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your ethereal fists would have no effect.");

  if (!tgt)
    FAIL("Attack who?");

  if (!tgt->is_living())
    FAIL("Maybe you need a training dummy.");

  if (tgt == tp)
    FAIL("Why would you do that?");

  limbs = tp->query_wielding_limbs();
  if (tp->query_race() == "bastet")
    limbs = filter(limbs, (: strsrch($1, "paw") != -1 :) );
  else
    limbs = filter(limbs, (: strsrch($1, "hand") != -1 :) );

  if (!sizeof(limbs))
    FAIL("Your hands are missing!");

  if (!sizeof(filter(limbs, (: $2->query_useable($1) :), tp)))
    FAIL("Your hands are hurt too badly.");

  if (!tp->query_mobile())
    FAIL("Your body is hurt too badly to do that!");

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  if (tp->query_sp() < 75)
    FAIL("You are too tired.");

  return 1;
}

int cmd_surgingblow(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  int rank, dmg, cost, perc, init, hit, dodge, ko;
  string limb, color;

  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  if (!tp->clean_up_attackers())
    init = 1;

  if (init)
    rank = 3;
  else
    rank = 2;

  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    ({ "melee" }),
    ({ "strength" }),
    ({ "strength", "dexterity" }) );

  cost = BALANCE3_D->get_cost(dmg, rank, "sp") * 105/100;

  if (tp->query_sp() < cost)
    FAIL("You are too tired.");

  tp->add_sp(-cost);
  tp->set_disable(1);
  tp->kill_ob(tgt);

  hit = tp->query_stats("dexterity");
  hit += tp->query_skill("attack")/3;
  hit += init*35;

  if (!tgt->query_rest_type()) {
    dodge = tgt->query_stats("constitution")/2;
    dodge = tgt->query_stats("dexterity")/2;
    dodge += tgt->query_skill("defense")/3;
    if (tgt->query_class() == "rogue")
      dodge += tgt->query_skill("agility")/5;
  }

  dodge -= hit + random(15) - random(15);

  limb = tgt->return_target_limb();
  if (!tgt->query_is_limb("head"))
    ko = -1;

  if (tp->query_rest_type())
    tp->set_rest_type(0);

  message("combat", COL+"You bend down, then swing your "+
    COL2+"f"+COL+"i"+COL2+"s"+COL+"t up as you "+
    COL2+"rise"+COL+"!"+RES, tp);
  message("combat", COL+tp->query_cap_name()+" bends down, then swings "+
    tp->query_possessive()+" "+
    COL2+"f"+COL+"i"+COL2+"s"+COL+"t up as "+
    tp->query_subjective()+" "+COL2+"rises"+COL+"!"+RES, env, tp);

  if (dodge > 0) {
    message("combat", "You manage to block the worst of the blow!", tgt);
    message("combat", tgt->query_cap_name()+" manages to block the worst "
      "of the blow!", env, tgt);
    dmg /= 10;
  }
  else {
    perc = COMBAT_D->combo(tp, "surgingblow");
    dmg = dmg * perc / 100;

    if (perc > 100) {
      ko++;
      color = COLC;
    }
    else {
      color = COL2;
    }

    if (init && random(100) < 35)
      ko++;

    if (ko > 0) {
      message("combat", COL+"The blow "+color+"catches"+COL+" you "+
        "under the chin and "+color+"knocks you out"+COL+"!"+RES, tgt);

      message("combat", COL+"The blow "+color+"catches"+COL+" "+
        tgt->query_cap_name()+" under the chin and "+color+
        "knocks "+tgt->query_objective()+" out"+COL+"!"+RES, env, tgt);

      limb = "head";
      tgt->set_paralyzed(2, "You have been knocked out.", "You awaken on the ground.");
      tgt->set_rest_type(LAY);
    }
    else {
      message("combat", COL+"The punch "+color+"slams"+COL+" into "
        "your "+limb+"!"+RES, tgt);
      message("combat", COL+"The punch "+color+"slams"+COL+" into "+
        tgt->query_cap_name()+"'s "+limb+"!"+RES, env, tgt);
    }
  }

  tgt->do_damage(limb, dmg, tp->query_unarmed_damage_type(), tp->query_unarmed_damage_flags(), tp);

  return 1;
}

