// Room: /d/5lt/yuchang.c
#include <ansi.h>
inherit ROOM;
#define MAX_EXP 80000
#define MIN_EXP 10
int do_jump(string arg);
int do_go(string);
void create()
{
	set("short", "海滨浴场");
	set("long", @LONG
这是一个非常干净的海滨浴场，每到夏季这里就变成全村最热闹的地
方，在这儿可以深海潜水、出海钓鱼、冲浪和游泳。海边的码头(pier)
还可以看到一艘豪华游艇。里人员繁杂，有小贩在叫卖，有工人在搬运
(ganhuo)粮袋，有官员手持长鞭在监工。
LONG);
	set("outdoors", "5lt");set("no_fight",1);set("chatroom",1);set("pingan",1);
	set("outdoors", "5lt");set("no_fight",1);set("chatroom",1);set("pingan",1);set("sleep_room", 1);
	set("exits", ([
		"east"  : __DIR__"haitan",
	]));
	set("objects",  ([
		__DIR__"npc/sunray": 1,
			"/d/city/npc/jiangong": 1,
	]));
	set("no_fight", "1");
	set("coor/x", -205);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
}


void init()
{
	add_action("do_work", ({"work", "ganhuo"}) );
}

int do_work()
{
	object me = this_player();
//	if ( query("worktimes") < 0)
//		return notify_fail("码头上现在不需要人干活，下次吧！\n");

	if (me->query("gender") == "女性") 
	return notify_fail("码头上现在不需要女孩子家干活！\n");
//	if ( me->query_temp("working") )
//		return notify_fail("你已经在干活了！！\n");
	if ( !objectp( present ("jian gong", environment(me) ) ) )
		return notify_fail("码头上现在不需要人干活，下次吧！\n");
	if (me->query("combat_exp")<MIN_EXP)
	{
		tell_object(me,"这里都是重活，你现在还干不了。\n");
		return 1;
	}
	

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢！\n");
	if ( (int)me->query("jing") < 10 || (int)me->query("qi") < 10 )
	{
		message_vision(
"监工冲着$N就是一鞭子，$N身上顿时起了一道血痕，$N踉踉跄跄躲到一\n"
"边去了。“妈的，你小子这副萎靡不振的样子还想干活？！！”监工骂\n"
"到：“滚！！”\n", me);
		me->receive_damage("qi", 11);
		me->receive_wound("qi", 11);
		return 1;
	}
if (me->query_temp("working") >=1)
{
	write(""+me->query("name")+"搬起一个麻袋，把它从仓库搬到了码头。\n");
}
else
{
	write("监工拿鞭子指了指，说道：“去那里搬麻袋吧。”\n");
	write(""+me->query("name")+"搬起一个麻袋，开始干活。\n");
}
	add("worktimes", -1);
	me->start_busy(5);
	me->add_temp("working",1);
//	remove_call_out("work_end");
if (me->query_temp("working") >=6)
	call_out("work_end", 1, me);

	return 1;
}

int work_end(object me)
{
	object ob1;
	int add_exp,add_pot,add_score;
	me->delete_temp("working");
	write("终于做完苦工了，搬了一天的麻袋，累个半死。\n"
"监工过来拍了拍"+me->query("name")+"的肩膀，说道：“小子，好样的，这是你的工钱。”\n");
	me->receive_damage("jing",me->query("jing")/8);
	me->receive_damage("qi",me->query("qi")/8);
	me->receive_damage("jing",10);
	me->receive_damage("qi",10);
		add_exp=3+random(5);
		add_pot=2+random(2);
		//add_score=1+random(1);
		me->add("combat_exp",add_exp);
		me->add("potential",add_pot);
		//me->add("score",add_score);
		ob1 = new("/clone/money/silver");
		ob1->set_amount(1);
		ob1->move(me);	
		tell_object(me,HIW"你得到了:"
			+ chinese_number(add_exp) + "点实战经验，"
			+ chinese_number(add_pot) + "点潜能。\n"NOR);				
	if ( me->query_temp("working") ) me->delete_temp("working");
	return 1;
}

