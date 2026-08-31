// seeker ... and NS
#include <daemons.h>
#include <std.h>
inherit DAEMON;
int cmd_hpinfo(string blah) {
    string str;
    string st;
    if(blah == "bold")
	st = "%^BOLD%^";
    else
	st = "%^RESET%^";

    st += "%^CYAN%^hp: %^GREEN%^$h";
    st += "%^BLUE%^|%^CYAN%^sp: %^GREEN%^$s";
    if(this_player()->query_race() == "vampire") {
	st += "%^BLUE%^|%^CYAN%^mp: %^GREEN%^$m";
	st += "%^BLUE%^|%^CYAN%^bp: %^RED%^$b %^BLUE%^>";
    } else
	st += "%^BLUE%^|%^CYAN%^mp: %^GREEN%^$m %^BLUE%^>";
    str = this_player()->getenv("prompt");
    if (str==st)
	this_player()->setenv("prompt",">");
    else
	this_player()->setenv("prompt", st);

    return 1;
}
void help() {
    write("Syntax: <hpinfo>\n\nChanges your prompt.\n"
      "If it is too dark for your screen, type <hpinfo [bold]>\n"
      "for a more visible prompt.\n");
}

