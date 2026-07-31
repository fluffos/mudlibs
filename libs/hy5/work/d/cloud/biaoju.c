
// biaoju.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{

        set("coor",({2200,3780,0}));
       set("my_point","绮云镇");
        set("short", "镖局");
        set("long",
"你现在正站在镖局里靠近门口的地方有一块乌木雕成的招牌(sign)。\n"
);
        set("exits", ([
                "north"          : __DIR__"eroad2" ]) );

        set("objects", ([
                __DIR__"npc/b_header" : 1,
                __DIR__"npc/bfighter" : 1,

        ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        setup();

}

string look_sign(object me)
{
        return "招牌写著：镖。\n";
}

