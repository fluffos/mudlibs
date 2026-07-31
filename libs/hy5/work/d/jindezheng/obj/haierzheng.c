#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIC"水蓝陶瓷孩儿枕"NOR, ({"haier zheng", "zheng"}));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "景德镇官窑烧制的陶瓷精品。\n");
		set("unit", "个");
		set("value", 10000);
	}
}
