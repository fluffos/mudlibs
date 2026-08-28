#include "godzone.h"

create_room()
{
    set_area("godzone");
    set_light(1);
    set_short("Entrance");
    set_long(
      "You look around and see only endless void all around you, but when "+
      "you turn your head down, you can see a construction, floating in the "+
      "empty void. The light here seems to emit from no obvious source, but "+
      "rather from everywhere around you. Empty vacuum rages all around you, "+
      "but you seem to be able to survive here without difficulties for some "+
      "odd reason.\n");
    add_item(({"void"}),"The void looks like nothing, as void is nothing.\n");
    add_item(({"construction"}),"There is a weird construction floating in the endless void.\n"+
      "It seems to have no permanent shape, rather it seems to change slightly\n"+
      "everytime you look at it.\n");
    set_sounds(60,({"Empty vacuum swirls and rages around you.\n"}));
    add_exit("enter", ROOM_PATH + "imhall");
}

