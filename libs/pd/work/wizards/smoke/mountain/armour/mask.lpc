#include <std.h>
inherit ARMOUR;
int extra_worn();

void create() {
    ::create();
    set_name("voodoo mask");
    set("id", ({ "mask", "voodoo mask" }) );
    set("short", "Petrified Voodoo mask");
    set("long", "The mask is made of a petrified cedar-type wood." 
	"it has two large holes to see out of and a small hole "
	"to breathe out of. It is painted with %^RED%^blood%^RESET%^"
	" and %^BOLD%^%^BLACK%^charcoal%^RESET%^ and other various "
	"natural colors. ");
    set_weight(9);
    set("value", 159);
    set_type("helmet");
    set_limbs( ({ "head" }) );
    set_ac(8);
    set_wear( (: extra_worn :) );
}

int extra_worn() {
    if((int)this_player()->query_alignment() > 0) {
         write("A holy aura denies the mask to your face.");
         say(this_player()->query_cap_name()+" is zapped by a holy "
	"light as they attempt to don the mask.");
         return 0;
    }
    write("The mask molds to your face and glows faintly %^BOLD%^%^BLACK%^"
	"black%^RESET%^.");
    say(this_player()->query_cap_name() + " puts on the mask and it starts "
	"to glow %^BOLD%^%^BLACK%^black%^RESET%^.");
    return 1;
}

