
#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

#define RES "%^RESET%^"
#define COL RES+"%^WHITE%^"
#define COL2 "%^YELLOW%^"
#define COLC COL+"%^B_RED%^"

#define FAIL(s) return notify_fail(s+"\n")

int abil() {
  object tp = this_player();
  if (tp->query_subclass() == "monk" && tp->query_skill("melee") >= 11*6)
    return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <palmstrike [whom]>\n\n"
    "This martial arts attack involves slamming your palm into "
    "your opponent to cause a wide area of damage.",
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
    FAIL("Your palms are not solid enough to do any damage.");

  if (!tgt)
    FAIL("Strike whom?");

  if (!tgt->is_living())
    FAIL("You hit it.");

  if (tgt == tp)
    FAIL("Not very good practice.");

  limbs = tp->query_wielding_limbs();
  if (tp->query_race() == "bastet")
  limbs = filter(limbs, (: strsrch($1, "paw") != -1 :) );
else
  limbs = filter(limbs, (: strsrch($1, "hand") != -1 :) );

  if (!sizeof(limbs))
    FAIL("Your hands are missing!");

  if (!sizeof(filter(limbs, (: $2->query_useable($1) :), tp)))
    FAIL("Your hands are hurt too badly.");

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  if (tp->query_sp() < 40)
    FAIL("You are too tired.");

  return 1;
}

int cmd_palmstrike(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  int rank, cost, dmg, perc;
  string mymsg, yourmsg, theirmsg, limb;

  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  if (tp->query_skill("melee") >= (14+random(3))*6)
    rank = 2;
  else
    rank = 1;

  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    ({ "melee", "melee", "attack" }),
    ({ "strength" }),
    ({ "strength", "dexterity" }) );

  perc = COMBAT_D->combo(tp, "palmstrike");
  dmg = dmg * perc / 100;

  cost = BALANCE3_D->get_cost(dmg, rank, "sp") - 1;

  if (tp->query_sp() < cost)
    FAIL("You are too tired.");

  tp->add_sp(-cost);
  tp->set_disable(1);
  tp->kill_ob(tgt);

  limb = tgt->return_target_limb();

  if (perc > 100) {
    mymsg = COL+"You extend your elbow backwards and ready your "+
      "a"+COL2+"tt"+COL+"a"+COL2+"c"+COL+"k.\n"
      "You unleash a "+COLC+"devastating"+COL+" palm strike against "+
      tgt->query_cap_name()+"!"+RES;
    yourmsg = COL+tp->query_cap_name()+" unleashes a "+
      COLC+"devastating"+COL+" palm strike against you!"+RES;
    theirmsg = COL+tp->query_cap_name()+" unleashes a "+
      COLC+"devastating"+COL+" palm strike against "+
      tgt->query_cap_name()+"!"+RES;
  }
  else {
    mymsg = COL+"You s"+COL2+"tr"+COL+"i"+COL2+"ke "+COL+
      tgt->query_cap_name()+" with your palm!"+RES;
    yourmsg = COL+tp->query_cap_name()+
      " s"+COL2+"tr"+COL+"i"+COL2+"ke"+COL+"s "
      "you with "+tp->query_possessive()+" palm!"+RES;
    theirmsg = COL+tp->query_cap_name()+
      " s"+COL2+"tr"+COL+"i"+COL2+"ke"+COL+"s "+
      tgt->query_cap_name()+" with "+
      tp->query_possessive()+" palm!"+RES;
  }

  message("combat", mymsg, tp);
  message("combat", yourmsg, tgt);
  message("combat", theirmsg, env, ({ tp, tgt }) );

  tgt->do_damage(limb, dmg/7, tp->query_unarmed_damage_type(), tp->query_unarmed_damage_flags() | DAMAGE_NO_HP, tp);
  tgt->do_damage(limb, dmg, tp->query_unarmed_damage_type(), tp->query_unarmed_damage_flags(), tp);

  tp->add_skill_points("melee", 15 + dmg/10);
  tp->add_skill_points("attack", 15 + dmg/10);

  return 1;
}

