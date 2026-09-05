// by aiai for xiakedao
// Modified by iszt@pkuxkx, 2007-04-02

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "轩堂");
	set("long", @LONG
轩堂中一尘不染，窗明几净，四壁堆满了书架，屋角一张琴几，琴旁一方棋
枰。墙上挂着一幅画(picture),还有几张未完成的画，散乱地堆在另一角的画桌
上。门上挂著湘妃帘，透过竹帘，可以看见那一洼盛开的菊花。
LONG);
	set("exits", ([ 
		"west" : __DIR__"dadian",
	]));
	set("item_desc", ([
		 "picture" : HIR"一幅古朴却洁净无比的画，画中一位女子，左手持剑，右手似乎掌心"
			"向下，端的是英气逼人，美奂绝伦！令人观之有天神之感。\n"NOR,
	]));
	setup();
}

void init()
{
	add_action("do_juan","juan");
	add_action("do_bai","bai");
	add_action("do_bai","bow");
}

int do_bai(string arg)
{
	object me = this_player();
	if( !arg || arg=="" )
		return 0;
	if( arg=="picture" )
	{
		write(
		BLU"    你朝着那天人模样的女子拜了下去。正在你站起的一瞬间，\n"
		"你抬起头，突然发现从这个角度，那女子的右手手心是朝着你的，\n"
		"手心中有个字，好象是「拳」，「卷」？太暗了，你也看不清。\n"NOR);
		this_player()->set_temp("marks/卷", 1);
		return 1;
	}
}

int do_juan(string arg)
{
	object me;
	me = this_player();
	if ( me->query_temp("marks/卷" ) )
	{
		message_vision("$N卷起图画，只见你眼前一道白光，一刹那，一切平静，人也不见了。\n", me );
		me->move(__DIR__"mishi");
		message_vision("$N被一条软绳卷了进来。\n", me );
		this_player()->delete_temp("marks/卷");
		return 1;
	}
	else {
		write("你想干什么？!\n");
		return 1;
	}
}
