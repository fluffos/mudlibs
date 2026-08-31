#include <std.h>
#include <amun.h>
inherit ROOM;
void init() {
    ::init();
    add_action("go_west", "west");
}
void create() {
    ::create();
    set_properties(([ "light" : 2, "indoors" : 1, "no bump" : 1, "no attack" : 1, "no magic" : 1 ]));
    set_short("Marsh Armoury");
    set_long("%^BOLD%^%^BLACK%^MARSH ARMORY%^RESET%^\n"
      "%^BOLD%^%^BLACK%^This is a place for you to sell your armour and get money for your travels.  Marvello has a list posted on the wall for all to read.");
    set_items( ([ "shop": "This is a place for you to sell your armour and get money for your travels.", "sign": "Propety of Marvello. All goods approved and commissioned for sale.", "list": "look_at_list" ]) );
    set_invis_exits( ({ "east", "west" }) );    
    set_exits( ([ "northeast" : MARSHROOM+"marsh_square", "west": MARSHROOM+"marsh_armour_storage" ]) );
    set_listen( "default", "You hear nothing, not even the sound of crickets.");
}

void reset() {
    ::reset();
    if(!present("marvello")) 
	new(MARSHMON+"marvello")->move(this_object());
}
int go_west() {
    if(!wizardp(this_player())) {
	message("my_action", "Do you think that would be illegal?",
	  this_player());
	message("other_action", (string)this_player()->query_cap_name()+ " is throw backwards by a something magical.",
	  this_object(), ({ this_player() }));
	return 1;
    }
}
