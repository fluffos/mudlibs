//  Coded by Whit
//  Treasury for guilds
#include <std.h>
#include <guild.h>
#include <daemons.h>

inherit TREASURY;
void create() {
    ::create();
    set_guild("AoD");
    set_name("AoD Treasury");
    set_short("treasury room");
    set_long("%^BOLD%^%^BLACK%^Sk%^RESET%^%^WHITE%^u%^BOLD%^%^BLACK%^lls line "
      "the walls, bags full of Black Diam%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^"
      "nds line the %^BOLD%^%^BLACK%^floors. %^BOLD%^%^YELLOW%^Gold%^BOLD%^"
      "%^BLACK%^ coins fill the room with a %^BOLD%^%^YELLOW%^Golden%^BOLD%^"
      "%^BLACK%^ sh%^BOLD%^%^YELLOW%^i%^BOLD%^%^BLACK%^ne. %^BOLD%^%^YELLOW%^"
      "Coins%^BOLD%^%^BLACK%^ %^BOLD%^%^BLACK%^flow from the eyes of the Sk"
      "%^RESET%^%^WHITE%^u%^BOLD%^%^BLACK%^lls. Dark R%^RESET%^%^RED%^ubi"
      "%^BOLD%^%^BLACK%^es cover the floor %^BOLD%^%^BLACK%^with a r%^BOLD%^"
      "%^RED%^e%^BOLD%^%^BLACK%^d glow. ");
 set_properties( ([ "no attack"   : 1,
                    "no magic"    : 1,
                    "no bump"     : 1,
                    "light"       : 2,
                    "night light" : 2,
		    "no teleport" : 1,
		    "no scry" : 1,
		    "indoors" : 1,
                    "no steal"    : 1 ]) );


    set_exits( (["west" : AoD"hall"]) );

    set_items(([
	"skulls" : "%^BOLD%^%^BLACK%^Human Skulls filled with coins.%^RESET%^",
	"bags" : "%^BOLD%^%^BLACK%^Bags filled with Black Diamonds.%^RESET%^ "
      ]) );
}

