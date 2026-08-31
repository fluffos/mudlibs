#include <std.h>
#include <amun.h>
inherit HALL;
void init() {
    ::init();
    add_action("homeroom", "down");
    add_action("blockview", "peer");
    if(this_player()->query_original_guild() != "lastsaints" && !wizardp(this_player()))
	GUILDOBJ"notin_guild"->eject(this_player());
}
int blockview(string str) {
    if(str == "down" || str == "d") {
	message("info", "The personal rooms cannot be seen from up here.",
	  this_player(), );
	return 1;
    }
    return 0;
}
