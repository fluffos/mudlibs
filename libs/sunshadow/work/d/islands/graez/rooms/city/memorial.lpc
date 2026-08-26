#include "../../graez.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("Graez barracks memorial room");
    set_short("%^C059%^Graez %^C144%^barracks%^C059%^ memorial room%^CRST%^");
    set_long("This room is completely different from the rest of the %^C059%^barracks%^CRST%^. The whole northern wall is plastered with small pieces of %^C230%^parchment%^CRST%^ and %^C144%^cloth%^CRST%^ with %^C250%^names%^CRST%^ written on them. %^C243%^Dented%^CRST%^ and %^C059%^torn%^CRST%^ %^C244%^helmets%^CRST%^ lay in the corners of the room and there is an air of solemnity here. In the middle of the room is a carefully piled %^C246%^cairn%^CRST%^ of %^C088%^heat blasted%^CRST%^ %^C245%^rocks%^CRST%^ and a piece of what looks like a %^C094%^gate%^CRST%^ rests on it. %^C245%^Soldiers%^CRST%^ mill about but do not speak here, instead touching forehead to the %^C245%^cairn%^CRST%^ or putting up new names.\n");
    set_smell("default","%^C143%^The area is dominated by the "+
        "%^C220%^acrid%^C143%^ smell of tobacco.%^CRST%^");
    set_listen("default","%^C060%^The room is almost silent.%^CRST%^");
    set_exits( ([
       "south" : TOWN"common",
    ]) );
}

