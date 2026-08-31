#include <std.h>
#include <guild.h>
inherit ROOM;
void create() {
    ::create();
    set_properties(([  "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"no scry"     : 1,
	"indoors"     : 1,
	"no steal"    : 1
      ]));
    set_short("Unholy Healing Shop");
    set_long("%^BOLD%^%^BLACK%^Unholy Healing Shop%^RESET%^\n"
      "%^BOLD%^%^RED%^The demon'%^RESET%^%^RED%^s %^BOLD%^%^RED%^wris%^MAGENTA%^t begins in this %^RED%^hall. The cou%^RESET%^%^RED%^nter can be seen against the wal%^BOLD%^%^RED%^l. %^MAGENTA%^T%^RESET%^%^RED%^h%^BOLD%^%^RED%^e demon behind the counte%^MAGENTA%^r looks qui%^RED%^te old and is quit%^RESET%^%^RED%^e close to j%^BOLD%^%^RED%^oining Lo%^MAGENTA%^rd Asmo%^RED%^deous. There is%^MAGENTA%^ a %^RESET%^%^RED%^sign on the %^BOLD%^%^RED%^wall behind the dem%^MAGENTA%^on for all t%^RED%^o read. %^RESET%^");
    set_items( ([ "shop": "This is a place for you to buy your healers.", "counter" : "%^BOLD%^%^WHITE%^It appears that the counter is made of bones that have been fused together with %^RED%^b%^RESET%^%^RED%^l%^BOLD%^%^RED%^ood %^WHITE%^by %^BLACK%^Lord Asmodeous.%^RESET%^" ]) );
    set_exits( ([ "north" : "/d/guilds/unholy/hall" ]) );
}

void reset() {
    ::reset();
    if(!present("demon"))
	new("/d/guilds/unholy/gnarled_demon")->move(this_object());
}
