#include "godzone.h"

create_room()
{
    set_area("godzone");
    set_light(1);
    set_short("Neutral's lounge");
    set_long(
      "This hall looks comfortable, with victorian decorations on the ceiling "+
      "that looms high above you. The furniture on this room is from victorian "+
      "origin, with a slight glimpse of baroque style in it. There are chairs "+
      "around several tables and few bookshelves next to them. Fire burns cozily "+
      "in the fireplace.\n");
    add_item(({"ceiling"}),"You see the ceiling somewhere high above you, with victorian\n"+
      "decorations. This room looks really big.\n");
    add_item(({"furniture"}),"The furniture of this room consists of chairs around baroque-styled\n"+
      "tables, and few bookshelves here and there.\n");
    add_item(({"chair","chairs"}),"Chairs here look really comfortable, and they are aligned\n"+
      "around the tables so that people can see each other when they talk.\n");
    add_item(({"tables"}),"The tables that are positioned around the room are baroque-styled,\n"+
      "made from sturdy wood.\n");
    add_item(({"bookshelf","bookshelves"}),"Bookshelves are full of huge volumes, some of them dusty and\n"+
      "partly ripped, but most of them in good shape.\n");
    add_item(({"volume","volumes"}),"These volumes seem to contain the whole history of Majik from\n"+
      "the beginning of time when Namhas created the world to current events.\n");
    add_item(({"fireplace","fire"}),"The fire burns cozily in the fireplace, but as you look closer\n"+
      "you notice that there are no wood in the fireplace. Fire must be of magical origin.\n");
    set_sounds(90,({"Fire crackles cozily in the fireplace.\n"}));

    add_exit("hall", ROOM_PATH + "imhall");
    add_exit("hell", ROOM_PATH + "elounge");
    add_exit("heaven", ROOM_PATH + "glounge");
}
