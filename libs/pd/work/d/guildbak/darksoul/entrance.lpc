#include <std.h>
#include <daemons.h>
#include <guild.h>
inherit ROOM;
string *guilds = ({ "darksoul" });
void create() {
    ::create();
    add_pre_exit_function("out","go_stairs");
    add_pre_exit_function("down","go_stairs");
    set_properties((["light"       : 2, 
	"indoors"     : 1, 
	"no steal"    : 1,
	"no teleport" : 1, 
	"no bump"     : 1]));
    set_name("Entrance to the Darksouls guild");
    set_long("This is the secret entrance to the depths of the "
      "Darksouls guild.  From here down the stairs many come to "
      "participate in its rituals and become the best of Primal "
      "Darkness-II.");
    set_exits(([
	"down" : ROOMS"darksoul/hall",
       "out" : "/d/nopk/tirun/library"
      ]));
}

int go_stairs() {
    if(!this_player()->is_player()) return 0;
    return 1; }


void init() {
    ::init();
    add_action("down", "down");
}
int down() {
    if ((member_array(this_player()->query_guild(), guilds)==-1) && !wizardp(this_player())) {
	notify_fail("A gust of wind prevents you from entering.");
	say("A gust of wind blows as "+this_player()->query_cap_name()+" tries "
	  "to leave down but fails.");
	return 1;
    }
    if(GUILD_D->query_locked() && !wizardp(this_player())) return 
      notify_fail(GUILD_D->query_lock_reason());

    this_player()->move_player(ROOMS"darksoul/hall");
    return 1;
}

void reset() {
    ::reset();
    if(!present("guard")) {
	new("/d/guilds/darksoul/guard3")->move(this_object());
    }
}
