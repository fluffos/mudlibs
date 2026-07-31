
// rich2.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        
	set("coor",({2250,3880,0}));
	set("short", "张百万家后院");
	set("long",
"你现在正站在张百万家里靠近门口的地方有一块乌木雕成的招牌(sign)。\n"
);
        set("exits", ([
                 "south" :__DIR__"rich1",
                ]) );

        set("objects", ([
                      __DIR__"npc/chenyaojia":1, 
                      __DIR__"npc/zhang":1, 
                       __DIR__"npc/room_guard":2,
                 ]) );
        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        setup();

}

string look_sign(object me)
{
        return "招牌写著：非请莫入。\n";
}

