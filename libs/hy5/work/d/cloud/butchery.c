
// butchery.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        
	set("coor",({1950,3950,0}));
	set("short", "镇北肉铺");
	set("long",
"你现在正站在镇北肉铺里，肉架上挂满了血淋淋的生肉，一股腥气扑面而来，不时有几只苍\n"
"蝇在屋里飞来飞去。靠近门口的地方有一块牛骨雕成的招牌(sign)，上面写着些什么。\n"
);

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        set("exits", ([
                "east"          : __DIR__"nwroad1" ]) );

        set("objects", ([
                __DIR__"npc/butcher" : 1,
		__DIR__"npc/fly.c" : 2,
 ]) );

        setup();

}

string look_sign(object me)
{
        return (@LONG
本店即将收购死狗。
LONG);
}

