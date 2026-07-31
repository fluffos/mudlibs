
// zaihuoy.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        
	set("coor",({2050,3850,0}));
	set("short", "杂货铺");
	set("long",
"你现在正站在杂货铺里靠近门口的地方有一块乌木雕成的招牌(sign)。\n"
);
        set("exits", ([
		"north"		: __DIR__"nwroad3",
                "east"          : __DIR__"nroad2" ]) );

	set("objects", ([
                __DIR__"npc/seller" : 1,
 ]) );

        set("item_desc", ([
                "sign": (: look_sign :)
        ]) );

        setup();

}

string look_sign(object me)
{
        return "招牌写著：商。\n";
}

