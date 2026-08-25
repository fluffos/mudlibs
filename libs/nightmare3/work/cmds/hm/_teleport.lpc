//	/bin/high_mortal/_teleport.c
//	from the Nightmare mudlib
//	A high mortal goto
//	created by Descartes of Borg 09 december 1992

#include <std.h>

inherit DAEMON;

int cmd_teleport(string str) {
    mixed location;

    if(!environment(this_player())) return 0;
    if(environment(this_player())->query_property("no teleport")) {
        this_player()->add_mp(-15);
        message("my_action", "A magic force prevents you from teleporting.",
          this_player());
        return 1;
    }
    if(!str) {
	if((int)this_player()->query_mp() < 15) {
	    notify_fail("Too low on magic power.\n");
	    return 0;
  	}
	location = (string)this_player()->getenv("marked");
	if(!location) location = (string)this_player()->getenv("start");
	this_player()->add_mp(-15);
	this_player()->move_player(location);
	return 1;
    }
    if(sscanf(str, "to %s", str) != 1) {
	notify_fail("Correct syntax: <teleport to [player]>\n");
	return 0;
    }
    if((int)this_player()->query_mp() < 60) {
	notify_fail("Too low on magic power.\n");
	return 0;
    }
    if(!find_living(str)) {
	notify_fail(capitalize(str)+" is nowhere to be found.\n");
	return 0;
    }
    if(creatorp(find_living(str))) {
        notify_fail("You may not teleport to immortals.\n");
        return 0;
    }
    if((string)find_living(str)->query_class() != (string)this_player()->query_class()) {
	notify_fail(capitalize(str)+" is beyond your reach.\n");
	return 0;
    }
    if(!find_living(str)->is_player()) {
      notify_fail("You can only teleport to players.\n");
      return 0;
    }
    location = environment(find_living(str));
    if(location->query_property("no teleport")) {
        this_player()->add_mp(-15);
        message("my_action", "A magic force prevents you from teleporting.",
          this_player());
        return 1;
    }
    if(this_player()->move_player(location))
        this_player()->add_mp(-60);
    else this_player()->add_mp(-15);
    return 1;
}

void help() {
    write("Syntax: <teleport (to [player])>\n\n"+
	"Allows you to teleport to a player in your class, or, if used\n"+
	"with no arguments, to a spot previosly marked by you.  If no\n"+
	"spot was previously marked, the it will teleport you to your\n"+
	"starting point.\n");
}
