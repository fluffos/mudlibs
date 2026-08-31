#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( ([ "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"night light" : 2,
	"no steal"    : 1 ]) );
    set("short", "The Cathedral Bakery");
    set("long",
      "%^BOLD%^%^WHITE%^The C%^RESET%^a%^BOLD%^%^WHITE%^th%^RESET%^e%^BOLD%^%^WHITE%^dr%^RESET%^a%^BOLD%^%^WHITE%^l Bakery%^RESET%^\n" 
      "%^BOLD%^%^WHITE%^The delicious smell of baked goods flows through the air. There are %^MAGENTA%^f%^CYAN%^l%^YELLOW%^o%^GREEN%^w%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLUE%^r%^WHITE%^s placed all around the room that add to the glorious smell. There are small round tables placed here and there for customers to stay and enjoy their yummy treats. There is a large sunroof in the ceiling that allows the %^YELLOW%^bright rays %^WHITE%^to shine through. Spring roams around the room helping all who enter. ");
    set_smell("default", "The delicious smell of cooking foods fills the air.");
    set_items(([
	"flowers"  : "%^BOLD%^%^WHITE%^The flowers smell great and are quite gorgeous.%^RESET%^",
	"tables" : "%^BOLD%^%^WHITE%^These are small round tables for customers to sit and enjoy their treats.%^RESET%^"
      ]));
    set_exits(([ "south" : SKYROOM "ls_4" ]));
}

void reset() {
    ::reset();
    /*
	    new("/std/obj/player_list")->move(this_object()); 
    */
    if(!present("spring")) 
	new(SKYMOB "spring")->move(this_object());
}
