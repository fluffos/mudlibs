#include <std.h>
#include <amun.h>
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
    set("short", "Last Saints");
    set("long", "%^BOLD%^%^WHITE%^This room is just a memory room for the Leaders of the Last Saints, there is a large %^YELLOW%^Golden Plaque%^WHITE%^ sitting in the middle of the room for all to look at.%^RESET%^");
    set_items(([ "writings" : "%^BOLD%^%^WHITE%^'And when I vest my flashing sword And my hand takes hold in judgement I will take vengeance upon mine enemies And I will repay those who hase me O Lord, raise me to Thy right hand And count me amoung Thy Saints. Whosoever shed last blood. By man shall his blood be shed. For immunity of god make he the man. Destroy all that which is evil. So that which is good may flourish. And I shall count thee amoung my favoured sheep. And you shall have the protection of all the angels in heaven. Never shall innocent blood be shed. Yet the blood of the wicked shall flow like a river. The three shall spread their blackened wings and be the vengeaful striking hammer of god.'%^RESET%^"]));
    set_exits( ([ "north" : GUILDROOM+"level1_main" ]) );
    new(GUILDOBJ+"golden_plaque")->move(this_object());
}
