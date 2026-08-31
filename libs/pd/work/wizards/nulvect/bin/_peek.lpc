
#include <std.h>

#define FAIL(s) return notify_fail(s+"\n")

#define COL "%^YELLOW%^"
#define RES "%^RESET%^"

inherit DAEMON;

int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "thief" &&
      tp->query_skill("perception") >= 19*5)
        return 1;
  return 0;
}

string type() { return "other"; }

void help() {
  message("help",
    "Syntax: <peek in [who's] [bag]>\n\n"
    "Thieves can peek into a container someone is carrying "
    "to see if there's anything in it worth stealing.",
    this_player() );
}

int can_cast(object tp, object tgt, object bag) {

  if (!tp) return 0;

  if (tp->query_busy())
    FAIL("You are busy.");

  if (!tgt)
    FAIL("Peek at whom?");

  if (!living(tgt))
    FAIL("That isn't alive.");

  if (tgt == tp)
    FAIL("You could just look.");

  if (!bag)
    FAIL(capitalize(tgt->query_subjective())+
         " isn't carrying that.");

  if (bag->query_locked())
    FAIL("It is locked.");

  return 1;
}

int cmd_peek(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt, bag;
  string who, what;
  int perc, stealth;

  if (!abil()) return 0;

  if (strlen(str)) {
    if (sscanf(str, "in %s's %s", who, what) != 2)
      sscanf(str, "%s %s", who, what);
  }

  if (strlen(who))
    tgt = present(who, env);

  if (tgt && strlen(what))
    bag = present(what, tgt);

  if (!can_cast(tp, tgt, bag)) return 0;

  tp->add_sp(-1);
  tp->set_disable();

  perc = tgt->query_skill("perception")*4/3;
  perc += tgt->query_stats("intelligence")*4;
  if (bag->query_closed())
    perc += 50 + random(bag->query_weight() * 3);

  stealth = tp->query_skill("stealth")*2/3;
  stealth += tp->query_skill("perception")*2/3;
  stealth += tp->query_stats("dexterity")*3;
  if (tp->use_stealth("look"))
    stealth += 50;
  if (tp->query_invis())
    stealth += 50;
  //stealth += random(tp->query_skill("stealing")/2);

  message("info", COL+"You peek in "+tgt->query_cap_name()+"'s "+
          bag->query_name()+"."+RES, tp);
  message("cmd_look", bag->query_long_more(), tp);

  if (perc > stealth)
    message("info", COL+"You notice "+tp->query_cap_name()+
      " peeking in your "+bag->query_name()+"."+RES, tgt);

  return 1;
}
