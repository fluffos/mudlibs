// houshan.c 无量山后山
// by llin
// Modified by iszt@pkuxkx, 2007-04-14

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "无量山后山");
	set("long", @LONG
眼前是一座直入云霄的山峰－－无量山，山峰是一片直上直落的峭壁(stiff)，
山岩嶙峋狰狞，只看到零星生着的几棵松树，数蓬野草。远处水声淙淙，似乎有
条山溪。南边是一条小道曲曲折折，正是下山的山道。
LONG);
	set("item_desc", ([
		"stiff" : "在高高的悬崖上突然闪过一个身影，待你定睛一看，却什麽都没有。\n"
			"大概是你眼睛花了吧。\n",
		]));
	set("exits", ([
		"southdown" : __DIR__"sroad3",
	]));
	setup();
}

void init()
{
	add_action("do_climb","climb");
}

int do_climb(string arg)
{
	object me=this_player();

	if(me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");
	me->set_temp("times",3);
	message_vision("$N一咬牙，扳住崖上的岩石，手脚并用向上爬去。\n",me);
//	remove_call_out("climbing");
	call_out("climbing",1,me);
	return 1;
}

int climbing(object me)
{
	int times,skl,hurt;
	if (!me)
	return 1;
	times=me->query_temp("times");
	skl=(int)me->query_skill("dodge",1);
	hurt=(int)me->query("max_qi")/3;
	if (times==3) {
		me->move(__DIR__"stiff");
		me->start_busy(5);
		me->add_temp("times",-1);
		call_out("climbing",5,me);
		return 1;
	}

	if (times==2 || times==1)
	{
		if (skl<80 && random(100-skl)>20)
		{
			tell_object(me,RED"突然你突然脚下踏了个空，向下一滑，听得一声惨叫：啊...... 直坠而下。\n"NOR);
			me->move(__DIR__"houshan");
			me->receive_wound("qi", hurt, "从无量山上摔");
			message("vision",HIY"忽听得崖上一声惨叫，只见" + (string)me->name() + "从半空摔将下来......\n"NOR,
				environment(me),me);
			me->unconcious();
			me->delete_temp("times");
			return 1;
		}
		me->start_busy(5);
		message_vision("$N手扯草根，脚踏岩缝，在凛冽的山风中艰难的向上爬着。\n", me);
		me->add_temp("times",-1);
		call_out("climbing",5,me);
		return 1;
	}
	if (times==0) {
	tell_object(me,"突然你突然脚下踏了个空，向下一滑，身子登时堕下了去。
你身在半空，双手乱挥，只盼能抓到什么东西，这么乱挥一阵，又下堕下百馀丈。
突然间蓬一声，屁股撞上了什么物事，身子向上弹起，原来恰好撞到崖边伸出的一株
古松。喀喇喇几声响，古松粗大的枝干登时断折，但下堕的巨力却也消了. \n");
	me->move(__DIR__"yafeng");
	return 1;
	}
}