
// bookstore.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        
	set("coor",({2000,3780,0}));
	set("short", "书局");
	set("long",
"你现在正站在书局里靠近门口的地方有一块乌木雕成的招牌(sign)。\n"
);
        set("exits", ([
                "north"          : __DIR__"wroad1" ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );
	set("objects",([ /* sizeof() == 1 */
	__DIR__"npc/book_seller":1,
	]));
        setup();

}

string look_sign(object me)
{
    if(objectp(this_player()))
        this_player()->set_explore("north#4");
        return "招牌写著：书。\n";
}

