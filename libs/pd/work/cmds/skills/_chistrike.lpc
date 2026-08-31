
#include <std.h>
#include <daemons.h>
#include <rest.h>
#include <damage_types.h>
#include <damage.h>

#define FAIL(s) return notify_fail(s+"\n")

#define RES "%^RESET%^"
#define COL RES+"%^WHITE%^"
#define COL2 RES+"%^CYAN%^"
#define COL3 "%^YELLOW%^"
#define COLC COL+"%^B_RED%^"

int abil() {
  object tp = this_player();
  if (tp->query_subclass() == "monk" &&
      tp->query_skill("faith") >= 35*6 &&
      tp->query_skill("attack") >= 35*5 &&
      tp->query_skill("melee") >= 35*6)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <chistrike [who]>\n\n"
    "Concentrating his chi energy into a physical force, "
    "a monk can strike out with it to do great damage to his opponent.",
    this_player() );
}

int can_cast(object tp, object tgt) {

  string *limbs;

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You cannot gather your chi in your current state.");

  if (!tgt)
    FAIL("Chistrike at whom?");

  if (!tgt->is_living())
    FAIL("It is not alive.");

  if (tgt == tp)
    FAIL("Hit yourself?");

  if (tp->query_race() == "bastet")
    limbs = filter(tp->query_wielding_limbs(), (: strsrch($1, "paw") != -1 :) );
  else
    limbs = filter(tp->query_wielding_limbs(), (: strsrch($1, "hand") != -1 :) );

  if (!sizeof(limbs))
    FAIL("Your hands are missing!");

  limbs = filter(limbs, (: $2->query_useable($1) :), tp);

  if (!sizeof(limbs))
    FAIL("Your hands are hurt too badly.");

  if (!tp->query_mobile())
    FAIL("Your body is hurt too badly to do that!");

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  if (tp->query_sp() < 100)
    FAIL("You are too tired.");

  if (tp->query_mp() < 100)
    FAIL("You need more magic.");

  return 1;
}

int cmd_chistrike(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  int rank, spcost, mpcost, dmg, perc, hit, dodge;

  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  if (tp->query_level() >= 45)
    rank = 4;
  else
    rank = 3;

  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    ({ "faith", "faith", "attack", "melee" }),
    ({ "strength", "dexterity" }),
    ({ "wisdom", "intelligence" }) );

  spcost = BALANCE3_D->get_cost(dmg, rank, "sp") + 10;
  mpcost = BALANCE3_D->get_cost(dmg, rank, "mp") * 3/2;

  if (tp->query_sp() < spcost)
    FAIL("You are too tired.");
  if (tp->query_mp() < mpcost)
    FAIL("You need more magic.");

  tp->kill_ob(tgt);
  tp->set_disable(1);
  tp->add_sp(-spcost);
  tp->add_mp(-mpcost);

  message("combat", COL3+"You concentrate your chi into one hand."+RES, tp);
  message("combat", COL3+tp->query_cap_name()+" concentrates "+
    tp->query_possessive()+" chi into one hand."+RES, env, tp);

  hit = tp->query_stats("dexterity")*2;
  hit += tp->query_skill("attack");
  hit += random(tp->query_skill("melee")/3);

  dodge = tgt->query_stats("dexterity")*2;
  dodge += tgt->query_skill("defense");
  if (tgt->query_class() == "rogue")
    dodge += tgt->query_skill("agility")/2;

  if (dodge > hit) {
    message("combat", COL+"You rush forward and drive your hand towards "+
      tgt->query_cap_name()+", but you miss!"+RES, tp);
    message("combat", COL+tp->query_cap_name()+" rushes forward and drives "+
      tp->query_possessive()+" hand towards you, but "+tp->query_subjective()+
      " misses!"+RES, tgt);
    message("combat", COL+tp->query_cap_name()+" rushes forward and drives "+
      tp->query_possessive()+" hand towards "+tgt->query_cap_name()+
      ", but misses!"+RES, env, ({ tp, tgt }) );
    tp->add_sp(spcost/3);
    tp->add_mp(mpcost/2);
    return 1;
  }

  perc = COMBAT_D->combo(tp, "chistrike");
  dmg = dmg * perc / 100;

  message("combat", COL+"You "+
    COL2+"r"+COL3+"u"+COL2+"s"+COL3+"h "+COL2+"fo"+COL3+"rwa"+COL2+"rd"+
    COL+" and "+COL2+"drive"+COL+" your hand into "+
    tgt->query_cap_name()+"!"+RES, tp);
  message("combat", COL+tp->query_cap_name()+" "+
    COL2+"r"+COL3+"u"+COL2+"s"+COL3+"h"+COL2+"e"+COL3+"s "+
    COL2+"fo"+COL3+"rwa"+COL2+"rd"+
    COL+" and "+COL2+"drives"+COL+" "+tp->query_possessive()+" hand into "+
    "you!"+RES, tgt);
  message("combat", COL+tp->query_cap_name()+" "+
    COL2+"r"+COL3+"u"+COL2+"s"+COL3+"h"+COL2+"e"+COL3+"s "+
    COL2+"fo"+COL3+"rwa"+COL2+"rd"+
    COL+" and "+COL2+"drives"+COL+" "+tp->query_possessive()+" hand into "+
    tgt->query_cap_name()+"!"+RES, env, ({ tp, tgt }) );

  tgt->do_damage("target", dmg, DAMAGE_FAITH | tp->query_unarmed_damage_type(), tp->query_unarmed_damage_flags() ^ DAMAGE_NO_SEVER, tp);
  tgt->add_sp(-(dmg/9));

  if (perc > 100 || random(5000) >= 4700) {
    string color;
    if (perc > 100) color = COLC;
    else color = COL2;

    message("combat", COL+"You are "+color+"thrown back"+RES+
      " onto the ground!"+RES, tgt);
    message("combat", COL+tgt->query_cap_name()+" is "+color+"thrown back"+RES+
      " onto the ground!"+RES, env, tgt);
    tgt->set_rest_type(SIT);
    if (!tgt->is_player())
      tgt->set_paralyzed(1);
  }

  return 1;
}

