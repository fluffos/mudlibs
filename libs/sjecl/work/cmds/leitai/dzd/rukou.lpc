// Room: /d/dzd/rukou.c

#include <ansi.h>
inherit __DIR__"dzd_room";

void create()
{
	set("short","石洞入口");
	set("long",@LONG
从瀑布中跃过，到达一个黑黝黝的山洞入口,脚下的石头由于常年被水冲刷，弄得湿漉漉，
滑溜溜。往里面看，似乎这个山洞很大，一条地下河流势湍急,水声震耳欲聋。
LONG
	);
	set("exits",([
		"northwest" : __DIR__"shidong1",
		"northeast" : __DIR__"shidong3",
		"north" : __DIR__"shidong2",
	]));
	setup();
}

void init()
{
	::init();
	add_action("do_tiao","tiao");
	if(!this_player()->query_temp("dzd_quest/shidong") && interactive(this_player())) {
		
		message_vision(HIY"$N突然由光明到黑暗，眼睛骤然适应不了！\n"NOR,this_player());
		this_player()->start_busy(3);
		this_player()->set_temp("dzd_quest/shidong","in");
	}
}

int do_tiao(string arg)
{
	object me = this_player();
	if(me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");
	if(!arg || arg == "" || arg!="out")
		return notify_fail("你想往哪儿跳？\n");

	message_vision(HIW"$N脚尖点地，纵身往外边跳去!\n"NOR,me);
	me->delete_temp("dzd_quest/shidong");	
	me->move(__DIR__"pubu");
	message_vision(HIW"$N顺势而下，轻轻的落在地上!\n"NOR,me);
	return 1;
}
