#include "../../graez.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("Graez barracks common room");
    set_short("Graez barracks common room");
    set_short("%^C059%^Graez %^C144%^barracks%^C059%^ common room%^CRST%^");
    set_long("This %^C059%^massive building%^CRST%^ has "+
        "been constructed of %^C094%^large timbers%^CRST%^ and the "+
        "ceiling arches far above you, coming together at the peak with a "+
        "massive %^C239%^wrought iron chandelier%^CRST%^ with "+
        "%^C255%^oversized candles%^CRST%^. The room is dominated "+
        "by %^C094%^two long tables %^CRST%^on either side, flanked "+
        "with %^C094%^benches%^CRST%^. At all hours of the day %^C245%^soldiers%^CRST%^ "+
        "come and go, either from their patrols on the walls or leaving for "+
        "it. Some sit and eat a %^C064%^quick meal%^CRST%^ or share a "+
        "%^C136%^drink%^CRST%^. In the %^C238%^dark corners%^CRST%^ "+
        "%^C244%^soldiers%^CRST%^ cry, ignored compassionately by their "+
        "brethren until they can pull themselves together to join. The mood "+
        "here flips from %^C031%^celebration%^CRST%^ to %^C056%^despair%^CRST%^ "+
        "quickly and the only constant is a thick layer of %^C143%^acrid "+
        "pipe smoke%^CRST%^ and the sounds of %^C244%^armor%^CRST%^. \n");
    set_smell("default","%^C143%^The area is dominated by the "+
        "%^C220%^acrid%^C143%^ smell of tobacco.%^CRST%^");
    set_listen("default","%^C060%^The room is filled "+
        "with %^C245%^soldiers%^C060%^.%^CRST%^");
    set_exits( ([
       "south" : TOWN"21",
       "east" : TOWN"barracks",
       "west" : TOWN"barracks2",
       "north" : TOWN"memorial",
    ]) );
}

void reset() {
    ::reset();
    if(!present("erdrick")) new(MOBS"erdrick")->move(TO);
}
