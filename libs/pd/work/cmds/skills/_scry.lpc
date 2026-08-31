// originally created by Descartes 19 Nov 1992
//
// balanced and cleaned up by Nulvect 08-Dec-2010

#include <std.h>
#define FAIL(s) return notify_fail(s)

inherit DAEMON;

mapping skills = ([
  "mage" : "conjuring",
  "clergy" : "faith",
  "black" : "conjuring",
  "gypsy" : "clairvoyance",
]);

string find_skill(object tp) {
  string ret;
  if (!tp) return 0;
  // this relies on short-circuit logic
  if ((ret = skills[tp->query_class()]) ||
      (ret = skills[tp->query_subclass()]) )
        return ret;
  return 0;
}

void help() {
  message("help",
    "Syntax: <scry [player]>\n\n"
    "A divination spell that allows the caster to locate someone.",
    this_player() );
}

// various levels, ranging from 10 to 15
int spell() {
  object tp = this_player();
  string skill = find_skill(tp);
  // require more faith than other skills, this kind of evens it out for clergy
  int amount = (skill && skill == "faith" ? 75 : 60);
  if (tp && skill && tp->query_skill(skill) >= amount)
    return 1;
  return 0;
}

string type() { return "conjuring"; }

int can_cast(object tp) {
  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your spell fails to take hold.");

  if (tp->query_current_attacker())
    FAIL("You are too busy fighting!");

  if (tp->query_mp() < 50)
    FAIL("Too low on magic.");

  return 1;
}

int cmd_scry(string str) {
  object tp = this_player();
  object tgt, tgtenv;
  string skill;
  int scry, resist, points, cost;
  string mymsg;

  if (!spell()) return 0;

  if (!can_cast(tp)) return 0;

  if (!str)
    FAIL("Scry who?");

  tgt = find_player(str);

  skill = find_skill(tp);
  scry = tp->query_skill(skill);

  // most mages have 4 or 4.5 conj/level, so without this,
  // their scry is inherently inferior to clergy/gypsy,
  // which seems wrong
  if (skill == "conjuring")
    scry = scry * 150 / 100;

  if (tgt)
    resist = tgt->query_stats("wisdom")*2;

  scry -= resist;

  cost = 35 + random(10) + resist/4;

  if (!tgt || wizardp(tgt) || tgt->query_property("no scry") ||
      !(tgtenv = environment(tgt)) ||
      tgtenv->query_property("no scry") ||
      tgtenv->query_property("no teleport") ||
      scry < random(180)) {
        mymsg = "You see only mist in your mind's eye.";
        points = 5;
  }
  else {
    mymsg = "%^BOLD%^%^WHITE%^Through the mists of other dimensions you see:%^RESET%^\n\n";
    mymsg += "%^CYAN%^";
    mymsg += strip_color(tgtenv->query_long(0))+"\n";
    foreach (object thing in all_inventory(tgtenv)) {
      if (!thing->query_invis()) {
        mymsg += strip_color(thing->query_short())+"\n";
      }
    }
    mymsg = mymsg+"%^RESET%^";
    points = cost;
  }

  message("magic", mymsg, tp);
  message("magic", tp->query_cap_name()+" closes "+tp->query_possessive()+
    " eyes and concentrates.", environment(tp), tp);

  tp->add_skill_points(skill, points);
  tp->add_mp(-cost);
  tp->set_magic_round(1);

  return 1;
}

