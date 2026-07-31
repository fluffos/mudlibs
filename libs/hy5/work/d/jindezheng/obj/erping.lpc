#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(HIC"雨后天青双耳瓶"NOR, ({"ping", "shuangerping"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "景德镇官窑烧制的陶瓷精品。\n");
		set("unit", "个");
		set("value", 20000);
		set("max_liquid", 200);
	}
}
