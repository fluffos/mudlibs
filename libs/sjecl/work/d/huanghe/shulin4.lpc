//by XiaoYao

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "树林");
	set("long", @LONG
树林里光线暗淡，只能听见头顶上传来一些鸟儿的啼鸣。偶而从茂密的叶
间透过的一线光伴着落叶在飞舞。朽木腐烂的气味和身後传来野兽的啸声使人
不觉犹豫了前进的脚步。
LONG );
	set("exits", ([
		"northwest"  : "/d/group/entry/hhshulin5",
		"east"       : __DIR__"shulin3",
		"south"      : __DIR__"shulin2",
	]));
	set("objects", ([
                __DIR__"npc/fox" : 1,
	]));

	set("outdoors", "黄河");
	setup();
}
