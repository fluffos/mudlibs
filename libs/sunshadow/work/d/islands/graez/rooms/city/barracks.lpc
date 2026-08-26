#include "../../graez.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("Graez barracks bunk room");
    set_short("%^C059%^Graez %^C144%^barracks%^C059%^ bunk room%^CRST%^");
    set_long("This room is lined with %^C094%^bunks %^CRST%^"+
	"stacked three high and covering every square inch of "+
	"space. At the end of each %^C058%^bunk %^CRST%^are "+
	"%^C059%^chests %^CRST%^for the %^C244%^soldier's "+
	"%^CRST%^belongings and are marked with the %^C243%^soldiers%^CRST%^' "+
	"names. The ceiling is high vaulted and ends in a "+
	"%^C239%^wrought iron chandelier%^CRST%^, however here "+
	"the %^C253%^candles%^CRST%^ are unlit. %^C243%^Soldiers "+
	"%^CRST%^sleep in half of the %^C058%^bunks%^CRST%^. "+
	"Some %^C243%^soldiers %^CRST%^linger and play %^C250%^dice "+
	"%^CRST%^in corners but they maintain as much %^C060%^quiet "+
	"%^CRST%^as possible to let their comrades sleep while they can.\n");
    set_smell("default","%^C143%^The area is dominated by the "+
        "%^C220%^acrid%^C143%^ smell of tobacco.%^CRST%^");
    set_listen("default","%^C060%^The room is filled "+
        "with %^C245%^soldiers%^C060%^.%^CRST%^");
    set_exits( ([
       "west" : TOWN"common",
    ]) );
}

void reset() {
    ::reset();
    if(!present("omthgar")) new(MOBS"omthgar")->move(TO);
}
