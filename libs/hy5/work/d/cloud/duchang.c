
// duchang.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        
	set("coor",({2150,3780,0}));
	set("short", "赌场");
	set("long",
"你现在正站在赌场里靠近门口的地方有一块乌木雕成的招牌(sign)。\n"
);
        set("exits", ([
                "north"          : __DIR__"eroad1", 
	 ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

	set("objects", ([
		__DIR__"npc/judge" : 1,
        ]) );
 
        setup();

}

string look_sign(object me)
{
        return "赌：胜者赢双。\n";
}

