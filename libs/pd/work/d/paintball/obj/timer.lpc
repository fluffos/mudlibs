//  Paintball Timer
#include <std.h>

inherit OBJECT;

int time;

void create() {
    ::create();
    set_name("timer");
    set_short("a paintball timer");
    set_id(({ "timer", "paintball timer" }));
    set_long("The commands is <settime [#] [Opt: m/s]>.  This will set the number of "
      "minutes the game will last.");
    time=0;
}

void init() {
    ::init();
    add_action("fsettime", "settime");
    add_action("fquery", "query");
}

int fsettime(string str) {
    int i;
    string tmp;

    if(!str) return notify_fail("Syntax: <settime [#] [optional: m/s]>\n");
    if(sscanf(str, "%d %s", i, tmp)==2) {
	switch(tmp) {
	case "m": time=i*60; break;
	case "s": i=i/5; time=i*60;
	default: write("Unknown time var.\n"); return 0; break;
	}
    } else {
	i=atoi(str);
	if(!i || !intp(i)) return notify_fail("Internal process error.\n");
	time=i*60;
    }
    write("Countdown. "+time+"seconds.\n");
    call_out("check", 5);
}

void check() {
    object o;

    if(time==0 || time<=0) {
	message("", "%^BOLD%^%^BLUE%^Paintball:%^RESET%^ The game has ended.", users());
	if(o=present("tablet", environment(this_object()))) {
	    o->endgame();
	}
	else {
	    "/daemon/chat"->do_raw_chat("cre", "Paintball <cre> Warning, game slab "
	      "not found for shutdown.");
	}
	return;
    }
    if(time== (5*60) ) {
	message("", "%^BOLD%^%^BLUE%^Paintball:%^RESET%^ 5 minutes left.", users());
    }
    if(time== 60 ) {
	message("", "%^BOLD%^%^BLUE%^Paintball:%^RESET%^ 1 minute left.", users());
    }
    if(time== 30 ) {
	message("", "%^BOLD%^%^BLUE%^Paintball:%^RESET%^ 30 seconds left.", users());
    }
    time = time-5;
    call_out("check", 5);
}

int fquery() {
    write(time+" seconds left.\n");
    return 1;
}

