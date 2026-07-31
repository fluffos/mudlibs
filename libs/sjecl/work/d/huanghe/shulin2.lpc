// BY XIAOYAO

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
		"east"  : __DIR__"shulin1",
		"north" : __DIR__"shulin4",
		"southwest" : "/d/zhiye/caikuang-chang0",
	]));
	set("objects", ([
                __DIR__"npc/wolf" : 1,
	]));
	set("outdoors", "黄河");
	
	setup();
}

int valid_leave(object me,string dir)
{
	if( me->query("no_quest") && dir == "southwest" ){
		return notify_fail("\n");
	}
	return ::valid_leave(me, dir);
}
