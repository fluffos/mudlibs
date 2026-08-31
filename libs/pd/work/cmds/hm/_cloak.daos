//	/bin/high_mortal/_cloak.c
//	from the Nightmare mudlib
//	A rogue cloaking device
//	created by Descartes of Borg 02 march 1993

#include <std.h>

inherit DAEMON;

int abil();
string type() { return "deception"; }
int cmd_cloak() {
    if (!abil()) return notify_fail("You cannot do that.\n");
    if(this_player()->query_invis()) {
	notify_fail("You are already cloaked!\n");
	return 0;
    }
    if(this_player()->query_disable()) return 1;
    this_player()->set_disable();
    if((int)this_player()->query_sp() < 75) {
	notify_fail("You do not have the strength to do that.\n");
	return 0;
    }
    this_player()->add_sp(-75);
    if((int)this_player()->query_skill("stealth") < 80) {
	notify_fail("You fail to slip into the shadows.\n");
	return 0;
    }
    this_player()->set_invis();
    return 1;
}

void help() {
    write("Syntax: <cloak>\n\nCloaks the person and makes them hard to see.\n");
    write("Staying cloaked drains you of sp!\n");
    write("\nSee also decloak.\n");
}

int abil() {
  object tp = this_player();
  if (tp && tp->query_class() == "rogue" &&
      tp->query_level() >= 20 &&
      tp->query_skill("stealth") >= 100)
        return 1;
  return 0;
}
