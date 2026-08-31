
#include <std.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s+"\n")

#define RES "%^RESET%^"
#define COL RES+"%^WHITE%^"
#define COL2 "%^BOLD%^%^BLUE%^"

inherit DAEMON;

int abil() {
  object tp = this_player();
  if (tp->query_subclass() == "monk" && tp->query_level() >= 8)
    return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <snapkick [whom]>\n\n"
    "Monks can snap their leg upwards and kick an opponent in the face.",
    this_player() );
}

int can_cast(object tp, object tgt) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your legs are not solid enough to do any damage.");

  if (!tgt)
    FAIL("Snapkick whom?");

  if (!tgt->is_living())
    FAIL("You kick it.");

  if (tgt == tp)
    FAIL("How acrobatic.");

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  if (tp->query_sp() < 40)
    FAIL("You are too tired.");

  return 1;
}

int cmd_snapkick(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  int dmg, cost, perc;
  string limb, lname;

  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  dmg = BALANCE3_D->get_damage(tp, tgt, 2,
    ({ "attack", "melee" }),
    ({ "strength", "dexterity" }) );

  perc = COMBAT_D->combo(tp, "snapkick");
  dmg = dmg * perc / 100;

  cost = dmg/7;

  if (tp->query_sp() < cost)
    FAIL("You are too tired.");

  tp->add_sp(-cost);
  tp->set_disable();
  tp->kill_ob(tgt);

  limb = "head";
  if (!tgt->query_is_limb(limb))
    limb = tgt->return_target_limb();
  if (limb == "head")
    lname = "face";
  else
    lname = limb;

  message("combat", COL+"You snap your leg up and "+COL2+"slam"+COL+
    " your foot into "+tgt->query_cap_name()+"'s "+lname+"!"+RES, tp);
  message("combat", COL+tp->query_cap_name()+" snaps "+tp->query_possessive()+
    " leg up and "+COL2+"slams"+COL+" "+tp->query_possessive()+
    " foot into your "+lname+"!"+RES, tgt);
  message("combat", COL+tp->query_cap_name()+" snaps "+tp->query_possessive()+
    " leg up and "+COL2+"slams"+COL+" "+tp->query_possessive()+
    " foot into "+tgt->query_cap_name()+"'s "+lname+"!"+RES,
    env, ({ tp, tgt }) );

  tgt->do_damage(limb, dmg);

  return 1;
}
