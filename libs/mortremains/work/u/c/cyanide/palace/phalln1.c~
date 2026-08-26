#include "main.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid( 0 );
    set ("author", "cyanide");
    set ("arena" ,1);
    set ("light", 0);
    set ("area_type", ([
      "black" : 2,
    ]) );
    set ("short", "Palace Hallway");
    set( "long", @EndText
This room needs a long desc.
EndText
    );
    set( "exits", ([
      "northeast" : MAIN+"/phalln2.c",
      "east" : MAIN+"/ballroom.c",
      "south" : MAIN+"/room8'5.c",
    ]) );

    set ("item_desc", ([
    ]) );
}
void init () {
    add_action ("exits","exits");
}
int exits() {
    write ("You begin to get a nasty headache.\n");
    say (NAME+" begins to look very confused.\n");
    return 1;
}
