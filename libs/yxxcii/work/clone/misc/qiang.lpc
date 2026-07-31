// yanpian.c 
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name("鸦片枪", ({"yapian qiang", "qiang"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一支装满了福寿膏的鸦片枪。\n");
		set("unit", "支");
		set("value", 0);
		set("no_give",1);
		set("no_put",1);
		set("no_sell",1);
		set("no_get",1);
		set("no_pawn",1);
	}
}

void init()
{
	add_action("do_light","light");
	add_action("do_xi","xi");
}

int do_light(string arg)
{
	object me,ob;
	me = this_player();
	ob = present("yapian qiang",me);

	if( !arg || arg=="" ) return notify_fail("你要点着什么？\n");
	if(!present("yapian qiang", me))  return notify_fail("你要点着什么？\n");
	if(ob->query("light")) return notify_fail("鸦片枪已经点燃了。\n");
	if( arg=="yapian qiang" || arg=="qiang") {
		message_vision(HIY"$N抽出一支香，把鸦片枪点燃，一阵扑鼻的芳香，真想吸(xi)上一口。\n"NOR,me);
		ob->set("light", 1);	
		return 1;
	}
}
int do_xi()
{
	object me,ob;
	me = this_player();
	ob = present("yapian qiang",me);
	
	if(!ob->query("light"))
		return notify_fail("鸦片枪还没有点燃，你怎么吸呀？\n");
	if(!present("yapian qiang",me))
		return notify_fail("你要吸什么？\n");
	if(!me->query_temp("give_yan_money"))
		return notify_fail("你还没给钱就想吸大烟？\n");
	if( ob->query("xi") > 3) {
		tell_object(me,"鸦片枪里的福寿膏已经被你吸光了。\n");
		destruct(ob);
	}
	
	message_vision(HIW"$N举起烟枪，放在嘴边，慢慢的吸了一口。\n"NOR,me);
	ob->add("xi",1);
	me->apply_condition("yapian",100);
	me->start_busy(5);
	remove_call_out("xi_yan");
	call_out("xi_yan",5,ob);
	return 1;
}

void xi_yan()
{
	object me;
	me = this_player();
	message_vision(WHT"只见$N从口中吐出一口清烟，$N显得十分陶醉！\n"NOR,me);
	tell_object(me,HIC"你觉得整个人精神了许多，手脚也十分有劲！\n"NOR);
	me->start_busy(0);
}

	
	
