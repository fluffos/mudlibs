//didao3.c	梅庄地道
//by bing

#include <room.h>
inherit ROOM;

void create()
{
	set("short","地道");
	set("long",@LONG 
墙壁上点着一盏油灯，发出淡黄色光芒，置身之所似是个地道。
这里有一扇铁门(gate)，铁门上有个尺许见方的洞孔。里面灯光很
暗，黑乎乎的看不清楚，仿佛是个牢房。
LONG
	);

	set("exits", ([
		"south" : __DIR__"didao2",
	]));
 	set("item_desc",([
		"gate"	: "这是一扇沉重的大铁门，上面有四个锁眼，看来需要四把钥匙才能够打开(unlock)它。\n",
 	   ]));
    set("no_task",1);
	setup();
}

void init()
{
	add_action("do_unlock","unlock");
}

int do_unlock()
{
	object me = this_player();
	
	if (present("key 1",me) && !me->query_temp("riyue/unlock1"))
	{
		message_vision("$N拿出一把钥匙，在其中的一个锁眼里扭了几下。\n",me);
		me->set_temp("riyue/unlock1",1);
		call_out("check",0,me);
		return 1;
	}

	if (present("key 2",me) && !me->query_temp("riyue/unlock2"))
	{
		message_vision("$N拿出一把钥匙，在其中的一个锁眼里扭了几下。\n",me);
		me->set_temp("riyue/unlock2",1);
		call_out("check",0,me);
		return 1;
	}

	if (present("key 3",me) && !me->query_temp("riyue/unlock3"))
	{
		message_vision("$N拿出一把钥匙，在其中的一个锁眼里扭了几下。\n",me);
		me->set_temp("riyue/unlock3",1);
		call_out("check",0,me);
		return 1;
	}

	if (present("key 4",me) && !me->query_temp("riyue/unlock4"))
	{
		message_vision("$N拿出一把钥匙，在其中的一个锁眼里扭了几下。\n",me);
		me->set_temp("riyue/unlock4",1);
		call_out("check",0,me);
		return 1;
	}
	return notify_fail("你没有相应的钥匙来看这扇门。\n");
}

void check(object me)
{

	if ( me->query_temp("riyue/unlock1")
		&& me->query_temp("riyue/unlock2")
		&& me->query_temp("riyue/unlock3")
		&& me->query_temp("riyue/unlock4"))
	{
		message_vision("铁门「吱呀」一声开了，声音窒滞，显然好久没有打开过了。里面的人听到声响，抬起头来看了你一眼。\n",me);
		set("exits/enter",__DIR__"prison");
		me->delete_temp("riyue/unlock1");
		me->delete_temp("riyue/unlock2");
		me->delete_temp("riyue/unlock3");
		me->delete_temp("riyue/unlock4");	}
}
