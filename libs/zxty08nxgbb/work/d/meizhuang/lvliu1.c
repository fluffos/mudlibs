// edit by daniel@jhfy.nh 2002
#include <room.h>

inherit ROOM;
void create()
{
    set("short", "绿柳林");
    set("long", @LONG
穿过青石小道，眼前是一片绿柳林，柳支垂拂细水。随着
清风缓缓摆动，人间一美景也。
LONG
    );
   set("no_fight", "1");
   set("outdoors", "meizhuang" );
   set("objects", ([
   ]));
   set("exits", ([
   "north" : __DIR__"xihu",
   "south" : __DIR__"road1",
        ]));
   setup();

}



