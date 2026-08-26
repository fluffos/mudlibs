// Chernobog (3/15/22)
// Palisade Walls Inherit

#include <std.h>

inherit VAULT;

void create(){
    ::create();
    set_terrain(GRASSLANDS);
    set_travel(DIRT_ROAD);
    set_property("indoors", 0);
    set_property("light", 2);
    set_name("A wooden palisade");
    set_short("%^RESET%^%^CRST%^%^C058%^A %^C130%^w%^C136%^o%^C130%^o%^C136%^d%^C130%^e%^C136%^n %^RESET%^%^C058%^palisade%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C058%^The %^C136%^wooden walls %^C058%^of a %^C136%^p%^C130%^a%^C136%^l%^C130%^i%^C136%^s%^C130%^a%^C136%^d%^C130%^e %^RESET%^%^C058%^rise up here, the tops of each log pointed and capped in %^C059%^tar%^C058%^. A crude gateway has been left open to the road here for entry, though several mobile %^C130%^barricades %^C058%^nearby are available should the need arise. The %^C046%^g%^C118%^r%^C154%^a%^C046%^s%^C118%^s%^C154%^e%^C046%^s %^RESET%^%^C058%^of the %^C144%^plains %^C058%^give way beyond the entrance to earth packed down by travel.%^CRST%^\n");
    set_smell("default", "%^RESET%^%^CRST%^%^C144%^A strange %^C156%^acrid scent %^C144%^is carried on the breeze.%^CRST%^");
    set_listen("default", "%^RESET%^%^CRST%^%^C126%^The sounds of people at work carry from within the outpost walls.%^CRST%^");
    set_items(([
        "barricades" : "%^RESET%^%^CRST%^%^C058%^These are simple defenses, triangular in shape with %^C144%^p%^C250%^o%^C255%^int%^C250%^e%^C144%^d %^C136%^posts %^C058%^jutting out. A couple of them would blockade the palisade entrance easily.%^CRST%^",
        ({"palisade", "walls"}) : "%^RESET%^%^CRST%^%^C058%^The palisade is a %^C136%^wooden wall %^C058%^comprised of logs sunk end-first into the earth and lashed together with strips of %^C130%^leather%^C058%^. It is a simple defense meant more to buy time than to actually keep someone out.%^CRST%^",
        ]));
}

