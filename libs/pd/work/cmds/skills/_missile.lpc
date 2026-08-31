
#include <std.h>
#include <daemons.h>
#include <damage.h>
#include <damage_types.h>

#define FAIL(s) return notify_fail(s+"\n")

#define COL "%^BOLD%^%^CYAN%^"
#define COL2 "%^YELLOW%^"
#define RES "%^RESET%^"

inherit DAEMON;

int spell() {
  object tp = this_player();
  if (tp && tp->query_class() == "mage")
    return 1;
  return 0;
}

void help() {
  message("help",
    "Syntax: <missile [target]>\n\n"
    "Casts a magic missile at the target to damage it.",
    this_player() );
}

string type() { return "attack"; }

int can_cast(object tp, object tgt) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your voice is hollow.");

  if (!tgt)
    FAIL("Cast a missile at whom?");

  if (!tgt->is_living())
    FAIL("That is not alive.");

  if (tp == tgt)
    FAIL("That would be unwise.");

  if (tgt->query_property("no missile"))
    FAIL(capitalize(tgt->query_subjective())+
         " is immune to such magic.");

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_missile(string str) {
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
    ({ "magic attack" }),
    ({ "intelligence" })
  );

  dmg = dmg * 60 / 100;

  cost = BALANCE3_D->get_cost(dmg, 1, "mp");

  if (tp->query_mp() < cost)
    FAIL("Too low on magic.");

  tp->add_mp(-cost);
  tp->add_skill_points("magic attack", dmg/20 + 5);
  tp->kill_ob(tgt);

  message("magic",
    COL+"You cast a "+COL2+"beam of light"+COL+
    " at "+tgt->query_cap_name()+"!"+RES, tp);
  message("magic",
    COL+tp->query_cap_name()+" casts a "+
    COL2+"beam of light"+COL+" flying at you!"+RES, tgt);
  message("magic",
    COL+tp->query_cap_name()+" casts a "+
    COL2+"beam of light"+COL+
    " at "+tgt->query_cap_name()+"!"+RES, env, ({ tp, tgt }) );

  tgt->do_damage("random", dmg, DAMAGE_MAGIC, 0, tp);
  tp->set_magic_round(1);
  tp->set_disable(1);

  return 1;
}
