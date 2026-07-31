// Room: /yanziwu/matou.c
// Date: Jan.28 2000 by Winder

#include <ansi.h>
#define MAX_EXP 80000
#define MIN_EXP 5000
inherit ROOM;
int do_go(string);
void create()
{
	set("short","宁海桥码头");
	set("long",@LONG
这里是扬州城里最大的码头，南方的粮食，两淮的盐铁在此卸下由
漕运署的官员抽查，或转运或暂时储存。这里人员繁杂，有小贩在叫卖，
有工人在搬运粮袋，有官员手持长鞭在监工，有几个泼皮在转来转去，
不知打些什么主意。南边就是漕运署。东边是达士街，新开了几家店铺。
    岸边停靠着一条客船。
LONG );
	set("outdoors", "city");
	set("worktimes", 20);
	set("exits", ([
		"north" : __DIR__"beiliuxiang",
		"south" : __DIR__"zhuqidian",
		"east"  : __DIR__"dashixijie",
		"west"  : __DIR__"ninghaiqiao",
	]));
	set("objects", ([
		__DIR__+"npc/jiangong" :1,
	]));
	set("coor/x", 40);
	set("coor/y", -10);
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
		add_exp=3+random(3);
		add_pot=1+random(2);
		add_score=1+random(1);
		me->add("combat_exp",add_exp);
		me->add("potential",add_pot);
		me->add("score",add_score);
		ob1 = new("/clone/money/silver");
		ob1->set_amount(add_score);
		ob1->move(me);	
		tell_object(me,HIW"你得到了:"
			+ chinese_number(add_exp) + "点实战经验，"
			+ chinese_number(add_pot) + "点潜能，"
			+ chinese_number(add_score) + "点江湖阅历。\n"NOR);				
	if ( me->query_temp("working") ) me->delete_temp("working");
	return 1;
}

