
#include <std.h>

#define COL "%^BOLD%^%^MAGENTA%^"
#define RES "%^RESET%^"

#define CHARM_PROP "charm_abil_bonus"

#define FAIL(s) return notify_fail(s+"\n");

inherit DAEMON;

void charm_on(object tp, int amt);
void charm_off(object tp);

object *who=({});

int abil() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "gypsy" && tp->query_level() >= 25)
    return 1;
  return 0;
}

string type() { return "deception"; }

void help() {
  message("help",
    "Syntax: <charm (on|off)>\n\n"
    "This allows a gypsy to act in an especially charming and agreeable "
    "manner for a period of time, affecting how everyone reacts to him. "
    "His powers of clairvoyance can sometimes help.",
    this_player() );
}

int can_cast(object tp) {

  if (!tp) return 0;

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Ghosts aren't charming at all.");

  return 1;
}

int cmd_charm(string str) {
  object tp=this_player();
  object env=environment(tp);
  int amt;
  float tmp;

  if (!abil()) return 0;

  switch (str) {
    case "off":
      if (!tp->query(CHARM_PROP))
        FAIL("You are not trying to be charming right now.");
      charm_off(tp);
      message("info", "You stop acting charming.", tp);
    break;
    
    case "on":
      if (!can_cast(tp)) return 0;
      if (tp->query(CHARM_PROP))
        FAIL("You are already being charming.");
      if (tp->query_sp() < 20)
        FAIL("You're too tired to do that.");
      amt = tp->query_stats("charisma")/4;
      tmp = ((tp->query_skill("clairvoyance")+tp->query_skill("bargaining")) - 25*(6+5));
      tmp = tmp/((50-25)*(6+5));
      if (tmp > 1) tmp = 1;
      if (tmp > 0) amt += to_int(tmp*amt*2);
      if (amt > tp->query_stats("charisma")*3/4)
        amt=tp->query_stats("charisma")*3/4;
      tp->add_sp(-10);
      tp->set_disable();
      //tp->add_hook("heart_beat", (: add_sp(-2) add_mp(-3) :) );
      charm_on(tp, amt);
      set_heart_beat(2);
      message("info", "You try to be "+COL+"charming"+RES+
                      " to all those around you.", tp);
    break;

    default:
      message("info", "Syntax: <charm (on|off)>", tp);
  }

  return 1;
}

void charm_on(object tp, int amt) {
  tp->add_stat_bonus("charisma", amt);
  tp->set(CHARM_PROP, amt);
  who += ({tp});
}

void charm_off(object tp) {
  tp->add_stat_bonus("charisma", -1*tp->query(CHARM_PROP));
  tp->set(CHARM_PROP,0);
  who -= ({tp});
}

void heart_beat() {
  foreach (object person in who) {
    if (!person) who-=({person});
    else {
      person->add_sp(-1);
      if (person->query_mp() > 5)
        person->add_mp(-(2+random(2)));
      if (person->query_sp() < 5) {
        charm_off(person);
        message("info", "You stop trying to act charming due to fatigue.", person);
      }
    }
  }
  if (!sizeof(who)) {
    set_heart_beat(0);
    return;
  }
}
