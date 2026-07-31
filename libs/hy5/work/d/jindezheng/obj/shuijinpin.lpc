#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(HIW"乳白水净瓶"NOR, ({"jinpin", "pin"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "景德镇烧制的陶瓷精品。\n");
		set("unit", "个");
		set("value",10000);
		set("max_liquid", 100);
	}
}
