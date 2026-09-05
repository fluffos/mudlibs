// cjgqian.c 藏经阁一楼
// seagate@pkuxkx by 2011.02.17
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "藏经阁一楼");
	set("long", @LONG
不愧为中原佛法的总源，少林寺此处藏经之富，天下罕有其
匹。这里都是密密麻麻，高及顶棚的书架，书架间仅有容身一人
通行的空隙。几排大书架中间，间隔地放着数丈长的书桌。目光
及处，你看到桌上放了几本佛经，屋角的地上有一张告示(notice)。
LONG
	);

	set("exits", ([
		"east" : "/d/shaolin/zhulin5",
		"west" : __DIR__"cjg1dmgbook",
		"south" : __DIR__"cjg1othbook",
		"northeast" : __DIR__"cjg1fojing",
		"north" : __DIR__"cjg1equip",
		"southwest" : __DIR__"cjg1yao",
		"southeast" : __DIR__"cjg1mishi",
		"northwest" : __DIR__"cjg1gjyao",
		"up" : __DIR__"cjg2",
	]));
	
	set("item_desc", ([ /* sizeof() == 1 */
  "notice" : YEL"藏经阁中存放着少林几千年来收藏的武功秘籍，神兵宝甲，秘制丹药。\n"+
  	         "欲从中获取先用chakan命令获得物品的id，名称，限制和积分兑换价格，\n" +
  	         "然后用积分执行命令duihuan 物品或者技能id，得到对应的奖励。藏经阁\n" +
  	         "有三层楼，一层楼比一层楼奖励更加良好，但是限制条件也越加严格，藏\n" +
  	         "经阁二楼只要你积分超过5万以上上去才能兑换，兑换前会自动扣除你\n" + 
  	         "500积分，藏经阁三楼只要你积分超过15万以上上去才能兑换，兑换前会\n" +
  	         "自动扣除你1000积分，积分未达标也可以上去，不会扣除积分，但是也不\n" +
  	         "能执行duihuan命令进行物品兑换，只能执行chakan命令查看物价。\n"NOR]));

	setup();
}

int valid_leave(object me, string dir)
{
  object ling;
  
  if (dir=="up" &&
		   me->query("cjg/point")>=50000 &&
		   !me->is_busy() )
	{
		me->add("cjg/point", -500);
		me->set_temp("cjg/level", 2);
		message_vision("$N花费500点积分走上了藏经阁二楼。\n", me);
	}
	else if ( dir=="up" &&
		   me->query("cjg/point")<50000 )
		message_vision("藏经阁二楼需要5万积分以上才能兑换，兑换前将会支付500积分的门槛费。\n5万积分以下可以参观。\n", me);
	
	if ( dir=="southeast" &&
	     objectp(ling=present("library card", me)) &&
	     ling->query("name")==HIG"阅览证"NOR )
	{
	  message_vision(HIG"一楼典籍阅览室收集着历代长老从各地收集的经史子集，宗教经典等书籍，\n每个阅览证只能让你在该阅览室呆四个小时。\n"NOR,me);
	  destruct(ling);
	  me->set_temp("cjg/read_time", time() );
	  me->set_temp("cjg/can_read", 1 );
	}
	else if ( dir=="southeast" &&
	     !objectp(ling=present("library card", me)) )
	{
	  
	  return notify_fail(HIG"一楼典籍阅览室收集着历代长老从各地收集的经史子集，宗教经典等书籍，\n没有阅览证不能让你进入该阅览室。\n"NOR);;
	}
	
	return ::valid_leave(me, dir);
}