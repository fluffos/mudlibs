
// park.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        
	
	set("coor",({2200,3820,0}));
	set("short", "张家花园");
	set("long",
"你现在正站在张家花园里\n"
);
        set("exits", ([
                "south"          : __DIR__"eroad2" 
        ]) );
        set("objects", ([
                      __DIR__"npc/flower_worker":2,
                   ])); 
        setup();

}

