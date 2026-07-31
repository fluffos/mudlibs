// zaisheng.c
#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	int i ;

	i = random (3);
	if ( i == 0 ) 
		set("long", "这是一颗洁白如玉的再生丸.\n");
	else {
		set("long", "这是一颗洁白如玉的再生丸。\n");
		i = 1;
	}
	add_action("do_eat"+i, "eat");
}

void create()
{
	set_name("再生丸", ({"zaisheng wan", "wan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗洁白如玉的再生丸.\n");
		set("value", 2000);
	}
	setup();
}

int do_eat0(string arg)
{
	object me = this_player();

	if (!id(arg))
	return notify_fail("你要吃什么？\n");
	me->add("max_neili", -1);
	message_vision(HIR "$N吃下一颗再生丸，只觉得肝肠寸断，胸闷欲呕，霎时就人事不醒了\n" NOR, me);
	me->unconcious();
	destruct(this_object());
	return 1;
}
