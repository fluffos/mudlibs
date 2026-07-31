
// jiyuan2.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        
	set("coor",({2150,4220,5}));
	set("short", "怡红院二楼");
	set("long",
"这是怡红院的姑娘们陪客人们饮酒品茗，吟诗作赋的地方，甚是幽雅。\n"
);
        set("exits", ([
                "down"  : __DIR__"jiyuan" ]) );

	set("objects", ([
                __DIR__"npc/girl" : 1,
	]) );

        setup();

}


