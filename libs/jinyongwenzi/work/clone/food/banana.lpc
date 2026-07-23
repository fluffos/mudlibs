// 香蕉

#include <ansi.h>
inherit ITEM;

void create()
{
        seteuid(getuid());
	set_name(HIY"香蕉"NOR, ({ "xiang jiao","jiao","banana" }) );
	set("long", "一只黄橙橙的香蕉。\n");
        set("value", 2000);
	set("unit", "只");
	set_weight(10);
	setup();
}

void init()
{
	add_action("do_bo","bo");
	add_action("do_eat","chi");
}

int do_bo(string arg)
{
	object me = this_player();
	
	if (!arg || arg!="xiangjiao" && arg!="xiang jiao" && arg!="banana")
		return notify_fail("你要拨什么？\n");
		
	if ( me->query_temp("banana") ) return notify_fail("香蕉已经被你拨过皮了。\n");
		
	me->set_temp("banana",1);
	me->set_temp("banana2",1);
	new(__DIR__"banana2")->move(me);
	message_vision(HIW"$N拨开了一只香蕉。\n"NOR, me);
	me->delete_temp("banana2");
	
	return 1;
}

int do_eat(string arg)
{
	object me = this_player();
	
	if (!arg || arg!="xiangjiao" && arg!="xiang jiao" && arg!="banana")
		return notify_fail("你要吃什么？\n");

	if (! me->query_temp("banana")) return notify_fail("你想连皮吃下么？\n");
	
	me->delete_temp("banana");
	me->add("food",40);
	message_vision(HIY"$N吃下一只香蕉。\n"NOR, me);
	destruct(this_object());	
	
	return 1;
}
