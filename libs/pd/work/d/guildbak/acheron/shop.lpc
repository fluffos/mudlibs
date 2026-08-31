#include <std.h>
#include <guild.h>
inherit ROOM;
void create() {
    ::create();
    set_name("Acheron Shop");
    set_items(([
	"plaque"   : "The plaque reads: To find out what there is for "
	"sale, just type: list.",
	"counter"  : "There is a small plaque inlaid into the counter, "
	"maybe you can look at it."
      ]));
    set_properties(([
	"light"       : 2, 
	"night light" : 2, 
	"no teleport" : 1, 
	"no attack"   : 1,  
	"no magic"    : 1,
	"no bump"     : 1,
	"no steal"    : 1,
	"indoors"     : 1,
      ]));
    set_short("Acheron Shop");
    set_long("%^BOLD%^%^BLUE%^There is a counter at the far end of the room "
      "where %^RESET%^%^GREEN%^Mi%^BOLD%^%^GREEN%^ch%^RESET%^%^GREEN%^ae%^BOLD%^"
      "%^GREEN%^l%^BOLD%^%^BLUE%^, %^BOLD%^%^BLUE%^the shop attendant stands. "
      "Various stands are all around the %^BOLD%^%^BLUE%^room, full of all sorts "
      "of equipment. A large %^RESET%^%^ORANGE%^counter%^BOLD%^%^BLUE%^ blocks "
      "%^BOLD%^%^BLUE%^the way north, a small plaque is inlaid into the counter.");
    set_smell("default", "The smell of iron and weapon oil wafts in the air.");
    set_listen("default", "Clinks and clanks are heard to the north.");
    set_exits(([
	"east" : ROOMS"acheron/hall",
      ]));
}
void reset() {
    ::reset();
    if(!present("michael"))
	new("/d/guilds/acheron/michael")->move(this_object());
}

