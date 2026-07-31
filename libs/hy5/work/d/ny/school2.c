
// Room: /d/snow/school2.c

#include <room.h>

inherit ROOM;

void create()
{
        set("coor",({-10,-50,0}));
	set("short", "淳风武馆教练场");
        set("long",
"你现在正站在一个宽敞的教练场中，地上铺著黄色的细砂，许多人正在这里努力地操练著，\n"
"北边是一间高大的兵器厅，往东则是武馆师父们休息的大厅。\n"
);
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"weapon_storage",
  "east" : __DIR__"school1",
   "west" : __DIR__"schoolhall",
]));
        set("outdoors", "ny");
        set("clean_up",1);

        setup();
        replace_program(ROOM);
}
