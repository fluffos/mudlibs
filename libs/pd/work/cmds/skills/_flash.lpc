
#include <std.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s+"\n")

#define COL "%^BOLD%^%^WHITE%^"
#define RES "%^RESET%^"

#define FLASH_PROP "flash_abil_time"
// delay in seconds
#define FLASH_DELAY 30

inherit DAEMON;

int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "swashbuckler" &&
      tp->query_level() >= 6)
        return 1;
  return 0;
}

string type() { return "deception"; }

void help() {
  message("help",
    "Syntax: <flash [whom]>\n\n"
    "You flash light off your blades into your opponent's eyes, "
    "blinding him for a moment.",
    this_player() );
}

int can_cast(object tp, object tgt, object *wep) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your mischief.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You're barely visible as is, ghosty.");

  if (!sizeof(wep))
    FAIL("You need to use a sword or knife for that.");

  if (!tgt)
    FAIL("Flash your blades at whom?");

  if (!tgt->is_living())
    FAIL("That isn't alive.");

  if (tgt == tp)
    FAIL("Blind yourself?");

  if (!tgt->query_is_limb("head"))
    FAIL(capitalize(tgt->query_subjective())+" has no head!");

  if (!tp->ok_to_kill(tgt))
    FAIL("You can't blind "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_flash(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  object *weps;
  int time, hit, miss;

  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  weps = filter(tp->query_wielded(), (:
    ($1->query_type() == "blade" || $1->query_type() == "knife")
  :) );

  if (!can_cast(tp, tgt, weps)) return 0;

  tp->add_sp(-(3+random(5)));

  hit = tp->query_skill("blade");
  hit += tp->query_skill("entertainment");
  hit += tp->query_level();
  if (sizeof(weps) > 1 && tp->query_skill("double wielding") >= 20*5)
    hit += hit*15/100;
  if (tp->query_current_attacker())
    hit -= hit*20/100;

  miss = tgt->query_skill("defense");
  miss += tgt->query_skill("perception");
  miss += tgt->query_level();
  if (tgt->query(FLASH_PROP) > time() || tgt->query_property("no blind"))
    miss = hit+50;

  hit -= miss;

  if (hit < 1) {
    message("info", "You try to blind "+tgt->query_cap_name()+", but "+
      tgt->query_subjective()+" notices your attempt!", tp);
    message("info", "You notice "+tp->query_cap_name()+" trying to "
      "flash light into your eyes!", tgt);
    message("info", tp->query_cap_name()+" tries to flash light into "+
      tgt->query_cap_name()+"'s eyes, but fails.", env, ({ tp, tgt }) );
  }

  else {
    time = time()+2;
    if (hit > miss*3/2 || random(3) == 2)
      time += 2;
    if (hit > miss*2 || random(5) == 2)
      time += 2;

    message("info", "You "+COL+"flash"+RES+" your "+COL+"blade"+
      (sizeof(weps) > 1 ? "s" : "")+RES+" at "+tgt->query_cap_name()+", "
      "blinding "+tgt->query_objective()+".", tp);
    message("info", "A "+COL+"flash of light"+RES+" hits you "
      "right in the eyes, blinding you!", tgt);
    message("info", tp->query_cap_name()+" "+COL+"flashes"+RES+" "+
      tp->query_possessive()+" "+COL+"blade"+
      (sizeof(weps) > 1 ? "s" : "")+RES+" at "+tgt->query_cap_name()+", "
      "blinding "+tgt->query_objective()+".", env, ({ tp, tgt }) );

    tgt->set_blind(-1);
    tgt->set(FLASH_PROP, time+FLASH_DELAY);
    DELAY_D->add_delay(time, tgt, "set_blind", 0, 0);
  }

  if (tgt->is_monster() && random(100) < 50) {
    tgt->force_me("kill "+tp->query_name());
    tgt->kill_ob(tp);
  }

  return 1;
}
