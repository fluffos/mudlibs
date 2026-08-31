#include <std.h>
#include <amun.h>
inherit ROOM;
void init() {
    ::init();
    add_action("go_east", "east");
}
void create() {
    ::create();
    set_properties(([ "light" : 2, "indoors" : 1, "no bump" : 1, "no attack" : 1, "no magic" : 1 ]));
    set_short("Hamen's Armoury");
    set_long(
      "%^BOLD%^%^BLACK%^HAMENS ARMOURY%^RESET%^\n"
      "%^BOLD%^%^YELLOW%^Welcome to Hamen's Tomb Armoury! This is a place for passerbys to sell their goods for a price, and to buy them for an even bigger price. The walls are full of ancient egyptian writings and a picture of the mystical sphinx. Horus has a list posted on the wall for all to read.%^RESET%^");
    set_items( ([ "shop": "This is a place for you to sell your armour and get money for your travels.", "sign": "Propety of Hamen. All goods approved and commissioned for sale." ]) );
    set_invis_exits( ( { "east", "west" } ) );    
    set_exits( ([ "northeast" : ROOMS "hamen_square", "east": ROOMS "hamen_armour_storage" ]) );
    set_listen( "default", "You hear the sound of travelers bustling around.");
}

void reset() {
    ::reset();
    if(!present("horus")) 
	new(MON "horus")->move(this_object());
}
int go_east() {
    if(!wizardp(this_player())) {
	message("my_action", "Do you think that would be illegal?",
	  this_player());
	message("other_action", (string)this_player()->query_cap_name()+ " is throw backwards by a something magical.",
	  this_object(), ({ this_player() }));
	return 1;
    }
}
