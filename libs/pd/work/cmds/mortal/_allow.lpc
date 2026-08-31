
#include <std.h>

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

string *allows = ({
  "mount",
  "bump",
  "cleanse",
  "polymorph",
});

void help() {
  message("help",
    "Syntax: <allow [who] to [what]>\n"
    "        <allow list>\n\n"
    "Gives someone permission to do something.\n"
    "[what] can be any of:\n"+
    implode(allows, ", "),
    this_player() );
}

int cmd_allow(string str) {
  object tp = this_player();
  object who;
  string name;
  string what;

  if (str == "list") {
    foreach (string a in allows) {
      string *ppl = tp->query_allow(a);
      if (!ppl) ppl = ({});
      message("info", a+": "+implode(ppl, ", ")+"\n", tp);
    }
    return 1;
  }

  if (!str || sscanf(str, "%s to %s", name, what) != 2)
    FAIL("Allow who to do what?");

  if (name != "all" && !objectp(who = find_player(name)))
    FAIL("No one around by that name.");

  if (member_array(what, allows) == -1)
    FAIL("You can't do that.");

  tp->add_allow(what, name);

  message("info", "Allowing "+name+" to "+what+".", tp);

  return 1;
}

