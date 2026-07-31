// Room: /d/snow/school2.c

#include <room.h>

inherit ROOM;

void create()
{
        set("coor",({0,4950,10}));
	set("short", "辽东要塞");
        set("long",
"你正站在一个要塞前，空场西边上有一个小棚，里面摆着桌椅板凳，许多人正在吃饭，小棚\n"
"外竖着一个大旗，上写：“关宁铁骑 ”路边树下有些边军和武将休息，往南则是林间小路，往\n"
"北就离开宁远城了。\n"
);
        set("exits", ([ /* sizeof() = 3 */
        "north" : __DIR__"droad0",
        "west" : __DIR__"happyinn0",
       "south" : __DIR__"crossroad",
]));
        set("objects", ([ /* sizeof() == 2 */
         __DIR__"npc/room_waiter" : 2,
]));
        set("outdoors", "ny");
        setup();
        replace_program(ROOM);
}

