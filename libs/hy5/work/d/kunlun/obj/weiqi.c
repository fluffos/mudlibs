// weiqi.c 围棋
// cck 4/7/97

#include <armor.h>

inherit ITEM;

void create()
{
	set_name("围棋", ({ "wei qi", "weiqi", "qi", "go" }));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "副");
		set("long",
			"这是一副围棋，棋盘用磁铁所制，棋子用铁铸成。\n");
		set("value", 5000);
		set("material", "steel");
		set("armor_prop/armor", 10 );
		}
}


void init()
{
		add_action("do_play", "play");
}

int do_play(string arg)
{
		object me = this_player();
	if ( me->query("int") < 24 && me->query_int() < 32)
	return notify_fail("琴棋书画乃是极其风雅之事，" +RANK_D->query_respect(me)+"似乎太过于俗气了些。\n");

	if( (int)me->query("shen") < -10000 )
	return notify_fail("你杀人如麻，倘若不能先平息了心头魔念，哪里又会有心思弹琴下棋？\n");

	if(me->query("family/family_name")!="昆仑派" )
	return notify_fail("你一个练武的粗人，学这些酸腐文人的东西干什么？\n");

if (!environment(me))return notify_fail("你要做什么？\n");
if (me->is_busy())return notify_fail("你要做什么？\n");
if (me->is_fighting())return notify_fail("你要做什么？\n");		
		if ( !arg && (arg != "music") && (arg != "zheng") && (arg != "gu zheng")
			  && (arg != "wei qi") && (arg != "qi") && (arg != "go") )
			return notify_fail("你要做什么？\n");

		if ( present("gu zheng", this_player()) &&
			((arg == "music") || (arg == "zheng") || (arg == "gu zheng"))  )
		{
			if ( me->query_skill("art", 1) < 30 )
			{
				message_vision("$N摆出一张古筝，铮铮琮琮弹了几声，只听得曲调杂乱无章，宛如鬼哭狼号。\n", me);
				me->receive_damage("jing", random(20) );
				me->receive_damage("qi", random(20) );
				return 1;
			}
	if ( me->query_skill("art", 1) >1200 )
			{
				message_vision("$N摆出一张古筝，铮铮琮琮弹了几声，只听得曲调平和，洋洋洒洒，颇有佳意。\n", me);
				return 1;
			}
			me->receive_damage("jing", 10);
			me->receive_damage("qi", 10);
			me->improve_skill("art", (int)me->query_skill("art", 1)/20);
			me->receive_damage("jing", 10);
			me->receive_damage("qi", 10);
me->add("combat_exp",random(3)+1);
me->add("potential", 1);
me->start_busy(5);		
		tell_object(me, "你摆出一张古筝，调了调弦，弹了起来，你只觉得连日来烦燥的心情好了许多。\n");

			message_vision("只见" + me->query("name") +
		  "雅兴大发，竟弹起曲子来，你只觉得时而金戈铁马、大漠平沙。。。。。。\n"
		  "时而小桥流水、几户人家。。。。。。万般气象，你心情顿时宁静了许多。\n",
			me );

			return 1;
		}

		if ( present("wei qi", this_player()) && ((arg == "wei qi") || (arg == "qi") || (arg == "go")) )
		{
			if ( (me->query_skill("art", 1) < 40) )
			{
				message_vision("$N摆出一张棋盘，想研究围棋，却总觉得心烦意乱，定不下神来。\n", me);
		        me->receive_damage("jing", random(20) );
				me->receive_damage("qi", random(20) );
				return 1;
			}
	if ( me->query_skill("art", 1) >1200 )
			{
				message_vision("$N摆出一张棋盘，只觉棋面布局尽在筹幄只之中，无密可研。\n", me);
				return 1;
			}

			me->receive_damage("jing", 10);
			me->receive_damage("qi", 10);
me->add("combat_exp",random(3)+1);
me->add("potential", 1);
me->start_busy(5);
			me->improve_skill("art", (int)me->query_skill("art", 1)/20);
			tell_object(me, "你摆出一张棋盘，研究起围棋来，只觉得心平气和，很快就仿佛入定了。\n");

			message_vision("只见" + me->query("name") +
		  "雅兴大发，竟打起棋谱来，对外界仿佛不闻不问，一副莫测高深的模样。\n",
			me );

		}
			return 1;
		}
