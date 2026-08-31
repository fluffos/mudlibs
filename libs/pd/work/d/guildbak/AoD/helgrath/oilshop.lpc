#include <std.h>
#include <guild.h>
inherit ROOM;
void create() {
    ::create();
    set_short("Skulls and Blood");
    set_long("%^BOLD%^%^BLACK%^H%^BOLD%^%^GREEN%^u%^BOLD%^%^BLACK%^m%^GREEN%^"
      "a%^BLACK%^n S%^GREEN%^k%^BLACK%^u%^GREEN%^l%^BLACK%^l%^GREEN%^s%^BOLD%^"
      "%^BLACK%^ lie on the shelfs glowing with a dark mist, %^BOLD%^%^BLACK%^"
      "vials of b%^BOLD%^%^RED%^loo%^BOLD%^%^BLACK%^d lie on the table. A "
      "huge Sacrom wizard stands %^BOLD%^%^BLACK%^behind the table waiting. "
      "Pictures of great warriors line the %^BOLD%^%^BLACK%^walls, the floor "
      "is coverd in b%^BOLD%^%^RED%^loo%^BOLD%^%^BLACK%^d, the smell of dead "
      "flesh %^BOLD%^%^BLACK%^fills your noise.");
    set_items(([
	"skulls" : "%^BOLD%^%^BLACK%^Human Skulls filled with a Dark mist."
	"%^RESET%^",
	"blood" : "%^RESET%^%^RED%^Deep Crimson Red Blood%^RESET%^ "]) );

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

    set_exits(([
	"north" : AoD"helgrath/hall",
      ]));
}
void reset() {
    ::reset();     
    if(!present("wizard"))
	new(AoD"mon/wizard")->move(this_object());
}

