// Room: /jyguan/dongmen.c 嘉峪关东门
// Ver 0.1 08/14/1998 by Freeze

#include <ansi.h>
inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", HIY "嘉 峪 关"NOR);
	set("long", @LONG
这是东城门，城门正上方刻着“东门”两个楷书大字，一侧城墙上贴着几张
官府告示(gaoshi)。官兵们警惕地注视着过往行人，你最好小心为妙。一条笔直
的青砖大道向东西两边延伸。东边是官道，可见商队和役夫们来来往往。西边就
进嘉峪关了。
LONG
	);
        set("outdoors", "jyguan");

	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"east" : __DIR__"road5",
//		"north" : __DIR__"beimen",
		"west" : __DIR__"guangchang",
	]));

	set("objects", ([
		__DIR__"npc/wujiang" : 2,
		__DIR__"npc/bing" : 5,
	]));

	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n嘉峪关总兵\n    狄志祥\n";
}

