// Room: /jyguan/beimen.c 嘉峪关北门
// Ver 0.1 08/14/1998 by Freeze

#include <ansi.h>
inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", HIY "嘉 峪 关"NOR);
	set("long", @LONG
这是北城门，城门正上方刻着“北门”两个楷书大字，一侧城墙上贴着几张
官府告示(gaoshi)。官兵们警惕地注视着北方，这里行人稀少。往北是一条笔直
的青砖大通向关内。关外沙海茫茫，这里是抵御外敌入侵的最前沿。
    东边可见长城蜿蜒过山...
LONG
	);
        set("outdoors", "jyguan");

	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		 "east" : __DIR__"shamo",
		"north" : __DIR__"shamo",
		 "west" : __DIR__"shamo",
                "south" : __DIR__"guangchang",
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

