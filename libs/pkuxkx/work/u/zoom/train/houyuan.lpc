//houyuan.c
//by zoom
//2004.3.29

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "后院");
    set("long", @LONG
新手学堂的后院，院子里载着几棵银杏树(tree)，院子中央有口水井(jing)。
树下几个小孩儿在玩耍。
LONG
    );

    set("item_desc", ([
	"tree"   : "银杏树。\n",
	"jing"   : "一口水井。\n",
    ]));

    set("exits", ([
                "south" : __DIR__"road2",
    ]));

    set("objects", ([
		__DIR__"npc/kid" : 1,
		]));
    
    set("outdoors", "train");
    setup();

}
