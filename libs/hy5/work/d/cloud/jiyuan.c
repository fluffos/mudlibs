
// jiyuan.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        
	set("coor",({2150,3820,0}));
	set("short", "怡红院");
        set("long",
"你现在正站在怡红院里靠近门口的地方有一块乌木雕成的招牌(sign)。\n"
);
        set("exits", ([
                "south"  : __DIR__"eroad1", 
                "up"  : __DIR__"jiyuan2",
        ]) );

        set("objects", ([
                __DIR__"npc/mother" : 1,
        ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        setup();

}

string look_sign(object me)
{
        return "招牌写著：怡红院\n";
}

