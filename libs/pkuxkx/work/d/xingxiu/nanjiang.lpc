// /d/xingxiu/nanjiang.c
// Jay 3/17/96
// modified by iszt@pkuxkx, 2007-01-18
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"小沙漠"NOR);
	set("long", @LONG
这里是一片不大的沙漠，可是风沙一起，不辨东西。一走进来，你立刻迷失
了方向。你感到口内十分焦渴，还是快些离开吧。
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"shanjiao",
		"southeast" : __FILE__,
		"northwest" : __DIR__"nanjiang1",
		"southwest" : __FILE__,
		"north" : __FILE__,
		"west" : __FILE__,
		"south" : __FILE__,
		"east" : __FILE__,
	]));
	setup();
//	replace_program(ROOM);
}

int moveback(object me)
{
		me->unconcious();
		me->move(__DIR__"shanjiao");
		return 1;
}

int valid_leave(object me, string dir)
{
	int current_water = me->query("water");

	if(!userp(me))
		return ::valid_leave(me, dir);

	if (current_water==0)
	{
		write("你已经感到不行了，冥冥中你觉得有人把你抬到天山脚下。\n");
		call_out("moveback",1,me);
		me->start_busy(1);
		return ::valid_leave(me, dir);		
	}

	if (current_water>0 && current_water<=20)
	{
		write("你过于缺水，眼冒金星。\n");
		me->set("water",0);
	}

	if (current_water>20)
		me->set("water",current_water-20);
	if (dir=="east" || dir=="south" || dir=="west" || dir=="north") 
		return notify_fail("你向那边走去，结果发现那是沙漠中的海市蜃楼。\n");
	return ::valid_leave(me, dir);
}