
// woodboxy.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("coor",({1950,3900,0}));
	set("short", "棺材铺");
	set("long",
"你现在正站在棺材铺里靠近门口的地方有一块乌木雕成的招牌(sign)。\n"
);
        set("exits", ([
                "east"          : __DIR__"nwroad2",
                "west"          : __DIR__"god1"
                      ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );
        set("objects", ([
                __DIR__"npc/box_boss" : 1,
        __DIR__"npc/box_waiter" : 1,
 ]) );
        setup();

}

string look_sign(object me)
{
        return "招牌写著：棺。\n";
}

