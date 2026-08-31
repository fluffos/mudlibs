
#include <std.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s+"\n")

#define COL "%^RED%^"
#define RES "%^RESET%^"

inherit DAEMON;

int spell() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "antipaladin" &&
      tp->query_level() >= 2)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <bleed [whom]>\n\n"
    "A spell of minor evil, used by antipaladins to cause bleeding "
    "in their victims.",
    this_player() );
}

int can_cast(object tp, object tgt) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (!tgt)
    FAIL("Cast it at whom?");

  if (!tgt->is_living())
    FAIL("That is not alive.");

  if (tp == tgt)
    FAIL("That would be unwise.");

  if (!tp->kill_ob(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_bleed(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  int rank, cost, dmg;

  if (!spell()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  rank = 1 + tp->query_level()/15;
  if (rank > 3)
    rank = 3;

  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    ({ "magic attack" }),
    ({ "intelligence", "wisdom" }),
    ({ "magic attack" }) );

  cost = BALANCE3_D->get_cost(dmg, rank, "mp");

  if (tp->query_mp() < cost)
    FAIL("Too low on magic power.");

  tp->set_magic_round(1);
  tp->add_mp(-cost);

  message("magic", COL+"Blood begins to seep from "+tgt->query_cap_name()+
    "'s body."+RES, env, tgt);
  message("magic", COL+"Blood begins to seep from your body."+RES, tgt);

  tgt->add_bleeding(dmg);

  return 1;
}
