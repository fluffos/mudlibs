// Room: zhaoze1.c

inherit ROOM;

void create()
{
	set("short", "沼泽");
	set("long", @LONG
脚下是零零散散的杂草和一些小水坑，水坑里的水平静而污浊。四周
死一般的寂静，连虫蚁的声音都没有，这寂静隐含着无尽的杀机。落脚之
处全是烂泥，丝毫也不受力，陷在里面无论你有通天彻底的武功也是无济
于事，越挣扎就陷得越快。
LONG
	);

	set("exits", ([
		"north" : __DIR__"zhaoze"+(random(3)+1),
		"south" : __DIR__"caohai3",
		"west" : __DIR__"zhaoze2",
		"east" : __DIR__"caohai"+(random(6)+1),   
	]));
	set("outdoor","大草原");
	setup();

}

void init()
{
	object me;
	me = this_player();
	if (userp(me) && me->query_skill("dodge") < 100) {
		message_vision("$N觉得脚下一软，双脚已经陷在泥里，$N挣扎着想把脚拔出来，结果陷得更深了。\n",me);
		message_vision("$N只觉得一股寒气从脚下冒了上来，这下完了。\n",me);
		me->set_temp("last_damage_from", "陷入沼泽窒息");
		me->die();
	}
}
