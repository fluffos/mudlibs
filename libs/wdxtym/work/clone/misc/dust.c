// dust.c

#include <ansi.h>

inherit ITEM;

void setup()
{
}

void create()
{
	set_name(HIC "化尸粉" NOR, ({"dust"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一包用毁尸灭迹的化尸粉，只要一"
			    "丁点就可以化去(dissolve)一具尸体！\n");
		set("value", 50);
	}
	setup();
}

void init()
{
	if (this_player() == environment())
		add_action("do_dissolve", "dissolve");
}
							   
int do_dissolve(string arg)
{
	object ob;

	if (! arg)
		return notify_fail("你要用化尸粉溶解什么东西？\n");

	if (! objectp(ob = present(arg, environment(this_player()))))
		return notify_fail("这里没有这样东西。\n");

	if (! ob->is_corpse() && ! ob->is_body_part() && ! ob->is_head())
		return notify_fail("化尸粉只能用来溶解尸体。\n");

	message_vision("$N用指甲挑了一点化尸粉在$n上，只听见一"
		       "阵「嗤嗤」声响带着一股可怕的恶臭，$n只"
		       "剩下一滩黄水。\n", this_player(), ob);
	destruct(ob);
	return 1;
}
