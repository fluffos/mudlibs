//  originally created by Bohemund 14 January 1994
//
//  cleaned up by Nulvect 08-Dec-2010

#include <std.h>

#define FAIL(s) return notify_fail(s)

inherit DAEMON;

string query_output(object tp, object ob);
string query_examine(object tp, object tgt);

int spell() {
  object tp = this_player();
  if (tp->query_class() == "mage" && tp->query_level() >= 6)
    return 1;
  return 0;
}

string type() { return "conjuring"; }

void help() {
  message("help",
    "Syntax: <lore [item]>\n\n"
    "Allows a mage to discern any magic powers inherent in an object. "
    "There is no way to tell the difference between a failure to discern "
    "magic in the object and the lack of magic in an object.",
    this_player());
}

string query_examine(object tp, object tgt) {
  tp->add_mp(-13);
  tp->add_skill_points("conjuring", 13);
  return query_output(tp, tgt);
}

string query_output(object tp, object ob) {
  string *magic = ob->query_property("magic item");
  if (!ob->query_property("no magic") && sizeof(magic) &&
      tp->query_skill("conjuring") > random(101)) {
    return "You discern a magical force emanating from it...\n"
           "You sense the word \"%^BOLD%^"+magic[random(sizeof(magic))]+"%^RESET%^\".";
  }
  return "You fail to discern anything special about it.";
}

int can_cast(object tp, object ob) {
  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your magical powers fail.");

  if (!ob)
    FAIL("Gather lore about what?");

  if (tp->query_current_attacker())
    FAIL("You are too busy fighting!");

  if (tp->query_mp() < 10)
    FAIL("Too low on magic power.");

  return 1;
}

int cmd_lore(string str) {
  object tp = this_player();
  object ob;

  if (!spell()) return 0;

  if (!str)
    FAIL("Gather lore about what?");

  ob = present(str, tp);

  if (!can_cast(tp, ob)) return 0;

  message("magic", "You mutter quietly as you focus on "+
    definite_article(ob->query_name())+".", tp);

  message("magic", tp->query_cap_name()+" mutters quietly as "+
    tp->query_subjective()+" focuses on "+
    definite_article(ob->query_name())+".", environment(tp), tp);

  tp->set_magic_round();
  tp->add_mp(-13);
  tp->add_skill_points("conjuring", 13);

  message("magic", query_output(tp, ob), tp);

  return 1;
}

