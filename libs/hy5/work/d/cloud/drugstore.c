
// drugstore.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        
	set("coor",({2100,3920,0}));
	set("short", "药店");
	set("long",
"你现在正站在药店里靠近门口的地方有一块乌木雕成的招牌(sign)。\n"
);
        set("exits", ([
                "south"          : __DIR__"nroad1" ]) );

        set("objects", ([
		__DIR__"npc/doctor" : 1,
	]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        setup();

}

string look_sign(object me)
{
        return "招牌写著：药。\n";
}

