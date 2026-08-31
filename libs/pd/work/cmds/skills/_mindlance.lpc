
#include <std.h>
#include <daemons.h>
#include <damage.h>
#include <damage_types.h>

#define FAIL(s) return notify_fail(s+"\n")

#define RES "%^RESET%^"
#define COL "%^BOLD%^%^MAGENTA%^"
#define COL2 "%^BOLD%^%^WHITE%^"

inherit DAEMON;

void do_hit(mixed *info);

int spell() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "sorceror" &&
      tp->query_skill("psionics") >= 25*6 &&
      tp->query_skill("magic attack") >= 25*6)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <mindlance [who]>\n\n"
    "A more advanced psionic attack that pierces an opponent's "
    "mind with a lance of psionic energy.",
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

  if (tp->query_mp() < 75)
    FAIL("Your magic is too low.");

  if (!tp->kill_ob(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_mindlance(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  int dmg, cost, rank;

  if (!spell()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  if (tp->query_level() >= 35)
    rank = 3;
  else
    rank = 2;

  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    ({ "psionics", "magic attack" }),
    ({ "intelligence" }),
    ({ "intelligence", "wisdom" }) );

  dmg = dmg*5/3;

  cost = BALANCE3_D->get_cost(dmg, rank, "mp");

  if (tp->query_mp() < cost)
    FAIL("Your magic is too low.");

  tp->add_mp(-(cost/2));
  tp->set_magic_round(2);

  message("magic", COL+"You concentrate your psionic energy."+RES, tp);

  tp->add_skill_points("psionics", dmg/50);

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

  message("magic", COL+"You "+COL2+"pierce"+COL+" through "+
    tgt->query_cap_name()+"'s thoughts with a "+COL2+"lance"+COL+
    " of energy!"+RES, tp);
  message("magic", COL+"A "+COL2+"lance"+COL+" of energy pierces "+
    "through your thoughts!"+RES, tgt);
  message("magic", COL+"A "+COL2+"lance"+COL+" of energy shoots from "+
    tp->query_cap_name()+" into "+tgt->query_cap_name()+"!"+RES,
    environment(tp), ({ tp, tgt }) );

  tp->set_magic_round(1);
}
