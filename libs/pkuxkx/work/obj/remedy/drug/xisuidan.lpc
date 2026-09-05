#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIM"伐毛洗髓丹"NOR, ({"xisui dan", "dan" }));
	set_weight(1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "一颗秘制灵药，可强身健体、易筋洗髓，但一生只能吃一颗。\n");
		set("value", 50000);
		set("no_give",1);
		set("no_drop",1);
		set("no_get",1);
		set("no_store",1);
		set("no_pawn",1);
	}
	setup();
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me, ob;
	if(!id(arg))
		return 0;	
	me = this_player();
	ob = this_object();
	if (ob->query("owner") != me->query("id") || !me->query("purefamily/level") || me->query("purefamily/xisui")) 
	{
		message_vision("$N把$n放进嘴里嚼了嚼，感觉味道不错，但却没发现有其他功效。\n", me, ob);
	}
	else
	{
		message_vision("$N把$n放进嘴里咽下，然后立即坐下运功调息。\n", me, ob);
		me->set("purefamily/xisui", 1);
		tell_object(me, "你的先天膂力提高了！\n");
		me->add("str",2);
		me->add("xiantian/str/purefamily",2);
		tell_object(me, "你的先天悟性提高了！\n");
		me->add("int",2);
		me->add("xiantian/int/purefamily",2);
		tell_object(me, "你的先天根骨提高了！\n");
		me->add("con",2);
		me->add("xiantian/con/purefamily",2);
		tell_object(me, "你的先天身法提高了！\n");
		me->add("dex",2);
		me->add("xiantian/dex/purefamily",2);
	}
	destruct(ob);
	return 1;
}