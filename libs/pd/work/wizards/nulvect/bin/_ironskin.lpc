
#include <std.h>
#include <effect_cl.h>

#define FAIL(s) return notify_fail(s+"\n")

#define COL "%^YELLOW%^"
#define RES "%^RESET%^"

inherit DAEMON;

void end_ironskin(class Effect);

int abil() {
  object tp = this_player();
  if (tp->query_subclass() == "monk" && tp->query_level() >= 8)
    return 1;
  return 0;
}

string type() { return "defense"; }

void help() {
  message("help",
    "Syntax: <ironskin>\n\n"
    "Monks can concentrate their chi energies "
    "to make their skin as hard as iron.",
    this_player() );
}

int can_cast(object tp) {

  if (!tp) return 0;

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You fail to gather your chi.");

  if (tp->query_effect("ironskin"))
    FAIL("Your skin is already as hard as iron!");

  if (tp->query_mp() < 50)
    FAIL("Your magic power is too low.");

  return 1;
}

int cmd_ironskin(string str) {
  object tp = this_player();
  int cost, amt, time, md, melee, tmp;
  class Effect iron;

  if (!abil()) return 0;

  if (!can_cast(tp)) return 0;

  md = tp->query_skill("magic defense");
  cost = 15 + md + random(md/2);

  if (tp->query_mp() < cost)
    FAIL("Your magic power is too low.");

  switch (md) {
    case -500..0: tmp = 0; break;
    case 1..39: tmp = 1; break;
    case 40..79: tmp = 2; break;
    case 80..149: tmp = 3; break;
    case 150..249: tmp = 4; break;
    case 250..399: tmp = 5; break;
    default: tmp = 6; break;
  }

  amt = 1 + tmp + random(tmp);
  melee = tmp*10 + random(tmp*5);
  time = 30 + tmp*25 + random(tmp*3);

  iron = new(class Effect);
  iron->name = "ironskin";
  iron->castername = tp->query_name();
  iron->caster = tp;
  iron->target = tp;
  iron->desc = "Your skin is as hard as iron.";
  iron->endtime = time()+time;
  iron->endfunc = (: end_ironskin :);
  iron->endmessages = ({
    COL+"Your skin returns to normal."+RES,
    COL+tp->query_cap_name()+"'s skin returns to normal."+RES,
  });
  iron->misc = ({ amt, melee });

  tp->add_magic_protection( ({ 0, amt, 0 }) );
  tp->add_skill_bonus("melee", melee);
  tp->add_effect(iron);

  message("info", COL+"You concentrate your chi, "
    "making your skin as hard as iron."+RES, tp);
  message("info", COL+tp->query_cap_name()+" seems to concentrate "
    "and "+tp->query_possessive()+" skin hardens."+RES, environment(tp), tp);

  tp->set_disable();
  tp->add_mp(-cost);
  tp->add_skill_points("magic defense", 5+md/30);
  tp->add_skill_points("faith", 5+md/30);

  return 1;
}

void end_ironskin(class Effect iron) {
  object who = iron->target;
  int *info = iron->misc;
  int amt = info[0];
  int melee = info[1];

  who->add_magic_protection( ({ 0, -amt, 0 }) );
  who->add_skill_bonus("melee", -melee);
}
