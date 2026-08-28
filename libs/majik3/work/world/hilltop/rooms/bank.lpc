inherit ROOM;

#include "../path.h"

create_room ()
{
    set_light (1);
    set_short ("Hilltop village bank");
    set_long ("You are standing in the hilltop village's bank. There is a " +
      "small sign hanging from the ceiling describing something important.\n");
    add_item (({"small sign", "sign"}), 
      "Available commands are:\n"+
      "  deposit <amount>\n"+
      "  withdraw <amount>\n"+
      "  loan <amount>\n"+
      "  transfer <amount> to <player>\n"+
      "  balance\n");

    add_exit ("southeast", ROOM_PATH + "room2");
    add_object (MONSTER_PATH + "officer");
}
