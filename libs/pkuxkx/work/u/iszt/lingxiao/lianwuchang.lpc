// File		: lianwuchang.c
// Created By	: iszt@pkuxkx, 2006-09-05

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
这里是凌霄城中最大的练武场。青石板上的积雪被扫得干干净净。一角的地
上钉着几根木桩(zhuang)，供人反复击打；另一角挂着若干沙袋(shadai)，正有
几人在不停地拍、踢、抓、戳。十数名弟子持剑，专心致志的练习剑法。一名中
年人走来走去，不时停下来出言指点。
LONG);

	set("outdoors", "凌霄城");
	set("exits", ([
		"south" : __DIR__"stones2",
		"north" : __DIR__"stonen3",
		"southwest" : __DIR__"stones1",
		"southeast" : __DIR__"stones3",
	]));
	set("objects", ([
		__DIR__"npc/fengwanli" : 1,
	]));

	setup();
}

void init()
{
	add_action("do_strike", "strike");	    
	add_action("do_strike","hit");
	add_action("do_strike","ji");
	add_action("do_strike","da");
	add_action("do_chuo","chuo");
	add_action("do_ti","ti");
	add_action("do_zhua","zhua");
	add_action("do_pai","pai");
}

int do_strike(string arg)
{
	object me = this_player();
	int costq, level;

	if (me->is_busy())
		return notify_fail("你现在正忙着呢！\n");

	if (me->is_fighting())
		return notify_fail("还是先把眼前的敌人解决了吧！\n");

	if ( !living(me))
		return notify_fail("你发疯了？\n");

	if( objectp( me->query_temp("weapon")) )
		return notify_fail("只有空手才能打木桩。\n");

	if ( !arg || arg != "zhuang" )
		return notify_fail("你要击打什么？\n");

	if (me->query("family/family_name") != "雪山派" && random(4) == 1)
	{
		me->start_busy(1);
		return notify_fail("你在木桩前扎好马步正想练功，却被一名雪山弟子客气的请开了。");
	}

	if ( (level = me->query_skill("parry", 1)) < 20 )
		return notify_fail("你对着木桩来回地击打，但是对如何招架毫无心得。\n");

	if (level >= 120)
		return notify_fail("你对着木桩来回地击打，但是打击木桩已经无法使你的基本招架提高了。\n");

	costq = level / 4 + random(level / 4);
	if (me->query("qi") <= costq) {
		write("你太累了，已经没有力气击打木桩了！\n");
		return 1;
	}
	me->receive_damage("qi", costq);
	write("你对着木桩来回地击打，觉得对你的基本招架有所促进。\n");
	if (!random(5)) tell_room(this_object(),
		me->name() + "正在来回地击打木桩。\n", ({ me }));
	me->improve_skill("parry", me->query("int"));       
	return 1;
}

int do_chuo(string arg)
{
	object me = this_player();
	int costj, costq;

	if (me->is_busy())
		return notify_fail("你现在正忙着呢！\n");

	if (me->is_fighting())
		return notify_fail("还是先把眼前的敌人解决了吧！\n");

	if ( !living(me))
		return notify_fail("你发疯了？\n");

	if( objectp( me->query_temp("weapon")) )
		return notify_fail("只有空手才能打沙袋。\n");

	if ( !arg || arg != "shadai" )
		return notify_fail("你要戳什么？\n");

	if (me->query("family/family_name") != "雪山派" && random(4) == 1)
	{
		me->start_busy(1);
		return notify_fail("你来到沙袋前正想练功，却被一名雪山弟子客气的请开了。");
	}

	costj = random((int)me->query("con"));
	costq = random((int)me->query("str"));

	if ((int)me->query("jing") < costj || (int)me->query("qi") < costq){
		message_vision(HIR"$N出指如风，终因精气不支晕倒在地！\n"NOR,me);
		me->unconcious();
	    return 1;
	}
	
	me->receive_damage("jing", costj);
	me->receive_damage("qi", costq);       

	message_vision("$N出指如风，不断变换着路数向沙袋戳去。\n", me);

	if ( (int)me->query_skill("finger", 1) < 20 && random(10)>6 ){
		write(HIM"沙袋左右摇晃，你不知不觉中领悟了些基本指法！\n"NOR);
		me->improve_skill("finger", (int)(me->query("int") * 3));
	}
	return 1;
}

int do_ti(string arg)
{     
	object me = this_player();
	int costj, costq;

	if (me->is_busy())
		return notify_fail("你现在正忙着呢！\n");

	if (me->is_fighting())
		return notify_fail("还是先把眼前的敌人解决了吧！\n");

	if ( !living(me))
		return notify_fail("你发疯了？\n");

	if( objectp( me->query_temp("weapon")) )
		return notify_fail("只有空手才能打沙袋。\n");

	if ( !arg || arg != "shadai" )
		return notify_fail("你要踢什么？\n");

	if (me->query("family/family_name") != "雪山派" && random(4) == 1)
	{
		me->start_busy(1);
		return notify_fail("你来到沙袋前正想练功，却被一名雪山弟子客气的请开了。");
	}

	costj = random((int)me->query("con"));
	costq = random((int)me->query("str"));

	if ((int)me->query("jing") < costj || (int)me->query("qi") < costq){
		message_vision(HIR"$N连连出腿，终因精气不支晕倒在地！\n"NOR,me);
		me->unconcious();
	    return 1;
	}
	
	me->receive_damage("jing", costj);
	me->receive_damage("qi", costq);

	message_vision("$N连连出腿，不断变换着路数向沙袋踢去。\n", me);

	if ( (int)me->query_skill("leg", 1) < 20 && random(10)>6 ){
		write(HIM"你把沙袋踢的摆来摆去，觉得自己的基本腿法有了提高！\n"NOR);
		me->improve_skill("leg", (int)(me->query("int") * 3));
	}
	return 1;
}

int do_zhua(string arg)
{
	object me = this_player();
	int costj, costq;

	if (me->is_busy())
		return notify_fail("你现在正忙着呢！\n");

	if (me->is_fighting())
		return notify_fail("还是先把眼前的敌人解决了吧！\n");

	if ( !living(me))
		return notify_fail("你发疯了？\n");

	if( objectp( me->query_temp("weapon")) )
		return notify_fail("只有空手才能打沙袋。\n");

	if ( !arg || arg != "shadai" )
		return notify_fail("你要抓什么？\n");

	if (me->query("family/family_name") != "雪山派" && random(4) == 1)
	{
		me->start_busy(1);
		return notify_fail("你来到沙袋前正想练功，却被一名雪山弟子客气的请开了。");
	}

	costj = random((int)me->query("con"));
	costq = random((int)me->query("str"));

	if ((int)me->query("jing") < costj || (int)me->query("qi") < costq){
		message_vision(HIR"$N爪影密布，终因精气不支晕倒在地！\n"NOR,me);
		me->unconcious();
	    return 1;
	}
	
	me->receive_damage("jing", costj);
	me->receive_damage("qi", costq);       

	message_vision("$N爪影密布，不断变换着路数向沙袋抓去。\n", me);

	if ( (int)me->query_skill("claw", 1) < 30 && random(10)>6 ){
		write(HIM"你不断的抓着沙袋，觉得自己的基本爪法有了提高！\n"NOR);
		me->improve_skill("claw", (int)(me->query("int") * 3));
	}
	return 1;
}

int do_pai(string arg)
{       
	object me = this_player();
	int costj, costq;

	if (me->is_busy())
		return notify_fail("你现在正忙着呢！\n");

	if (me->is_fighting())
		return notify_fail("还是先把眼前的敌人解决了吧！\n");

	if ( !living(me))
		return notify_fail("你发疯了？\n");

	if( objectp( me->query_temp("weapon")) )
		return notify_fail("只有空手才能打沙袋。\n");

	if ( !arg || arg != "shadai" )
		return notify_fail("你要拍什么？\n");

	if (me->query("family/family_name") != "雪山派" && random(4) == 1)
	{
		me->start_busy(1);
		return notify_fail("你来到沙袋前正想练功，却被一名雪山弟子客气的请开了。");
	}

	costj = random((int)me->query("con"));
	costq = random((int)me->query("str"));

	if ((int)me->query("jing") < costj || (int)me->query("qi") < costq){
		message_vision(HIR"$N运气于掌，终因精气不支晕倒在地！\n"NOR,me);
		me->unconcious();
	    return 1;
	}
	
	me->receive_damage("jing", costj);
	me->receive_damage("qi", costq);       

	message_vision("$N运气于掌，不断变换着路数向沙袋拍去。\n", me);

	if ( (int)me->query_skill("strike", 1) < 20 && random(10)>6){
		write(HIM"你把沙袋拍的荡来荡去，觉得自己的基本掌法有了提高！\n"NOR);
		me->improve_skill("strike", (int)(me->query("int") * 3));
	}
	return 1;
}
