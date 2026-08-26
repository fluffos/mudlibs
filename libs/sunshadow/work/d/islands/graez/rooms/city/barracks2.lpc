#include "../../graez.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("Graez barracks armory");
    set_short("%^C059%^Graez %^C144%^barracks%^C059%^ armory%^CRST%^");
    set_long("This room is filled with %^C058%^cabinets %^CRST%^and "+
	"%^C058%^racks %^CRST%^of %^C052%^battle%^CRST%^ ready "+
	"%^C241%^weapons %^CRST%^and piles of %^C136%^repaired "+
	"%^CRST%^and %^C136%^oiled %^C244%^armor%^CRST%^. "+
	"%^C057%^Officers %^CRST%^and %^C058%^smiths %^CRST%^walk "+
	"from pile to pile making kits for %^C244%^soldiers "+
	"%^CRST%^to grab for outgoing patrols and berating "+
	"%^C244%^soldiers %^CRST%^who come back without gear. "+
	"This is controlled and managed chaos. The room is "+
	"lit with a series of %^C220%^candelabras %^CRST%^that "+
	"sit on the tables of %^C244%^gear %^CRST%^ensuring that "+
	"each pile is well lit.\n");
    set_smell("default","%^C143%^The area is dominated by the "+
        "%^C220%^acrid%^C143%^ smell of tobacco.%^CRST%^");
    set_listen("default","%^C060%^The room is filled "+
        "with %^C245%^soldiers%^C060%^.%^CRST%^");
    set_exits( ([
       "east" : TOWN"common",
    ]) );
}

void reset() {
    ::reset();
//    if(!present("omthgar")) new(MOBS"omthgar")->move(TO);
}
