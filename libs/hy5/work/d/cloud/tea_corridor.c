
// tea_corridor.c

#include <room.h>

inherit ROOM;

string look_sign();

void create()
{
	set("short", "香茗坊茶窖");
	set("long",
"茶窖里有几个大竹箩，里面装满了茶叶。\n"
);

        set("exits", ([
                "south"          : __DIR__"tearoom",
	]) );

//	set("objects", ([
//	]) );


        setup();

}


