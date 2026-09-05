//shuilao.c -- 水牢-假山下
//Zone: 汝阳王府
//Created by ddid
//2009-6-14

#include <ansi.h>
inherit ROOM;

string look_men();
string look_men_east();
string look_men_west();

void create()
{
  set("short", HIC"水牢"NOR);
  set("long", @LONG
这里是个水牢，你正身陷在齐腰深的水中，上身被一条锁链(suolian)
牢牢地绑在一根石柱(shizhu)上，动弹不得。旁边还有几根石柱，其中一
根上还绑着一个已经泡得浮肿的死人，惨不忍睹，你连忙闭眼。

LONG
  );

  set("exits", ([     
  ]));

	set("item_desc", ([
		"shizhu" : "石柱表面并不光滑，似乎可以爬(climb)上去。\n",
		"石柱" : "石柱表面并不光滑，似乎可以爬(climb)上去。\n",
		"suolian" : "一条粗大的锁链正紧紧地绑住你的上半身，不过在水里泡得久了，锁链上全是锈迹，你胸前的几个环扣都已经锈透了，你可以试试，能不能把它崩断(beng)。\n",		
		"锁链" : "一条粗大的锁链(suolian)正紧紧地绑住你的上半身，不过在水里泡得久了，锁链上全是锈迹，你胸前的几个环扣都已经锈透了，你可以试试，能不能把它崩断(beng)。\n",
		"men" : (: look_men() :),
		"men east" : (: look_men_east() :),
		"men west" : (: look_men_west() :),
	]));

  set("resource/water",1);
  set("cost", 4);
  setup();
}

void init()
{
	object me = this_player();
	
	me->set_temp("kunbang", 1);
	
	add_action("do_beng", "beng");
	add_action("do_climb", "climb");
	add_action("do_move", "move");
	add_action("do_move", "push");
}

int do_beng(string arg)
{
	object me = this_player();
	
	if ( me->is_busy() )
		return notify_fail("你现在正忙着呢。\n");
	
	if ( (int)me->query_temp("kunbang") != 1 )
		return notify_fail("你又没被绑着，瞎挣蹦什么？\n");	
	
	if (!arg || (arg != "suolian"))
		return notify_fail("你要干什么？\n");

	if( arg=="suolian" )
	{
		switch(random(3))
			{
    	case 0:
				message_vision("\n你暗运内力，两膀较劲，双手猛地一挣!\n粗大的锁链竟纹丝未动。\n", me);
				me->start_busy(random(3));
  			break;
      case 1:
				message_vision("\n你暗运内力，两膀较劲，双手猛地一挣!\n锁链中间的几个锈蚀的环扣似乎微微松动了。\n", me);
				me->start_busy(random(3));				
				break;
			case 2:
				message_vision("\n你暗运内力，两膀较劲，双手猛地一挣!\n想不到粗大的锁链竟然应手而开。\n你连忙除下身上的锁链，一把把它丢开。\n\n", me);
				me->delete_temp("kunbang");
				me->start_busy(1);
			}
	}			
	return 1;
}

int do_climb(string arg)
{
	object me = this_player();
	
	if ( (int)me->query_temp("kunbang") == 1 )
		return notify_fail("你还被绑着呢，动都动不了。\n");	
	
	if (!arg || (arg != "shizhu"))
		return notify_fail("你要干什么？\n");

	if( arg=="shizhu" )
		message_vision(
				"\$N爬上了一根石柱，四下看了看，发现水牢东、西两面的水下各有一道闸门(men)。\n", me);
			
	return 1;
}

int do_move(string arg)
{
	object me = this_player();
	
	if ( (int)me->query_temp("kunbang") == 1 )
		return notify_fail("你还被绑着呢，动都动不了。\n");	

	if ( (int)me->query("neili") < 1000 || (int)me->query("jiali") < 100 )
		return notify_fail("你的气力不足，无法搬动闸门。\n");
		
	if ( !arg || (arg !="men" && arg != "men east" && arg != "men west") )
		return notify_fail("你要干什么？\n");
	
	if( arg=="men" )
			return notify_fail("你要搬动那扇闸门？\n");

	if( arg=="men west" )
	{
		message_vision(
				"\$N深吸了一口气，潜入水下，搬开了西面的闸门，一股巨大的水流突然向$N冲来，$N再也站立不住，\n栽入水中，随着水流，竟一头撞在墙上，再也爬不起来了。\n", me);
		me->receive_damage("qi", 50, "在水牢中被淹");		
		me->unconcious();		
		me->die();
	}

	if( arg=="men east" )
	{
		message_vision(
				"\$N$N深吸了一口气，潜入水下，搬开了东面的闸门，突然间水牢内的水向外狂泻，\n$N被巨大的水流一冲，不禁脚底一滑，沉入水中……\n", me);
		me->add("qi", -500);
		me->add("neili", -1000);
		me->unconcious();
		
		remove_call_out("move_me");
		call_out("move_me", 2, me);
	}	

	return 1;
}

int move_me(object me)
{
	me->move(__DIR__"liushuiting");
	return 1;
}

int wakeup(object me)
{
	me->revive();
	return 1;
}

string look_men()
{
	object me = this_player();
	
	if ( (int)me->query_temp("kunbang") == 1 )
		return "你还被绑着，不能去观察闸门。\n";
		
	return "你要看哪边的闸门？\n";
}

string look_men_east()
{
	object me = this_player();
		
	if ( (int)me->query_temp("kunbang") == 1 )
		return "你还被绑着，不能去观察闸门。\n";
			
	return "这是水下的一个闸门，似乎可以搬动(move)。\n";
}

string look_men_west()
{
	object me = this_player();
		
	if ( (int)me->query_temp("kunbang") == 1 )
		return "你还被绑着，不能去观察闸门。\n";
			
	return "这是水下的一个闸门，似乎可以搬动(move)，不过总觉得有种不祥的预感。\n";
}
