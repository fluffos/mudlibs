
#include <std.h>
#include <daemons.h>
#include <damage.h>
#include <damage_types.h>

#define FAIL(s) return notify_fail(s+"\n")

#define RES "%^RESET%^"
#define COL "%^BOLD%^%^MAGENTA%^"

inherit DAEMON;

void do_hit(mixed *info);


int spell() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "sorceror" && tp->query_level() >= 2)
    return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <mindstab [who]>\n\n"
    "This basic spell shoots a spike of psionic energy into "
    "an opponent's mind, damaging it.",
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

  if (tp->query_ghost())
    FAIL("You can't manage your powers while dead.");

  if (!tgt)
    FAIL("Cast it at whom?");

  if (!living(tgt))
    FAIL("That is not alive, so it has no mind to attack.");

  if (tgt == tp)
    FAIL("You can't cast that at yourself.");

  if (tgt->is_player() && !interactive(tgt))
    FAIL("You cannot attack a link-dead player.");

  if (tp->query_mp() < 25)
    FAIL("Your magic is too low.");

  if (!tp->kill_ob(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_mindstab(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  int dmg, cost;

  if (!spell()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  dmg = BALANCE3_D->get_damage(tp, tgt, 1,
    ({ "psionics" }), ({ "intelligence" }) );

  dmg = dmg*4/3;

  cost = BALANCE3_D->get_cost(dmg, 1, "mp");

  if (tp->query_mp() < cost)
    FAIL("Your magic is too low.");

  tp->add_mp(-(cost/2));
  tp->set_magic_round(2);

  message("magic", COL+"You concentrate your psionic energy."+RES, tp);

  tp->add_skill_points("psionics", 20);
  tp->add_skill_points("magic attack", 10);

  call_out("do_hit", 2, ({ tp, tgt, dmg, cost/2 }) );
  return 1;
}

void do_hit(mixed *info) {
  object tp = info[0];
  object tgt = info[1];
  int dmg = info[2];
  int cost = info[3];

  if (!tp) return;

  if (!tgt || environment(tgt) != environment(tp)) {
    message("info", "Your target is not here!", tp);
    return;
  }

  if (member_array(tgt, tp->query_attackers()) == -1)
    return;

  tp->add_mp(-cost);
  tgt->do_damage("none", dmg, DAMAGE_MAGIC | DAMAGE_PSYCHIC, DAMAGE_HP_ONLY | DAMAGE_BYPASS_ARMOUR, tp);

  message("magic", COL+"You shoot a spike of energy into "+
    tgt->query_cap_name()+"'s mind!"+RES, tp);
  message("magic", COL+"A spike of energy shoots from "+
    tp->query_cap_name()+" and stabs into your mind!"+RES, tgt);
  message("magic", COL+"A spike of energy shoots from "+
    tp->query_cap_name()+" into "+tgt->query_cap_name()+"!"+RES,
    environment(tp), ({ tp, tgt }) );

  tp->set_magic_round(1);
}
