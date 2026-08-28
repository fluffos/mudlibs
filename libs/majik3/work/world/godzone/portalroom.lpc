#include "godzone.h"

create_room()
{
    set_area("godzone");
    set_light(1);
    set_short("Portal room");
    set_long("This is a circular room known as 'the portal room', mainly because "+
      "the wall of this room are covered with different kind of portals, "+
      "leading to different places in time and space.\n");
    add_item(({"wall","walls"}),"In this room, you can't talk about walls, since the room is\n"+
      "circular, but everywhere you look, you can see portals; small, big, different\n"+
      "coloured and shaped.\n");
    add_item(({"portals"}),"There are so many different kinda portals that you wonder if\n"+
      "you have ever seen as many. The portals create a strange humming noise\n"+
      "that echoes around the room.\n");
    set_sounds(60,({"Strange humming noise echoes in the room...\n"}));

    add_exit("world","/world/misc/start");
    add_exit("namhas","/home/namhas/workroom");
    add_exit("sinister","/home/sinister/workroom");
    add_exit("malekith","/home/malekith/workroom");
    add_exit("dazzt","/home/dazzt/workroom");
    add_exit("waster","/home/waster/workroom");
    add_exit("deicider","/home/deicider/workroom");
    add_exit("mordoc","/home/mordoc/workroom");
    add_exit("tytalus","/home/tytalus/workroom");
    add_exit("gaurhoth","/home/gaurhoth/workroom");
    add_exit("stairs", ROOM_PATH + "imhall");
}

