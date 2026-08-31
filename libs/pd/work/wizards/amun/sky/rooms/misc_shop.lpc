#include <std.h>
#include <amun.h>
inherit ROOM;
void init() {
    ::init();
    add_action("go_southeast", "southeast");
}
void create() {
    ::create();
    set_properties(([ "light" : 2, "indoors" : 1, "no bump" : 1, "no attack" : 1, "no magic" : 1 ]));
    set_short("Sky Temple's Misc Supply");
    set_long(
      "%^BOLD%^%^YELLOW%^SKY TEMPLE'S MISC SUPPLY%^RESET%^\n"
      "%^BOLD%^%^WHITE%^Welcome to the Sky Temple's Misc Shop! This is a place for passerbys to buy items for a nice price. The room is very quaint and comfortable. Serith, is standing behind the counter awaiting customers to flock through. She has a list posted on the wall for all to read.%^RESET%^");
    set_invis_exits( ( { "southeast", "southwest" } ) );    
    set_exits( ([ "north" : SKYROOM "rs_5", "southeast": SKYROOM "misc_shop_supply" ]) );
}
void reset() {
    ::reset();
    if(!present("serith")) 
	new(SKYMOB "serith")->move(this_object());
}
int go_southeast() {
    if(!wizardp(this_player())) {
	message("my_action", "Do you think that would be illegal?",
	  this_player());
	message("other_action", (string)this_player()->query_cap_name()+
	  " is throw backwards by a something magical.",
	  this_object(), ({ this_player() }));
	return 1;
    }
}
