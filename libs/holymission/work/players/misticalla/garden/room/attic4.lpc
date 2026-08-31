
inherit "room/room";
#include "../garden.h" 

reset(arg) {
    if (arg) return;
    set_light(0);
    property = "no_teleport";
    short_desc = "On an attic";
    no_castle_flag = 0;
    long_desc = 
    "You are in the attic of a strange building. "+
    "It's a bit cold and damp here, you can smell "+
    "the odor of rotting wood. A little corridor leads "+
    "further to the south and to the west.\n";
    dest_dir = ({ ROOM+"/attic5","south", 
      ROOM+"/attic3","west"
    });

    items = ({"wood","Stinking dark wood",
      "bottom","A dark wooden bottom",
      "wall","Black wet walls"});
    clone_list = ({ 1, 3, "bat", "players/whisky/garden/monster/bat", 0 });
    ::reset();
    RP;
}

