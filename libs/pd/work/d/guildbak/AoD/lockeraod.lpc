#include <std.h>
#include <guild.h>
inherit LOCKER;

void create() {
    set_path("/adm/save/votes/AoD");
    ::create();
    set_properties( ([ "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"night light" : 2,
	"no teleport" : 1,
	"no scry" : 1,
	"indoors" : 1,
	"no steal"    : 1 ]) );

    set_short("AoD locker room");
    set_long("%^BOLD%^%^BLACK%^Ar%^RESET%^%^WHITE%^m%^BOLD%^%^BLACK%^y of "
      "Dark%^RESET%^%^WHITE%^ne%^BOLD%^%^WHITE%^ss%^BOLD%^%^BLACK%^ storage "
      "room.\n%^BOLD%^%^BLACK%^The AoD storage room is long and narrow. "
      "An%^WHITE%^ci%^RESET%^%^WHITE%^e%^BOLD%^%^BLACK%^nt weapons and "
      "%^BOLD%^%^BLACK%^suits of armor line the walls. Piles of tre%^WHITE%^"
      "as%^RESET%^%^WHITE%^ur%^BOLD%^%^BLACK%^e won in %^BOLD%^%^BLACK%^"
      "battle litter the floor. Among the tre%^WHITE%^as%^RESET%^%^WHITE%^ur"
      "%^BOLD%^%^BLACK%^e lie holy %^BOLD%^%^BLACK%^talismans of tribes, "
      "thrown to the ground in disdain. Small %^BOLD%^%^BLACK%^niches in the "
      "walls are used to store the bel%^WHITE%^on%^RESET%^%^WHITE%^gi%^BOLD%^"
      "%^BLACK%^ngs of the guild %^BOLD%^%^BLACK%^members.");
    set_smell("default", "\n%^BOLD%^%^BLACK%^The scent of b%^RED%^loo%^BLACK%^d "
      "mingled with %^RESET%^%^ORANGE%^copper, %^BOLD%^%^YELLOW%^gold%^BOLD%^"
      "%^BLACK%^ and other metals lay heavily upon the air.");
    set_exits(([
	"east" : AoD"hall",
	"west" : AoD"pray"    
      ]));
}

