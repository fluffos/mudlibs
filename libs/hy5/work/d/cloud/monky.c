
// monky.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        
	set("coor",({2050,3780,0}));
	set("short", "斋院");
	set("long",
"你现在正站在斋院里靠近门口的地方有一块乌木雕成的招牌(sign)。\n"
);
        set("exits", ([
                "north"          : __DIR__"wroad2" ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );
        set("objects", ([
		__DIR__"npc/monk" : 1,

	]) );

        setup();

}

string look_sign(object me)
{
        return "招牌写著：善。\n";
}

