#include <std.h>
inherit DAEMON;

void help() {
  write("Syntax: <hold [item]>\n\n"+
   "Puts a magic hold on a locked object.  This will help\n"+
   "to prevent would-be thieves from breaking into your lockable\n"+
   "chest or room.\n"
   "See also: keep\n"
  );
}

// level 11 for wiz/necro, 13 for sorc
int spell() {
  object tp = this_player();
  string *allowed = ({ "wizard", "necromancer", "sorceror" });
  if (tp && tp->query_skill("conjuring") >= to_int(11*4.5) &&
      member_array(tp->query_subclass(), allowed) != -1)
        return 1;
  return 0;
}

string type() { return "conjuring"; }

int cmd_hold(string str) {
  object tp, ob;
  int con, amount;

  tp = this_player();
  if (!spell()) {
    return 0;
  }
  if(!str) ob = environment(tp);
  if(!ob) {
    if(!(ob= present(str, environment(tp)))) ob = present(str, tp);
    if(!ob) if(environment(tp)->id(str)) ob = environment(tp);
    if(!ob) ob = parse_objects(environment(tp), str);
    if(!ob) ob = parse_objects(tp, str);
    if(!ob) {
      notify_fail("No such thing around here.\n");
      return 0;
    }
  }
  if(!ob->query_locked()) {
    notify_fail("You may only place a hold on locked objects.\n");
    return 0;
  }
  if( (con = (int)tp->query_skill("conjuring")) < 2) {
    notify_fail("You are not experienced enought to cast such a spell.\n");
    return 0;
  }
  amount = random(con)/2;
  if( (int)tp->query_mp() < 5) {
    notify_fail("Too low on magic power.\n");
    return 0;
  }
  tp->add_mp(-5);
  ob->set_property("magic hold", amount);
  tp->add_skill_points("conjuring", amount);
  write("You cast a spell of holding on "+lower_case((string)ob->query_short())+".\n");
  say(tp->query_cap_name()+" casts a spell of holding.\n", tp);
  return 1;
}

