// dongchongcao.c 冬虫草

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_fu", "fu");
}

void create()
{
	set_name(HIB"冬虫草"NOR, ({"dongchong cao", "cao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "株");
		set("long", HIB"这是一株夏季从冬季钻入土中的死虫身上长出的冬虫夏草。\n"NOR);
set("value", 2500);
	}
	setup();
}

int do_fu(string arg)
{
	string what = query("cure");
	int howmuch = query("amount");

	if (!id(arg))
		return notify_fail("你想吃什么？\n");

	if ((int)this_player()->query("eff_qi") ==
		 (int)this_player()->query("max_qi"))
		return notify_fail("你现在身上没有受到任何伤害！\n");
	else {
		this_player()->receive_curing("qi", 50);
		message_vision("$N把一株冬虫草放进口中嚼碎，小心敷在伤口上，气色看起来好多了。\n", this_player());
		destruct(this_object());
		return 1;
	}
}

