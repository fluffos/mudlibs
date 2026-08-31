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
    set_short("SKY TEMPLE'S Weapons");
    set_long(
      "%^BOLD%^%^YELLOW%^SKY TEMPLE'S WEAPONS%^RESET%^\n"
      "%^BOLD%^%^WHITE%^Welcome to the Sky Temple's Weapon Shop! This is a place for passerbys to sell their goods for a price, and to buy them for an even bigger price. The shop is bright and %^MAGENTA%^beautiful%^WHITE%^, as almost all areas of the Sky Temple are. There is a nice soft, %^CYAN%^cool breeze %^WHITE%^coming in through the door allowing the room to smell of sweet perfumes. There is a list posted on the wall for all to read.%^RESET%^");
    set_invis_exits( ( { "southeast", "southwest" } ) );    
    set_exits( ([ "southwest" : SKYROOM "wep_storage", "south": SKYROOM "rs_2" ]) );
}
void reset() {
    ::reset();
    if(!present("autumn")) 
	new(SKYMOB "autumn")->move(this_object());
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
