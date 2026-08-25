//	/bin/high_mortal/_cloak.c
//	from the Nightmare mudlib
//	A rogue cloaking device
//	created by Descartes of Borg 02 march 1993

#include <std.h>

inherit DAEMON;

int cmd_cloak(string str) {
  if(!str) {
    if(this_player()->query_invis())
      write("You are currently cloaked.");
    else write("You are not currently cloaked.");
    return 1;
  }
  if(str != "on" && str != "off") {
    write("Syntax: cloak [on|off]");
    return 1;
  }
  if(str == "on") {
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
    if((int)this_player()->query_skill("stealth") < 100) {
      notify_fail("You fail to slip into the shadows.\n");
      return 0;
    }
    write("You slip into the shadows.");
    this_player()->set_invis(1);
    return 1;
  }
  if(str == "off") {
    if(!this_player()->query_invis()) {
      notify_fail("You are not cloaked!\n");
      return 0;
    }
    write("You slip out of the shadows.");
    this_player()->set_invis(0);
    return 1;
  }
}

void help() {
  write("Syntax: cloak [on|off]\nThis command allows the person to slip "
	"into the shadows, making them hard to perceive. Staying cloaked drains "
	"you. If the command is given without a parameter your current status "
	"is shown.\n");
}
