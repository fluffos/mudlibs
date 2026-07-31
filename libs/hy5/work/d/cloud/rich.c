
// rich.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("coor",({2250,3860,0}));
	set("short", "张百万家前厅");
	set("long",
"你现在正站在张百万家里靠近门口的地方有一块乌木雕成的招牌(sign)。\n"
);
        set("exits", ([
                "south"          : __DIR__"eroad3", 

                 "north" :__DIR__"rich1",
                ]));
        set("outdoors","cloud");
        set("objects", ([
                 __DIR__"npc/room_waiter":2,
                 __DIR__"npc/whitelady":3,
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
int valid_leave(object me, string dir)
{
	if ( objectp(present("white lady", environment(me))) && 
		dir == "north")
		return notify_fail("白衣剑姬拦住了你的去路。说道: 少主人吩咐了 外人不得入内。\n");
	return ::valid_leave(me, dir);
}


