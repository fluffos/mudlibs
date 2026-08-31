#include <std.h>
#include <amun.h>
inherit ROOM;
void init() {
    ::init();
    add_action("go_southwest", "southwest");
}
void create() {
    ::create();
    set_properties(([ "light" : 2, "indoors" : 1, "no bump" : 1, "no attack" : 1, "no magic" : 1 ]));
    set_short("Heaven's Weapons");
    set_long(
      "%^BOLD%^%^YELLOW%^Heaven's WEAPONS%^RESET%^\n"
      "%^BOLD%^%^YELLOW%^Welcome to Heaven's Weapon Shop! This is a place for passerbys to sell their goods for a price, and to buy them for an even bigger price. The shop is bright and beautiful, as almost all areas of Heaven is. There is a nice soft, cool breeze coming in through the door allowing the room to smell of sweet perfumes. There is a list posted on the wall for all to read.%^RESET%^");
    set_invis_exits( ( { "southeast", "southwest" } ) );    
    set_exits( ([ "southwest" : HEVROOM "wep_storage", "east": HEVROOM "heaven_square" ]) );
}
void reset() {
    ::reset();
    if(!present("autumn")) 
	new(HEVMOB "autumn")->move(this_object());
}
int go_southwest() {
    if(!wizardp(this_player())) {
	message("my_action", "Do you think that would be illegal?",
	  this_player());
	message("other_action", (string)this_player()->query_cap_name()+ " is thrown backwards by a something magical.", 
	  this_object(), ({ this_player() }));
	return 1;
    }
}
