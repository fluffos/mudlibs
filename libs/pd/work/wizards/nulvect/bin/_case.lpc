
#include <std.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s+"\n")

#define RES "%^RESET%^"
#define COL "%^WHITE%^"

inherit DAEMON;

string *allmsgs = ({
  "You would surely be caught and punished!",
  "You might get away with something small, but it's risky.",
  "You should be able to steal something.",
  "You'll definitely be able to swipe something.",
  "Ripe for the picking!",
});

int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "thief" &&
      tp->query_skill("perception") >= 17*5 &&
      tp->query_skill("stealing") >= 17*6)
        return 1;
  return 0;
}

string type() { return "other"; }

void help() {
  message("help",
    "Syntax: <case [who | what]>\n\n"
    "Thieves can check out people to try and get an idea "
    "of how easy it would be to steal something from them. "
    "Casing an item gives a rough estimate of its worth in gold.",
    this_player() );
}

int can_cast(object tp, object tgt, string str) {

  if (!tp) return 0;

  if (tp->query_ghost())
    FAIL("There are more important things right now, like becoming alive again.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (!strlen(str))
    FAIL("Who or what do you want to check out?");

  if (!tgt)
    FAIL("You don't see that here.");

  if (tgt == tp)
    FAIL("That wouldn't make any sense.");

  if (tp->clean_up_attackers())
    FAIL("You are too busy fighting!");

  if (tp->query_sp() < 1)
    FAIL("You are too tired.");

  return 1;
}

int cmd_case(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  int value, tmp, s;
  mapping currval;

  if (!abil()) return 0;

  if (str) {
    tgt = present(str, env);
    if (!tgt || !tgt->is_living())
      tgt = present(str, tp);
  }

  if (!can_cast(tp, tgt, str)) return 0;

  tp->set_disable();
  tp->add_sp(-(3+random(3)));

  tmp = 100 -
    (tp->query_skill("stealing")/4 + tp->query_skill("perception")/5 +
    tp->query_stats("intelligence")/3);
  if (tmp < 0) tmp = 0;

  if (tgt->is_living()) {
    value = BALANCE3_D->get_steal(tp, tgt, 1,
      ({ "stealing", "stealth" }),
      ({ "dexterity", "charisma" }) );
    value += 7;
    value = value + random(tmp/16) - random(tmp/18);
    if (value < 0)
      value = 0;
    s = sizeof(allmsgs);
    value /= s;
    if (value > s-1)
      value = s-1;
    message("info", COL+allmsgs[value]+RES, tp);
    if (!tp->use_stealth(3)) {
      message("look", COL+tp->query_cap_name()+" looks you over.", tgt);
      message("look", COL+tp->query_cap_name()+" looks over "+
          tgt->query_cap_name()+".", env, ({ tp, tgt }) );
    }
  }
  else {
    currval = tgt->query_curr_value();
    value = (currval && currval["gold"] ? currval["gold"] : 0);
    value = value + random(tmp) - random(tmp);
    if (value < 0) value = 0;
    message("info", COL+"The "+remove_article(strip_color(tgt->query_short()))+
      " seems to be worth about "+value+" gold."+RES, tp);
    if (!tp->use_stealth(3))
      message("info", COL+tp->query_cap_name()+" looks over "+
        definite_article(strip_color(tgt->query_short()))+".", env, tp);
  }


  return 1;
}

