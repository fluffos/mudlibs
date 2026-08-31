
#include <std.h>
#include <daemons.h>
#include <damage.h>
#include <damage_types.h>

#define FAIL(s) return notify_fail(s+"\n")

#define RES "%^RESET%^"
#define COL "%^BOLD%^%^MAGENTA%^"
#define COL2 "%^YELLOW%^"

inherit DAEMON;

void do_hit(mixed *info);

int spell() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "sorceror" &&
      tp->query_skill("psionics") >= 12*6)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <fracture [who]>\n\n"
    "Sorcerors can fracture the minds of their opponents, "
    "sometimes making spellcasting impossible for a short time and "
    "dealing a fair amount of mental damage.",
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

  if (tp->query_mp() < 100)
    FAIL("Your magic is too low.");

  if (!tp->kill_ob(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_fracture(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  int dmg, dmg_mp, cost, rank, stupor;

  if (!spell()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  if (tp->query_level() >= 25)
    rank = 2;
  else
    rank = 1;

  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    ({ "psionics", "magic attack" }),
    ({ "intelligence" }) );

  dmg = dmg * 140 / 100;

  dmg_mp = BALANCE3_D->get_damage(tp, tgt, 4,
    ({ "psionics" }),
    ({ "intelligence" }),
    ({ "intelligence" }) );

  stupor = 2+random(2);
  stupor += tp->query_stats("wisdom")/15;
  stupor -= tgt->query_stats("wisdom")/8;
  if (stupor < 1)
    stupor = 1;
  if (stupor > 4)
    stupor = 4 + (stupor-4)/3;

  cost = BALANCE3_D->get_cost(dmg, rank, "mp") * 3 / 2;

  if (tp->query_mp() < cost)
    FAIL("Your magic is too low.");

  tp->add_mp(-(cost/2));
  tp->set_magic_round(2);

  message("magic", COL+"You concentrate your psionic energy."+RES, tp);

  tp->add_skill_points("magic attack", 10+random(20));

  call_out("do_hit", 2, ({ tp, tgt, dmg, cost/2, stupor, dmg_mp }) );
  return 1;
}

void do_hit(mixed *info) {
  object tp = info[0];
  object tgt = info[1];
  int dmg = info[2];
  int cost = info[3];
  int stupor = info[4];
  int dmg_mp = info[5];

  if (!tp) return;

  if (!tgt || environment(tgt) != environment(tp)) {
    message("info", "Your target is not here!", tp);
    return;
  }

  if (member_array(tgt, tp->query_attackers()) == -1)
    return;

  tp->add_mp(-cost);
  tp->set_magic_round(1);
  tgt->do_damage("none", dmg, DAMAGE_MAGIC | DAMAGE_PSYCHIC, DAMAGE_HP_ONLY | DAMAGE_BYPASS_ARMOUR, tp);
  tgt->add_mp(-dmg_mp);

  message("magic", COL+"A "+COL2+"seething cloud"+COL+" of chaotic "+
    COL2+"power"+COL+" envelopes "+tgt->query_cap_name()+"'s head!"+RES,
    environment(tgt), tgt);
  message("magic", COL+"A "+COL2+"seething cloud"+COL+" of chaotic "+
    COL2+"power"+COL+" envelopes your head!"+RES, tgt);

  if (random(5000) < 700 + (tp->query_level()*30))
    tgt->set_stupor(stupor);
}
