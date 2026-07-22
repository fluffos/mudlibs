
inherit ROOM;
#include <ansi.h>
int do_jump(string arg);

void create()
{
	set("short", "雪谷");
	set("long", @LONG
这里是群山环绕中的一个山谷，人迹罕至。仰面向上看，四面山峰高耸入云，
覆盖着冰雪。周围茫茫雪原，甚至连野兽的足迹都看不到。
LONG
	);
	set("exits", ([
		"eastdown" : __DIR__"shanlu2",
	]));
	set("objects", ([
		__DIR__"npc/laozu" : 1,
	]));
	set("outdoors", "雪山");
	setup();
}

void init()
{
	object me = this_player();
	if ( me->query("xs_job") > 0) {
		me->add("job_time/雪山", me->query("xs_job"));
		me->delete("xs_job");
	}
	add_action("do_jump", ({"jump", "tiao"}));
}
int do_jump(string arg)
{
	object room,me = this_player();
    if( arg == "down")
    {
		if(me->query_skill("dodge")<150) 
		{
			message_vision(HIC"\n$N吸了一口气，尝试跳下雪谷，却突然发现风大山高，却退了回来。\n"NOR,me);
			return 1;
		}
		if (!(room = find_object(__DIR__"xuegu2")))
			room = load_object(__DIR__"xuegu2");
		if(!room)
		{ 
			tell_object(me,HIR"\n你无论怎么跳，发现都还在原地!\n");
			log_file("quest/LCHJ", sprintf("%s(%s)缺少xuegu2.c文件。\n", me->name(1),me->query("id")) );	
		}
		else
		{
			message_vision(HIC"\n$N吸了一口气，涌身跃落，没入深雪，随即窜上，跃向谷边的岩石。\n"NOR, me);
			me->move(room);
			me->start_busy(1);
                        tell_room(environment(me),HIC"\n只见一个身影飞身而下，原来是"+me->name()+"从雪谷上跳下。\n"NOR, ({me}));                       
		}
		return 1;
	}
	return 0;
}
