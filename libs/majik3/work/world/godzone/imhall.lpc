#include "godzone.h"

create_room()
{
    set_area("godzone");
    set_light(1);
    set_short("Main hall");
    set_long("This is the hall where immortals gather to decide things to happen in "+
      "Majik, or in other realms. The room itself looks weird, almost "+
      "indefinite, since the room doesn't seem to contain any walls. "+
      "Yet, you are able to walk through the whole room with just few steps. "+
      "There is a big round marble table in the middle of the room, and "+
      "huge chairs, each in symmetrical formation around the enormous table. "+
      "There is a certain atmosphere of hidden power in the air. "+
      "There are stairs leading down to portal room, peculiar-looking hallway "+
      "leading to lounge of the gods, elevator driven by steam-power and pistons "+
      "leading to crystal room and glowing portal back to the void.\n");

    add_item(({"stairs"}),"These stairs look almost too normal to this environment,\n"+
      "they are just stairs leading to the portal room.\n");

    add_item(({"hallway"}),"The hallway is impossibly curved and twisty, you can't help\n"+
      "but wonder how anything like this can have been built.\n");

    add_item(({"elevator"}),"The elevator is driven by steam-power with steaming pistons\n"+
      "all around it.\n");

    add_item(({"piston","pistons"}),"The pistons occasionally let out hot gusts of steam.\n");

    add_item(({"hall","room"}),"The hall looks enormous, with no walls nor dimensions.\n"+
      "You are able to walk through the massive-looking hall with just few steps.\n"+
      "You see enormous round table in the middle of the room, with chairs around it.\n");

    add_item(({"table"}),"The huge round table is made from purest white marble, and\n"+
      "it's surface is shiny, almost mirror-like.\n");

    add_item(({"chair","chairs"}),"The chairs are positioned in symmetrical formation around the round\n"+
      "table. They are made from the same white marble as the table, in fact,\n"+
      "it seems that the table and the chairs are crafted from one huge piece\n"+
      "of white marble.\n");

    add_item(({"portal"}),"This glowing portal leads back to the entrance of this godly\n"+
      "building in the void.\n");

    add_exit("stairs", ROOM_PATH + "portalroom");
    add_exit("hallway", ROOM_PATH + "nlounge");
    add_exit("elevator", ROOM_PATH + "croom");
    add_exit("portal", ROOM_PATH + "entrance");
}
