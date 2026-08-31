#include <std.h>
#include <daemons.h>
#include <guild.h>

inherit "std/room";

int done;

void create() {
    ::create();
    set_property("light", 3);
    set("short", "Outland Supply storage");
    set("long", "This small, back room is where Bertha used to "
      "keep all of her supplies before they were sold. The lack "
      "of any light other than that which enters through the door "
      "you just came through causes the room to be rather dark. "
      "Strange shadows gather about the walls and niches in the "
      "walls.");
    set_items((["light" : "There is not much light in here.",
	({ "shadow", "shadows" }) : "Strange shadows cover "
	"up niches in the walls."]));
    set_exits((["south" : "/d/nopk/standard/outlands/shop"]));
    done = 1;
}

void init() {
    ::init();
    add_action("search_shadows","search");
    add_action("enter_shadows", "shadows");
}

void reset() {
    ::reset();
    done = 1;
}

int search_shadows() {
    if(done == 0)
	return 0;
    write("You find a small silver object in the shadows.");
    message("other action", this_player()->query_cap_name()+
      " finds a small object in one of the niches in the shadows.",
      this_object(), ({ this_player() }));
    new("/d/nopk/standard/outlands/pick")->move(this_player());
    remove_action("search_shadows","search");
    done = 0;
    return 1;
}
int enter_shadows() {
    if(this_player()->query_guild()!="forsaken" && !wizardp(this_player())) {
	write("You can not see through the shadows.\n");
	say(this_player()->query_cap_name()+" cannot see through the shadows.");
	this_player()->add_hp(-10);
	return 1;
    }
    if(GUILD_D->query_locked() && !wizardp(this_player())) return 
	notify_fail(GUILD_D->query_lock_reason());

    write("You pass through the shadows with ease.");
    say(this_player()->query_cap_name()+" enters the shadows and disappears.");
    this_player()->move_player(ROOMS"forsaken/hall");
    return 1;
}
