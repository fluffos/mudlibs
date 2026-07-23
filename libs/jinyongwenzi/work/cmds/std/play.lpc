// play.c 
// cck 6/7/97

#include <ansi.h>;

inherit F_CLEAN_UP;

int main(object me, string arg)
{

	if ( !arg || (arg != "music") && (arg != "zheng") && (arg != "gu
	     zheng") && (arg != "wei qi") && (arg != "qi") && (arg != "go") )
	return notify_fail("你要做什么？\n");

	if ( present("gu zheng", this_player()) &&
	     ((arg == "music") || (arg == "zheng") || (arg == "gu zheng"))  )
	{
		if ( random(me->query_skill("art", 1)) < 50 )
		{
		message_vision("$N摆出一张古筝，铮铮琮琮弹了几声只听得曲调杂"
		"乱无章，宛如鬼哭狼号。\n", me);
		me->receive_damage("jing", random(30) );
		me->receive_damage("qi", random(30) );
		return 1;
		}

		me->receive_damage("jing", 20);
		me->receive_damage("qi", 20);
		if (me->query_skill("art",1) < 200)
		me->improve_skill("art", (int)me->query_int()/4 + (int)me
		    ->query_skill("art", 1)/10);
		tell_object(me, "你摆出一张古筝，调了调弦，弹了起来，你只"
			"觉得连日来烦燥的心情好了许多。\n");
		
		message("vision", "只见" + me->query("name") +
	"雅兴大发，竟弹起曲子来，你只觉得时而金戈铁马、大漠平沙。。。。。。\n"
	"时而小桥流水、几户人家。。。。。。万般气象，你心情顿时宁静了许多。\n",
		environment(me), ({me}) );
		return 1;
	}

	if ( present("wei qi", this_player()) && ((arg == "wei qi") 
	     || (arg == "qi") || (arg == "go")) )
	{
		if ( random(me->query_skill("art", 1)) < 50 )
		{
		message_vision("$N摆出一张棋盘，想研究围棋，却总"
		"觉得心烦意乱，定不下神来。\n", me);
		me->receive_damage("jing", random(30) );
		me->receive_damage("qi", random(30) );
		return 1;
		}

		me->receive_damage("jing", 20);
		me->receive_damage("qi", 20);
		if (me->query_skill("art",1) < 200)
		me->improve_skill("art", (int)me->query_int()/4 + (int)me
		    ->query_skill("art", 1)/10);

		tell_object(me, "你摆出一张棋盘，研究起围棋来，只觉得心平"
			    "气和，很快就仿佛入定了。\n");

		message("vision", "只见" + me->query("name") +
	"雅兴大发，竟打起棋谱来，对外界仿佛不闻不问，一副莫测高深的模样。\n",
		environment(me), ({me}) );
	}
		
	return notify_fail("你要做什么？\n");
}
