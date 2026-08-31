#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_properties(([  "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"no scry"     : 1,
	"indoors"     : 1,
	"no steal"    : 1
      ]));
    set("short", "Last Saints");
    set("long","%^%^BOLD%^%^WHITE%^This room is full of open windows allowing the sky to shine through. Marble columns line the wall opposite the windows allowing the light, whether night or day, to shine upon them.%^RESET%^\n");
    set_exits( ([ "northwest" : GUILDROOM+"last_saints_board" ]) );
}
void reset() {
    ::reset();
    if(!present("fountain"))
	new(GUILDOBJ+"stone_fountain")->move(this_object());
}
void init() {
    ::init();
    add_action("view", "find");
}
int view(string str) {
    mixed strr;
    object env;
    if(!str || str == "")
	return notify_fail("Find who?");
    strr = find_player(str);
    env = environment(strr);
    if(!find_player(str))
	return notify_fail("Cannot find "+capitalize(str)+".\n");
    if(env->query_property("no scry") || wizardp(strr))
	return notify_fail("The fountain reveals nothing.\n");
    write("\nThe fountain reveals "+capitalize(str)+" is in "+env->query_short()+".\n");
    return 1;
}
