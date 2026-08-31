#include <std.h>
inherit ROOM;
//Coded by a nutcase
void create() {
    ::create();
    set_short("Acheron's Scroll and Orb Shop");
    set_long("%^BOLD%^%^BLUE%^An exotic room this is, in the middle is a large "
      "counter %^BOLD%^%^BLUE%^where %^BOLD%^%^RED%^E%^RESET%^%^RED%^dw%^BOLD%^"
      "%^RED%^i%^RESET%^%^RED%^n%^BOLD%^%^BLUE%^ the guild %^RESET%^%^ORANGE%^Al"
      "%^BOLD%^%^YELLOW%^c%^BOLD%^%^WHITE%^he%^BOLD%^%^YELLOW%^mi%^RESET%^"
      "%^ORANGE%^st%^BOLD%^%^BLUE%^ stands. Behind him is a large %^BOLD%^"
      "%^BLUE%^case where the %^BOLD%^%^WHITE%^s%^BOLD%^%^BLACK%^c%^RESET%^"
      "%^RED%^r%^BOLD%^%^RED%^o%^RESET%^%^RED%^l%^BOLD%^%^BLACK%^l%^BOLD%^"
      "%^WHITE%^s%^BOLD%^%^BLUE%^ and %^BOLD%^%^BLUE%^o%^CYAN%^r%^BLUE%^b"
      "%^CYAN%^s%^BLUE%^ can be seen. A small sign can %^BOLD%^%^BLUE%^be seen "
      "on the wall.");
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
	"south" : "/d/guilds/acheron/hall",
      ]));

}

void reset() {
    ::reset();
    if (!present("edwin", this_object()))
	new("/d/guilds/acheron/edwin" )->move(this_object());
}

