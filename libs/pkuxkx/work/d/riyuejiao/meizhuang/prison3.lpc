//prison3.c	救了任我行后到的梅庄地牢
//by bing

#include <room.h>
inherit ROOM;

void create()
{
	set("short","地牢");
	set("long",@LONG 
你一踏进这里，一阵霉气扑鼻而至。这囚室不过丈许见方，出口的大铁门(gate)已经关闭。
靠墙放有一榻(bed)。屋里甚阴暗潮湿，墙壁上一灯如豆，令人更觉郁闷。
LONG
	);

 	set("item_desc",([
		"bed"	: "这是张铁板床，床上铺着一张席子(xi zi)。\n",
		"xi zi" : "这是一张破席子，胡乱铺在床上。天热时你可以移开(move)它，直接睡在铁板上。\n",
 	   ]));
       set("sleep_room",1);
	set("objects",([
		__DIR__"obj/ironbed" : 1,
		]));
        set("no_task", 1);



	setup();
}

void init()
{
	add_action("do_look","l");
	add_action("do_look","look");
	add_action("do_open","open");
}

int do_look(string arg)
{
	object me = this_player();
	if (arg == "gate")
	{
		if (random(10) == 1)
		{
			tell_object(me,"你仔细看了一下铁门，发现上面的锁早已不知被谁锯开，很容易打开。\n");
			me->set_temp("riyue/看门",1);
			return 1;
		}
		tell_object(me,"大铁门锁得紧紧的，你出不去。\n");
		return 1;
	}
	return 0;
}

int do_open(string arg)
{
	object me = this_player();
	if (arg == "gate")
	{
		if (me->query_temp("riyue/看门"))
		{
			message_vision("$N使劲打开了大铁门。\n",me);
			set("exits/out",__DIR__"outdidao3");
			return 1;
		}
		tell_object(me,"门上着锁，你开不开。\n");
		return 1;
	}
	return 0;
}
