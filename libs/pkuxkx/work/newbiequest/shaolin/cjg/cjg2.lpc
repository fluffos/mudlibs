// cjgqian.c 藏经阁一楼
// seagate@pkuxkx by 2011.02.17
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "藏经阁二楼");
	set("long", @LONG
不愧为中原佛法的总源，少林寺此处藏经之富，天下罕有其
匹。这里都是密密麻麻，高及顶棚的书架，书架间仅有容身一人
通行的空隙。几排大书架中间，间隔地放着数丈长的书桌。目光
及处，你看到桌上放了几本佛经。
LONG
	);

	set("exits", ([
		"west" : __DIR__"cjg2dmgbook",
		"south" : __DIR__"cjg2othbook",
		"northeast" : __DIR__"cjg2fojing",
		"north" : __DIR__"cjg2equip",
		"southwest" : __DIR__"cjg2yao",
		"southeast" : __DIR__"cjg2mishi",
		"northwest" : __DIR__"cjg2gjyao",
		"down" : __DIR__"cjg1",
		"up" : __DIR__"cjg3",
	]));

	setup();
}

int valid_leave(object me, string dir)
{
  object ling;
  if (dir=="up" &&
		   me->query("cjg/point")>=150000 &&
		   !me->is_busy() )
	{
		me->add("cjg/point", -1000);
		me->set_temp("cjg/level", 3);
		message_vision("$N花费1000点积分走上了藏经阁三楼。\n", me);
	}
	else if ( dir=="up" &&
		   me->query("cjg/point")<150000 )
		message_vision("藏经阁三楼需要15万积分以上才能兑换，兑换前将会支付1000积分的门槛费。\n15万积分以下可以参观。\n", me);

	if ( dir=="southeast" &&
	     objectp(ling=present("library card", me)) &&
	     ling->query("name")==HIB"阅览证"NOR )
	{
	  message_vision(HIG"二楼典籍阅览室收集着历代长老从各地收集的武林秘籍，\n每个阅览证只能让你在该阅览室呆四个小时。\n"NOR,me);
	  destruct(ling);
	  me->set_temp("cjg/read_time", time() );
	  me->set_temp("cjg/can_read", 1 );
	}
	else if ( dir=="southeast" &&
	     !objectp(ling=present("library card", me)) )
	{	  
	  return notify_fail(HIG"二楼典籍阅览室收集着历代长老从各地收集的武林秘籍，\n没有阅览证不能让你进入该阅览室。\n"NOR);;
	}

	return ::valid_leave(me, dir);
}