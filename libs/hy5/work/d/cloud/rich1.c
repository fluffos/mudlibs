
// rich.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        
	set("coor",({2250,3870,0}));
	set("short", "张百万家正厅");
	set("long",
"你现在正站在张百万家正厅里靠近门口的地方有一块乌木雕成的招牌(sign)。\n"
);
        set("exits", ([/* sizeof()== 2 */
              "south" : __DIR__"rich", 
                 "north" :__DIR__"rich2",
                ]) );

        set("objects", ([
                 __DIR__"npc/dashou":2,
                __DIR__"npc/dashou_head":1,  
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

