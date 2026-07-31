#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(HIR"玫瑰红乾坤壶"NOR, ({"qiankun hu", "hu"}));
	set_weight(800);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "景德镇官窑烧制的陶瓷精品。\n");
		set("unit", "个");
		set("value", 10000);
		set("max_liquid", 80);
	}
}
