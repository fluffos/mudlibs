
#include <std.h>
#include <rest.h>
#include <damage_types.h>
#include <damage.h>

#define FAIL(s) return notify_fail(s+"\n")

#define RES "%^RESET%^"
#define COL "%^CYAN%^"

inherit DAEMON;

int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "jester" && tp->query_level() >= 7)
    return 1;
  return 0;
}

string type() { return "defense"; }

void help() {
  message("help",
    "Syntax: <flop>\n\n"
    "A very basic slapstick move, this lets a jester purposely fall down "
    "and avoid the brunt of a blow. He will take a little damage from the "
    "fall itself, however.",
    this_player() );
}

int can_cast(object tp) {

  if (!tp) return 0;

  if (tp->query_ghost())
    FAIL("Why bother when you're dead?");

  if (!tp->clean_up_attackers())
    FAIL("You are not fighting anyone.");

  if (tp->query_rest_type())
    FAIL("You have to stand up first!");

  return 1;
}

int cmd_flop(string str) {
  object tp = this_player();
  object env = environment(tp);
  int def, time, level, hp;

  if (!abil()) return 0;

  if (!can_cast(tp)) return 0;

  def = 0;
  time = 2;
  level = tp->query_level();
  hp = tp->query_hp();

  // purposely let these fall through
  switch (level) {
    default: def = 50; break;
    case 36..500: def += level/5 + 1;
    case 21..35: def += level/3 + 5;
    case 11..20: def += level/2 + 10 + random(15);
    case 1..10: def += level*5 + 25 + random(10);
  }

  message("info", "You "+COL+"flop"+RES+" down on the ground.", tp);
  message("info", tp->query_cap_name()+" "+COL+"flops"+RES+
    " down on the ground.", env, tp);

  tp->set_rest_type(LAY);
  tp->set_disable(1);
  tp->add_skill_bonus("defense", def, time);
  tp->do_damage("random", level/2+random(level/3), DAMAGE_PHYSICAL | DAMAGE_IMPACT, DAMAGE_NO_SEVER | DAMAGE_NONLETHAL, tp);

  return 1;
}

