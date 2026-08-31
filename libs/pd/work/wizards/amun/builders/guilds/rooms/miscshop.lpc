#include <std.h>
#include <guild.h>
#include <daemons.h>
inherit ROOM;

void init() {
    ::init();
    add_action("go_south", "south");
}

void create() {
    ::create();
    set_properties(([ "light" : 2, "indoors" : 1, "no bump" : 1, "no attack" : 1, "no magic" : 1 ]));
    set_short("The Guild Town Weapon Shop");
    set_long("%^CYAN%^The GT Misc Shop%^RESET%^\n"
      "%^RESET%^%^ORANGE%^The shop is very small and looks like it is not well taken care of. It is only standing because Starburst bought it for her cousin %^RESET%^%^MAGENTA%^Berry%^RESET%^%^ORANGE%^. Much like his cousin, Berry sells general supplies for travelers. There is a sign posted with a list of items.%^RESET%^"
    );
    set_items(([
	"shop" : "%^RESET%^%^ORANGE%^The shop is very dirty, as if it's never been cleaned.%^RESET%^" ]));
    set_exits(([
	"north" : GROOM"board_room"
      ]));
}

void reset() {
    ::reset();
    if(!present("berry")) 
	new(GMOB"berry")->move(this_object());
}

int go_south() {
    if(!wizardp(this_player())) {
	message("my_action", "That would surely be against the law.",
	  this_player());
	message("other_action", (string)this_player()->query_cap_name()+
	  " begins to leave east then thinks better of it.",
	  this_object(), ({ this_player() }));
	return 1;
    }
    this_player()->move_player(GROOM"msstorage", "south");
    return 1;
}
