#include <cmd.h>

// How about some bugfixing? --Bull Apr 21, 1997

nomask int
allowshadow_cmd(string str) {
    if(!CHECK) return 0;
    if(!interactive(this_player())) return 0;
    if(str != "YES") {
	this_player()->set_allow_shadow(0);
	return notify_fail("Allowshadow: preventing shadowing. \n"), 0;
    }
    this_player()->tell_me(
      "Allowshadow: allowing shadowing. ");
    this_player()->set_allow_shadow(1);
    return 1;
}
