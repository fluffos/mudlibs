// D:\xkx\d\liuxiu-shanzhuang\jizhen-xiaodao2.c集镇小道2
// labaz  2012/10/21.
#include <room.h>
#include <ansi.h>
inherit ROOM;
#include "newbie_village.h"

void create()
{
    set("short", "集镇小道");
    set("long", @LONG
你到了一行不宽的道路，柳树越来越密。你细细嗅去，北边似乎
飘来一阵桂花香气。你想大概就是那大户人家花园传来的了。西
边叮叮当当的打铁声在宣告这个集镇并不是一味的慵懒，依然在
为这个世外桃源输送兵铁。东边杂货铺的货物林林总总，五脏俱
全，都堆到这边的路上了。
LONG);

    set("outdoors","liuxiu-shanzhuang");

    set("exits", ([
        "west" : __DIR__"tiejiangpu",
        "east" : __DIR__"zahuopu",
        "south" : __DIR__"jizhen-xiaodao1",
		"north" : __DIR__"shanzhuang-damen",
        ])
     );

    setup();
}

void init()
{
	add_action("show_quest","quest");
}

