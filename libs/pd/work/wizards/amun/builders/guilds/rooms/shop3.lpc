#include <std.h>
#include <guild.h>
inherit ROOM;

void init() {
    ::init();
    add_action("go_east", "east");
}

void create() {
    ::create();
    set_properties(([ "light" : 2, "indoors" : 1, "no bump" : 1, "no attack" : 1, "no magic" : 1 ]));
    set_short("The Guild Town Weapon Shop");
    set_long("%^CYAN%^The GT Weapon Shop%^RESET%^\n"
      "%^BOLD%^%^WHITE%^Weapons line the white walls in the shop. Fraylore stands behind the counter waiting to buy items from travelers and make profit from them. The shop is small but looks well taken care of. There is a list for all to read.%^RESET%^"
    );
    set_items(([
	"weapons" : "The weapons sparkle with cleanliness.",
	"counter" : "The counter is clean and houses a bored Fraylore.",
	"shop" : "The shop is very clean for being so small.",
	"walls" : "%^BOLD%^%^WHITE%^The walls are newly painted white.%^RESET%^",
      ]));
    set_exits(([
	"south" : GROOM"r_main2"
      ]));
}

void reset() {
    ::reset();
    if(!present("fraylore")) 
	new(GMOB"fraylore")->move(this_object());
}

int go_east() {
    if(!wizardp(this_player())) {
	message("my_action", "That would surely be against the law.",
	  this_player());
	message("other_action", (string)this_player()->query_cap_name()+
	  " begins to leave east then thinks better of it.",
	  this_object(), ({ this_player() }));
	return 1;
    }
    this_player()->move_player(GROOM"wepstorage", "east");
    return 1;
}
