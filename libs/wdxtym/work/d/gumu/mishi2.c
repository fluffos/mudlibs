#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "密室");
	set("long", @LONG
这里是古墓中的密室，四周密不透风，你只能借着墙上昏暗的灯
光来勉强分辨方向。墙是用整块的青石砌合起来的，接合的甚是完美，
你难以从中找出一丝缝隙。墙上(wall)好象雕有一些文字。
LONG );

	set("item_desc", ([
		"【墙壁】": WHT "一堵用整块青石砌合而成的墙，上面雕刻着很多文字，似乎记载了一些鞭法的窍决所在。"NOR"\n"
			ZJOBACTS2"参悟:canwu wall\n",
	]) );

	set("exits", ([
		"east" : __DIR__"mishi3",
		"north" : __FILE__,
		"south" : __FILE__,
		"up" : __DIR__"houting",
	]));

	setup();
}

void init()
{
	add_action("do_canwu", "canwu");
}

int do_canwu(string arg)
{
	object me = this_player();
	object ob;
	object ob1;

	if (arg != "wall" && arg != "wall")
		return notify_fail("你要参悟什么？\n");

	if ((int)me->query("can_perform/yinsuo-jinling/feng"))
		return notify_fail("你已经学会了「风神诀」这一招。\n");

	if (! (int)me->query_skill("yinsuo-jinling"))
		return notify_fail("你参悟了半天，觉得墙上记载的东西和你"
				   "所习的武学没什么瓜葛，参悟不出什么。\n");

	if ((int)me->query_skill("yinsuo-jinling", 1) < 130)
		return notify_fail("你对银索金铃的理解不够，参悟不出什么。\n");

	if (me->is_busy())
		return notify_fail("你现在正在参悟中。\n");

	if ((int)me->query("potential") < 5)
		return notify_fail("你的潜能不够了，参悟不出什么。\n");

	if ((int)me->query("jing") < 30)
		return notify_fail("你太疲倦了，休息一下吧。\n");

	if (random(20) < 18)
	{
		me->receive_damage("jing", 25);
		me->add("potential", -5);
		me->start_busy(2);
		message_vision(WHT "$N" WHT "面对着石壁静思良久，参"
			       "悟着石壁上所记载的东西。"NOR"\n", me);
		tell_object(me, HIY "你对银索金铃有了更深的理解，但"
			       "尚需进一步的参悟。"NOR"\n");
		return 1;
	} else
	{ 
		me->receive_damage("jing", 25);
		me->add("potential", -5);
		me->start_busy(2);
		message_vision(WHT "$N" WHT "面对着石壁静思良久，参"
			       "悟着石壁上所记载的东西。"NOR"\n", me);
		tell_object(me, HIY "良久……良久……你终于破晓了"
				"银索金铃「风神诀」绝技的奥秘！\n\n"
				NOR + HIC "你学会了「风神诀」这一招"
				"。"NOR"\n");
		if (me->can_improve_skill("whip"))
			me->improve_skill("whip", 960000);
		if (me->can_improve_skill("parry"))
			me->improve_skill("parry", 960000);
		if (me->can_improve_skill("dodge"))
			me->improve_skill("dodge", 960000);
		if (me->can_improve_skill("yinsuo-jinling"))
			me->improve_skill("yinsuo-jinling", 960000);
		me->set("can_perform/yinsuo-jinling/feng", 1);
	}

	return 1;
}

