#include <std.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s+"\n")

#define RES "%^RESET%^"
#define COL RES+"%^WHITE%^"
#define COL2 "%^BOLD%^%^RED%^"
#define COLC COL+"%^B_RED%^"

inherit DAEMON;

mapping limb_name = ([
  "head" : "throat",
  "torso" : "heart",
]);

int abil() {
  object tp = this_player();
  if (tp->query_subclass() == "monk" &&
      tp->query_skill("melee") >= 45*6 &&
      tp->query_skill("attack") >= 45*5)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <eagleclaw [who]>\n\n"
    "This powerful attack is used by monks to finish off a foe "
    "by crushing his throat or heart.",
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
    FAIL("Your hands are not solid enough.");

  if (!tgt->is_living())
    FAIL("That is not alive.");

  if (tgt == tp)
    FAIL("Why would you do that?");

  limbs = regexp(tp->query_wielding_limbs(), "hand|paw");

  if (!sizeof(limbs))
    FAIL("Your hands are missing!");

  limbs = filter(limbs, (: $2->query_useable($1) :), tp);

  if (!sizeof(limbs))
    FAIL("Your hands are hurt too badly!");

  if (!tp->query_mobile())
    FAIL("Your body is hurt too badly to do that!");

  if (tp->query_rest_type())
    FAIL("You must stand up first.");

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  if (tp->query_sp() < 70)
    FAIL("You are too tired.");

  return 1;
}

int cmd_eagleclaw(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  int cost, dmg, perc;
  string limb, lname, color;

  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  dmg = BALANCE3_D->get_damage(tp, tgt, 4,
    ({ "attack", "melee" }),
    ({ "strength", "dexterity" }),
    ({ "strength" }) );

  dmg = dmg * 180 / 100;

  cost = dmg/11;

  if (tp->query_sp() < cost)
    FAIL("You are too tired.");

  tp->add_sp(-cost);
  tp->set_disable();

  perc = COMBAT_D->do_combo(tp, "eagleclaw");
  dmg = dmg * perc / 100;

  limb = "head";
  if (random(10) < 4 || !tgt->query_is_limb(limb))
    limb = "torso";

  lname = limb_name[limb];

  message("combat", COL+"You focus on "+tgt->query_cap_name()+
    " and "+COL2+"thrust"+COL+" your hand towards "+
    tgt->query_possessive()+" "+lname+"!\n", tp);
  message("combat", COL+tp->query_cap_name()+" "+COL2+"thrusts"+COL+
    " a hand towards your "+lname+"!\n", tgt);
  message("combat", COL+tp->query_cap_name()+" "+COL2+"thrusts"+COL+
    " a hand towards "+tgt->query_cap_name()+"'s "+lname+"!\n",
    env, ({ tp, tgt }) );

  if (tgt->query_hp() > dmg) {
    message("combat", "Your attack just grazes "+tgt->query_objective()+
      ", throwing you off balance!", tp);
    message("combat", tp->query_cap_name()+"'s attack just grazes you, "
      "throwing "+tp->query_objective()+" off balance!", tgt);
    message("combat", tp->query_cap_name()+"'s attack just grazes "+
      tgt->query_cap_name()+", "
      "throwing "+tp->query_objective()+" off balance!", env, ({ tp, tgt }) );
    tp->set_paralyzed(2+random(2), "You are terribly off balance!");
    tp->add_sp(-(cost/3));
    dmg = dmg / 7;
  }
  else {
    if (perc > 100) color = COLC;
    else color = COL2;

    // adding \n at the end of these lines so you can see the death line better
    message("combat", COL+"Your fingers "+color+"pierce"+COL+" "+
      tgt->query_cap_name()+"'s "+lname+" and you "+color+"tear it out"+COL+
      ", spraying "+color+"blood"+COL+" everywhere!\n", tp);
    message("combat", COL+tp->query_cap_name()+"'s fingers "+color+"pierce"+COL+
      " your "+lname+" and "+tp->query_subjective()+" "+color+"tears it out"+
      COL+", spraying "+color+"blood"+COL+" everywhere!\n", tgt);
    message("combat", COL+tp->query_cap_name()+"'s fingers "+color+"pierce"+COL+
      " "+tgt->query_cap_name()+"'s "+lname+" and "+tp->query_cap_name()+" "+
      color+"tears it out"+COL+", spraying "+color+"blood"+COL+" everywhere!\n",
      env, ({ tp, tgt }) );
    dmg = dmg * 2;
  }

  tgt->do_damage(limb, dmg);

  // make sure they die
  if (tgt->query_hp() < 1)
    tgt->heart_beat();

  return 1;
}

