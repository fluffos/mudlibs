// jinchuang.c 金创药
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
	set_name("金创药", ({"jinchuang yao", "jin", "jinchuang"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "包");
		set("long", "这是一包武林人士必备的金创药。\n");
        set("value", 2500);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
		return notify_fail("你要吃什么药？\n");
	if(this_player()->is_fighting())
		return notify_fail("战斗中不能敷药。\n");
	if ((int)this_player()->query("eff_qi") == 
	    (int)this_player()->query("max_kee"))
		return notify_fail("你现在不需要用金创药。\n");
	else {
		this_player()->receive_curing("kee", 50);
                message_vision(GRN "$N吃下一包金创药，气色看起来好多了。\n" NOR, this_player());
		destruct(this_object());
		return 1;
	}
}

