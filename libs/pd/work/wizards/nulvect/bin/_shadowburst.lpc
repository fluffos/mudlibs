
#include <std.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s+"\n")

#define COL "%^BOLD%^%^BLACK%^"
#define RES "%^RESET%^"

inherit DAEMON;

string *subs = ({ "kataan", "necromancer", "antipaladin" });

int spell() {
  object tp = this_player();
  if (member_array(tp->query_subclass(), subs) != -1 &&
      tp->query_skill("magic attack") >= 40 &&
      tp->query_level() >= 8)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <shadowburst [who]>\n\n"
    "This spell engulfs the caster's enemy in harmful shadows.",
    this_player());
}

int can_cast(object tp, object tgt) {

  if (environment(tp)->query_property("no magic") ||
      environment(tp)->query_property("no attack"))
        FAIL("Some force prevents your violence.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your magic fails.");

  if (!tgt)
    FAIL("Shadowburst whom?");

  if (!tgt->is_living())
    FAIL("That is not alive.");

  if (tgt == tp)
    FAIL("The demons laugh at you.");

  if (!tp->ok_to_kill(tgt))
    FAIL("You may not attack "+tgt->query_cap_name()+".");

  if (tp->query_mp() < 45)
    FAIL("Too low on magic power.");

  return 1;
}

int cmd_shadowburst(string str) {
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

  dmg = BALANCE3_D->get_damage(tp, tgt, 2,
    ({ "magic attack" }),
    ({ "intelligence", "wisdom" }) );

  cost = dmg/7;

  if (tp->query_mp() < cost)
    FAIL("Too low on magic power.");
  
  tp->kill_ob(tgt);

  if (dmg < 10) {
    message("magic", "Shadows surround "+tgt->query_cap_name()+
      " and evaporate harmlessly.", env, tgt);
    message("magic", "Shadows surround you, "
      "but they evaporate harmlessly.", tgt);
    return 1;
  }

  message("magic", COL+"Shadows engulf "+tgt->query_cap_name()+"!", env, tgt);
  message("magic", COL+"Shadows engulf you!", tgt);

  tp->set_casting(dmg);
  tp->add_mp(-cost);

  return 1;
}
