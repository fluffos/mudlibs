// 池塘
// edit: by zine Aug 21 2010

inherit __DIR__"skfroom1";
#include <ansi.h>

void create()
{
	set("short", "池塘");
	set("long", @LONG
一片安静得可怕的池塘，你觉得似乎有什么不对的地方。
LONG
	);
	set("exits", ([ 
		"north" : __DIR__"grass",	
	]));
	set("no_task",1);
	setup();
	::create();
}

void init()
{
	object me=this_player();
	if (userp(me)&&!me->query_temp("skf/mingpin"))
	{
		tell_object(me,"这是通向南方唯一的道路，你想了想让你心有余悸的密林，决定涉水过去。\n");
		if (me->query("qi")>100)
		me->add("qi",-100);
		else
		me->unconcious();
		tell_object(me,RED"你刚准备淌水越过池塘，猛然惊觉池塘里满是水蛇，你连忙退回岸边。\n"NOR);
		call_out("goback",3,me);
	}
	::init();
	return;	
}

int goback(object me)
{
	tell_object(me,WHT"水蛇布满了池塘，已经有不少向岸边游来，你不禁头皮一阵发麻。\n"NOR);
	tell_object(me,"看来此路不通，你招呼众人赶紧退回原路。\n");
	if (!me->query_temp("skf/pool"))
	{
		tell_object(me,"你心中暗想，也许应该做(make)一个竹筏渡过这个池塘。\n");
		me->set_temp("skf/pool",1);
	}
}