#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"白衣送子观音像"NOR, ({"shenxiang", "xiang"}));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "景德镇官窑烧制的陶瓷精品。\n");
		set("unit", "个");
		set("value", 10000);
	}
}
