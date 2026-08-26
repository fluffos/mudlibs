// Chernobog (3/15/22)
// Yniam Waystation - Forge

#include <std.h>
#include "../defs.h"
inherit VAULT;

void create(){
    ::create();
    set_terrain(GRASSLANDS);
    set_travel(DIRT_ROAD);
    set_property("indoors", 0);
    set_property("light", 2);
    set_property("smithy", 1);
    set_name("A smithy within the waystation");
    set_short("%^RESET%^%^CRST%^%^C046%^A %^C245%^smi%^C248%^th%^C245%^y %^C046%^within the %^C144%^waystation%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C144%^Wooden %^C136%^workbenches %^C144%^and %^C059%^heavy %^C245%^ir%^C248%^o%^C245%^n %^C059%^anvils %^C144%^are scattered about the area, a testament to the frequent use of this facility. A handful of %^C244%^m%^C246%^e%^C248%^t%^C246%^a%^C244%^l %^C246%^r%^C248%^o%^C246%^d%^C244%^s %^RESET%^%^C144%^have been stocked in the corner for basic farrier work, and a bin of %^C059%^c%^C244%^oa%^C059%^l %^C144%^sits nearby to feed the %^C202%^h%^C196%^u%^C202%^n%^C208%^g%^C202%^r%^C196%^y %^C202%^f%^C208%^l%^C202%^a%^C196%^m%^C202%^e%^C208%^s%^RESET%^%^C144%^. Left mostly open, a simple lean-to offers some cover over the roaring %^C245%^sto%^C248%^n%^C245%^e bel%^C248%^l%^C245%^y %^RESET%^%^C144%^of the %^C214%^f%^C220%^o%^C226%^r%^C220%^g%^C214%^e%^C144%^, and the back wall of the structure is covered with a variety of tools hanging from pegs.%^CRST%^\n");
    set_smell("default", "%^RESET%^%^CRST%^%^C059%^The air is heavy with the scent of %^C244%^smoke %^C059%^and %^C124%^flame%^C059%^.%^CRST%^");
    set_listen("default", "%^RESET%^%^CRST%^%^C202%^The rise and fall of the %^C208%^bellows %^C202%^and the roar of the %^C208%^forge %^C202%^fill the air.%^CRST%^");
    set_items(([
        ({"workbenches", "tables"}) : "%^RESET%^%^CRST%^%^C058%^Fashioned from %^C136%^solid oak%^C058%^, these are sturdy places to work. Several %^C244%^m%^C246%^e%^C248%^t%^C246%^a%^C244%^l v%^C246%^i%^C248%^c%^C246%^e%^C244%^s %^RESET%^%^C058%^have been affixed to the ends of a few tables, and the surfaces are already showing dents and impressions from use.%^CRST%^",
        "anvils" : "%^RESET%^%^CRST%^%^C058%^A collection of %^C059%^anvils %^C058%^placed on %^C136%^wooden stumps %^C058%^are arranged around the area. Some are quite massive while others are quite small for delicate work.%^CRST%^",
        ({"rods", "metal rods"}) : "%^RESET%^%^CRST%^%^C058%^A few rods of %^C244%^m%^C246%^e%^C248%^t%^C246%^a%^C244%^l %^RESET%^%^C058%^are piled against the corner of the lean-to, often used for simple projects in the forge such as %^C244%^horseshoes %^C058%^and %^C248%^nails%^C058%^.%^CRST%^",
        "forge" : "%^RESET%^%^CRST%^%^C058%^Heavy %^C245%^sto%^C248%^n%^C245%^e %^RESET%^%^C058%^has been laid in a circle in the center of the smithy, forming a pit full of %^C059%^c%^C244%^oa%^C059%^l %^C058%^and other fuel for the %^C202%^f%^C196%^i%^C202%^r%^C208%^e%^RESET%^%^C058%^. Bellows hang from hooks nearby, to be used to bring the flames to a %^C214%^r%^C220%^o%^C226%^ari%^C220%^n%^C214%^g b%^C220%^r%^C226%^illian%^C220%^c%^C214%^e %^RESET%^%^C058%^when needed.%^CRST%^",
        ]));
    set_exits(([
        "south" : ROOMS"outpost_hub",
        ]));
}

