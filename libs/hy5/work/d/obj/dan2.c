#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(BLU"孽龙丹"NOR, ({"long dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗孽龙的内丹。\n");
		set("value", 0);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("你要吃什么？\n");

	this_player()->add("combat_exp", 2000);
	this_player()->add("potential",1000);
	message_vision("$N吃下一颗孽龙丹,只觉得自己又变利害了一些 !\n", this_player());
	destruct(this_object());
	return 1;
}

