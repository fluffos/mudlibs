
#include <std.h>
#include <dirs.h>

#define FAIL(s) return notify_fail(s+"\n")

#define COL "%^BOLD%^%^CYAN%^"
#define RES "%^RESET%^"

#define FEINT_PROP "feint_abil_time"
#define FEINT_TIME 10

string *possible_attacks = ({
  "thrust", "slash", "strike", "fleche", "lunge",
  "bladedance", "pierce", "stab",
});

int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "swashbuckler" &&
      tp->query_skill("blade") >= 12*6 &&
      tp->query_skill("entertainment") >= 12*3)
        return 1;
  return 0;
}

string type() { return "deception"; }

void help() {
  message("help",
    "Syntax: <feint [attack] [whom]>\n\n"
    "This move is a false attack. You pretend to attack in one direction, "
    "then swiftly move and attack from elsewhere.",
    this_player() );
}

int can_cast(object tp, object tgt, object *weps, string attack) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your current form could do no harm anyway.");

  if (!tgt)
    FAIL("Attack whom?");

  if (!sizeof(weps))
    FAIL("You can only feint with a blade or a knife.");
  
  if (member_array(attack, possible_attacks) == -1)
    FAIL("You cannot feint with that move.");

  if (!load_object(DIR_CLASS_CMDS+"/_"+attack)->abil())
    FAIL("You don't know how to use that move.");

  if (!tgt->is_living())
    FAIL("That isn't alive.");

  if (tgt == tp)
    FAIL("It would be a shame to do that.");

  if (tp->query_rest_type())
    FAIL("You must stand up first.");

  if (tp->query_sp() < 50)
    FAIL("You are too tired.");

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_feint(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  object *weps;
  string who, attack;
  int bonus, bonusstr, bonusatt;
  int minusdex, minusdef;
  int maxstr, maxatt, maxdex, maxdef;

  if (!abil()) return 0;

  if (str) {
    if (sscanf(str, "%s %s", attack, who) == 2)
      tgt = present(who, env);
    else if (!(tgt = present(str, env)))
      attack = str;
  }

  if (!tgt)
    tgt = tp->query_current_attacker();
  if (!attack)
    attack = ({"thrust","slash"})[random(2)];

  weps = filter(tp->query_wielded(), (:
    $1->query_type() == "blade" || $1->query_type() == "knife"
  :) );

  if (!can_cast(tp, tgt, weps, attack)) return 0;

  tp->add_sp(-(15+random(6)));
  tp->kill_ob(tgt);

  bonus = tp->query_skill("blade")*55/100;
  bonus += tp->query_stats("dexterity")*2;
  // purposely make this easier when using 2+ weapons
  if (sizeof(weps) > 1)
    bonus += tp->query_skill("double wielding")/3;

  if (tp->query_blind())
    bonus -= tgt->query_skill("perception")/3;
  else
    bonus -= tgt->query_skill("perception");
  bonus -= tgt->query_stats("intelligence");
  bonus -= tgt->query_skill("agility")/4;

  if (tgt->query(FEINT_PROP) > time())
    bonus -= tgt->query_skill("defense");

  bonus += random(12);

  if (bonus < 1) {
    message("combat", "You feint to one side, but "+tgt->query_cap_name()+
      " sees through your deception.", tp);
    message("combat", tp->query_cap_name()+" tries a feint, but you see "
      "through it.", tgt);
    message("combat", tp->query_cap_name()+" tries a feint, but "+
      tgt->query_cap_name()+" sees through it.", env, ({ tp, tgt }) );
    return 1;
  }

  tgt->set(FEINT_PROP, time()+FEINT_TIME);

  bonusstr = bonus*2+random(bonus/2);
  maxstr = tp->query_base_stats("strength")*4/3;
  if (bonusstr > maxstr) bonusstr = maxstr + random((maxstr-bonusstr)/6);

  bonusatt = bonus*5+random(bonus/2);
  maxatt = tp->query_base_skill("attack")*4/3;
  if (bonusatt > maxatt) bonusatt = maxatt + random((maxatt-bonusatt)/6);

  minusdex = bonus*3+random(bonus/2);
  maxdex = tgt->query_base_stats("dexterity")/3;
  if (minusdex > maxdex) minusdex = maxdex + random((maxdex-minusdex)/6);

  minusdef = bonus*6+random(bonus/2);
  maxdef = tgt->query_base_skill("defense")/3;
  if (minusdef > maxdef) minusdef = maxdef + random((maxdef-minusdef)/6);

  tp->add_stat_bonus("strength", bonusstr);
  tp->add_skill_bonus("attack", bonusatt);
  tgt->add_stat_bonus("dexterity", -minusdef);
  tgt->add_skill_bonus("defense", -minusdef);

  /* debug info:
  if (wizardp(tp))
    printf("base: %d, str: %d, dex: %d, -dex: %d, -def: %d\n",
      bonus, bonusstr, bonusatt, minusdex, minusdef);
  */

  message("combat", "You "+COL+"feint"+RES+" to one side, "
    "see an "+COL+"opening"+RES+", and "+COL+"attack"+RES+"!", tp);
  message("combat", tp->query_cap_name()+" starts to attack from one side, "
    "but "+tp->query_subjective()+" suddenly "+COL+"moves"+RES+" "
    "and "+COL+"strikes"+RES+" from the other!", tgt);
  message("combat", tp->query_cap_name()+" starts to attack "+
    tgt->query_cap_name()+" from one side, but suddenly "+
    COL+"moves"+RES+" and "+COL+"strikes"+RES+" from the other!",
    env, ({ tp, tgt }) );

  // this relies on the attack using query_current_attacker when you don't tell it who to hit
  tp->force_me(attack);

  tp->add_stat_bonus("strength", -bonusstr);
  tp->add_skill_bonus("attack", -bonusatt);
  tgt->add_stat_bonus("dexterity", minusdef);
  tgt->add_skill_bonus("defense", minusdef);

  return 1;
}

