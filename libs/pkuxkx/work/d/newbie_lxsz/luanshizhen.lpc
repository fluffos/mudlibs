// D:\xkx\d\liuxiu-shanzhuang\luanshizhen.c乱石阵
// labaz  2012/10/20.
#include <room.h>
#include <ansi.h>
inherit ROOM;
#include "newbie_village.h"

void create()
{
    set("short", "乱石阵");
    set("long", @LONG
你走过来，眼前顿升一片雾霭。迷雾之中，你隐约瞧见了几块林立的
灰色乱石。你刚想转身离开，却觉得似乎不对头：这些乱石看似杂乱无章，
细看下发现似乎是按什么规律排成的。有几块石头上有些文字(word)。
LONG);

    set("outdoors","liuxiu-shanzhuang");

     set("item_desc", ([
         "word":"逝者如斯夫！\n",
         ]));

    set("exits", ([
        "west" : __DIR__"weiminggu",
        ])
     );

    setup();
}



void init()
{
	object me;
	me=this_player();
	
	if (me->query(NEWBIE_VILLAGE_INDEX)==get_questindex("用east、west、south等方向命令来探索未明谷周围的三块地方，并回到未明谷"))
	{
		me->set_temp("newbie/luanshizhen",1);
	}
	add_action("show_quest", "quest");
}

