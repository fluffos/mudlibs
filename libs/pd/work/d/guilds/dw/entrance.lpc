#include <std.h>
#include <daemons.h>
#include <guild.h>

inherit "/std/room";

void create() {
    ::create();
    set_name("Dragon Warrior's Entry");
    set_long(" A head of a dragon, with two glowing red eyes is carved into the "
      "mountainside.  With the entrance of a cave sitting inside the open mouth, the "
      "eyes flicker, daring anyone to enter.");
    set_short("Dragon Warrior's Entry");
    set_exits((["enter" : ROOMS"dw/hall",
        "out" : "/d/nopk/standard/cult/ent"]));
}

void reset() {
    ::reset();
    if(!present("monster",this_object()))
	new("/d/guilds/dw/tyrant")->move(this_object());
}
void init() {
    ::init();
    add_action("down", "enter");
}
int down() {
    if(GUILD_D->query_quild(this_player()->query_name())!="dw" && !wizardp(this_player())) {
	notify_fail("A gust of wind prevents you from entering.");
	say("A gust of wind blows as "+this_player()->query_cap_name()+" tries "
	  "to enter but fails.");
	return 0;
    }
    this_player()->move_player(ROOMS"dw/hall");
    return 1;
}

