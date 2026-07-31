// by 无名英雄

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(GRN"『琴技入门』"NOR, ({ "string's book", "book" }));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", HIY"一本线装图谱，上绘徵、宫、羽、商、角五音之入门基础。\n"+
			"你可以研读（Read）它来修炼基本的琴技。\n"NOR);
		set("value", 500);
		set("material", "paper");
		set("exp_required",100000);
		set("jing_cost", 18);
		set("difficulty", 28);
		set("max_skill", 30);
	}
}

void init()
{
	if( environment() == this_player() )
		add_action("do_du", "read");
}

int do_du(string arg)
{
	object me,ob;
	int i, j;

	me = this_player();
	ob = this_object(); 

	i = (int)me->query_skill("string", 1);
	j = (int)me->query_skill("literate", 1);

	if( !(arg == ob->query("id") || arg == "book") ) return 0;

	if( !me->query_skill("literate", 1) )
		return notify_fail("你是个文盲，先学点文化(literate)吧。\n");	   

	if( me->is_busy() )
		return notify_fail("你现在正忙着呢。\n");

	if( me->is_fighting() ) 
		return notify_fail("你无法在战斗中专心下来研读新知！\n");

	if( !id(arg) )
		return notify_fail("你要读什么？\n");

	if( j < 100 )
		return notify_fail("你的读书写字等级不够，无法理解书中记载的「乐理琴技」。\n"); 

	if( !random(5) )
		message("vision", me->name() + "正专心地研读" + this_object()->name()+"。\n", environment(me), me);

	if( (int)me->query("jing") < ob->query("jing_cost") )
		return notify_fail("你现在过于疲倦，无法专心下来研读新知。\n");

	if( (int)me->query("combat_exp") < ob->query("exp_required"))
		return notify_fail("你的实战经验不足钻研更高深的「乐理琴技」。\n");	

	if( (int)me->query("combat_exp") < i*i*i/10 )
		return notify_fail("你的实战经验不足，再怎么读也没用。\n");

	if( me->query_int() < ob->query("difficulty") )
		return notify_fail("你研读了一会儿，发现根本不能领悟到上面写些什么。\n");

	if( i < ob->query("min_skill") )
		return notify_fail("你研读了一会儿，但是发现上面所说的对你而言都太深了，没有学到任何东西。\n");

	if( i > ob->query("max_skill") )
		return notify_fail("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");

	me->receive_damage("jing", ob->query("jing_cost")); 
	me->improve_skill("string", me->query_int()/3 + 3);
	write("你仔细研读着"+ob->name()+"，觉得自己对音律之道有所收益。\n");
	return 1;
}
