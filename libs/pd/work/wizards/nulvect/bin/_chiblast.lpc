
#include <std.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s+"\n");

#define RES "%^RESET%^"
#define COL "%^YELLOW%^"
#define COL2 "%^BOLD%^%^CYAN%^"
#define COLC COL+"%^B_RED%^"

int spell() {
  object tp = this_player();
  if (tp->query_subclass() == "monk" &&
      tp->query_skill("faith") >= 50*6 &&
      tp->query_skill("attack") >= 50*5)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <chiblast [whom]>\n\n"
    "The most highly trained monks can blast forth their chi in a "
    "powerful stream to devastate their foes.",
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
    FAIL("You cannot gather your chi in this state.");

  if (!tgt)
    FAIL("Chiblast whom?");

  if (!tgt->is_living())
    FAIL("That would be a waste of time.");

  if (tgt == tp)
    FAIL("That would be impossible.");

  limbs = filter(tp->query_wielding_limbs(), (: strsrch($1, "hand") != -1 :) );

  if (!sizeof(limbs))
    FAIL("Your hands are missing!");

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  if (tp->query_sp() < 100)
    FAIL("You are too tired.");

  if (tp->query_mp() < 150)
    FAIL("You need more magic power.");

  return 1;
}

int cmd_chiblast(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  int dmg, cost, perc, bodydam;
  string mymsg, yourmsg, theirmsg;

  if (!spell()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  dmg = BALANCE3_D->get_damage(tp, tgt, 4,
    ({ "faith" }),
    ({ "wisdom", "wisdom", "intelligence", "strength" }),
    ({ "faith", "attack" }) );

  dmg = dmg * 110 / 100;

  cost = dmg/7;
  if (tp->query_mp() < cost)
    FAIL("You are too low on magic power.");
  if (tp->query_sp() < cost/3)
    FAIL("You are too tired.");

  tp->add_mp(-cost);
  tp->add_sp(-(cost/3));
  tp->set_disable(1);
  tp->kill_ob(tgt);

  perc = COMBAT_D->do_combo(tp, "chiblast");
  dmg = dmg * perc / 100;

  mymsg = COL+"You gather your "+COL2+"chi"+COL+
          " into a ball in your hands.\n"
          "You "+COL2+"blast"+COL+" "+tgt->query_cap_name()+" with a "+
          COL2+"stream"+COL+" of "+COL2+"chi"+COL+" energy!"+RES;
  yourmsg = COL+tp->query_cap_name()+" gathers "+tp->query_possessive()+" "+
            COL2+"chi"+COL+" into a ball.\n"+
            tp->query_cap_name()+" "+COL2+"blasts"+COL+" you "
            " with a "+COL2+"stream"+COL+" of "+
            COL2+"chi"+COL+" energy!"+RES;
  theirmsg = COL+tp->query_cap_name()+" gathers "+tp->query_possessive()+" "+
             COL2+"chi"+COL+" into a ball.\n"+
             tp->query_cap_name()+" "+COL2+"blasts"+COL+" "+
             tgt->query_cap_name()+" with a "+COL2+"stream"+COL+" of "+
             COL2+"chi"+COL+" energy!"+RES;

  message("combat", mymsg, tp);
  message("combat", yourmsg, tgt);
  message("combat", theirmsg, env, ({ tp, tgt }));

  if (tp->is_player())
    bodydam = dmg/8;
  else
    bodydam = dmg/(tgt->query_level()*8);

  if (perc > 100) {
    message("combat", COLC+"The blast devastates your body!"+RES, tgt);
    message("combat", COLC+"The blast devastates "+
      tgt->query_cap_name()+"'s body!"+RES, env, tgt);
    bodydam = bodydam * 210 / 100;
  }

  foreach (string limb in tgt->query_limbs()) {
    int amt = bodydam;
    if (random(500) > 300) continue;
    if (amt > tgt->query_max_dam(limb)/3)
      amt = tgt->query_max_dam(limb)/3 + random(amt/10) - random(amt/10);
    tgt->heal_limb(limb, -amt);
  }

  tgt->do_damage(tgt->return_limb(), dmg);

  return 1;
}
