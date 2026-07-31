// Room: /u/jpei/thd/dongkou.c
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "洞口");
	set("long", @LONG
在桃花丛里居然安排了这么一个岩洞，可见岛主用心之巧。岩洞周围全是
桃花，而向洞里看，黑乎乎地什么也看不见。往下就是桃花岛主布下的两
仪四象五行奇阵，凡是不得其法而入者大多无法生还。
LONG
	);
	set("exits", ([ 
		"out" : __DIR__"road5",
		"enter" : __DIR__"cave",
		"down" : __DIR__"liangyi",
	]) );
	set("no_clean_up", 0);
	set("outdoors","taohua");

	setup();
}

void init()
{
	object me = this_player(), oyf;
	
	add_action("do_quit", "quit");
	
if (!me->query_temp("jyoyf"))
{
	if (objectp(present("jiuyin zhenjing", me))
	 || objectp(present("jiuyin shangjuan", me))
	 || objectp(present("jiuyin xiajuan", me))) {
	 	me->start_busy(2);
	 	oyf = present("ouyang feng", environment(me));
	 	if (oyf) destruct(oyf);
		oyf = new("/kungfu/class/btshan/ouyangfeng");
		oyf->move(environment(me));
		message_vision(HIR"\n忽然一阵狂笑从远处传来，只转眼间，一个人影就出现在洞口。\n"NOR, me);
		message_vision(HIR"$N仔细看去，原来竟是大名鼎鼎的西毒欧阳峰。\n"NOR, me);
		message_vision(HIR"只听得他大笑道：“皇天不负苦心人，没想到最后得到九阴真经的还是我西毒欧阳峰！\n\n"NOR, me);
	 	me->set_temp("jyoyf",1);
		oyf->kill_ob(me);
	}
}
}

int valid_leave(object me, string dir)
{
	if (objectp(present("ouyang feng", environment(me)))
	 && (objectp(present("jiuyin zhenjing", me))
	 || objectp(present("jiuyin shangjuan", me))
	 || objectp(present("jiuyin xiajuan", me))))
		return notify_fail("欧阳峰大喝一声：“哪里逃！”，身形一晃，拦在你的面前。\n");
	return ::valid_leave(me, dir);
}

int do_quit()
{
	write("这里不准退出！\n");
	return 1;
}
