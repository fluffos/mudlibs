#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG"无常造化丹"NOR, ({"wuchangzaohua dan", "dan" }));
	set_weight(1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "一颗有起死回生之效的神药，只是闻起来的味道有些古怪。\n");
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
	if (ob->query("owner") != me->query("id")) 
	{
		tell_object(me, "你用两个指头拈起药丸闻了闻，觉得有股子恶臭味，闻之令人作呕，犹豫了半天也没敢放到嘴里。\n");
		return 1;
	}
	
	message_vision("$N把$n塞进嘴里，一扬脖子咽了下去，感觉一股热流直冲丹田，浑身都暖洋洋的。\n", me, ob);
	me->add("death_decrease", 5+random(8));
	
	destruct(ob);
	return 1;
}