// Chernobog (3/15/22)
// Watch Tower Base Inherit

#include <std.h>

inherit VAULT;

void create(){
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("indoors", 1);
    set_property("light", 2);
    set_name("A lookout station on the Yniam Plains");
    set_short("%^RESET%^%^CRST%^%^C058%^A lookout station on the %^C144%^Yniam Plains%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C058%^This is the base floor of a lookout post along the trade routes in the %^C120%^pl%^C156%^a%^C120%^i%^C156%^n%^C120%^s%^C058%^. Constructed of wood, this building is obviously not intended to withstand an attack but to give warning instead. A %^C136%^ladder %^C058%^in the corner leads up to the second floor, while a table surrounded by a few chairs occupy the center of the room. %^C065%^Bunk beds %^C058%^line one of the walls, making this a workable, if unappetizing, living space. An open space on the wall has been splashed with %^C040%^f%^C046%^re%^C040%^s%^C046%^h p%^C040%^ai%^C046%^n%^C040%^t%^RESET%^%^C058%^, covering something up and displaying the %^C040%^e%^C046%^me%^C040%^r%^C046%^a%^C040%^l%^C046%^d g%^C040%^re%^C046%^e%^C040%^n l%^C046%^iv%^C040%^e%^C046%^r%^C040%^y %^C058%^of %^C144%^Yniam%^C058%^.%^CRST%^\n");
    set_smell("default", "%^RESET%^%^CRST%^%^C110%^It is %^C104%^musty %^C110%^and smells of %^C104%^body odor%^C110%^.%^CRST%^");
    set_listen("default", "%^RESET%^%^CRST%^%^C030%^You can hear the %^C045%^b%^C087%^re%^C045%^e%^C087%^ze %^C030%^as it blows past the doorway.%^CRST%^");

    set_items(([
        ({"table", "chairs"}) : "%^RESET%^%^CRST%^%^C058%^The table and chairs have seen better days, but still seem quite solid. A myriad of %^C130%^cuts %^C058%^and %^C136%^carvings %^C058%^in the table attest to hours of %^C059%^bo%^C244%^re%^C059%^do%^C244%^m %^C058%^for those stationed here.%^CRST%^",
        ({"bed", "beds", "bunk beds"}) : "%^RESET%^%^CRST%^%^C058%^A pair of %^C065%^bunks %^C058%^line the wall in an efficient use of space. The mattresses seem lumpy and %^C064%^smell %^C058%^a bit.%^CRST%^",
        ({"paint", "livery"}) : "%^RESET%^%^CRST%^%^C058%^The insignia of %^C144%^Yniam %^C058%^has been painted on the wall here, that of an %^C040%^e%^C046%^me%^C040%^r%^C046%^a%^C040%^l%^C046%^d c%^C040%^i%^C046%^rcl%^C040%^e %^C058%^containing a white stylized silhouette of gathered %^C144%^stalks of wheat %^C058%^alongside a %^C136%^pair of barrels%^C058%^.%^CRST%^",
        ]));
}

