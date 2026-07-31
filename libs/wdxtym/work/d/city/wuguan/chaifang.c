// chaifang.c
// Modify By River@SJ

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG"柴房"NOR);
	set("long", @LONG
刚进屋就被屋里叮叮哐哐的声音所吸引，你仔细一看，里面堆满了松柴稻
草。很多人忙碌地在墙边劈柴，屋子特别大，屋子一边堆满了已经锯短的木头，
但是另一边劈好的柴却并不见多。
LONG
	);
        
	set("exits", ([
		"east" : __DIR__"houyuan",
	]));

	set("no_fight",1);

	set("objects", ([
		__DIR__"npc/guanjia1" : 1,
	]));
	set("action_list", ([
		"劈柴":"pi 柴",
	]));
	setup();
}

void init()
{
	add_action("do_pi", "pi");
	add_action("do_pi", "劈");       
}

int do_pi(string arg)
{
	object me = this_player(), weapon;
	int costj, costq;

	if ( !arg || arg != "柴" )
		return notify_fail("你要劈什么？劈人吗？\n");

	if(me->query_temp("job_name")!="劈柴") 
		return notify_fail("你必须跟馆主领了这工作才能在这里干! \n");

	if (me->is_busy())
		return notify_fail("你现在正忙着呢!\n");

	if (me->is_fighting())
		return notify_fail("你正在战斗中,无法专心干活!\n");

	weapon = me->query_temp("weapon");

	if( !weapon || weapon->query("id") != "chai dao")
		return notify_fail("你想用什么来劈柴，用手吗？\n");

	costj = random( me->query("con")/3);
	costq = random( me->query("str")/3);

	if ( me->query("jing") < costj || me->query("qi") < costq){
		message_vision(HIR"$N手一歪，不小心劈在自己的腿上"NOR"\n",me);
		me->unconcious();
		return 1;
	}

	me->receive_damage("jing", costj);
	me->add("qi", -costq);

	if( me->query_temp("mark/劈") > 15 + random(5) || me->query_temp("mark/完了")) {
		me->set_temp("mark/完了",1);
		write(CYN"柴房管事说道：「干的不错，好了，你可以到大师兄鲁坤那里去覆命了！」"NOR"\n");
		return 1;
	}
	write("你摆正一块木头，一刀劈了下去，“哐”的一声，木头被劈为两片。\n");
	me->start_busy(1);
	me->add_temp("mark/劈",1);
	if( me->query_skill("blade", 1) < 30 && random(10) > 6 ){
		write(HIM"你在劈柴中对于刀的用法有些体会!"NOR"\n");
		me->improve_skill("blade",  me->query("int") / 10 );
	}
	return 1;
}
