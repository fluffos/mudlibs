//观日峰

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIR "观日峰" NOR);
	set("long", 
"这里就是"HIG"嵩山观日峰"NOR"，往这里一站,你不禁有一种:\n\n"
"          渺万里层云,千山暮雪,只影向谁去?\n\n"
"的感觉,这里有几块石头,大概是练气士平时修炼打坐的地方!\n\n"
);
	set("outdoors", "嵩山");

	set("exits",([
		"west":__DIR__"fengchantai",
	]));
	setup();
}

void init()
{
	add_action("do_guan", "guan");
}

int do_guan(string arg)
{
	object me=this_player();
	if (me->is_busy())
		return notify_fail("你现在正忙着呢！\n");
	if( !arg || arg=="" ) return 0;
	if( arg=="sun" ){
		message_vision("$N往石头上一站,看着刚刚升起的太阳,渐渐进入冥思。\n", me);
		return 1;
	}
}
